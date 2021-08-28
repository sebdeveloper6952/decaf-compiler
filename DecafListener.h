
// Generated from Decaf.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "DecafParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by DecafParser.
 */
class  DecafListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(DecafParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(DecafParser::ProgramContext *ctx) = 0;

  virtual void enterDeclaration(DecafParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(DecafParser::DeclarationContext *ctx) = 0;

  virtual void enterVar_decl(DecafParser::Var_declContext *ctx) = 0;
  virtual void exitVar_decl(DecafParser::Var_declContext *ctx) = 0;

  virtual void enterVar_arr_decl(DecafParser::Var_arr_declContext *ctx) = 0;
  virtual void exitVar_arr_decl(DecafParser::Var_arr_declContext *ctx) = 0;

  virtual void enterVar_struct_decl(DecafParser::Var_struct_declContext *ctx) = 0;
  virtual void exitVar_struct_decl(DecafParser::Var_struct_declContext *ctx) = 0;

  virtual void enterStructDeclaration(DecafParser::StructDeclarationContext *ctx) = 0;
  virtual void exitStructDeclaration(DecafParser::StructDeclarationContext *ctx) = 0;

  virtual void enterVarType(DecafParser::VarTypeContext *ctx) = 0;
  virtual void exitVarType(DecafParser::VarTypeContext *ctx) = 0;

  virtual void enterMethodType(DecafParser::MethodTypeContext *ctx) = 0;
  virtual void exitMethodType(DecafParser::MethodTypeContext *ctx) = 0;

  virtual void enterMethodDeclaration(DecafParser::MethodDeclarationContext *ctx) = 0;
  virtual void exitMethodDeclaration(DecafParser::MethodDeclarationContext *ctx) = 0;

  virtual void enterParameter(DecafParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(DecafParser::ParameterContext *ctx) = 0;

  virtual void enterParameterType(DecafParser::ParameterTypeContext *ctx) = 0;
  virtual void exitParameterType(DecafParser::ParameterTypeContext *ctx) = 0;

  virtual void enterBlock(DecafParser::BlockContext *ctx) = 0;
  virtual void exitBlock(DecafParser::BlockContext *ctx) = 0;

  virtual void enterSt_if(DecafParser::St_ifContext *ctx) = 0;
  virtual void exitSt_if(DecafParser::St_ifContext *ctx) = 0;

  virtual void enterSt_while(DecafParser::St_whileContext *ctx) = 0;
  virtual void exitSt_while(DecafParser::St_whileContext *ctx) = 0;

  virtual void enterSt_return(DecafParser::St_returnContext *ctx) = 0;
  virtual void exitSt_return(DecafParser::St_returnContext *ctx) = 0;

  virtual void enterSt_method_call(DecafParser::St_method_callContext *ctx) = 0;
  virtual void exitSt_method_call(DecafParser::St_method_callContext *ctx) = 0;

  virtual void enterSt_block(DecafParser::St_blockContext *ctx) = 0;
  virtual void exitSt_block(DecafParser::St_blockContext *ctx) = 0;

  virtual void enterSt_assignment(DecafParser::St_assignmentContext *ctx) = 0;
  virtual void exitSt_assignment(DecafParser::St_assignmentContext *ctx) = 0;

  virtual void enterSt_expression(DecafParser::St_expressionContext *ctx) = 0;
  virtual void exitSt_expression(DecafParser::St_expressionContext *ctx) = 0;

  virtual void enterLoc_var(DecafParser::Loc_varContext *ctx) = 0;
  virtual void exitLoc_var(DecafParser::Loc_varContext *ctx) = 0;

  virtual void enterLoc_array(DecafParser::Loc_arrayContext *ctx) = 0;
  virtual void exitLoc_array(DecafParser::Loc_arrayContext *ctx) = 0;

  virtual void enterLoc_member(DecafParser::Loc_memberContext *ctx) = 0;
  virtual void exitLoc_member(DecafParser::Loc_memberContext *ctx) = 0;

  virtual void enterExpr_literal(DecafParser::Expr_literalContext *ctx) = 0;
  virtual void exitExpr_literal(DecafParser::Expr_literalContext *ctx) = 0;

  virtual void enterExpr_loc(DecafParser::Expr_locContext *ctx) = 0;
  virtual void exitExpr_loc(DecafParser::Expr_locContext *ctx) = 0;

  virtual void enterExpr_neg(DecafParser::Expr_negContext *ctx) = 0;
  virtual void exitExpr_neg(DecafParser::Expr_negContext *ctx) = 0;

  virtual void enterExpr_par(DecafParser::Expr_parContext *ctx) = 0;
  virtual void exitExpr_par(DecafParser::Expr_parContext *ctx) = 0;

  virtual void enterExpr_arith_1(DecafParser::Expr_arith_1Context *ctx) = 0;
  virtual void exitExpr_arith_1(DecafParser::Expr_arith_1Context *ctx) = 0;

  virtual void enterExpr_arith_0(DecafParser::Expr_arith_0Context *ctx) = 0;
  virtual void exitExpr_arith_0(DecafParser::Expr_arith_0Context *ctx) = 0;

  virtual void enterExpr_cond(DecafParser::Expr_condContext *ctx) = 0;
  virtual void exitExpr_cond(DecafParser::Expr_condContext *ctx) = 0;

  virtual void enterExpr_method_call(DecafParser::Expr_method_callContext *ctx) = 0;
  virtual void exitExpr_method_call(DecafParser::Expr_method_callContext *ctx) = 0;

  virtual void enterExpr_rel(DecafParser::Expr_relContext *ctx) = 0;
  virtual void exitExpr_rel(DecafParser::Expr_relContext *ctx) = 0;

  virtual void enterExpr_eq(DecafParser::Expr_eqContext *ctx) = 0;
  virtual void exitExpr_eq(DecafParser::Expr_eqContext *ctx) = 0;

  virtual void enterExpr_not(DecafParser::Expr_notContext *ctx) = 0;
  virtual void exitExpr_not(DecafParser::Expr_notContext *ctx) = 0;

  virtual void enterMethodCall(DecafParser::MethodCallContext *ctx) = 0;
  virtual void exitMethodCall(DecafParser::MethodCallContext *ctx) = 0;

  virtual void enterRel_op(DecafParser::Rel_opContext *ctx) = 0;
  virtual void exitRel_op(DecafParser::Rel_opContext *ctx) = 0;

  virtual void enterEq_op(DecafParser::Eq_opContext *ctx) = 0;
  virtual void exitEq_op(DecafParser::Eq_opContext *ctx) = 0;

  virtual void enterCond_op(DecafParser::Cond_opContext *ctx) = 0;
  virtual void exitCond_op(DecafParser::Cond_opContext *ctx) = 0;

  virtual void enterLiteral(DecafParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(DecafParser::LiteralContext *ctx) = 0;

  virtual void enterInt_literal(DecafParser::Int_literalContext *ctx) = 0;
  virtual void exitInt_literal(DecafParser::Int_literalContext *ctx) = 0;

  virtual void enterChar_literal(DecafParser::Char_literalContext *ctx) = 0;
  virtual void exitChar_literal(DecafParser::Char_literalContext *ctx) = 0;

  virtual void enterBool_literal(DecafParser::Bool_literalContext *ctx) = 0;
  virtual void exitBool_literal(DecafParser::Bool_literalContext *ctx) = 0;


};

