#pragma once

#include "antlr4-runtime.h"
#include "DecafBaseListener.h"
#include "SymbolTable.h"

/**
 * This class provides an empty implementation of DecafListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class SymbolTableListener : public DecafBaseListener
{
private:
    SymbolTable *table;
    size_t num_tables = 0;
    bool is_main_valid;
    void push_table();
    void pop_table();
    void process_arith_expr(DecafParser::ExpressionContext *ctx);
    void print_error(std::string msg);
    antlr4::tree::ParseTreeProperty<int> node_types;

public:
    SymbolTableListener(SymbolTable *table);

    // class Program
    void enterProgram(DecafParser::ProgramContext *ctx);
    void exitProgram(DecafParser::ProgramContext *ctx);

    // var declarations
    void enterVar_decl(DecafParser::Var_declContext *ctx);
    void enterVar_arr_decl(DecafParser::Var_arr_declContext *ctx);

    // block
    void enterBlock(DecafParser::BlockContext *ctx);
    void exitBlock(DecafParser::BlockContext *ctx);

    // statements
    void exitSt_return(DecafParser::St_returnContext *ctx);

    // location
    void enterLocation(DecafParser::LocationContext *ctx);
    void exitLocation(DecafParser::LocationContext *ctx);

    // method declaration
    void enterMethodDeclaration(DecafParser::MethodDeclarationContext *ctx);
    void exitMethodDeclaration(DecafParser::MethodDeclarationContext *ctx);

    // expressions
    void enterExpression(DecafParser::ExpressionContext *ctx);
    void exitExpression(DecafParser::ExpressionContext *ctx);
    void enterExpr_arith_1(DecafParser::Expr_arith_1Context *ctx);
    void exitExpr_arith_1(DecafParser::Expr_arith_1Context *ctx);
    void enterExpr_arith_0(DecafParser::Expr_arith_0Context *ctx);
    void exitExpr_arith_0(DecafParser::Expr_arith_0Context *ctx);
    void enterExpr_rel(DecafParser::Expr_relContext *ctx);
    void exitExpr_rel(DecafParser::Expr_relContext *ctx);

    void enterLiteral(DecafParser::LiteralContext *ctx);
    void exitLiteral(DecafParser::LiteralContext *ctx);
    void enterInt_literal(DecafParser::Int_literalContext *ctx);
    void exitInt_literal(DecafParser::Int_literalContext *ctx);
    void enterChar_literal(DecafParser::Char_literalContext *ctx);
    void exitChar_literal(DecafParser::Char_literalContext *ctx);
    void enterBool_literal(DecafParser::Bool_literalContext *ctx);
    void exitBool_literal(DecafParser::Bool_literalContext *ctx);

    void put_node_type(antlr4::tree::ParseTree *node, int type);
    int get_node_type(antlr4::tree::ParseTree *node);
};
