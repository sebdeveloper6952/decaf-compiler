
// Generated from Decaf.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "DecafParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by DecafParser.
 */
class  DecafVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by DecafParser.
   */
    virtual antlrcpp::Any visitProgram(DecafParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(DecafParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitVar_decl(DecafParser::Var_declContext *context) = 0;

    virtual antlrcpp::Any visitVar_arr_decl(DecafParser::Var_arr_declContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclaration(DecafParser::StructDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitVarType(DecafParser::VarTypeContext *context) = 0;

    virtual antlrcpp::Any visitMethodType(DecafParser::MethodTypeContext *context) = 0;

    virtual antlrcpp::Any visitMethodDeclaration(DecafParser::MethodDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitParameter(DecafParser::ParameterContext *context) = 0;

    virtual antlrcpp::Any visitParameterType(DecafParser::ParameterTypeContext *context) = 0;

    virtual antlrcpp::Any visitBlock(DecafParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitStatement(DecafParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitLocation(DecafParser::LocationContext *context) = 0;

    virtual antlrcpp::Any visitExpr_literal(DecafParser::Expr_literalContext *context) = 0;

    virtual antlrcpp::Any visitExpr_loc(DecafParser::Expr_locContext *context) = 0;

    virtual antlrcpp::Any visitExpr_neg(DecafParser::Expr_negContext *context) = 0;

    virtual antlrcpp::Any visitExpr_par(DecafParser::Expr_parContext *context) = 0;

    virtual antlrcpp::Any visitExpr_arith_1(DecafParser::Expr_arith_1Context *context) = 0;

    virtual antlrcpp::Any visitExpr_arith_0(DecafParser::Expr_arith_0Context *context) = 0;

    virtual antlrcpp::Any visitExpr_cond(DecafParser::Expr_condContext *context) = 0;

    virtual antlrcpp::Any visitExpr_method_call(DecafParser::Expr_method_callContext *context) = 0;

    virtual antlrcpp::Any visitExpr_rel(DecafParser::Expr_relContext *context) = 0;

    virtual antlrcpp::Any visitExpr_eq(DecafParser::Expr_eqContext *context) = 0;

    virtual antlrcpp::Any visitExpr_not(DecafParser::Expr_notContext *context) = 0;

    virtual antlrcpp::Any visitMethodCall(DecafParser::MethodCallContext *context) = 0;

    virtual antlrcpp::Any visitArith_op(DecafParser::Arith_opContext *context) = 0;

    virtual antlrcpp::Any visitRel_op(DecafParser::Rel_opContext *context) = 0;

    virtual antlrcpp::Any visitEq_op(DecafParser::Eq_opContext *context) = 0;

    virtual antlrcpp::Any visitCond_op(DecafParser::Cond_opContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(DecafParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitInt_literal(DecafParser::Int_literalContext *context) = 0;

    virtual antlrcpp::Any visitChar_literal(DecafParser::Char_literalContext *context) = 0;

    virtual antlrcpp::Any visitBool_literal(DecafParser::Bool_literalContext *context) = 0;


};

