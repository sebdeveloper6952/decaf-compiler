#include <iostream>

#include "SymbolTableListener.h"
#include "SymbolTable.h"
#include "SymbolTableListener.h"
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
            "Source program must include a valid 'main' function declaration.",
            ctx->start->getLine());
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
            std::cout << "put() params: ";
            for (DecafParser::ParameterContext *p : params)
            {
                this->table->put(
                    O_DATA,
                    p->ID()->getText(),
                    p->parameterType()->getText());
            }
            std::cout << std::endl;
        }
    }
}

// exit the current block
void SymbolTableListener::exitBlock(DecafParser::BlockContext *ctx)
{
    this->pop_table();
}

/// ---------------------------------------- Var Declarations ----------------------------------------
void SymbolTableListener::enterVar_decl(DecafParser::Var_declContext *ctx)
{
    DecafParser::VarTypeContext *var_type = ctx->varType();
    antlr4::tree::TerminalNode *id = ctx->ID();

    if (!this->table->put(O_DATA, id->getText(), var_type->getText()))
    {
        std::cout << "error: varDeclaration id ("
                  << id->getText()
                  << ") is already declared."
                  << std::endl;

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
    DecafParser::VarTypeContext *var_type = ctx->varType();
    antlr4::tree::TerminalNode *id = ctx->ID();
    antlr4::tree::TerminalNode *array_size = ctx->NUM();

    if (std::stoi(array_size->getText()) < 1)
    {
        put_node_type(ctx, T_ERROR);
        std::string msg = "";
        msg += array_size->getText();
        msg += " is an invalid integer for array size.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    size_t size = std::stoi(array_size->getText());
    if (!this->table->put(O_ARRAY, id->getText(), var_type->getText(), size))
    {
        std::string msg = "varDeclaration id (" + id->getText() + ") is already declared.";
        print_error(msg, ctx->start->getLine());

        return;
    }
}

void SymbolTableListener::enterVar_struct_decl(DecafParser::Var_struct_declContext *ctx)
{
    std::cout << std::endl
              << "enterVar_struct_decl" << std::endl;

    std::vector<antlr4::tree::TerminalNode *> ids = ctx->ID();
    std::string struct_type = ids[0]->getText();
    std::string struct_id = ids[1]->getText();

    // get struct type from symbol table
    std::cout << "\tget table for struct: " << struct_type << std::endl;
    SymbolTable *struct_table = this->table->get_struct_table(struct_type);

    // check for struct type validity
    if (struct_table == NULL)
    {
        put_node_type(ctx, T_ERROR);
        std::cout << "\ttable for struct: '" << struct_type << "' not found." << std::endl;

        return;
    }

    // save new variable of type struct
    this->table->put(
        O_STRUCT_I,
        struct_id,
        struct_type,
        0);
}

void SymbolTableListener::exitVar_struct_decl(DecafParser::Var_struct_declContext *ctx)
{
    std::cout
        << "exitVar_struct_decl" << std::endl;
}

/// ---------------------------------------- Struct Declaration -----------------------------------
void SymbolTableListener::enterStructDeclaration(DecafParser::StructDeclarationContext *ctx)
{
    std::cout << std::endl
              << "enterStructDeclaration: " << ctx->getText() << std::endl;
    std::cout << "\tinsert this struct type into the custom types table." << std::endl;

    // new symbol table for this struct scope
    this->push_table();
}

void SymbolTableListener::exitStructDeclaration(DecafParser::StructDeclarationContext *ctx)
{
    std::string id = ctx->ID()->getText();

    // get this struct symbol table
    SymbolTable *table = this->pop_table();

    // save the struct declaration as a new type
    this->table->put(
        O_STRUCT,
        id,
        "struct",
        0);

    this->table->add_struct_table(id, table);

    std::cout << "exitStructDeclaration"
              << std::endl
              << "\tgot table: " << table->get_name()
              << std::endl;
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
            return;
        }

        SymbolTable *struct_table = this->table->get_struct_table(e->type);
        if (struct_table == NULL)
        {
            return;
        }

        std::cout << "\tparent is struct '"
                  << e->type
                  << "', search in its symbol table." << std::endl;
    }
    else
    {
        std::string id = ctx->ID()->getText();

        std::cout << std::endl
                  << "enterLocation:"
                  << "\t" << ctx->getText() << std::endl
                  << "\t" << id
                  << std::endl;

        SymbolTableEntry *entry = this->table->get(id);
        if (entry == NULL)
        {
            std::cout << "error: id '"
                      << id
                      << "' no declaration found."
                      << std::endl;
        }
        else
        {
            std::cout << id << " was found" << std::endl;
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

        std::cout << "\tsearching '"
                  << ctx->ID()->getText()
                  << "' in struct symbol table '"
                  << top->get_name()
                  << "'" << std::endl;

        SymbolTableEntry *e = top->get(ctx->ID()->getText());
        if (e == NULL)
        {
            put_node_type(ctx, T_ERROR);

            return;
        }

        put_node_type(ctx, e->data_type);
        put_node_type(ctx->parent, e->data_type);

        std::cout << "'" << ctx->ID()->getText()
                  << "' is a valid member of '"
                  << top->get_name() << "' with type '"
                  << e->type << "'"
                  << std::endl;
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

        std::cout << "exitLoc_var: type: "
                  << DataTypes::int_to_type(get_node_type(ctx))
                  << std::endl;
    }
}

void SymbolTableListener::enterLoc_array(DecafParser::Loc_arrayContext *ctx)
{
    SymbolTableEntry *e = this->table->get(ctx->ID()->getText());

    // validate ID exists
    if (e == NULL)
    {
        put_node_type(ctx, T_ERROR);
        std::string msg = "";
        msg += ": id '" + ctx->ID()->getText() + "' is not declared.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // validate ID refers to an array object
    if (e->obj_type != O_ARRAY)
    {
        put_node_type(ctx, T_ERROR);
        std::string msg = "";
        msg += ": id '" + ctx->ID()->getText() + "' is not an array.";
        print_error(msg, ctx->start->getLine());

        return;
    }
}

void SymbolTableListener::exitLoc_array(DecafParser::Loc_arrayContext *ctx)
{
    std::cout << std::endl
              << "exitLoc_array" << std::endl;
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
        std::string msg = "";
        msg += ": array index must be of type 'INTEGER'";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // set this node type as the type of the array
    SymbolTableEntry *e = this->table->get(ctx->ID()->getText());
    put_node_type(ctx, e->data_type);
}

void SymbolTableListener::enterLoc_member(DecafParser::Loc_memberContext *ctx)
{
    std::string var_name = ctx->ID()->getText();

    std::cout << std::endl
              << "enterLoc_member" << std::endl
              << "\t" << ctx->getText() << std::endl
              << "\tget table for struct: "
              << var_name
              << std::endl;

    // validate var_name exists
    SymbolTableEntry *e = this->table->get(var_name);
    if (e == NULL)
    {
        put_node_type(ctx, T_ERROR);

        return;
    }

    // var_name is a struct, get its struct symbol table
    SymbolTable *struct_table = this->table->get_struct_table(e->type);
    if (struct_table == NULL)
    {
        put_node_type(ctx, T_ERROR);

        return;
    }

    std::cout << "\tfound table for struct '"
              << e->id << "'"
              << std::endl;

    this->push_struct_table(struct_table);
}

void SymbolTableListener::exitLoc_member(DecafParser::Loc_memberContext *ctx)
{
    std::cout << "exitLoc_member" << std::endl;

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

    if (this->table->put(O_METHOD, id, method_type))
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
    std::cout << "exitMethodDeclaration" << std::endl;
    // get symbol table entry for this method
    SymbolTableEntry *entry = this->table->get(ctx->ID()->getText());

    // get the method block statements
    std::vector<DecafParser::StatementContext *> block = ctx->block()->statement();

    // get the return statement
    DecafParser::St_returnContext *ec = NULL;
    for (DecafParser::StatementContext *c : block)
    {
        if (DecafParser::St_returnContext *d = dynamic_cast<DecafParser::St_returnContext *>(c))
        {
            ec = (DecafParser::St_returnContext *)c;
            std::cout << "\treturn statement found: " << ec->getText() << std::endl;

            break;
        }
    }

    // method type is void and no return expression found
    if (ec == NULL && entry->data_type == T_VOID)
    {
        put_node_type(ctx, T_VOID);
        std::cout << "\tNo return statement found and method type is 'VOID'." << std::endl;

        return;
    }

    DecafParser::ExpressionContext *ret_expr = ec->expression();
    int ret_type = T_VOID;
    // return has an expression
    if (ret_expr != NULL)
    {
        ret_type = get_node_type(ret_expr->children[0]);
        std::cout << "\treturn expression: " << ret_expr->getText() << std::endl;
    }

    if (entry->data_type != ret_type)
    {
        put_node_type(ctx, T_ERROR);
        std::string msg = "";
        msg += ": return type: '" + DataTypes::int_to_type(ret_type);
        msg += "' not compatible with method type: '" + DataTypes::int_to_type(entry->data_type);
        msg += "'";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // all previous checks passed, method type and return type are correct
    put_node_type(ctx, ret_type);
    std::cout << "\tMethod type: '" + DataTypes::int_to_type(entry->data_type)
              << "' is compatible with return type '" << DataTypes::int_to_type(ret_type)
              << "'" << std::endl;
}
/// -----------------------------------------------------------------------------------------------------

/// ---------------------------------------- Method Calls ----------------------------------------
void SymbolTableListener::enterMethodCall(DecafParser::MethodCallContext *ctx)
{
    std::cout << std::endl
              << "enterMethodCall" << std::endl;

    SymbolTableEntry *e = this->table->get(ctx->ID()->getText());

    // method not declared
    if (e == NULL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "";
        msg += ": method '" + ctx->ID()->getText() + "' is not declared.";
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

        std::string msg = "";
        msg += ": expected " + std::to_string(e->m_params.size()) + " parameters, but found ";
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

            std::string msg = "";
            msg += ": actual parameter type '" + DataTypes::int_to_type(a_type);
            msg += "' differs from formal parameter type '" + DataTypes::int_to_type(e->m_params[i]);
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
    std::cout << std::endl
              << "enterExpr_arith_0" << std::endl;
}

void SymbolTableListener::exitExpr_arith_0(DecafParser::Expr_arith_0Context *ctx)
{
    process_arith_expr(ctx);
}

void SymbolTableListener::enterExpr_arith_1(DecafParser::Expr_arith_1Context *ctx)
{
    std::cout << std::endl
              << "enterExpr_arith_1: " << ctx->getText() << std::endl;
}

void SymbolTableListener::exitExpr_arith_1(DecafParser::Expr_arith_1Context *ctx)
{
    process_arith_expr(ctx);
}

void SymbolTableListener::enterExpr_rel(DecafParser::Expr_relContext *ctx)
{
    std::cout << std::endl
              << "enterExpr_rel: " << ctx->getText() << std::endl;
}

void SymbolTableListener::exitExpr_rel(DecafParser::Expr_relContext *ctx)
{
    // set child types
    put_node_type(ctx->children[0], get_node_type(ctx->children[0]->children[0]));
    put_node_type(ctx->children[2], get_node_type(ctx->children[2]->children[0]));

    if (get_node_type(ctx->children[0]) != T_INT)
    {
        size_t line = ctx->start->getLine();
        std::string msg = ctx->children[0]->getText() + "' is not an integer";
        print_error(msg, ctx->start->getLine());
        put_node_type(ctx, T_ERROR);
    }

    if (get_node_type(ctx->children[2]) != T_INT)
    {
        size_t line = ctx->start->getLine();
        std::string msg = ctx->children[2]->getText() + "' is not an integer";
        print_error(msg, ctx->start->getLine());
        put_node_type(ctx, T_ERROR);
    }

    if (get_node_type(ctx) != T_ERROR)
    {
        put_node_type(ctx, T_BOOL);
        std::cout
            << "exitExpr_arith_1: "
            << ctx->getText()
            << " is a valid relational expression."
            << std::endl;
    }
}

void SymbolTableListener::enterExpr_cond(DecafParser::Expr_condContext *ctx)
{
    std::cout << std::endl
              << "enterExpr_cond: " << ctx->getText() << std::endl;
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

    for (auto c : ctx->children)
    {
        std::cout << "\tchild: " << c->getText() << std::endl;
    }

    if (left_type != T_BOOL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "";
        msg += exprs[0]->getText() + " must be of type 'BOOL', '";
        msg += DataTypes::int_to_type(left_type) + "' found.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    if (right_type != T_BOOL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "";
        msg += exprs[1]->getText() + " must be of type 'BOOL', '";
        msg += DataTypes::int_to_type(right_type) + "' found.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    put_node_type(ctx, T_BOOL);
    std::cout << "exitExpr_cond: "
              << ctx->getText()
              << " has type: '"
              << DataTypes::int_to_type(get_node_type(ctx))
              << "'" << std::endl;
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

        std::string msg = "";
        msg += expr->getText() + " must be of type 'BOOL', '";
        msg += DataTypes::int_to_type(expr_type) + "' found.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    put_node_type(ctx, T_BOOL);

    std::cout << "exitExpr_not: "
              << ctx->getText()
              << " has type '"
              << DataTypes::int_to_type(get_node_type(ctx))
              << "'"
              << std::endl;
}

/**
 *
 */
void SymbolTableListener::enterExpr_eq(DecafParser::Expr_eqContext *ctx)
{
    std::cout << std::endl
              << "enterExpr_eq" << std::endl;
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
        std::string msg = "";
        msg += ctx->eq_op()->getText() + "' operator must be applied to operands of the same type.";
        msg += " Left operand has type '" + DataTypes::int_to_type(left_type);
        msg += "', right operand has type '" + DataTypes::int_to_type(right_type) + "'";
        print_error(msg, ctx->start->getLine());

        return;
    }

    put_node_type(ctx, T_BOOL);
    std::cout
        << "exitExpr_eq: "
        << ctx->getText()
        << " has type '"
        << DataTypes::int_to_type(get_node_type(ctx))
        << "'"
        << std::endl;
}

void SymbolTableListener::exitExpr_method_call(DecafParser::Expr_method_callContext *ctx)
{
    SymbolTableEntry *e = this->table->get(ctx->methodCall()->ID()->getText());

    // method not declared
    if (e == NULL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "";
        msg += ": method '" + ctx->methodCall()->ID()->getText() + "' not declared.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    if (e->data_type == T_VOID)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "";
        msg += ": method '" + ctx->methodCall()->ID()->getText() + "' has return type of 'void',";
        msg += " not allowed in an expression.";
        print_error(msg, ctx->start->getLine());
    }
}

/// ----------------------------------------------------------------------------------------------------

/// ---------------------------------------- Literals ----------------------------------------
void SymbolTableListener::enterLiteral(DecafParser::LiteralContext *ctx)
{
    std::cout << "enterLiteral" << std::endl;
}

/// Set this literal node type to its children type
void SymbolTableListener::exitLiteral(DecafParser::LiteralContext *ctx)
{
    put_node_type(ctx, get_node_type(ctx->children[0]));
    std::cout << "exitLiteral: "
              << "(type: " << get_node_type(ctx) << ")" << std::endl;
}

void SymbolTableListener::enterInt_literal(DecafParser::Int_literalContext *ctx)
{
    std::cout
        << "enterInt_literal" << std::endl;
}

void SymbolTableListener::exitInt_literal(DecafParser::Int_literalContext *ctx)
{
    put_node_type(ctx, T_INT);
    std::cout
        << "exitInt_literal: " << ctx->getText() << " (type: " << get_node_type(ctx) << ")" << std::endl;
}

void SymbolTableListener::enterChar_literal(DecafParser::Char_literalContext *ctx)
{
    std::cout << std::endl
              << "enterChar_literal" << std::endl;
}

void SymbolTableListener::exitChar_literal(DecafParser::Char_literalContext *ctx)
{
    std::cout
        << "exitChar_literal: " << ctx->getText() << std::endl;
    put_node_type(ctx, T_CHAR);
}

void SymbolTableListener::enterBool_literal(DecafParser::Bool_literalContext *ctx)
{
    std::cout
        << "enterBool_literal" << std::endl;
}

void SymbolTableListener::exitBool_literal(DecafParser::Bool_literalContext *ctx)
{
    std::cout
        << "exitBool_literal: " << ctx->getText() << std::endl;

    for (auto c : ctx->children)
    {
        put_node_type(c, T_BOOL);
        std::cout
            << "bool child: "
            << c->getText()
            << " has type: "
            << std::to_string(get_node_type(c));
    }

    put_node_type(ctx, T_BOOL);
    std::cout << std::endl
              << "exitBool_literal has type: " << std::to_string(get_node_type(ctx)) << std::endl;
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

        std::string msg = "";
        msg += ": expression type: '" + DataTypes::int_to_type(expr_type);
        msg += "' is incompatible with type: '" + DataTypes::int_to_type(loc_type) + "'";
        print_error(msg, ctx->start->getLine());

        return;
    }

    std::cout << std::endl
              << "exitSt_assignment: "
              << ctx->getText()
              << " " << DataTypes::int_to_type(loc_type)
              << " = "
              << DataTypes::int_to_type(expr_type)
              << std::endl;
}

void SymbolTableListener::enterSt_if(DecafParser::St_ifContext *ctx)
{
    std::cout << std::endl
              << "enterSt_if"
              << std::endl
              << "\t"
              << ctx->getText() << std::endl;
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

        std::string msg = "";
        msg += ": if expression must be of type 'BOOL', '";
        msg += DataTypes::int_to_type(expr_type) + "' found.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // TODO: node has type VOID
    put_node_type(ctx, T_VOID);

    std::cout << "exitSt_if: has type: '"
              << DataTypes::int_to_type(get_node_type(ctx))
              << "'"
              << std::endl;
}

void SymbolTableListener::enterSt_while(DecafParser::St_whileContext *ctx)
{
    std::cout << std::endl
              << "enterSt_while"
              << std::endl
              << "\t"
              << ctx->getText() << std::endl;
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

        std::string msg = "";
        msg += ": if expression must be of type 'BOOL', '";
        msg += DataTypes::int_to_type(expr_type) + "' found.";
        print_error(msg, ctx->start->getLine());

        return;
    }

    // TODO: node has type VOID
    put_node_type(ctx, T_VOID);

    std::cout << "exitSt_while: has type: '"
              << DataTypes::int_to_type(get_node_type(ctx))
              << "'"
              << std::endl;
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

    std::cout << "------------------ "
              << "push() " << this->table->get_name()
              << " ------------------"
              << std::endl;
}

SymbolTable *SymbolTableListener::pop_table()
{
    // pop the top table
    SymbolTable *old = this->table;
    this->table = this->table->get_parent();

    std::cout << "pop(): " << old->get_name() << " | contents:" << std::endl;
    old->print_table();
    std::cout << "----------------------------------------------------" << std::endl;

    return old;
}

void SymbolTableListener::process_arith_expr(DecafParser::ExpressionContext *ctx)
{
    // set child types
    put_node_type(ctx->children[0], get_node_type(ctx->children[0]->children[0]));
    put_node_type(ctx->children[2], get_node_type(ctx->children[2]->children[0]));

    if (get_node_type(ctx->children[0]) != T_INT)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = ctx->children[0]->getText() + "' is not an integer";
        print_error(msg, ctx->start->getLine());
    }

    if (get_node_type(ctx->children[2]) != T_INT)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = ctx->children[2]->getText() + "' is not an integer";
        print_error(msg, ctx->start->getLine());
    }

    if (get_node_type(ctx) != T_ERROR)
    {
        put_node_type(ctx, T_INT);
        std::cout
            << "exitExpr_arith_1: "
            << ctx->getText()
            << " is a valid arithmetic expression."
            << std::endl;
    }
}

void SymbolTableListener::push_struct_table(SymbolTable *table)
{
    this->struct_tables.push(table);
}

SymbolTable *SymbolTableListener::pop_struct_table()
{
    SymbolTable *top = this->struct_tables.top();
    this->struct_tables.pop();

    return top;
}

void SymbolTableListener::print_error(std::string msg, size_t line_num)
{
    std::cout << "[ERROR](in line "
              << std::to_string(line_num) << ") => "
              << msg
              << std::endl;
}