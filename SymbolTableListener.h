#pragma once

#include <stack>
#include <vector>
#include "antlr4-runtime.h"
#include "DecafBaseListener.h"
#include "SymbolTable.h"
#include "NodeAttrs.h"
#include "IcgInstr.h"

/**
 * This class provides an empty implementation of DecafListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class SymbolTableListener : public DecafBaseListener
{
private:
    SymbolTable *table;
    std::vector<IcgInstr *> *instrs;
    size_t num_tables = 0;
    bool is_main_valid;
    antlr4::tree::ParseTreeProperty<int> node_types;
    std::stack<SymbolTable *> struct_tables;
    antlr4::tree::ParseTreeProperty<NodeAttrs *> node_attrs;
    uint temp_count = 0;
    uint label_count = 0;
    std::vector<std::string> vec_code;
    void push_table();
    SymbolTable *pop_table();
    void process_arith_expr(DecafParser::ExpressionContext *ctx);
    void print_error(std::string msg, size_t line_num);
    void gen_code_expr(DecafParser::ExpressionContext *ctx);

public:
    SymbolTableListener(SymbolTable *table, std::vector<IcgInstr *> *instrs);

    // class Program
    void enterProgram(DecafParser::ProgramContext *ctx);
    void exitProgram(DecafParser::ProgramContext *ctx);

    // var declarations
    void enterVar_decl(DecafParser::Var_declContext *ctx);
    void enterVar_arr_decl(DecafParser::Var_arr_declContext *ctx);
    void enterVar_struct_decl(DecafParser::Var_struct_declContext *ctx);
    void exitVar_struct_decl(DecafParser::Var_struct_declContext *ctx);

    // struct declaration
    void enterStructDeclaration(DecafParser::StructDeclarationContext *ctx);
    void exitStructDeclaration(DecafParser::StructDeclarationContext *ctx);

    // block
    void enterBlock(DecafParser::BlockContext *ctx);
    void exitBlock(DecafParser::BlockContext *ctx);

    // statements
    void enterSt_assignment(DecafParser::St_assignmentContext *ctx);
    void exitSt_assignment(DecafParser::St_assignmentContext *ctx);
    void enterSt_if(DecafParser::St_ifContext *ctx);
    void exitSt_if(DecafParser::St_ifContext *ctx);
    void enterSt_while(DecafParser::St_whileContext *ctx);
    void exitSt_while(DecafParser::St_whileContext *ctx);
    void exitSt_return(DecafParser::St_returnContext *ctx);
    void exitSt_method_call(DecafParser::St_method_callContext *ctx);

    // location
    void exitLoc_var(DecafParser::Loc_varContext *ctx);
    void enterLoc_var(DecafParser::Loc_varContext *ctx);
    void enterLoc_array(DecafParser::Loc_arrayContext *ctx);
    void exitLoc_array(DecafParser::Loc_arrayContext *ctx);
    void enterLoc_member(DecafParser::Loc_memberContext *ctx);
    void exitLoc_member(DecafParser::Loc_memberContext *ctx);

    // method declaration
    void enterMethodDeclaration(DecafParser::MethodDeclarationContext *ctx);
    void exitMethodDeclaration(DecafParser::MethodDeclarationContext *ctx);

    // method calls
    void enterMethodCall(DecafParser::MethodCallContext *ctx);
    void exitMethodCall(DecafParser::MethodCallContext *ctx);

    // expressions
    void enterExpression(DecafParser::ExpressionContext *ctx);
    void exitExpression(DecafParser::ExpressionContext *ctx);
    void enterExpr_arith_1(DecafParser::Expr_arith_1Context *ctx);
    void exitExpr_arith_1(DecafParser::Expr_arith_1Context *ctx);
    void enterExpr_arith_0(DecafParser::Expr_arith_0Context *ctx);
    void exitExpr_arith_0(DecafParser::Expr_arith_0Context *ctx);
    void enterExpr_rel(DecafParser::Expr_relContext *ctx);
    void exitExpr_rel(DecafParser::Expr_relContext *ctx);

    void enterExpr_cond_and(DecafParser::Expr_cond_andContext *ctx);
    void exitExpr_cond_and(DecafParser::Expr_cond_andContext *ctx);
    void enterExpr_cond_or(DecafParser::Expr_cond_orContext *ctx);
    void exitExpr_cond_or(DecafParser::Expr_cond_orContext *ctx);

    void exitExpr_not(DecafParser::Expr_notContext *ctx);
    void enterExpr_eq(DecafParser::Expr_eqContext *ctx);
    void exitExpr_eq(DecafParser::Expr_eqContext *ctx);
    void exitExpr_method_call(DecafParser::Expr_method_callContext *ctx);
    void exitExpr_neg(DecafParser::Expr_negContext *ctx);
    void exitExpr_par(DecafParser::Expr_parContext *ctx);
    void enterExpr_loc(DecafParser::Expr_locContext *ctx);
    void exitExpr_loc(DecafParser::Expr_locContext *ctx);

    // literals
    void enterLiteral(DecafParser::LiteralContext *ctx);
    void exitLiteral(DecafParser::LiteralContext *ctx);
    void enterInt_literal(DecafParser::Int_literalContext *ctx);
    void exitInt_literal(DecafParser::Int_literalContext *ctx);
    void enterChar_literal(DecafParser::Char_literalContext *ctx);
    void exitChar_literal(DecafParser::Char_literalContext *ctx);
    void enterBool_literal(DecafParser::Bool_literalContext *ctx);
    void exitBool_literal(DecafParser::Bool_literalContext *ctx);

    // utils
    void put_node_type(antlr4::tree::ParseTree *node, int type);
    int get_node_type(antlr4::tree::ParseTree *node);
    void push_struct_table(SymbolTable *table);
    SymbolTable *pop_struct_table();
    void put_node_attrs(
        antlr4::tree::ParseTree *node,
        NodeAttrs *attrs);
    NodeAttrs *get_node_attrs(antlr4::tree::ParseTree *node);
    std::string new_temp();
    std::string new_label();
    std::string new_method_label(std::string);
    void emit(std::string code);
};
