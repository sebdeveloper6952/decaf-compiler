
// Generated from Decaf.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "DecafVisitor.h"


/**
 * This class provides an empty implementation of DecafVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  DecafBaseVisitor : public DecafVisitor {
public:

  virtual antlrcpp::Any visitProgram(DecafParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclaration(DecafParser::DeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_decl(DecafParser::Var_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_arr_decl(DecafParser::Var_arr_declContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStructDeclaration(DecafParser::StructDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarType(DecafParser::VarTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodType(DecafParser::MethodTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodDeclaration(DecafParser::MethodDeclarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter(DecafParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterType(DecafParser::ParameterTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(DecafParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSt_if(DecafParser::St_ifContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSt_while(DecafParser::St_whileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSt_return(DecafParser::St_returnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSt_method_call(DecafParser::St_method_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSt_block(DecafParser::St_blockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSt_assignment(DecafParser::St_assignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSt_expression(DecafParser::St_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoc_var(DecafParser::Loc_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoc_array(DecafParser::Loc_arrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_literal(DecafParser::Expr_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_loc(DecafParser::Expr_locContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_neg(DecafParser::Expr_negContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_par(DecafParser::Expr_parContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_arith_1(DecafParser::Expr_arith_1Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_arith_0(DecafParser::Expr_arith_0Context *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_cond(DecafParser::Expr_condContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_method_call(DecafParser::Expr_method_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_rel(DecafParser::Expr_relContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_eq(DecafParser::Expr_eqContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr_not(DecafParser::Expr_notContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMethodCall(DecafParser::MethodCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArith_op(DecafParser::Arith_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRel_op(DecafParser::Rel_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEq_op(DecafParser::Eq_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCond_op(DecafParser::Cond_opContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(DecafParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInt_literal(DecafParser::Int_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitChar_literal(DecafParser::Char_literalContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBool_literal(DecafParser::Bool_literalContext *ctx) override {
    return visitChildren(ctx);
  }


};

