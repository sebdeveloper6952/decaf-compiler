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

    std::cout << this->table->get_name() << "->push(): " << id->getText() << std::endl;
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

    if (!this->table->put(O_ARRAY, id->getText(), var_type->getText()))
    {
        std::cout << "error: varDeclaration id ("
                  << id->getText()
                  << ") is already declared."
                  << std::endl;

        return;
    }

    std::cout << this->table->get_name() << "->push(): " << id->getText() << std::endl;
}

// location
void SymbolTableListener::enterLocation(DecafParser::LocationContext *ctx)
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

void SymbolTableListener::exitLocation(DecafParser::LocationContext *ctx) {}

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
        std::cout << "methodDeclaration saved in symbol table: "
                  << method_type
                  << "|"
                  << id
                  << std::endl;
    }
}
/// -----------------------------------------------------------------------------------------------------

void SymbolTableListener::exitMethodDeclaration(DecafParser::MethodDeclarationContext *ctx) {}

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
void SymbolTableListener::exitSt_return(DecafParser::St_returnContext *ctx)
{
    std::cout << "exitSt_return" << std::endl;

    // validate an ancestor is a method
    antlr4::tree::ParseTree *parent = ctx->parent;
    while (parent != NULL)
    {
        // node in question is a method declaration
        if (((antlr4::ParserRuleContext *)parent)->getRuleIndex() == DecafParser::RuleMethodDeclaration)
        {
            break;
        }
        parent = parent->parent;
    }
    // return statement was made outside of methodDeclaration
    if (parent == NULL)
    {
        put_node_type(ctx, T_ERROR);
        std::string msg = "return statement must be inside a method block.";

        return;
    }

    // get return type of method
    DecafParser::MethodDeclarationContext *method = (DecafParser::MethodDeclarationContext *)parent;
    SymbolTableEntry *entry = this->table->get(method->ID()->getText());
    std::cout << "\treturn statement found inside "
              << entry->id
              << " | "
              << entry->data_type
              << std::endl;

    // validate return type expression
    DecafParser::ExpressionContext *expr = ctx->expression();
    if (expr != NULL && expr->children.size() > 0)
    {
        int expr_type = get_node_type(expr->children[0]);
        if (entry->data_type != expr_type)
        {
            std::string msg = "return expression of type: " + expr_type;
            msg += " is incompatible with method type of: " + entry->data_type;
            print_error(msg);
        }
        else
        {
            std::cout << "\treturn type is compatible with method type."
                      << std::endl;
        }
    }
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