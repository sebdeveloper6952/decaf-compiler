
// Generated from Decaf.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "DecafListener.h"


/**
 * This class provides an empty implementation of DecafListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  DecafBaseListener : public DecafListener {
public:

  virtual void enterProgram(DecafParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(DecafParser::ProgramContext * /*ctx*/) override { }

  virtual void enterDeclaration(DecafParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(DecafParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterVar_decl(DecafParser::Var_declContext * /*ctx*/) override { }
  virtual void exitVar_decl(DecafParser::Var_declContext * /*ctx*/) override { }

  virtual void enterVar_arr_decl(DecafParser::Var_arr_declContext * /*ctx*/) override { }
  virtual void exitVar_arr_decl(DecafParser::Var_arr_declContext * /*ctx*/) override { }

  virtual void enterStructDeclaration(DecafParser::StructDeclarationContext * /*ctx*/) override { }
  virtual void exitStructDeclaration(DecafParser::StructDeclarationContext * /*ctx*/) override { }

  virtual void enterVarType(DecafParser::VarTypeContext * /*ctx*/) override { }
  virtual void exitVarType(DecafParser::VarTypeContext * /*ctx*/) override { }

  virtual void enterMethodType(DecafParser::MethodTypeContext * /*ctx*/) override { }
  virtual void exitMethodType(DecafParser::MethodTypeContext * /*ctx*/) override { }

  virtual void enterMethodDeclaration(DecafParser::MethodDeclarationContext * /*ctx*/) override { }
  virtual void exitMethodDeclaration(DecafParser::MethodDeclarationContext * /*ctx*/) override { }

  virtual void enterParameter(DecafParser::ParameterContext * /*ctx*/) override { }
  virtual void exitParameter(DecafParser::ParameterContext * /*ctx*/) override { }

  virtual void enterParameterType(DecafParser::ParameterTypeContext * /*ctx*/) override { }
  virtual void exitParameterType(DecafParser::ParameterTypeContext * /*ctx*/) override { }

  virtual void enterBlock(DecafParser::BlockContext * /*ctx*/) override { }
  virtual void exitBlock(DecafParser::BlockContext * /*ctx*/) override { }

  virtual void enterSt_if(DecafParser::St_ifContext * /*ctx*/) override { }
  virtual void exitSt_if(DecafParser::St_ifContext * /*ctx*/) override { }

  virtual void enterSt_while(DecafParser::St_whileContext * /*ctx*/) override { }
  virtual void exitSt_while(DecafParser::St_whileContext * /*ctx*/) override { }

  virtual void enterSt_return(DecafParser::St_returnContext * /*ctx*/) override { }
  virtual void exitSt_return(DecafParser::St_returnContext * /*ctx*/) override { }

  virtual void enterSt_method_call(DecafParser::St_method_callContext * /*ctx*/) override { }
  virtual void exitSt_method_call(DecafParser::St_method_callContext * /*ctx*/) override { }

  virtual void enterSt_block(DecafParser::St_blockContext * /*ctx*/) override { }
  virtual void exitSt_block(DecafParser::St_blockContext * /*ctx*/) override { }

  virtual void enterSt_assignment(DecafParser::St_assignmentContext * /*ctx*/) override { }
  virtual void exitSt_assignment(DecafParser::St_assignmentContext * /*ctx*/) override { }

  virtual void enterSt_expression(DecafParser::St_expressionContext * /*ctx*/) override { }
  virtual void exitSt_expression(DecafParser::St_expressionContext * /*ctx*/) override { }

  virtual void enterLoc_var(DecafParser::Loc_varContext * /*ctx*/) override { }
  virtual void exitLoc_var(DecafParser::Loc_varContext * /*ctx*/) override { }

  virtual void enterLoc_array(DecafParser::Loc_arrayContext * /*ctx*/) override { }
  virtual void exitLoc_array(DecafParser::Loc_arrayContext * /*ctx*/) override { }

  virtual void enterExpr_literal(DecafParser::Expr_literalContext * /*ctx*/) override { }
  virtual void exitExpr_literal(DecafParser::Expr_literalContext * /*ctx*/) override { }

  virtual void enterExpr_loc(DecafParser::Expr_locContext * /*ctx*/) override { }
  virtual void exitExpr_loc(DecafParser::Expr_locContext * /*ctx*/) override { }

  virtual void enterExpr_neg(DecafParser::Expr_negContext * /*ctx*/) override { }
  virtual void exitExpr_neg(DecafParser::Expr_negContext * /*ctx*/) override { }

  virtual void enterExpr_par(DecafParser::Expr_parContext * /*ctx*/) override { }
  virtual void exitExpr_par(DecafParser::Expr_parContext * /*ctx*/) override { }

  virtual void enterExpr_arith_1(DecafParser::Expr_arith_1Context * /*ctx*/) override { }
  virtual void exitExpr_arith_1(DecafParser::Expr_arith_1Context * /*ctx*/) override { }

  virtual void enterExpr_arith_0(DecafParser::Expr_arith_0Context * /*ctx*/) override { }
  virtual void exitExpr_arith_0(DecafParser::Expr_arith_0Context * /*ctx*/) override { }

  virtual void enterExpr_cond(DecafParser::Expr_condContext * /*ctx*/) override { }
  virtual void exitExpr_cond(DecafParser::Expr_condContext * /*ctx*/) override { }

  virtual void enterExpr_method_call(DecafParser::Expr_method_callContext * /*ctx*/) override { }
  virtual void exitExpr_method_call(DecafParser::Expr_method_callContext * /*ctx*/) override { }

  virtual void enterExpr_rel(DecafParser::Expr_relContext * /*ctx*/) override { }
  virtual void exitExpr_rel(DecafParser::Expr_relContext * /*ctx*/) override { }

  virtual void enterExpr_eq(DecafParser::Expr_eqContext * /*ctx*/) override { }
  virtual void exitExpr_eq(DecafParser::Expr_eqContext * /*ctx*/) override { }

  virtual void enterExpr_not(DecafParser::Expr_notContext * /*ctx*/) override { }
  virtual void exitExpr_not(DecafParser::Expr_notContext * /*ctx*/) override { }

  virtual void enterMethodCall(DecafParser::MethodCallContext * /*ctx*/) override { }
  virtual void exitMethodCall(DecafParser::MethodCallContext * /*ctx*/) override { }

  virtual void enterArith_op(DecafParser::Arith_opContext * /*ctx*/) override { }
  virtual void exitArith_op(DecafParser::Arith_opContext * /*ctx*/) override { }

  virtual void enterRel_op(DecafParser::Rel_opContext * /*ctx*/) override { }
  virtual void exitRel_op(DecafParser::Rel_opContext * /*ctx*/) override { }

  virtual void enterEq_op(DecafParser::Eq_opContext * /*ctx*/) override { }
  virtual void exitEq_op(DecafParser::Eq_opContext * /*ctx*/) override { }

  virtual void enterCond_op(DecafParser::Cond_opContext * /*ctx*/) override { }
  virtual void exitCond_op(DecafParser::Cond_opContext * /*ctx*/) override { }

  virtual void enterLiteral(DecafParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(DecafParser::LiteralContext * /*ctx*/) override { }

  virtual void enterInt_literal(DecafParser::Int_literalContext * /*ctx*/) override { }
  virtual void exitInt_literal(DecafParser::Int_literalContext * /*ctx*/) override { }

  virtual void enterChar_literal(DecafParser::Char_literalContext * /*ctx*/) override { }
  virtual void exitChar_literal(DecafParser::Char_literalContext * /*ctx*/) override { }

  virtual void enterBool_literal(DecafParser::Bool_literalContext * /*ctx*/) override { }
  virtual void exitBool_literal(DecafParser::Bool_literalContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

