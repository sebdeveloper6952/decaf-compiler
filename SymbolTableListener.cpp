#include <iostream>
#include "SymbolTableListener.h"
#include "SymbolTable.h"
#include "DataTypes.h"

SymbolTableListener::SymbolTableListener(
    SymbolTable *table,
    std::vector<IcgInstr *> *instrs)
{
    this->table = table;
    this->instrs = instrs;
}

/// ---------------------------------------- top level class Program ----------------------------------------

/**
 * enterProgram
 * 
 */
void SymbolTableListener::enterProgram(DecafParser::ProgramContext *ctx) {}

/**
 * exitProgram
 * 
 * Check that the source program has a valid 'main' declaration.
 */
void SymbolTableListener::exitProgram(DecafParser::ProgramContext *ctx)
{
    if (!this->is_main_valid)
    {
        put_node_type(ctx, T_ERROR);
        print_error(
            "source program must include a valid 'main' function declaration.",
            ctx->start->getLine());
    }

    // check for propagated errors
    for (antlr4::tree::ParseTree *child : ctx->children)
    {
        if (get_node_type(child) == T_ERROR)
        {
            put_node_type(ctx, T_ERROR);

            std::string msg = "source program is invalid.";
            print_error(msg, ctx->stop->getLine());

            return;
        }
    }

    // program is valid
    put_node_type(ctx, T_VOID);

    std::cout << "\n[INFO] program is valid ✅\n"
              << std::endl;

    for (antlr4::tree::ParseTree *child : ctx->children)
    {
        NodeAttrs *a = this->get_node_attrs(child);
        if (a != NULL)
        {
            for (IcgInstr *c : a->l_code)
                this->instrs->push_back(c);
        }
    }
}

// Enter a new block
void SymbolTableListener::enterBlock(DecafParser::BlockContext *ctx)
{
    // push a new symbol table for this block
    this->push_table();

    // if this node parent is a methodDeclaration, handle its parameters
    // as if they were local variables of this block
    if (ctx->parent != NULL)
    {
        DecafParser::MethodDeclarationContext *p = (DecafParser::MethodDeclarationContext *)ctx->parent;
        std::vector<DecafParser::ParameterContext *> params = p->parameter();
        if (params.size())
        {
            for (DecafParser::ParameterContext *p : params)
            {
                int param_type = DataTypes::get_instance()
                                     ->get_type_int(p->parameterType()->getText());

                this->table->put(
                    O_DATA,
                    param_type,
                    p->ID()->getText(),
                    p->parameterType()->getText());
            }
        }
    }
}

// exit the current block
void SymbolTableListener::exitBlock(DecafParser::BlockContext *ctx)
{
    // pop the symbol table for this block
    SymbolTable *top = this->pop_table();

    NodeAttrs *attrs = this->get_node_attrs(ctx);
    if (attrs == NULL)
    {
        attrs = new NodeAttrs();
        this->put_node_attrs(ctx, attrs);
    }

    // icg code accumulation
    for (auto child : ctx->children)
    {
        NodeAttrs *n = this->get_node_attrs(child);
        if (n != NULL)
        {
            for (IcgInstr *c : n->l_code)
                attrs->l_code.push_back(c);
        }
    }
}

/// ---------------------------------------- Var Declarations ----------------------------------------
void SymbolTableListener::enterVar_decl(DecafParser::Var_declContext *ctx)
{
    std::string var_type = ctx->varType()->getText();
    std::string id = ctx->ID()->getText();
    int var_t = DataTypes::get_instance()->get_type_int(var_type);

    if (!this->table->put(O_DATA, var_t, id, var_type))
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "id '" + id + "' is already declared.";
        print_error(msg, ctx->start->getLine());

        return;
    }
}

/**
 * Check that an array declaration is valid. If it is valid, save the array object
 * int the symbol table.
 * 
 * Checks that NUM is a valid integer literal:
 *  - must be greater than zero
 *  - no upper bound as of right now
 */
void SymbolTableListener::enterVar_arr_decl(DecafParser::Var_arr_declContext *ctx)
{
    std::string var_type = ctx->varType()->getText();
    std::string id = ctx->ID()->getText();
    std::string array_size = ctx->NUM()->getText();

    if (std::stoll(array_size) < 1)
    {
        put_node_type(ctx, T_ERROR);
        std::string msg = "array size must be greater than zero.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    if (std::stoll(array_size) > T_INT_MAX)
    {
        put_node_type(ctx, T_ERROR);
        std::string msg = "array size must be less than " + T_INT_MAX;
        print_error(msg, ctx->start->getLine());

        return;
    }

    size_t size = std::stoi(array_size);
    int var_t = DataTypes::get_instance()->get_type_int(var_type);
    if (!this->table->put(O_ARRAY, var_t, id, var_type, size))
    {
        std::string msg = "varDeclaration id (" + id + ") is already declared.";
        print_error(msg, ctx->start->getLine());

        return;
    }
}

void SymbolTableListener::enterVar_struct_decl(DecafParser::Var_struct_declContext *ctx)
{
    std::vector<antlr4::tree::TerminalNode *> ids = ctx->ID();
    std::string struct_type = ids[0]->getText();
    std::string struct_id = ids[1]->getText();

    // get struct type from symbol table
    SymbolTable *struct_table = this->table->get_struct_table(struct_type);

    // check for struct type validity
    if (struct_table == NULL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "table for struct: '" + struct_type + "' not found.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // array of structs
    if (ctx->NUM() != NULL)
    {
        // save new variable of type struct
        int struct_t = DataTypes::get_instance()->get_type_int(struct_type);

        // calculate array size as NUM * STRUCT_SIZE
        int array_size = std::stoi(ctx->NUM()->getText());
        array_size *= struct_table->get_offset();

        if (!this->table->put(O_ARRAY, struct_t, struct_id, struct_type, array_size))
        {
            put_node_type(ctx, T_ERROR);

            std::string msg = "id '" + struct_id + "' is already declared";
            print_error(msg, ctx->start->getLine());

            return;
        }
    }
    // struct instance declaration
    else
    {
        // save new variable of type struct
        int struct_t = DataTypes::get_instance()->get_type_int(struct_type);

        if (!this->table->put(O_STRUCT_I, struct_t, struct_id, struct_type, struct_table->get_offset()))
        {
            put_node_type(ctx, T_ERROR);

            std::string msg = "id '" + struct_id + "' is already declared";
            print_error(msg, ctx->start->getLine());

            return;
        }
    }

    // save this node type
    put_node_type(ctx, T_STRUCT);
}

void SymbolTableListener::exitVar_struct_decl(DecafParser::Var_struct_declContext *ctx)
{
}

/// ---------------------------------------- Struct Declaration -----------------------------------
void SymbolTableListener::enterStructDeclaration(DecafParser::StructDeclarationContext *ctx)
{
    // new symbol table for this struct scope
    this->push_table();
}

void SymbolTableListener::exitStructDeclaration(DecafParser::StructDeclarationContext *ctx)
{
    std::string struct_id = ctx->ID()->getText();

    // get this struct symbol table
    SymbolTable *table = this->pop_table();

    // add the new type
    int new_type = DataTypes::get_instance()->add_type(struct_id);

    // save the struct declaration as a new type
    this->table->put(
        O_STRUCT,
        new_type,
        struct_id,
        "struct",
        0);

    this->table->add_struct_table(struct_id, table);
}

/// -----------------------------------------------------------------------------------------------

/// ---------------------------------------- Var Locations ----------------------------------------
/**
 * Check if var id exists in symbol table.
 */
void SymbolTableListener::enterLoc_var(DecafParser::Loc_varContext *ctx)
{
    // parent is location member, search in struct symbol tables
    if (DecafParser::Loc_memberContext *d =
            dynamic_cast<DecafParser::Loc_memberContext *>(ctx->parent))
    {
        std::string struct_name = d->ID()->getText();
        SymbolTableEntry *e = this->table->get(struct_name);
        if (e == NULL)
        {
            put_node_type(ctx, T_ERROR);
            return;
        }

        SymbolTable *struct_table = this->table->get_struct_table(e->type);
        if (struct_table == NULL)
        {
            put_node_type(ctx, T_ERROR);
            return;
        }
    }
    else
    {
        std::string id = ctx->ID()->getText();

        SymbolTableEntry *entry = this->table->get(id);
        if (entry == NULL)
        {
            put_node_type(ctx, T_ERROR);

            std::string msg = "id '" + id + "' no declaration found.";
            print_error(msg, ctx->start->getLine());

            return;
        }
        else
        {
            put_node_type(ctx, entry->data_type);
        }
    }
}

/**
 * Set node type of this location node.
 */
void SymbolTableListener::exitLoc_var(DecafParser::Loc_varContext *ctx)
{
    if (DecafParser::Loc_memberContext *d =
            dynamic_cast<DecafParser::Loc_memberContext *>(ctx->parent))
    {
        SymbolTable *top = this->struct_tables.top();
        SymbolTableEntry *e = top->get(ctx->ID()->getText());
        if (e == NULL)
        {
            put_node_type(ctx, T_ERROR);

            return;
        }

        put_node_type(ctx, e->data_type);
        put_node_type(ctx->parent, e->data_type);

        // icg
        NodeAttrs *attrs = this->get_node_attrs(ctx);
        if (attrs == NULL)
            attrs = new NodeAttrs();
        attrs->entry = e;
        attrs->addr = std::to_string(e->offset);

        this->put_node_attrs(ctx, attrs);
        this->put_node_attrs(ctx->parent, attrs);
    }
    else
    {
        SymbolTableEntry *e = this->table->get(ctx->ID()->getText());
        if (e == NULL)
        {
            put_node_type(ctx, T_ERROR);

            return;
        }

        put_node_type(ctx, e->data_type);

        // icg
        std::string addr = e->is_global ? "g" : "l";
        addr += "[" + std::to_string(e->offset) + "]";

        NodeAttrs *attrs = this->get_node_attrs(ctx);
        if (attrs == NULL)
        {
            attrs = new NodeAttrs();
            this->put_node_attrs(ctx, attrs);
        }
        attrs->entry = e;
        attrs->addr = addr;

        this->put_node_attrs(ctx->parent, attrs);
    }
}

void SymbolTableListener::enterLoc_array(DecafParser::Loc_arrayContext *ctx)
{
    SymbolTableEntry *entry = NULL;

    // if parent is a struct
    if (DecafParser::Loc_memberContext *d = dynamic_cast<DecafParser::Loc_memberContext *>(ctx->parent))
    {
        SymbolTable *top = this->struct_tables.top();
        entry = top->get(ctx->ID()->getText());
    }
    else
    {
        entry = this->table->get(ctx->ID()->getText());
    }

    // validate ID exists
    if (entry == NULL)
    {
        put_node_type(ctx, T_ERROR);
        std::string msg = "id '" + ctx->ID()->getText() + "' is not declared.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // validate ID refers to an array object
    if (entry->obj_type != O_ARRAY)
    {
        put_node_type(ctx, T_ERROR);
        std::string msg = "id '" + ctx->ID()->getText() + "' is not an array.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // location has type void
    put_node_type(ctx, T_VOID);
}

void SymbolTableListener::exitLoc_array(DecafParser::Loc_arrayContext *ctx)
{
    DecafParser::ExpressionContext *expr = ctx->expression();
    int expr_type = T_VOID;
    if (expr->children.size() == 1)
        expr_type = get_node_type(expr->children[0]);
    else
        expr_type = get_node_type(expr);

    // expression must be of type integer
    if (expr_type != T_INT)
    {
        put_node_type(ctx, T_ERROR);
        std::string msg = "array index must be of type 'int'";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // try to parse expression to validate array size
    try
    {
        if (std::stol(expr->getText()) < 0)
        {
            put_node_type(ctx, T_ERROR);

            std::string msg = "invalid array index.";
            print_error(msg, ctx->start->getLine());

            return;
        }
    }
    catch (const std::exception &e)
    {
    }

    // set this node type as the type of the array
    SymbolTableEntry *entry = NULL;
    if (DecafParser::Loc_memberContext *d = dynamic_cast<DecafParser::Loc_memberContext *>(ctx->parent))
    {
        SymbolTable *top = this->struct_tables.top();
        entry = top->get(ctx->ID()->getText());
    }
    else
    {
        entry = this->table->get(ctx->ID()->getText());
    }

    // save node type
    put_node_type(ctx, entry->data_type);

    // icg
    // this node attributes
    NodeAttrs *attrs = new NodeAttrs();

    NodeAttrs *expr_e = this->get_node_attrs(expr);
    if (expr->children.size() == 1)
        expr_e = this->get_node_attrs(expr->children[0]);
    uint width = DataTypes::int_to_width(entry->data_type);

    // L.addr = new Temp
    std::string t1 = this->new_temp();

    // acc code
    for (auto c : expr_e->l_code)
        attrs->l_code.push_back(c);

    // calc expr * width
    IcgInstr *i0 = new IcgInstr();
    i0->op_code = OP_MUL;
    i0->a0 = expr_e->value != "" ? expr_e->value : expr_e->addr;
    i0->a1 = std::to_string(width);
    i0->res = t1;
    attrs->l_code.push_back(i0);

    std::string t2 = this->new_temp();

    // calc offset
    IcgInstr *i1 = new IcgInstr();
    i1->op_code = OP_SUM;
    i1->a0 = std::to_string(entry->offset);
    i1->a1 = t1;
    i1->res = entry->is_global ? "g" : "l";
    i1->res += "[" + t2 + "]";
    attrs->l_code.push_back(i1);

    attrs->entry = entry;
    attrs->addr = entry->is_global ? "g" : "l";
    attrs->addr += "[" + t2 + "]";

    this->put_node_attrs(ctx, attrs);
    this->put_node_attrs(ctx->parent, attrs);
}

void SymbolTableListener::enterLoc_member(DecafParser::Loc_memberContext *ctx)
{
    std::string var_name = ctx->ID()->getText();

    // entry for this var name
    SymbolTableEntry *entry = NULL;

    // if parent is a struct
    if (DecafParser::Loc_memberContext *d = dynamic_cast<DecafParser::Loc_memberContext *>(ctx->parent))
    {
        SymbolTable *top = this->struct_tables.top();
        entry = top->get(var_name);
    }
    else
    {
        // validate var_name exists
        entry = this->table->get(var_name);
        if (entry == NULL)
        {
            put_node_type(ctx, T_ERROR);

            std::string msg = "id '" + var_name + "' is not declared.";
            print_error(msg, ctx->start->getLine());

            return;
        }
    }

    // if location refers to array, validate it is an array
    if (ctx->expression() != NULL && entry->obj_type != O_ARRAY)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "id '" + var_name + "' is not an array.";
        print_error(msg, ctx->start->getLine());
    }

    // var_name is a struct, get its struct symbol table
    SymbolTable *struct_table = this->table->get_struct_table(entry->type);
    if (struct_table == NULL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "id '" + var_name + "' not found.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    this->push_struct_table(struct_table);
}

void SymbolTableListener::exitLoc_member(DecafParser::Loc_memberContext *ctx)
{
    int loc_type = get_node_type(ctx->location());
    put_node_type(ctx, loc_type);

    // icg
    SymbolTableEntry *entry = NULL;

    // if parent is a struct
    if (DecafParser::Loc_memberContext *d = dynamic_cast<DecafParser::Loc_memberContext *>(ctx->parent))
    {
        // get the parent struct table to get offset of a.b
        SymbolTable *temp = this->struct_tables.top();
        this->struct_tables.pop();
        entry = this->struct_tables.top()->get(ctx->ID()->getText());
        this->struct_tables.push(temp);
    }
    else
    {
        entry = this->table->get(ctx->ID()->getText());
    }

    // icg
    // this node attributes
    NodeAttrs *attrs = new NodeAttrs();

    // get location node attrs
    NodeAttrs *loc_attrs = get_node_attrs(ctx->location());

    // loc_mem.addr = new Temp()
    std::string temp = this->new_temp();

    std::string addr = entry->is_global ? "g" : "l";
    addr += "[" + temp + "]";

    // acc location code
    for (auto c : loc_attrs->l_code)
        attrs->l_code.push_back(c);

    IcgInstr *i0 = new IcgInstr();
    i0->op_code = OP_SUM;
    i0->a0 = std::to_string(entry->offset);
    i0->a1 = loc_attrs->addr;
    i0->res = temp;
    attrs->l_code.push_back(i0);

    // save node attributes
    attrs->entry = entry;
    attrs->addr = addr;

    // point this node to its attributes
    this->put_node_attrs(ctx, attrs);
    this->put_node_attrs(ctx->parent, attrs);

    this->pop_struct_table();
}

/// ----------------------------------------  Method declaration ----------------------------------------

/**
 * Called on each method declaration.
 * 
 * Check if the method being declared is the required 'main' method.
 */
void SymbolTableListener::enterMethodDeclaration(DecafParser::MethodDeclarationContext *ctx)
{
    std::string method_type = ctx->methodType()->getText();
    std::string id = ctx->ID()->getText();

    // validate 'main' declaration
    if (id == "main")
    {
        this->is_main_valid = method_type == "void" &&
                              ctx->parameter().size() == 0;
    }

    int method_t = DataTypes::get_instance()->get_type_int(method_type);
    if (this->table->put(O_METHOD, method_t, id, method_type))
    {
        // get method params
        std::vector<DecafParser::ParameterContext *> params = ctx->parameter();
        for (DecafParser::ParameterContext *param : params)
        {
            this->table->add_method_param(id, param->parameterType()->getText());
        }
    }
}

void SymbolTableListener::exitMethodDeclaration(DecafParser::MethodDeclarationContext *ctx)
{
    NodeAttrs *attrs = new NodeAttrs();
    NodeAttrs *block_attrs = this->get_node_attrs(ctx->block());

    // new method label
    attrs->addr = this->new_method_label(ctx->ID()->getText());

    attrs->l_code.push_back(new IcgInstr(OP_FN, "", "", attrs->addr));
    for (IcgInstr *c : block_attrs->l_code)
        attrs->l_code.push_back(c);
    attrs->l_code.push_back(new IcgInstr(OP_EFN, "", "", attrs->addr));
    this->put_node_attrs(ctx, attrs);
    this->put_node_attrs(ctx->parent, attrs);
}
/// -----------------------------------------------------------------------------------------------------

/// ---------------------------------------- Method Calls ----------------------------------------
void SymbolTableListener::enterMethodCall(DecafParser::MethodCallContext *ctx)
{

    SymbolTableEntry *e = this->table->get(ctx->ID()->getText());

    // method not declared
    if (e == NULL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "method '" + ctx->ID()->getText() + "' is not declared.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // set method call type to method declared type
    put_node_type(ctx, e->data_type);
}

void SymbolTableListener::exitMethodCall(DecafParser::MethodCallContext *ctx)
{
    SymbolTableEntry *e = this->table->get(ctx->ID()->getText());

    // validate method parameters
    std::vector<DecafParser::ExpressionContext *> a_params = ctx->expression();

    if (e->m_params.size() != a_params.size())
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "expected " + std::to_string(e->m_params.size()) + " parameters, but found ";
        msg += std::to_string(a_params.size());
        print_error(msg, ctx->start->getLine());

        return;
    }

    // validate type of parameters
    for (int i = 0; i < e->m_params.size(); i++)
    {
        int a_type = get_node_type(a_params[i]);
        if (a_params[i]->children.size() == 1)
            a_type = get_node_type(a_params[i]->children[0]);

        if (e->m_params[i] != a_type)
        {
            put_node_type(ctx, T_ERROR);

            std::string msg = "actual parameter type '" + DataTypes::get_instance()->get_type(a_type);
            msg += "' differs from formal parameter type '" + DataTypes::get_instance()->get_type(e->m_params[i]);
            msg += "'";
            print_error(msg, ctx->start->getLine());

            return;
        }
    }

    // icg
    NodeAttrs *attrs = new NodeAttrs();
    for (auto param : ctx->expression())
    {
        auto p_attrs = this->get_node_attrs(param);
        if (p_attrs != NULL)
            attrs->l_code.insert(
                attrs->l_code.end(),
                p_attrs->l_code.begin(),
                p_attrs->l_code.end());
    }

    for (auto param : ctx->expression())
    {
        auto p_attrs = this->get_node_attrs(param);
        if (p_attrs != NULL)
        {
            std::string t = p_attrs->value != "" ? p_attrs->value : p_attrs->addr;
            attrs->l_code.push_back(new IcgInstr(OP_PARM, t, "", ""));
        }
    }

    if (e->data_type != T_VOID)
    {
        attrs->addr = this->new_temp();

        attrs->l_code.push_back(
            new IcgInstr(OP_CALL, e->id, std::to_string(e->m_params.size()), attrs->addr));
    }
    else
    {
        attrs->l_code.push_back(
            new IcgInstr(OP_CALL, e->id, std::to_string(e->m_params.size()), ""));
    }

    this->put_node_attrs(ctx, attrs);
}

/// -----------------------------------------------------------------------------------------------------

/// ---------------------------------------- Expressions ----------------------------------------
void SymbolTableListener::enterExpr_arith_0(DecafParser::Expr_arith_0Context *ctx)
{
}

void SymbolTableListener::exitExpr_arith_0(DecafParser::Expr_arith_0Context *ctx)
{
    this->process_arith_expr(ctx);

    this->gen_code_expr(ctx);
}

void SymbolTableListener::enterExpr_arith_1(DecafParser::Expr_arith_1Context *ctx)
{
}

void SymbolTableListener::exitExpr_arith_1(DecafParser::Expr_arith_1Context *ctx)
{
    this->process_arith_expr(ctx);

    this->gen_code_expr(ctx);
}

void SymbolTableListener::enterExpr_rel(DecafParser::Expr_relContext *ctx)
{
}

void SymbolTableListener::exitExpr_rel(DecafParser::Expr_relContext *ctx)
{
    // set child types
    put_node_type(ctx->children[0], get_node_type(ctx->children[0]->children[0]));
    put_node_type(ctx->children[2], get_node_type(ctx->children[2]->children[0]));

    if (get_node_type(ctx->children[0]) != T_INT)
    {
        size_t line = ctx->start->getLine();
        std::string msg = "'" + ctx->children[0]->getText() + "' is not an integer";
        print_error(msg, ctx->start->getLine());
        put_node_type(ctx, T_ERROR);
    }

    if (get_node_type(ctx->children[2]) != T_INT)
    {
        size_t line = ctx->start->getLine();
        std::string msg = "'" + ctx->children[2]->getText() + "' is not an integer";
        print_error(msg, ctx->start->getLine());
        put_node_type(ctx, T_ERROR);
    }

    if (get_node_type(ctx) != T_ERROR)
    {
        put_node_type(ctx, T_BOOL);
    }

    // intermediate code generation
    this->gen_code_expr(ctx);
}

void SymbolTableListener::enterExpr_cond_and(DecafParser::Expr_cond_andContext *ctx)
{
    NodeAttrs *parent_attrs = this->get_node_attrs(ctx->parent);
    NodeAttrs *attrs = this->get_node_attrs(ctx);
    NodeAttrs *e0 = new NodeAttrs();
    NodeAttrs *e1 = new NodeAttrs();

    // e0.true = expr.true
    e0->l_true = this->new_label();
    // e0.false = newlabel()
    e0->l_false = attrs->l_false;
    // e1.true = expr.true
    e1->l_true = attrs->l_true;
    // e1.false = expr.false
    e1->l_false = attrs->l_false;

    // this->put_node_attrs(ctx, attrs);
    this->put_node_attrs(ctx->children[0], e0);
    this->put_node_attrs(ctx->children[2], e1);
}
void SymbolTableListener::exitExpr_cond_and(DecafParser::Expr_cond_andContext *ctx)
{
    std::vector<DecafParser::ExpressionContext *> exprs = ctx->expression();

    int left_type = get_node_type(exprs[0]);
    if (exprs[0]->children.size() == 1)
        left_type = get_node_type(exprs[0]->children[0]);

    int right_type = get_node_type(exprs[1]);
    if (exprs[1]->children.size() == 1)
        right_type = get_node_type(exprs[1]->children[0]);

    if (left_type != T_BOOL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = exprs[0]->getText() + " must be of type 'BOOL', '";
        msg += DataTypes::get_instance()->get_type(left_type) + "' found.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    if (right_type != T_BOOL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = exprs[1]->getText() + " must be of type 'BOOL', '";
        msg += DataTypes::get_instance()->get_type(right_type) + "' found.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    put_node_type(ctx, T_BOOL);

    // icg
    // TODO resolve when to generate j code and when not
    NodeAttrs *attrs = this->get_node_attrs(ctx);
    NodeAttrs *e0 = this->get_node_attrs(ctx->children[0]);
    NodeAttrs *e1 = this->get_node_attrs(ctx->children[2]);

    for (IcgInstr *c : e0->l_code)
        attrs->l_code.push_back(c);
    for (IcgInstr *c : e0->lj_code)
        attrs->l_code.push_back(c);

    attrs->l_code.push_back(new IcgInstr(OP_LBL, "", "", e0->l_true));

    for (IcgInstr *c : e1->l_code)
        attrs->l_code.push_back(c);
    for (IcgInstr *c : e1->lj_code)
        attrs->l_code.push_back(c);
}
void SymbolTableListener::enterExpr_cond_or(DecafParser::Expr_cond_orContext *ctx)
{
    NodeAttrs *parent_attrs = this->get_node_attrs(ctx->parent);
    NodeAttrs *attrs = this->get_node_attrs(ctx);
    NodeAttrs *e0 = new NodeAttrs();
    NodeAttrs *e1 = new NodeAttrs();

    if (attrs == NULL)
    {
        std::cout << "attrs NULL" << std::endl;
    }

    // e0.true = expr.true
    e0->l_true = attrs->l_true;
    // e0.false = newlabel()
    e0->l_false = this->new_label();
    // e1.true = expr.true
    e1->l_true = attrs->l_true;
    // e1.false = expr.false
    e1->l_false = attrs->l_false;

    // this->put_node_attrs(ctx, attrs);
    this->put_node_attrs(ctx->children[0], e0);
    this->put_node_attrs(ctx->children[2], e1);
}
void SymbolTableListener::exitExpr_cond_or(DecafParser::Expr_cond_orContext *ctx)
{
    std::vector<DecafParser::ExpressionContext *> exprs = ctx->expression();

    int left_type = get_node_type(exprs[0]);
    if (exprs[0]->children.size() == 1)
        left_type = get_node_type(exprs[0]->children[0]);

    int right_type = get_node_type(exprs[1]);
    if (exprs[1]->children.size() == 1)
        right_type = get_node_type(exprs[1]->children[0]);

    if (left_type != T_BOOL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = exprs[0]->getText() + " must be of type 'BOOL', '";
        msg += DataTypes::get_instance()->get_type(left_type) + "' found.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    if (right_type != T_BOOL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = exprs[1]->getText() + " must be of type 'BOOL', '";
        msg += DataTypes::get_instance()->get_type(right_type) + "' found.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    put_node_type(ctx, T_BOOL);

    // icg
    // TODO resolve when to generate j code and when not
    // TODO remove code repetition
    NodeAttrs *attrs = this->get_node_attrs(ctx);
    NodeAttrs *e0 = this->get_node_attrs(ctx->children[0]);
    NodeAttrs *e1 = this->get_node_attrs(ctx->children[2]);

    for (IcgInstr *c : e0->l_code)
        attrs->l_code.push_back(c);
    for (IcgInstr *c : e0->lj_code)
        attrs->l_code.push_back(c);

    attrs->l_code.push_back(new IcgInstr(OP_LBL, "", "", e0->l_false));

    for (IcgInstr *c : e1->l_code)
        attrs->l_code.push_back(c);
    for (IcgInstr *c : e1->lj_code)
        attrs->l_code.push_back(c);
}

/**
 * not_op expression
 * 
 * not_op = { '!' }
 * 
 * expression must be of type bool.
 */
void SymbolTableListener::exitExpr_not(DecafParser::Expr_notContext *ctx)
{
    DecafParser::ExpressionContext *expr = ctx->expression();

    int expr_type = get_node_type(expr);
    if (expr->children.size() == 1)
        expr_type = get_node_type(expr->children[0]);

    if (expr_type != T_BOOL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = expr->getText() + " must be of type 'BOOL', '";
        msg += DataTypes::get_instance()->get_type(expr_type) + "' found.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    put_node_type(ctx, T_BOOL);

    // intermediate code generation
    NodeAttrs *attrs = this->get_node_attrs(ctx);
    if (attrs == NULL)
    {
        attrs = new NodeAttrs();
        this->put_node_attrs(ctx, attrs);
    }
    attrs->addr = this->new_temp();

    // e.addr = e0.addr OP e1.addr
    NodeAttrs *n0 = this->get_node_attrs(ctx->expression());
    if (ctx->expression()->children.size() == 1)
        n0 = this->get_node_attrs(ctx->expression()->children[0]);

    std::string expr_0 = n0->value != "" ? n0->value : n0->addr;
}

/**
 *
 */
void SymbolTableListener::enterExpr_eq(DecafParser::Expr_eqContext *ctx)
{
}

/**
 * expression eq_op expression
 * 
 * eq_op = { '==', '!=' }
 * 
 * Both expression must be of the same type;
 */
void SymbolTableListener::exitExpr_eq(DecafParser::Expr_eqContext *ctx)
{
    std::vector<DecafParser::ExpressionContext *> exprs = ctx->expression();

    int left_type = get_node_type(exprs[0]);
    if (exprs[0]->children.size() == 1)
        left_type = get_node_type(exprs[0]->children[0]);

    int right_type = get_node_type(exprs[1]);
    if (exprs[1]->children.size() == 1)
        right_type = get_node_type(exprs[1]->children[0]);

    if (left_type != right_type)
    {
        put_node_type(ctx, T_ERROR);
        std::string msg = ctx->eq_op()->getText() + "' operator must be applied to operands of the same type.";
        msg += " Left operand has type '" + DataTypes::get_instance()->get_type(left_type);
        msg += "', right operand has type '" + DataTypes::get_instance()->get_type(right_type) + "'";
        print_error(msg, ctx->start->getLine());

        return;
    }

    put_node_type(ctx, T_BOOL);

    // intermediate code generation
    this->gen_code_expr(ctx);
}

void SymbolTableListener::exitExpr_method_call(DecafParser::Expr_method_callContext *ctx)
{
    SymbolTableEntry *e = this->table->get(ctx->methodCall()->ID()->getText());

    // method not declared
    if (e == NULL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "method '" + ctx->methodCall()->ID()->getText() + "' not declared.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    if (e->data_type == T_VOID)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "method '" + ctx->methodCall()->ID()->getText() + "' has return type of 'void',";
        msg += " not allowed in an expression.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // icg
    NodeAttrs *child_attrs = this->get_node_attrs(ctx->methodCall());
    this->put_node_attrs(ctx, child_attrs);
}

/**
 * Has the form '-' expression
 * 
 * Must validate that expression is of type integer.
 */
void SymbolTableListener::exitExpr_neg(DecafParser::Expr_negContext *ctx)
{

    // get type of expression
    DecafParser::ExpressionContext *expr = ctx->expression();
    int expr_type = get_node_type(expr);
    if (expr->children.size() == 1)
        expr_type = get_node_type(expr->children[0]);

    if (expr_type != T_INT)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = expr->getText() + " is not of type integer.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // save this node type
    put_node_type(ctx, T_INT);

    // icg
    NodeAttrs *attrs = new NodeAttrs();
    // e.addr = new Temp()
    std::string addr = this->new_temp();
    // e.addr = '-' e1.addr
    NodeAttrs *expr_e = get_node_attrs(expr);
    if (expr->children.size() == 1)
        expr_e = get_node_attrs(expr->children[0]);

    attrs->addr = addr;
    this->put_node_attrs(ctx, attrs);
}

/**
 * Has the form '(' expression ')'
 * 
 * Must set the type of this node to the type of the inner expression.
 */
void SymbolTableListener::exitExpr_par(DecafParser::Expr_parContext *ctx)
{
    // get type of expression
    DecafParser::ExpressionContext *expr = ctx->expression();
    int expr_type = get_node_type(expr);
    if (expr->children.size() == 1)
        expr_type = get_node_type(expr->children[0]);
    put_node_type(ctx, expr_type);

    // icg
    NodeAttrs *child_attrs = this->get_node_attrs(ctx->expression());
    this->put_node_attrs(ctx, child_attrs);
}

void SymbolTableListener::enterExpr_loc(DecafParser::Expr_locContext *ctx)
{
    NodeAttrs *attrs = this->get_node_attrs(ctx);
    // if some ancestor created the attributes, pass them down
    if (attrs != NULL)
    {
        NodeAttrs *child_attrs = new NodeAttrs();
        child_attrs->l_true = attrs->l_true;
        child_attrs->l_false = attrs->l_false;
        child_attrs->l_next = attrs->l_next;
        this->put_node_attrs(ctx->children[0], child_attrs);
    }
}

void SymbolTableListener::exitExpr_loc(DecafParser::Expr_locContext *ctx)
{
    // this node attributes
    NodeAttrs *attrs = this->get_node_attrs(ctx);
    if (attrs == NULL)
    {
        attrs = new NodeAttrs();
        this->put_node_attrs(ctx, attrs);
    }

    int node_type = this->get_node_type(ctx->children[0]);
    NodeAttrs *a = this->get_node_attrs(ctx->children[0]);

    // if this location is boolean, we generate its jumping code because some
    // ancestor node might use it
    if (node_type == T_BOOL)
    {
        std::string new_temp = this->new_temp();
        a->lj_code.push_back(new IcgInstr(OP_EQ, a->addr, "1", new_temp));
        a->lj_code.push_back(new IcgInstr(OP_IF, new_temp, "", attrs->l_true));
        a->lj_code.push_back(new IcgInstr(OP_GOTO, "", "", attrs->l_false));
    }

    // E.addr = loc.addr
    attrs->entry = a->entry;
    attrs->addr = a->addr;
    attrs->l_code.insert(attrs->l_code.begin(), a->l_code.begin(), a->l_code.end());
}

/// ----------------------------------------------------------------------------------------------------

/// ---------------------------------------- Literals ----------------------------------------
void SymbolTableListener::enterLiteral(DecafParser::LiteralContext *ctx)
{
}

/// Set this literal node type to its children type
void SymbolTableListener::exitLiteral(DecafParser::LiteralContext *ctx)
{
    put_node_type(ctx, get_node_type(ctx->children[0]));

    NodeAttrs *child = this->get_node_attrs(ctx->children[0]);

    NodeAttrs *attrs = new NodeAttrs();
    attrs->value = child->value;
    attrs->addr = child->value;
    this->put_node_attrs(ctx, attrs);
    this->put_node_attrs(ctx->parent, attrs);
}

void SymbolTableListener::enterInt_literal(DecafParser::Int_literalContext *ctx)
{
}

void SymbolTableListener::exitInt_literal(DecafParser::Int_literalContext *ctx)
{
    this->put_node_type(ctx, T_INT);

    NodeAttrs *attrs = new NodeAttrs();
    attrs->value = ctx->NUM()->getText();
    this->put_node_attrs(ctx, attrs);
}

void SymbolTableListener::enterChar_literal(DecafParser::Char_literalContext *ctx)
{
}

void SymbolTableListener::exitChar_literal(DecafParser::Char_literalContext *ctx)
{
    put_node_type(ctx, T_CHAR);

    // icg
    NodeAttrs *attrs = new NodeAttrs();
    attrs->value = ctx->CHAR()->getText();
    this->put_node_attrs(ctx, attrs);
}

void SymbolTableListener::enterBool_literal(DecafParser::Bool_literalContext *ctx)
{
}

void SymbolTableListener::exitBool_literal(DecafParser::Bool_literalContext *ctx)
{
    for (auto c : ctx->children)
    {
        put_node_type(c, T_BOOL);
    }

    put_node_type(ctx, T_BOOL);

    // icg
    NodeAttrs *attrs = new NodeAttrs();
    attrs->value = ctx->TRUE() != NULL ? "1" : "0";
    this->put_node_attrs(ctx, attrs);
}
/// ---------------------------------------- Finish Literals ----------------------------------------

/// ---------------------------------------- Statements ----------------------------------------
void SymbolTableListener::enterSt_assignment(DecafParser::St_assignmentContext *ctx)
{
    antlr4::tree::ParseTree *expr = ctx->expression();
    if (DecafParser::Expr_relContext *d = dynamic_cast<DecafParser::Expr_relContext *>(expr))
    {
        NodeAttrs *attrs = new NodeAttrs();
        this->put_node_attrs(expr, attrs);
    }
}

void SymbolTableListener::exitSt_assignment(DecafParser::St_assignmentContext *ctx)
{
    DecafParser::LocationContext *loc = ctx->location();
    DecafParser::ExpressionContext *expr = ctx->expression();

    int loc_type = get_node_type(loc);

    int expr_type = get_node_type(expr);
    if (expr->children.size() == 1)
        expr_type = get_node_type(expr->children[0]);

    if (loc_type != expr_type)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "expression: '" + expr->getText();
        msg += "' of type '" + DataTypes::get_instance()->get_type(expr_type) + "'";
        msg += " is incompatible with type: '" + DataTypes::get_instance()->get_type(loc_type) + "'";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // save node type
    put_node_type(ctx, T_VOID);

    // intermediate code generation
    NodeAttrs *assign_attrs = new NodeAttrs();
    NodeAttrs *loc_attrs = this->get_node_attrs(loc);
    NodeAttrs *expr_attrs = this->get_node_attrs(expr);

    for (IcgInstr *c : loc_attrs->l_code)
        assign_attrs->l_code.push_back(c);
    for (IcgInstr *c : expr_attrs->l_code)
        assign_attrs->l_code.push_back(c);

    assign_attrs->l_code.push_back(new IcgInstr(OP_ASGN, expr_attrs->addr, "", loc_attrs->addr));
    assign_attrs->addr = loc_attrs->addr;

    this->put_node_attrs(ctx, assign_attrs);
}

/**
 * if (expression) block else block
 */
void SymbolTableListener::enterSt_if(DecafParser::St_ifContext *ctx)
{
    // S
    NodeAttrs *attrs = new NodeAttrs();
    attrs->l_next = this->new_label();
    this->put_node_attrs(ctx, attrs);

    // expr
    NodeAttrs *expr_attrs = new NodeAttrs();
    // expr.true = newlabel()
    expr_attrs->l_true = this->new_label();
    // expr.false = s.next
    expr_attrs->l_false = attrs->l_next;
    this->put_node_attrs(ctx->expression(), expr_attrs);

    // block1
    NodeAttrs *if_block_attrs = new NodeAttrs();
    // s1.next = s.next
    if_block_attrs->l_next = attrs->l_next;
    this->put_node_attrs(ctx->block()[0], if_block_attrs);

    // if an else block exists
    if (ctx->block().size() > 1)
    {
        // expr.false = newlabel()
        expr_attrs->l_false = this->new_label();

        NodeAttrs *else_block_attrs = new NodeAttrs();
        // s2.next = s.next
        else_block_attrs->l_next = attrs->l_next;
        this->put_node_attrs(ctx->block()[1], else_block_attrs);
    }
}

/**
 * if '(' expression ')' block ('else' block)?
 * 
 * expression must be of type BOOL.
 */
void SymbolTableListener::exitSt_if(DecafParser::St_ifContext *ctx)
{
    DecafParser::ExpressionContext *expr = ctx->expression();

    int expr_type = get_node_type(expr);
    if (expr->children.size() == 1)
        expr_type = get_node_type(expr->children[0]);

    if (expr_type != T_BOOL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "if expression must be of type 'BOOL', '";
        msg += DataTypes::get_instance()->get_type(expr_type) + "' found.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // TODO: node has type VOID
    put_node_type(ctx, T_VOID);

    // icg
    NodeAttrs *attrs = this->get_node_attrs(ctx);
    NodeAttrs *expr_attrs = this->get_node_attrs(expr);
    NodeAttrs *if_block_attrs = this->get_node_attrs(ctx->block()[0]);

    for (IcgInstr *c : expr_attrs->l_code)
        attrs->l_code.push_back(c);
    for (IcgInstr *c : expr_attrs->lj_code)
        attrs->l_code.push_back(c);

    // label(expr.true)
    if (expr_attrs->value != "")
    {
        if (expr_attrs->value == "1")
        {
            // s1.code
            for (IcgInstr *c : if_block_attrs->l_code)
                attrs->l_code.push_back(c);
        }
        else
        {
            NodeAttrs *else_block_attrs = this->get_node_attrs(ctx->block()[1]);
            if (else_block_attrs != NULL)
                for (IcgInstr *c : else_block_attrs->l_code)
                    attrs->l_code.push_back(c);
        }
    }
    else
    {
        IcgInstr *i0 = new IcgInstr();
        i0->op_code = OP_LBL;
        i0->res = expr_attrs->l_true;
        attrs->l_code.push_back(i0);

        // s1.code
        for (IcgInstr *c : if_block_attrs->l_code)
            attrs->l_code.push_back(c);
        // attrs->l_code.push_back(new IcgInstr(OP_EBL, "", "", ""));

        // if an else block exists
        if (ctx->block().size() > 1)
        {
            NodeAttrs *else_block_attrs = this->get_node_attrs(ctx->block()[1]);

            IcgInstr *i1 = new IcgInstr();
            i1->op_code = OP_GOTO;
            i1->res = attrs->l_next;
            attrs->l_code.push_back(i1);

            IcgInstr *i2 = new IcgInstr();
            i2->op_code = OP_LBL;
            i2->res = expr_attrs->l_false;
            attrs->l_code.push_back(i2);

            for (IcgInstr *c : else_block_attrs->l_code)
                attrs->l_code.push_back(c);
            // attrs->l_code.push_back(new IcgInstr(OP_EBL, "", "", ""));
        }

        // s.next
        attrs->l_code.push_back(new IcgInstr(OP_LBL, "", "", attrs->l_next));
    }
}

void SymbolTableListener::enterSt_while(DecafParser::St_whileContext *ctx)
{
    NodeAttrs *s_attrs = new NodeAttrs();
    NodeAttrs *expr_attrs = new NodeAttrs();
    NodeAttrs *block_attrs = new NodeAttrs();

    // S.next = newlabel()
    s_attrs->l_next = this->new_label();
    // begin = newlabel()
    s_attrs->l_begin = this->new_label();

    // expr.true = newlabel()
    expr_attrs->l_true = this->new_label();
    // expr.false = S.next
    expr_attrs->l_false = s_attrs->l_next;

    // block.next = begin
    block_attrs->l_next = s_attrs->l_begin;

    this->put_node_attrs(ctx, s_attrs);
    this->put_node_attrs(ctx->expression(), expr_attrs);
    this->put_node_attrs(ctx->block(), block_attrs);
}

void SymbolTableListener::exitSt_while(DecafParser::St_whileContext *ctx)
{
    DecafParser::ExpressionContext *expr = ctx->expression();

    int expr_type = get_node_type(expr);
    if (expr->children.size() == 1)
        expr_type = get_node_type(expr->children[0]);

    if (expr_type != T_BOOL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "if expression must be of type 'BOOL', '";
        msg += DataTypes::get_instance()->get_type(expr_type) + "' found.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    put_node_type(ctx, T_VOID);

    // icg

    NodeAttrs *s_attrs = this->get_node_attrs(ctx);
    NodeAttrs *expr_attrs = this->get_node_attrs(ctx->expression());
    NodeAttrs *block_attrs = this->get_node_attrs(ctx->block());

    // if there is a dumb while(false) statement
    if (expr_attrs->value == "0")
        return;

    // generate the begin label
    s_attrs->l_code.push_back(new IcgInstr(OP_LBL, "", "", s_attrs->l_begin));

    // in the case of while (expr) we do generate jumping code
    // we dont if the case is while(true)
    if (expr_attrs->value != "1")
    {
        for (IcgInstr *c : expr_attrs->l_code)
            s_attrs->l_code.push_back(c);
        for (IcgInstr *c : expr_attrs->lj_code)
            s_attrs->l_code.push_back(c);
        s_attrs->l_code.push_back(new IcgInstr(OP_LBL, "", "", expr_attrs->l_true));
    }

    // s_attrs->l_code.push_back(new IcgInstr(OP_LBL, "", "", s_attrs->l_begin));
    // for (IcgInstr *c : expr_attrs->l_code)
    //     s_attrs->l_code.push_back(c);
    // for (IcgInstr *c : expr_attrs->lj_code)
    //     s_attrs->l_code.push_back(c);
    // s_attrs->l_code.push_back(new IcgInstr(OP_LBL, "", "", expr_attrs->l_true));
    for (IcgInstr *c : block_attrs->l_code)
        s_attrs->l_code.push_back(c);
    s_attrs->l_code.push_back(new IcgInstr(OP_GOTO, "", "", s_attrs->l_begin));
    s_attrs->l_code.push_back(new IcgInstr(OP_LBL, "", "", s_attrs->l_next));
}

void SymbolTableListener::exitSt_return(DecafParser::St_returnContext *ctx)
{

    int return_type = 0;

    // no expression for return, implicit VOID
    if (ctx->expression() == NULL)
        return_type = T_VOID;
    else
    {
        return_type = get_node_type(ctx->expression());
        if (ctx->expression()->children.size() == 1)
            return_type = get_node_type(ctx->expression()->children[0]);
    }

    // try to get method
    std::string method_name = "";
    antlr4::tree::ParseTree *node = ctx->parent;
    while (node != NULL)
    {
        if (DecafParser::MethodDeclarationContext *d = dynamic_cast<DecafParser::MethodDeclarationContext *>(node))
            method_name = d->ID()->getText();

        node = node->parent;
    }

    // method was not found
    if (method_name == "")
    {
        this->put_node_type(ctx, T_ERROR);
        return;
    }

    // get symbol table entry for method
    SymbolTableEntry *entry = this->table->get(method_name);
    if (entry == NULL)
    {
        this->put_node_type(ctx, T_ERROR);

        return;
    }

    // main method must be void
    if (entry->id == "main" && return_type != T_VOID)
    {
        this->put_node_type(ctx, T_ERROR);

        std::string msg = "expression return type '";
        msg += DataTypes::get_instance()->get_type(return_type);
        msg += "' is not valid for the 'main' method.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // compare expression return type with method return type
    if (entry->data_type != return_type)
    {
        this->put_node_type(ctx, T_ERROR);

        std::string msg = "return expression";
        if (ctx->expression() != NULL)
            msg += " '" + ctx->expression()->getText() + "'";
        msg += "with type '" + DataTypes::get_instance()->get_type(return_type) + "' ";
        msg += "differs from method return type '" + DataTypes::get_instance()->get_type(entry->data_type);
        msg += "'.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    this->put_node_type(ctx, return_type);

    // icg
    if (return_type != T_VOID)
    {
        NodeAttrs *ret_expr_attrs = this->get_node_attrs(ctx->expression());
        NodeAttrs *attrs = new NodeAttrs();

        // return code
        for (IcgInstr *c : ret_expr_attrs->l_code)
            attrs->l_code.push_back(c);
        attrs->l_code.push_back(new IcgInstr(OP_RET, ret_expr_attrs->addr, "", ""));
        // attrs->l_code.push_back(new IcgInstr(OP_GOTO, "", "", "next"));

        this->put_node_attrs(ctx, attrs);
    }
}

void SymbolTableListener::exitSt_method_call(DecafParser::St_method_callContext *ctx)
{
    std::cout << "exitSt_method_call" << std::endl;
    NodeAttrs *child_attrs = this->get_node_attrs(ctx->methodCall());
    this->put_node_attrs(ctx, child_attrs);
}

/// --------------------------------------------------------------------------------------------

// ---------------------------------------- Private auxiliary methods ----------------------------------------
// Node Type association
void SymbolTableListener::put_node_type(antlr4::tree::ParseTree *node, int type)
{
    this->node_types.put(node, type);
}

int SymbolTableListener::get_node_type(antlr4::tree::ParseTree *node)
{
    return this->node_types.get(node);
}

// Auxiliary methods.
void SymbolTableListener::push_table()
{
    // push a new table
    SymbolTable *new_top =
        new SymbolTable(this->table, "table_" + std::to_string(this->num_tables++));
    this->table = new_top;
}

SymbolTable *SymbolTableListener::pop_table()
{
    // pop the top table
    SymbolTable *old = this->table;
    this->table = this->table->get_parent();

    return old;
}

void SymbolTableListener::process_arith_expr(DecafParser::ExpressionContext *ctx)
{
    // set child types
    int left_type = get_node_type(ctx->children[0]);
    if (ctx->children[0]->children.size() == 1)
        left_type = get_node_type(ctx->children[0]->children[0]);
    int right_type = get_node_type(ctx->children[2]);
    if (ctx->children[2]->children.size() == 1)
        right_type = get_node_type(ctx->children[2]->children[0]);

    // set child types
    put_node_type(ctx->children[0], left_type);
    put_node_type(ctx->children[2], right_type);

    if (left_type != T_INT)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "'" + ctx->children[0]->getText() + "' is not an integer";
        print_error(msg, ctx->start->getLine());

        return;
    }

    if (right_type != T_INT)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "'" + ctx->children[2]->getText() + "' is not an integer";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // save this node type
    put_node_type(ctx, T_INT);
}

void SymbolTableListener::push_struct_table(SymbolTable *table)
{
    this->struct_tables.push(table);
}

SymbolTable *SymbolTableListener::pop_struct_table()
{
    if (this->struct_tables.size())
    {
        SymbolTable *top = this->struct_tables.top();
        this->struct_tables.pop();

        return top;
    }

    return NULL;
}

void SymbolTableListener::put_node_attrs(
    antlr4::tree::ParseTree *node,
    NodeAttrs *attrs)
{
    this->node_attrs.put(node, attrs);
}

NodeAttrs *SymbolTableListener::get_node_attrs(antlr4::tree::ParseTree *node)
{
    NodeAttrs *attrs = this->node_attrs.get(node);

    return attrs;
}

void SymbolTableListener::emit(std::string code)
{
    this->vec_code.push_back(code);
}

std::string SymbolTableListener::new_temp()
{
    return "t" + std::to_string(++this->temp_count);
}

std::string SymbolTableListener::new_label()
{
    return "l_" + std::to_string(++this->label_count);
}

std::string SymbolTableListener::new_method_label(std::string extra)
{
    return "_" + extra + "_";
}

void SymbolTableListener::print_error(std::string msg, size_t line_num)
{
    std::cout << "[ERROR](in line "
              << std::to_string(line_num) << ") => "
              << msg
              << std::endl;
}

// common intermmediate code
void SymbolTableListener::gen_code_expr(DecafParser::ExpressionContext *ctx)
{
    // intermediate code generation
    // e.addr = new Temp()
    NodeAttrs *attrs = this->get_node_attrs(ctx);
    if (attrs == NULL)
    {
        attrs = new NodeAttrs();
        this->put_node_attrs(ctx, attrs);
    }
    attrs->addr = this->new_temp();

    // e.addr = e0.addr OP e1.addr
    NodeAttrs *n0 = this->get_node_attrs(ctx->children[0]);
    if (ctx->children[0]->children.size() == 1)
        n0 = this->get_node_attrs(ctx->children[0]->children[0]);
    NodeAttrs *n1 = this->get_node_attrs(ctx->children[2]);
    if (ctx->children[2]->children.size() == 1)
        n1 = this->get_node_attrs(ctx->children[2]->children[0]);

    std::string expr_0 = n0->value != "" ? n0->value : n0->addr;
    std::string expr_1 = n1->value != "" ? n1->value : n1->addr;

    // save operator
    attrs->op = ctx->children[1]->getText();

    // acc code
    for (auto c : n0->l_code)
        attrs->l_code.push_back(c);
    for (auto c : n1->l_code)
        attrs->l_code.push_back(c);

    // expression code
    // IcgInstr *i0 = new IcgInstr();
    // i0->op_code = IcgInstr::op_to_int(attrs->op);
    // i0->a0 = expr_0;
    // i0->a1 = expr_1;
    // i0->res = attrs->addr;

    attrs->l_code.push_back(new IcgInstr(IcgInstr::op_to_int(attrs->op), expr_0, expr_1, attrs->addr));
    attrs->lj_code.push_back(new IcgInstr(OP_IF, attrs->addr, "", attrs->l_true));
    attrs->lj_code.push_back(new IcgInstr(OP_GOTO, "", "", attrs->l_false));

    // jumping code
    // IcgInstr *i1 = new IcgInstr();
    // i1->op_code = OP_IF;
    // i1->a0 = attrs->addr;
    // i1->res = attrs->l_true;
    // IcgInstr *i2 = new IcgInstr();
    // i2->op_code = OP_GOTO;
    // i2->res = attrs->l_false;

    // attrs->l_code.push_back(i0);
    // attrs->lj_code.push_back(i1);
    // attrs->lj_code.push_back(i2);
}
