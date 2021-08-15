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
        print_error("Source program must include a valid 'main' function declaration.");
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
        std::string msg =
            "in line " + std::to_string(ctx->start->getLine()) + ": ";
        msg += array_size->getText();
        msg += " is an invalid integer for array size.";
        print_error(msg);

        return;
    }

    size_t size = std::stoi(array_size->getText());
    if (!this->table->put(O_ARRAY, id->getText(), var_type->getText(), size))
    {
        std::string msg = "varDeclaration id (" + id->getText() + ") is already declared.";
        print_error(msg);

        return;
    }
}

/// ---------------------------------------- Var Locations ----------------------------------------
/**
 * Check if var id exists in symbol table.
 */
void SymbolTableListener::enterLoc_var(DecafParser::Loc_varContext *ctx)
{
    std::string id = ctx->ID()->getText();
    std::cout << std::endl
              << "enterLocation: " << id << std::endl;

    SymbolTableEntry *entry = this->table->get(id);
    if (entry == NULL)
    {
        std::cout << "error: id ("
                  << id
                  << ") no declaration found."
                  << std::endl;
    }
    else
    {
        std::cout << id << " was found" << std::endl;
    }
}

/**
 * Set node type of this location node.
 */
void SymbolTableListener::exitLoc_var(DecafParser::Loc_varContext *ctx)
{
    SymbolTableEntry *e = this->table->get(ctx->ID()->getText());
    put_node_type(ctx, e->data_type);
    std::cout << "exitLoc_var: type: "
              << DataTypes::int_to_type(get_node_type(ctx))
              << std::endl;
}

void SymbolTableListener::enterLoc_array(DecafParser::Loc_arrayContext *ctx)
{
    SymbolTableEntry *e = this->table->get(ctx->ID()->getText());

    // validate ID exists
    if (e == NULL)
    {
        put_node_type(ctx, T_ERROR);
        std::string msg = "in line " + std::to_string(ctx->start->getLine());
        msg += ": id '" + ctx->ID()->getText() + "' is not declared.";
        print_error(msg);

        return;
    }

    // validate ID refers to an array object
    if (e->obj_type != O_ARRAY)
    {
        put_node_type(ctx, T_ERROR);
        std::string msg = "in line " + std::to_string(ctx->start->getLine());
        msg += ": id '" + ctx->ID()->getText() + "' is not an array.";
        print_error(msg);

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
        std::string msg = "in line " + std::to_string(ctx->start->getLine());
        msg += ": array index must be of type 'INTEGER'";
        print_error(msg);

        return;
    }

    // set this node type as the type of the array
    SymbolTableEntry *e = this->table->get(ctx->ID()->getText());
    put_node_type(ctx, e->data_type);
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
    }
}
/// -----------------------------------------------------------------------------------------------------

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
        if (c->getText().find("return") != std::string::npos)
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

    std::cout << "here1" << std::endl;
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
        std::string msg = "in line " + std::to_string(ctx->start->getLine());
        msg += ": return type: '" + DataTypes::int_to_type(ret_type);
        msg += "' not compatible with method type: '" + DataTypes::int_to_type(entry->data_type);
        msg += "'";
        print_error(msg);

        return;
    }

    // all previous checks passed, method type and return type are correct
    put_node_type(ctx, ret_type);
    std::cout << "\tMethod type: '" + DataTypes::int_to_type(entry->data_type)
              << "' is compatible with return type '" << DataTypes::int_to_type(ret_type)
              << "'" << std::endl;
}

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
        std::string msg =
            "in line " + std::to_string(line) + ": '" + ctx->children[0]->getText() + "' is not an integer";
        print_error(msg);
        put_node_type(ctx, T_ERROR);
    }

    if (get_node_type(ctx->children[2]) != T_INT)
    {
        size_t line = ctx->start->getLine();
        std::string msg =
            "in line " + std::to_string(line) + ": '" + ctx->children[2]->getText() + "' is not an integer";
        print_error(msg);
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

        std::string msg = "in line " + std::to_string(ctx->start->getLine()) + ": ";
        msg += exprs[0]->getText() + " must be of type 'BOOL', '";
        msg += DataTypes::int_to_type(left_type) + "' found.";
        print_error(msg);

        return;
    }

    if (right_type != T_BOOL)
    {
        put_node_type(ctx, T_ERROR);

        std::string msg = "in line " + std::to_string(ctx->start->getLine()) + ": ";
        msg += exprs[1]->getText() + " must be of type 'BOOL', '";
        msg += DataTypes::int_to_type(right_type) + "' found.";
        print_error(msg);

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
 * 
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

        std::string msg = "in line " + std::to_string(ctx->start->getLine()) + ": ";
        msg += expr->getText() + " must be of type 'BOOL', '";
        msg += DataTypes::int_to_type(expr_type) + "' found.";
        print_error(msg);

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
/// ---------------------------------------- Finish Expressions ----------------------------------------

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

        std::string msg = "in line " + std::to_string(ctx->start->getLine());
        msg += ": expression type: '" + DataTypes::int_to_type(expr_type);
        msg += "' is incompatible with array type: '" + DataTypes::int_to_type(loc_type) + "'";
        print_error(msg);

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

void SymbolTableListener::pop_table()
{
    // pop the top table
    SymbolTable *old = this->table;
    this->table = this->table->get_parent();

    std::cout << "pop(): " << old->get_name() << " | contents:" << std::endl;
    old->print_table();
    std::cout << "----------------------------------------------------" << std::endl;
}

void SymbolTableListener::process_arith_expr(DecafParser::ExpressionContext *ctx)
{
    // set child types
    put_node_type(ctx->children[0], get_node_type(ctx->children[0]->children[0]));
    put_node_type(ctx->children[2], get_node_type(ctx->children[2]->children[0]));

    if (get_node_type(ctx->children[0]) != T_INT)
    {
        size_t line = ctx->start->getLine();
        std::string msg =
            "in line " + std::to_string(line) + ": '" + ctx->children[0]->getText() + "' is not an integer";
        print_error(msg);
        put_node_type(ctx, T_ERROR);
    }

    if (get_node_type(ctx->children[2]) != T_INT)
    {
        size_t line = ctx->start->getLine();
        std::string msg =
            "in line " + std::to_string(line) + ": '" + ctx->children[2]->getText() + "' is not an integer";
        print_error(msg);
        put_node_type(ctx, T_ERROR);
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

void SymbolTableListener::print_error(std::string msg)
{
    std::cout << "[ERROR]: "
              << msg
              << std::endl;
}