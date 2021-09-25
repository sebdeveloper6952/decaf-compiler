#include <iostream>
#include "SymbolTableListener.h"
#include "SymbolTable.h"
#include "DataTypes.h"

SymbolTableListener::SymbolTableListener(SymbolTable *table)
{
    this->table = table;
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

    std::cout << "\n[INFO] program is valid ✅" << std::endl;
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
    // top->print_table();
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
        // e.addr = base[offset]
        std::string addr = e->is_global ? "g" : "l";
        addr += "[" + std::to_string(e->offset) + "]";
        put_node_attrs(ctx, e, addr, "");
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
}

/// -----------------------------------------------------------------------------------------------------

/// ---------------------------------------- Expressions ----------------------------------------
void SymbolTableListener::enterExpr_arith_0(DecafParser::Expr_arith_0Context *ctx)
{
}

void SymbolTableListener::exitExpr_arith_0(DecafParser::Expr_arith_0Context *ctx)
{
    process_arith_expr(ctx);

    // intermediate code generation
    // e.addr = new Temp()
    std::string temp = "t" + std::to_string(++this->temp_count);
    put_node_attrs(ctx, NULL, temp, "");

    // e.addr = e0.addr OP e1.addr
    auto n0 = get_node_attrs(ctx->children[0]);
    if (ctx->children[0]->children.size() == 1)
        n0 = get_node_attrs(ctx->children[0]->children[0]);
    auto n1 = get_node_attrs(ctx->children[2]);
    if (ctx->children[2]->children.size() == 1)
        n1 = get_node_attrs(ctx->children[2]->children[0]);

    std::cout << temp << "=" << n0->addr << ctx->children[1]->getText() << n1->addr << std::endl;
}

void SymbolTableListener::enterExpr_arith_1(DecafParser::Expr_arith_1Context *ctx)
{
}

void SymbolTableListener::exitExpr_arith_1(DecafParser::Expr_arith_1Context *ctx)
{
    process_arith_expr(ctx);

    // intermediate code generation
    // e.addr = new Temp()
    std::string temp = "t" + std::to_string(++this->temp_count);
    put_node_attrs(ctx, NULL, temp, "");

    // e.addr = e0.addr OP e1.addr
    NodeAttrs *n0 = get_node_attrs(ctx->children[0]);
    if (ctx->children[0]->children.size() == 1)
        n0 = get_node_attrs(ctx->children[0]->children[0]);
    NodeAttrs *n1 = get_node_attrs(ctx->children[2]);
    if (ctx->children[2]->children.size() == 1)
        n1 = get_node_attrs(ctx->children[2]->children[0]);

    std::cout << temp << "=" << n0->addr << ctx->children[1]->getText() << n1->addr << std::endl;
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
}

void SymbolTableListener::enterExpr_cond(DecafParser::Expr_condContext *ctx)
{
}

/**
 * expression cond_op expression
 * 
 * Both expression must be of type bool.
 */
void SymbolTableListener::exitExpr_cond(DecafParser::Expr_condContext *ctx)
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
    }
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
    // e.addr = new Temp()
    std::string addr = "t" + std::to_string(++this->temp_count);
    // e.addr = '-' e1.addr
    NodeAttrs *expr_e = get_node_attrs(expr);
    if (expr->children.size() == 1)
        expr_e = get_node_attrs(expr->children[0]);
    std::cout << addr << "=-" << expr_e->addr << std::endl;
    std::cout << "here1" << std::endl;
    put_node_attrs(ctx, NULL, addr, "");
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
}

void SymbolTableListener::enterInt_literal(DecafParser::Int_literalContext *ctx)
{
}

void SymbolTableListener::exitInt_literal(DecafParser::Int_literalContext *ctx)
{
    put_node_type(ctx, T_INT);
}

void SymbolTableListener::enterChar_literal(DecafParser::Char_literalContext *ctx)
{
}

void SymbolTableListener::exitChar_literal(DecafParser::Char_literalContext *ctx)
{
    put_node_type(ctx, T_CHAR);
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
}
/// ---------------------------------------- Finish Literals ----------------------------------------

/// ---------------------------------------- Statements ----------------------------------------
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
    // emit(top.get(location.id) '=' e1.addr)
    NodeAttrs *loc_e = get_node_attrs(loc);
    NodeAttrs *expr_e = get_node_attrs(expr);
    std::cout << loc_e->addr << "=" << expr_e->addr << std::endl;
}

void SymbolTableListener::enterSt_if(DecafParser::St_ifContext *ctx)
{
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
}

void SymbolTableListener::enterSt_while(DecafParser::St_whileContext *ctx)
{
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
        put_node_type(ctx, T_ERROR);
        return;
    }

    // get symbol table entry for method
    SymbolTableEntry *entry = this->table->get(method_name);
    if (entry == NULL)
    {
        put_node_type(ctx, T_ERROR);

        return;
    }

    // main method must be void
    if (entry->id == "main" && return_type != T_VOID)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "expression return type '";
        msg += DataTypes::get_instance()->get_type(return_type);
        msg += "' is not valid for the 'main' method.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // compare expression return type with method return type
    if (entry->data_type != return_type)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "return expression";
        if (ctx->expression() != NULL)
            msg += " '" + ctx->expression()->getText() + "'";
        msg += "with type '" + DataTypes::get_instance()->get_type(return_type) + "' ";
        msg += "differs from method return type '" + DataTypes::get_instance()->get_type(entry->data_type);
        msg += "'.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    put_node_type(ctx, return_type);
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
    SymbolTableEntry *entry,
    std::string addr,
    std::string code)
{

    NodeAttrs *attrs = new NodeAttrs(entry, addr, code);
    this->node_attrs.put(node, attrs);
}

NodeAttrs *SymbolTableListener::get_node_attrs(antlr4::tree::ParseTree *node)
{
    NodeAttrs *attrs = this->node_attrs.get(node);

    return attrs;
}

void SymbolTableListener::print_error(std::string msg, size_t line_num)
{
    std::cout << "[ERROR](in line "
              << std::to_string(line_num) << ") => "
              << msg
              << std::endl;
}