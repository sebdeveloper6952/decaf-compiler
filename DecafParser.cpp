
// Generated from Decaf.g4 by ANTLR 4.7.2


#include "DecafListener.h"
#include "DecafVisitor.h"

#include "DecafParser.h"


using namespace antlrcpp;
using namespace antlr4;

DecafParser::DecafParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

DecafParser::~DecafParser() {
  delete _interpreter;
}

std::string DecafParser::getGrammarFileName() const {
  return "Decaf.g4";
}

const std::vector<std::string>& DecafParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& DecafParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

DecafParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DecafParser::ProgramContext::CLASS() {
  return getToken(DecafParser::CLASS, 0);
}

tree::TerminalNode* DecafParser::ProgramContext::PROGRAM() {
  return getToken(DecafParser::PROGRAM, 0);
}

tree::TerminalNode* DecafParser::ProgramContext::EOF() {
  return getToken(DecafParser::EOF, 0);
}

std::vector<DecafParser::DeclarationContext *> DecafParser::ProgramContext::declaration() {
  return getRuleContexts<DecafParser::DeclarationContext>();
}

DecafParser::DeclarationContext* DecafParser::ProgramContext::declaration(size_t i) {
  return getRuleContext<DecafParser::DeclarationContext>(i);
}


size_t DecafParser::ProgramContext::getRuleIndex() const {
  return DecafParser::RuleProgram;
}

void DecafParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void DecafParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


antlrcpp::Any DecafParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::ProgramContext* DecafParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, DecafParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(44);
    match(DecafParser::CLASS);
    setState(45);
    match(DecafParser::PROGRAM);
    setState(46);
    match(DecafParser::T__0);
    setState(50);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__5)
      | (1ULL << DecafParser::T__6)
      | (1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::STRUCT)
      | (1ULL << DecafParser::VOID))) != 0)) {
      setState(47);
      declaration();
      setState(52);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(53);
    match(DecafParser::T__1);
    setState(54);
    match(DecafParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

DecafParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::StructDeclarationContext* DecafParser::DeclarationContext::structDeclaration() {
  return getRuleContext<DecafParser::StructDeclarationContext>(0);
}

DecafParser::VarDeclarationContext* DecafParser::DeclarationContext::varDeclaration() {
  return getRuleContext<DecafParser::VarDeclarationContext>(0);
}

DecafParser::MethodDeclarationContext* DecafParser::DeclarationContext::methodDeclaration() {
  return getRuleContext<DecafParser::MethodDeclarationContext>(0);
}


size_t DecafParser::DeclarationContext::getRuleIndex() const {
  return DecafParser::RuleDeclaration;
}

void DecafParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void DecafParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any DecafParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::DeclarationContext* DecafParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, DecafParser::RuleDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(59);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(56);
      structDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(57);
      varDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(58);
      methodDeclaration();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclarationContext ------------------------------------------------------------------

DecafParser::VarDeclarationContext::VarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::VarDeclarationContext::getRuleIndex() const {
  return DecafParser::RuleVarDeclaration;
}

void DecafParser::VarDeclarationContext::copyFrom(VarDeclarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Var_struct_declContext ------------------------------------------------------------------

tree::TerminalNode* DecafParser::Var_struct_declContext::STRUCT() {
  return getToken(DecafParser::STRUCT, 0);
}

std::vector<tree::TerminalNode *> DecafParser::Var_struct_declContext::ID() {
  return getTokens(DecafParser::ID);
}

tree::TerminalNode* DecafParser::Var_struct_declContext::ID(size_t i) {
  return getToken(DecafParser::ID, i);
}

DecafParser::Var_struct_declContext::Var_struct_declContext(VarDeclarationContext *ctx) { copyFrom(ctx); }

void DecafParser::Var_struct_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_struct_decl(this);
}
void DecafParser::Var_struct_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_struct_decl(this);
}

antlrcpp::Any DecafParser::Var_struct_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitVar_struct_decl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Var_declContext ------------------------------------------------------------------

DecafParser::VarTypeContext* DecafParser::Var_declContext::varType() {
  return getRuleContext<DecafParser::VarTypeContext>(0);
}

tree::TerminalNode* DecafParser::Var_declContext::ID() {
  return getToken(DecafParser::ID, 0);
}

DecafParser::Var_declContext::Var_declContext(VarDeclarationContext *ctx) { copyFrom(ctx); }

void DecafParser::Var_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_decl(this);
}
void DecafParser::Var_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_decl(this);
}

antlrcpp::Any DecafParser::Var_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitVar_decl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Var_arr_declContext ------------------------------------------------------------------

DecafParser::VarTypeContext* DecafParser::Var_arr_declContext::varType() {
  return getRuleContext<DecafParser::VarTypeContext>(0);
}

tree::TerminalNode* DecafParser::Var_arr_declContext::ID() {
  return getToken(DecafParser::ID, 0);
}

tree::TerminalNode* DecafParser::Var_arr_declContext::NUM() {
  return getToken(DecafParser::NUM, 0);
}

DecafParser::Var_arr_declContext::Var_arr_declContext(VarDeclarationContext *ctx) { copyFrom(ctx); }

void DecafParser::Var_arr_declContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_arr_decl(this);
}
void DecafParser::Var_arr_declContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_arr_decl(this);
}

antlrcpp::Any DecafParser::Var_arr_declContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitVar_arr_decl(this);
  else
    return visitor->visitChildren(this);
}
DecafParser::VarDeclarationContext* DecafParser::varDeclaration() {
  VarDeclarationContext *_localctx = _tracker.createInstance<VarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 4, DecafParser::RuleVarDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(76);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarDeclarationContext *>(_tracker.createInstance<DecafParser::Var_declContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(61);
      varType();
      setState(62);
      match(DecafParser::ID);
      setState(63);
      match(DecafParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarDeclarationContext *>(_tracker.createInstance<DecafParser::Var_arr_declContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(65);
      varType();
      setState(66);
      match(DecafParser::ID);
      setState(67);
      match(DecafParser::T__3);
      setState(68);
      match(DecafParser::NUM);
      setState(69);
      match(DecafParser::T__4);
      setState(70);
      match(DecafParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<VarDeclarationContext *>(_tracker.createInstance<DecafParser::Var_struct_declContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(72);
      match(DecafParser::STRUCT);
      setState(73);
      match(DecafParser::ID);
      setState(74);
      match(DecafParser::ID);
      setState(75);
      match(DecafParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclarationContext ------------------------------------------------------------------

DecafParser::StructDeclarationContext::StructDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DecafParser::StructDeclarationContext::STRUCT() {
  return getToken(DecafParser::STRUCT, 0);
}

tree::TerminalNode* DecafParser::StructDeclarationContext::ID() {
  return getToken(DecafParser::ID, 0);
}

std::vector<DecafParser::VarDeclarationContext *> DecafParser::StructDeclarationContext::varDeclaration() {
  return getRuleContexts<DecafParser::VarDeclarationContext>();
}

DecafParser::VarDeclarationContext* DecafParser::StructDeclarationContext::varDeclaration(size_t i) {
  return getRuleContext<DecafParser::VarDeclarationContext>(i);
}


size_t DecafParser::StructDeclarationContext::getRuleIndex() const {
  return DecafParser::RuleStructDeclaration;
}

void DecafParser::StructDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclaration(this);
}

void DecafParser::StructDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclaration(this);
}


antlrcpp::Any DecafParser::StructDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitStructDeclaration(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::StructDeclarationContext* DecafParser::structDeclaration() {
  StructDeclarationContext *_localctx = _tracker.createInstance<StructDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 6, DecafParser::RuleStructDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    match(DecafParser::STRUCT);
    setState(79);
    match(DecafParser::ID);
    setState(80);
    match(DecafParser::T__0);
    setState(84);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__5)
      | (1ULL << DecafParser::T__6)
      | (1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::STRUCT)
      | (1ULL << DecafParser::VOID))) != 0)) {
      setState(81);
      varDeclaration();
      setState(86);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(87);
    match(DecafParser::T__1);
    setState(88);
    match(DecafParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarTypeContext ------------------------------------------------------------------

DecafParser::VarTypeContext::VarTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DecafParser::VarTypeContext::VOID() {
  return getToken(DecafParser::VOID, 0);
}


size_t DecafParser::VarTypeContext::getRuleIndex() const {
  return DecafParser::RuleVarType;
}

void DecafParser::VarTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarType(this);
}

void DecafParser::VarTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarType(this);
}


antlrcpp::Any DecafParser::VarTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitVarType(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::VarTypeContext* DecafParser::varType() {
  VarTypeContext *_localctx = _tracker.createInstance<VarTypeContext>(_ctx, getState());
  enterRule(_localctx, 8, DecafParser::RuleVarType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__5)
      | (1ULL << DecafParser::T__6)
      | (1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::VOID))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodTypeContext ------------------------------------------------------------------

DecafParser::MethodTypeContext::MethodTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DecafParser::MethodTypeContext::VOID() {
  return getToken(DecafParser::VOID, 0);
}


size_t DecafParser::MethodTypeContext::getRuleIndex() const {
  return DecafParser::RuleMethodType;
}

void DecafParser::MethodTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodType(this);
}

void DecafParser::MethodTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodType(this);
}


antlrcpp::Any DecafParser::MethodTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitMethodType(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::MethodTypeContext* DecafParser::methodType() {
  MethodTypeContext *_localctx = _tracker.createInstance<MethodTypeContext>(_ctx, getState());
  enterRule(_localctx, 10, DecafParser::RuleMethodType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(92);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__5)
      | (1ULL << DecafParser::T__6)
      | (1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::VOID))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodDeclarationContext ------------------------------------------------------------------

DecafParser::MethodDeclarationContext::MethodDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::MethodTypeContext* DecafParser::MethodDeclarationContext::methodType() {
  return getRuleContext<DecafParser::MethodTypeContext>(0);
}

tree::TerminalNode* DecafParser::MethodDeclarationContext::ID() {
  return getToken(DecafParser::ID, 0);
}

DecafParser::BlockContext* DecafParser::MethodDeclarationContext::block() {
  return getRuleContext<DecafParser::BlockContext>(0);
}

std::vector<DecafParser::ParameterContext *> DecafParser::MethodDeclarationContext::parameter() {
  return getRuleContexts<DecafParser::ParameterContext>();
}

DecafParser::ParameterContext* DecafParser::MethodDeclarationContext::parameter(size_t i) {
  return getRuleContext<DecafParser::ParameterContext>(i);
}


size_t DecafParser::MethodDeclarationContext::getRuleIndex() const {
  return DecafParser::RuleMethodDeclaration;
}

void DecafParser::MethodDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodDeclaration(this);
}

void DecafParser::MethodDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodDeclaration(this);
}


antlrcpp::Any DecafParser::MethodDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitMethodDeclaration(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::MethodDeclarationContext* DecafParser::methodDeclaration() {
  MethodDeclarationContext *_localctx = _tracker.createInstance<MethodDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 12, DecafParser::RuleMethodDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(94);
    methodType();
    setState(95);
    match(DecafParser::ID);
    setState(96);
    match(DecafParser::T__8);
    setState(105);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__5)
      | (1ULL << DecafParser::T__6)
      | (1ULL << DecafParser::T__7))) != 0)) {
      setState(97);
      parameter();
      setState(102);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DecafParser::T__9) {
        setState(98);
        match(DecafParser::T__9);
        setState(99);
        parameter();
        setState(104);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(107);
    match(DecafParser::T__10);
    setState(108);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

DecafParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::ParameterTypeContext* DecafParser::ParameterContext::parameterType() {
  return getRuleContext<DecafParser::ParameterTypeContext>(0);
}

tree::TerminalNode* DecafParser::ParameterContext::ID() {
  return getToken(DecafParser::ID, 0);
}


size_t DecafParser::ParameterContext::getRuleIndex() const {
  return DecafParser::RuleParameter;
}

void DecafParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void DecafParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}


antlrcpp::Any DecafParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::ParameterContext* DecafParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 14, DecafParser::RuleParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    parameterType();
    setState(111);
    match(DecafParser::ID);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterTypeContext ------------------------------------------------------------------

DecafParser::ParameterTypeContext::ParameterTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::ParameterTypeContext::getRuleIndex() const {
  return DecafParser::RuleParameterType;
}

void DecafParser::ParameterTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterType(this);
}

void DecafParser::ParameterTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterType(this);
}


antlrcpp::Any DecafParser::ParameterTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitParameterType(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::ParameterTypeContext* DecafParser::parameterType() {
  ParameterTypeContext *_localctx = _tracker.createInstance<ParameterTypeContext>(_ctx, getState());
  enterRule(_localctx, 16, DecafParser::RuleParameterType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(113);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__5)
      | (1ULL << DecafParser::T__6)
      | (1ULL << DecafParser::T__7))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

DecafParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DecafParser::VarDeclarationContext *> DecafParser::BlockContext::varDeclaration() {
  return getRuleContexts<DecafParser::VarDeclarationContext>();
}

DecafParser::VarDeclarationContext* DecafParser::BlockContext::varDeclaration(size_t i) {
  return getRuleContext<DecafParser::VarDeclarationContext>(i);
}

std::vector<DecafParser::StatementContext *> DecafParser::BlockContext::statement() {
  return getRuleContexts<DecafParser::StatementContext>();
}

DecafParser::StatementContext* DecafParser::BlockContext::statement(size_t i) {
  return getRuleContext<DecafParser::StatementContext>(i);
}


size_t DecafParser::BlockContext::getRuleIndex() const {
  return DecafParser::RuleBlock;
}

void DecafParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void DecafParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}


antlrcpp::Any DecafParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::BlockContext* DecafParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 18, DecafParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    match(DecafParser::T__0);
    setState(119);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__5)
      | (1ULL << DecafParser::T__6)
      | (1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::STRUCT)
      | (1ULL << DecafParser::VOID))) != 0)) {
      setState(116);
      varDeclaration();
      setState(121);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(125);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__0)
      | (1ULL << DecafParser::T__2)
      | (1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__11)
      | (1ULL << DecafParser::T__12)
      | (1ULL << DecafParser::T__19)
      | (1ULL << DecafParser::T__20)
      | (1ULL << DecafParser::TRUE)
      | (1ULL << DecafParser::FALSE)
      | (1ULL << DecafParser::IF)
      | (1ULL << DecafParser::ID)
      | (1ULL << DecafParser::NUM)
      | (1ULL << DecafParser::APOSTROPHE))) != 0)) {
      setState(122);
      statement();
      setState(127);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(128);
    match(DecafParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

DecafParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::StatementContext::getRuleIndex() const {
  return DecafParser::RuleStatement;
}

void DecafParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- St_ifContext ------------------------------------------------------------------

tree::TerminalNode* DecafParser::St_ifContext::IF() {
  return getToken(DecafParser::IF, 0);
}

DecafParser::ExpressionContext* DecafParser::St_ifContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

std::vector<DecafParser::BlockContext *> DecafParser::St_ifContext::block() {
  return getRuleContexts<DecafParser::BlockContext>();
}

DecafParser::BlockContext* DecafParser::St_ifContext::block(size_t i) {
  return getRuleContext<DecafParser::BlockContext>(i);
}

tree::TerminalNode* DecafParser::St_ifContext::ELSE() {
  return getToken(DecafParser::ELSE, 0);
}

DecafParser::St_ifContext::St_ifContext(StatementContext *ctx) { copyFrom(ctx); }

void DecafParser::St_ifContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSt_if(this);
}
void DecafParser::St_ifContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSt_if(this);
}

antlrcpp::Any DecafParser::St_ifContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitSt_if(this);
  else
    return visitor->visitChildren(this);
}
//----------------- St_blockContext ------------------------------------------------------------------

DecafParser::BlockContext* DecafParser::St_blockContext::block() {
  return getRuleContext<DecafParser::BlockContext>(0);
}

DecafParser::St_blockContext::St_blockContext(StatementContext *ctx) { copyFrom(ctx); }

void DecafParser::St_blockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSt_block(this);
}
void DecafParser::St_blockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSt_block(this);
}

antlrcpp::Any DecafParser::St_blockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitSt_block(this);
  else
    return visitor->visitChildren(this);
}
//----------------- St_expressionContext ------------------------------------------------------------------

DecafParser::ExpressionContext* DecafParser::St_expressionContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::St_expressionContext::St_expressionContext(StatementContext *ctx) { copyFrom(ctx); }

void DecafParser::St_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSt_expression(this);
}
void DecafParser::St_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSt_expression(this);
}

antlrcpp::Any DecafParser::St_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitSt_expression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- St_whileContext ------------------------------------------------------------------

DecafParser::ExpressionContext* DecafParser::St_whileContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::BlockContext* DecafParser::St_whileContext::block() {
  return getRuleContext<DecafParser::BlockContext>(0);
}

DecafParser::St_whileContext::St_whileContext(StatementContext *ctx) { copyFrom(ctx); }

void DecafParser::St_whileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSt_while(this);
}
void DecafParser::St_whileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSt_while(this);
}

antlrcpp::Any DecafParser::St_whileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitSt_while(this);
  else
    return visitor->visitChildren(this);
}
//----------------- St_returnContext ------------------------------------------------------------------

DecafParser::ExpressionContext* DecafParser::St_returnContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::St_returnContext::St_returnContext(StatementContext *ctx) { copyFrom(ctx); }

void DecafParser::St_returnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSt_return(this);
}
void DecafParser::St_returnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSt_return(this);
}

antlrcpp::Any DecafParser::St_returnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitSt_return(this);
  else
    return visitor->visitChildren(this);
}
//----------------- St_method_callContext ------------------------------------------------------------------

DecafParser::MethodCallContext* DecafParser::St_method_callContext::methodCall() {
  return getRuleContext<DecafParser::MethodCallContext>(0);
}

DecafParser::St_method_callContext::St_method_callContext(StatementContext *ctx) { copyFrom(ctx); }

void DecafParser::St_method_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSt_method_call(this);
}
void DecafParser::St_method_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSt_method_call(this);
}

antlrcpp::Any DecafParser::St_method_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitSt_method_call(this);
  else
    return visitor->visitChildren(this);
}
//----------------- St_assignmentContext ------------------------------------------------------------------

DecafParser::LocationContext* DecafParser::St_assignmentContext::location() {
  return getRuleContext<DecafParser::LocationContext>(0);
}

DecafParser::ExpressionContext* DecafParser::St_assignmentContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::St_assignmentContext::St_assignmentContext(StatementContext *ctx) { copyFrom(ctx); }

void DecafParser::St_assignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSt_assignment(this);
}
void DecafParser::St_assignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSt_assignment(this);
}

antlrcpp::Any DecafParser::St_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitSt_assignment(this);
  else
    return visitor->visitChildren(this);
}
DecafParser::StatementContext* DecafParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 20, DecafParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::St_ifContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(130);
      match(DecafParser::IF);
      setState(131);
      match(DecafParser::T__8);
      setState(132);
      expression(0);
      setState(133);
      match(DecafParser::T__10);
      setState(134);
      block();
      setState(137);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DecafParser::ELSE) {
        setState(135);
        match(DecafParser::ELSE);
        setState(136);
        block();
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::St_whileContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(139);
      match(DecafParser::T__11);
      setState(140);
      match(DecafParser::T__8);
      setState(141);
      expression(0);
      setState(142);
      match(DecafParser::T__10);
      setState(143);
      block();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::St_returnContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(145);
      match(DecafParser::T__12);
      setState(147);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << DecafParser::T__8)
        | (1ULL << DecafParser::T__19)
        | (1ULL << DecafParser::T__20)
        | (1ULL << DecafParser::TRUE)
        | (1ULL << DecafParser::FALSE)
        | (1ULL << DecafParser::ID)
        | (1ULL << DecafParser::NUM)
        | (1ULL << DecafParser::APOSTROPHE))) != 0)) {
        setState(146);
        expression(0);
      }
      setState(149);
      match(DecafParser::T__2);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::St_method_callContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(150);
      methodCall();
      setState(151);
      match(DecafParser::T__2);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::St_blockContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(153);
      block();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::St_assignmentContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(154);
      location();
      setState(155);
      match(DecafParser::T__13);
      setState(156);
      expression(0);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::St_expressionContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(159);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << DecafParser::T__8)
        | (1ULL << DecafParser::T__19)
        | (1ULL << DecafParser::T__20)
        | (1ULL << DecafParser::TRUE)
        | (1ULL << DecafParser::FALSE)
        | (1ULL << DecafParser::ID)
        | (1ULL << DecafParser::NUM)
        | (1ULL << DecafParser::APOSTROPHE))) != 0)) {
        setState(158);
        expression(0);
      }
      setState(161);
      match(DecafParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LocationContext ------------------------------------------------------------------

DecafParser::LocationContext::LocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::LocationContext::getRuleIndex() const {
  return DecafParser::RuleLocation;
}

void DecafParser::LocationContext::copyFrom(LocationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Loc_varContext ------------------------------------------------------------------

tree::TerminalNode* DecafParser::Loc_varContext::ID() {
  return getToken(DecafParser::ID, 0);
}

DecafParser::Loc_varContext::Loc_varContext(LocationContext *ctx) { copyFrom(ctx); }

void DecafParser::Loc_varContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoc_var(this);
}
void DecafParser::Loc_varContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoc_var(this);
}

antlrcpp::Any DecafParser::Loc_varContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitLoc_var(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Loc_memberContext ------------------------------------------------------------------

tree::TerminalNode* DecafParser::Loc_memberContext::ID() {
  return getToken(DecafParser::ID, 0);
}

DecafParser::LocationContext* DecafParser::Loc_memberContext::location() {
  return getRuleContext<DecafParser::LocationContext>(0);
}

DecafParser::Loc_memberContext::Loc_memberContext(LocationContext *ctx) { copyFrom(ctx); }

void DecafParser::Loc_memberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoc_member(this);
}
void DecafParser::Loc_memberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoc_member(this);
}

antlrcpp::Any DecafParser::Loc_memberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitLoc_member(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Loc_arrayContext ------------------------------------------------------------------

tree::TerminalNode* DecafParser::Loc_arrayContext::ID() {
  return getToken(DecafParser::ID, 0);
}

DecafParser::ExpressionContext* DecafParser::Loc_arrayContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::Loc_arrayContext::Loc_arrayContext(LocationContext *ctx) { copyFrom(ctx); }

void DecafParser::Loc_arrayContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoc_array(this);
}
void DecafParser::Loc_arrayContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoc_array(this);
}

antlrcpp::Any DecafParser::Loc_arrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitLoc_array(this);
  else
    return visitor->visitChildren(this);
}
DecafParser::LocationContext* DecafParser::location() {
  LocationContext *_localctx = _tracker.createInstance<LocationContext>(_ctx, getState());
  enterRule(_localctx, 22, DecafParser::RuleLocation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(173);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<LocationContext *>(_tracker.createInstance<DecafParser::Loc_varContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(164);
      match(DecafParser::ID);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<LocationContext *>(_tracker.createInstance<DecafParser::Loc_arrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(165);
      match(DecafParser::ID);
      setState(166);
      match(DecafParser::T__3);
      setState(167);
      expression(0);
      setState(168);
      match(DecafParser::T__4);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<LocationContext *>(_tracker.createInstance<DecafParser::Loc_memberContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(170);
      match(DecafParser::ID);
      setState(171);
      match(DecafParser::T__14);
      setState(172);
      location();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

DecafParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::ExpressionContext::getRuleIndex() const {
  return DecafParser::RuleExpression;
}

void DecafParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- Expr_literalContext ------------------------------------------------------------------

DecafParser::LiteralContext* DecafParser::Expr_literalContext::literal() {
  return getRuleContext<DecafParser::LiteralContext>(0);
}

DecafParser::Expr_literalContext::Expr_literalContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::Expr_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_literal(this);
}
void DecafParser::Expr_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_literal(this);
}

antlrcpp::Any DecafParser::Expr_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitExpr_literal(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_locContext ------------------------------------------------------------------

DecafParser::LocationContext* DecafParser::Expr_locContext::location() {
  return getRuleContext<DecafParser::LocationContext>(0);
}

DecafParser::Expr_locContext::Expr_locContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::Expr_locContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_loc(this);
}
void DecafParser::Expr_locContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_loc(this);
}

antlrcpp::Any DecafParser::Expr_locContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitExpr_loc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_negContext ------------------------------------------------------------------

DecafParser::ExpressionContext* DecafParser::Expr_negContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::Expr_negContext::Expr_negContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::Expr_negContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_neg(this);
}
void DecafParser::Expr_negContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_neg(this);
}

antlrcpp::Any DecafParser::Expr_negContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitExpr_neg(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_parContext ------------------------------------------------------------------

DecafParser::ExpressionContext* DecafParser::Expr_parContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::Expr_parContext::Expr_parContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::Expr_parContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_par(this);
}
void DecafParser::Expr_parContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_par(this);
}

antlrcpp::Any DecafParser::Expr_parContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitExpr_par(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_arith_1Context ------------------------------------------------------------------

std::vector<DecafParser::ExpressionContext *> DecafParser::Expr_arith_1Context::expression() {
  return getRuleContexts<DecafParser::ExpressionContext>();
}

DecafParser::ExpressionContext* DecafParser::Expr_arith_1Context::expression(size_t i) {
  return getRuleContext<DecafParser::ExpressionContext>(i);
}

DecafParser::Expr_arith_1Context::Expr_arith_1Context(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::Expr_arith_1Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_arith_1(this);
}
void DecafParser::Expr_arith_1Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_arith_1(this);
}

antlrcpp::Any DecafParser::Expr_arith_1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitExpr_arith_1(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_arith_0Context ------------------------------------------------------------------

std::vector<DecafParser::ExpressionContext *> DecafParser::Expr_arith_0Context::expression() {
  return getRuleContexts<DecafParser::ExpressionContext>();
}

DecafParser::ExpressionContext* DecafParser::Expr_arith_0Context::expression(size_t i) {
  return getRuleContext<DecafParser::ExpressionContext>(i);
}

DecafParser::Expr_arith_0Context::Expr_arith_0Context(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::Expr_arith_0Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_arith_0(this);
}
void DecafParser::Expr_arith_0Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_arith_0(this);
}

antlrcpp::Any DecafParser::Expr_arith_0Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitExpr_arith_0(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_condContext ------------------------------------------------------------------

std::vector<DecafParser::ExpressionContext *> DecafParser::Expr_condContext::expression() {
  return getRuleContexts<DecafParser::ExpressionContext>();
}

DecafParser::ExpressionContext* DecafParser::Expr_condContext::expression(size_t i) {
  return getRuleContext<DecafParser::ExpressionContext>(i);
}

DecafParser::Cond_opContext* DecafParser::Expr_condContext::cond_op() {
  return getRuleContext<DecafParser::Cond_opContext>(0);
}

DecafParser::Expr_condContext::Expr_condContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::Expr_condContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_cond(this);
}
void DecafParser::Expr_condContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_cond(this);
}

antlrcpp::Any DecafParser::Expr_condContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitExpr_cond(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_method_callContext ------------------------------------------------------------------

DecafParser::MethodCallContext* DecafParser::Expr_method_callContext::methodCall() {
  return getRuleContext<DecafParser::MethodCallContext>(0);
}

DecafParser::Expr_method_callContext::Expr_method_callContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::Expr_method_callContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_method_call(this);
}
void DecafParser::Expr_method_callContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_method_call(this);
}

antlrcpp::Any DecafParser::Expr_method_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitExpr_method_call(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_relContext ------------------------------------------------------------------

std::vector<DecafParser::ExpressionContext *> DecafParser::Expr_relContext::expression() {
  return getRuleContexts<DecafParser::ExpressionContext>();
}

DecafParser::ExpressionContext* DecafParser::Expr_relContext::expression(size_t i) {
  return getRuleContext<DecafParser::ExpressionContext>(i);
}

DecafParser::Rel_opContext* DecafParser::Expr_relContext::rel_op() {
  return getRuleContext<DecafParser::Rel_opContext>(0);
}

DecafParser::Expr_relContext::Expr_relContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::Expr_relContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_rel(this);
}
void DecafParser::Expr_relContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_rel(this);
}

antlrcpp::Any DecafParser::Expr_relContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitExpr_rel(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_eqContext ------------------------------------------------------------------

std::vector<DecafParser::ExpressionContext *> DecafParser::Expr_eqContext::expression() {
  return getRuleContexts<DecafParser::ExpressionContext>();
}

DecafParser::ExpressionContext* DecafParser::Expr_eqContext::expression(size_t i) {
  return getRuleContext<DecafParser::ExpressionContext>(i);
}

DecafParser::Eq_opContext* DecafParser::Expr_eqContext::eq_op() {
  return getRuleContext<DecafParser::Eq_opContext>(0);
}

DecafParser::Expr_eqContext::Expr_eqContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::Expr_eqContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_eq(this);
}
void DecafParser::Expr_eqContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_eq(this);
}

antlrcpp::Any DecafParser::Expr_eqContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitExpr_eq(this);
  else
    return visitor->visitChildren(this);
}
//----------------- Expr_notContext ------------------------------------------------------------------

DecafParser::ExpressionContext* DecafParser::Expr_notContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::Expr_notContext::Expr_notContext(ExpressionContext *ctx) { copyFrom(ctx); }

void DecafParser::Expr_notContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr_not(this);
}
void DecafParser::Expr_notContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr_not(this);
}

antlrcpp::Any DecafParser::Expr_notContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitExpr_not(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::ExpressionContext* DecafParser::expression() {
   return expression(0);
}

DecafParser::ExpressionContext* DecafParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  DecafParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  DecafParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 24;
  enterRecursionRule(_localctx, 24, DecafParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(187);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Expr_locContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(176);
      location();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Expr_method_callContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(177);
      methodCall();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Expr_literalContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(178);
      literal();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Expr_negContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(179);
      match(DecafParser::T__19);
      setState(180);
      expression(3);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Expr_notContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(181);
      match(DecafParser::T__20);
      setState(182);
      expression(2);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<Expr_parContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(183);
      match(DecafParser::T__8);
      setState(184);
      expression(0);
      setState(185);
      match(DecafParser::T__10);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(209);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(207);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Expr_arith_0Context>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(189);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(190);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << DecafParser::T__15)
            | (1ULL << DecafParser::T__16)
            | (1ULL << DecafParser::T__17))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(191);
          expression(9);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Expr_arith_1Context>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(192);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(193);
          _la = _input->LA(1);
          if (!(_la == DecafParser::T__18

          || _la == DecafParser::T__19)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(194);
          expression(8);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Expr_relContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(195);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(196);
          rel_op();
          setState(197);
          expression(7);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Expr_eqContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(199);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(200);
          eq_op();
          setState(201);
          expression(6);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Expr_condContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(203);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(204);
          cond_op();
          setState(205);
          expression(5);
          break;
        }

        } 
      }
      setState(211);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MethodCallContext ------------------------------------------------------------------

DecafParser::MethodCallContext::MethodCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DecafParser::MethodCallContext::ID() {
  return getToken(DecafParser::ID, 0);
}

std::vector<DecafParser::ExpressionContext *> DecafParser::MethodCallContext::expression() {
  return getRuleContexts<DecafParser::ExpressionContext>();
}

DecafParser::ExpressionContext* DecafParser::MethodCallContext::expression(size_t i) {
  return getRuleContext<DecafParser::ExpressionContext>(i);
}


size_t DecafParser::MethodCallContext::getRuleIndex() const {
  return DecafParser::RuleMethodCall;
}

void DecafParser::MethodCallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodCall(this);
}

void DecafParser::MethodCallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodCall(this);
}


antlrcpp::Any DecafParser::MethodCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitMethodCall(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::MethodCallContext* DecafParser::methodCall() {
  MethodCallContext *_localctx = _tracker.createInstance<MethodCallContext>(_ctx, getState());
  enterRule(_localctx, 26, DecafParser::RuleMethodCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(212);
    match(DecafParser::ID);
    setState(213);
    match(DecafParser::T__8);
    setState(221);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__19)
      | (1ULL << DecafParser::T__20)
      | (1ULL << DecafParser::TRUE)
      | (1ULL << DecafParser::FALSE)
      | (1ULL << DecafParser::ID)
      | (1ULL << DecafParser::NUM)
      | (1ULL << DecafParser::APOSTROPHE))) != 0)) {
      setState(214);
      expression(0);
      setState(217);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DecafParser::T__9) {
        setState(215);
        match(DecafParser::T__9);
        setState(216);
        expression(0);
      }
      setState(223);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(224);
    match(DecafParser::T__10);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arith_opContext ------------------------------------------------------------------

DecafParser::Arith_opContext::Arith_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::Arith_opContext::getRuleIndex() const {
  return DecafParser::RuleArith_op;
}

void DecafParser::Arith_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArith_op(this);
}

void DecafParser::Arith_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArith_op(this);
}


antlrcpp::Any DecafParser::Arith_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitArith_op(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Arith_opContext* DecafParser::arith_op() {
  Arith_opContext *_localctx = _tracker.createInstance<Arith_opContext>(_ctx, getState());
  enterRule(_localctx, 28, DecafParser::RuleArith_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__15)
      | (1ULL << DecafParser::T__16)
      | (1ULL << DecafParser::T__17)
      | (1ULL << DecafParser::T__18)
      | (1ULL << DecafParser::T__19))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_opContext ------------------------------------------------------------------

DecafParser::Rel_opContext::Rel_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::Rel_opContext::getRuleIndex() const {
  return DecafParser::RuleRel_op;
}

void DecafParser::Rel_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_op(this);
}

void DecafParser::Rel_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_op(this);
}


antlrcpp::Any DecafParser::Rel_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitRel_op(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Rel_opContext* DecafParser::rel_op() {
  Rel_opContext *_localctx = _tracker.createInstance<Rel_opContext>(_ctx, getState());
  enterRule(_localctx, 30, DecafParser::RuleRel_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__21)
      | (1ULL << DecafParser::T__22)
      | (1ULL << DecafParser::T__23)
      | (1ULL << DecafParser::T__24))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Eq_opContext ------------------------------------------------------------------

DecafParser::Eq_opContext::Eq_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::Eq_opContext::getRuleIndex() const {
  return DecafParser::RuleEq_op;
}

void DecafParser::Eq_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEq_op(this);
}

void DecafParser::Eq_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEq_op(this);
}


antlrcpp::Any DecafParser::Eq_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitEq_op(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Eq_opContext* DecafParser::eq_op() {
  Eq_opContext *_localctx = _tracker.createInstance<Eq_opContext>(_ctx, getState());
  enterRule(_localctx, 32, DecafParser::RuleEq_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(230);
    _la = _input->LA(1);
    if (!(_la == DecafParser::T__25

    || _la == DecafParser::T__26)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Cond_opContext ------------------------------------------------------------------

DecafParser::Cond_opContext::Cond_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t DecafParser::Cond_opContext::getRuleIndex() const {
  return DecafParser::RuleCond_op;
}

void DecafParser::Cond_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCond_op(this);
}

void DecafParser::Cond_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCond_op(this);
}


antlrcpp::Any DecafParser::Cond_opContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitCond_op(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Cond_opContext* DecafParser::cond_op() {
  Cond_opContext *_localctx = _tracker.createInstance<Cond_opContext>(_ctx, getState());
  enterRule(_localctx, 34, DecafParser::RuleCond_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(232);
    _la = _input->LA(1);
    if (!(_la == DecafParser::T__27

    || _la == DecafParser::T__28)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

DecafParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DecafParser::Int_literalContext* DecafParser::LiteralContext::int_literal() {
  return getRuleContext<DecafParser::Int_literalContext>(0);
}

DecafParser::Char_literalContext* DecafParser::LiteralContext::char_literal() {
  return getRuleContext<DecafParser::Char_literalContext>(0);
}

DecafParser::Bool_literalContext* DecafParser::LiteralContext::bool_literal() {
  return getRuleContext<DecafParser::Bool_literalContext>(0);
}


size_t DecafParser::LiteralContext::getRuleIndex() const {
  return DecafParser::RuleLiteral;
}

void DecafParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void DecafParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}


antlrcpp::Any DecafParser::LiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitLiteral(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::LiteralContext* DecafParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 36, DecafParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(237);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::NUM: {
        enterOuterAlt(_localctx, 1);
        setState(234);
        int_literal();
        break;
      }

      case DecafParser::APOSTROPHE: {
        enterOuterAlt(_localctx, 2);
        setState(235);
        char_literal();
        break;
      }

      case DecafParser::TRUE:
      case DecafParser::FALSE: {
        enterOuterAlt(_localctx, 3);
        setState(236);
        bool_literal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Int_literalContext ------------------------------------------------------------------

DecafParser::Int_literalContext::Int_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DecafParser::Int_literalContext::NUM() {
  return getToken(DecafParser::NUM, 0);
}


size_t DecafParser::Int_literalContext::getRuleIndex() const {
  return DecafParser::RuleInt_literal;
}

void DecafParser::Int_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInt_literal(this);
}

void DecafParser::Int_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInt_literal(this);
}


antlrcpp::Any DecafParser::Int_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitInt_literal(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Int_literalContext* DecafParser::int_literal() {
  Int_literalContext *_localctx = _tracker.createInstance<Int_literalContext>(_ctx, getState());
  enterRule(_localctx, 38, DecafParser::RuleInt_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
    match(DecafParser::NUM);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Char_literalContext ------------------------------------------------------------------

DecafParser::Char_literalContext::Char_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DecafParser::Char_literalContext::APOSTROPHE() {
  return getTokens(DecafParser::APOSTROPHE);
}

tree::TerminalNode* DecafParser::Char_literalContext::APOSTROPHE(size_t i) {
  return getToken(DecafParser::APOSTROPHE, i);
}

tree::TerminalNode* DecafParser::Char_literalContext::CHAR() {
  return getToken(DecafParser::CHAR, 0);
}


size_t DecafParser::Char_literalContext::getRuleIndex() const {
  return DecafParser::RuleChar_literal;
}

void DecafParser::Char_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChar_literal(this);
}

void DecafParser::Char_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChar_literal(this);
}


antlrcpp::Any DecafParser::Char_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitChar_literal(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Char_literalContext* DecafParser::char_literal() {
  Char_literalContext *_localctx = _tracker.createInstance<Char_literalContext>(_ctx, getState());
  enterRule(_localctx, 40, DecafParser::RuleChar_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    match(DecafParser::APOSTROPHE);
    setState(242);
    match(DecafParser::CHAR);
    setState(243);
    match(DecafParser::APOSTROPHE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Bool_literalContext ------------------------------------------------------------------

DecafParser::Bool_literalContext::Bool_literalContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DecafParser::Bool_literalContext::TRUE() {
  return getToken(DecafParser::TRUE, 0);
}

tree::TerminalNode* DecafParser::Bool_literalContext::FALSE() {
  return getToken(DecafParser::FALSE, 0);
}


size_t DecafParser::Bool_literalContext::getRuleIndex() const {
  return DecafParser::RuleBool_literal;
}

void DecafParser::Bool_literalContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBool_literal(this);
}

void DecafParser::Bool_literalContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBool_literal(this);
}


antlrcpp::Any DecafParser::Bool_literalContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitBool_literal(this);
  else
    return visitor->visitChildren(this);
}

DecafParser::Bool_literalContext* DecafParser::bool_literal() {
  Bool_literalContext *_localctx = _tracker.createInstance<Bool_literalContext>(_ctx, getState());
  enterRule(_localctx, 42, DecafParser::RuleBool_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    _la = _input->LA(1);
    if (!(_la == DecafParser::TRUE

    || _la == DecafParser::FALSE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool DecafParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 12: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool DecafParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 8);
    case 1: return precpred(_ctx, 7);
    case 2: return precpred(_ctx, 6);
    case 3: return precpred(_ctx, 5);
    case 4: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> DecafParser::_decisionToDFA;
atn::PredictionContextCache DecafParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN DecafParser::_atn;
std::vector<uint16_t> DecafParser::_serializedATN;

std::vector<std::string> DecafParser::_ruleNames = {
  "program", "declaration", "varDeclaration", "structDeclaration", "varType", 
  "methodType", "methodDeclaration", "parameter", "parameterType", "block", 
  "statement", "location", "expression", "methodCall", "arith_op", "rel_op", 
  "eq_op", "cond_op", "literal", "int_literal", "char_literal", "bool_literal"
};

std::vector<std::string> DecafParser::_literalNames = {
  "", "'{'", "'}'", "';'", "'['", "']'", "'int'", "'char'", "'bool'", "'('", 
  "','", "')'", "'while'", "'return'", "'='", "'.'", "'*'", "'/'", "'%'", 
  "'+'", "'-'", "'!'", "'<'", "'>'", "'<='", "'>='", "'=='", "'!='", "'&&'", 
  "'||'", "'class'", "'Program'", "'struct'", "'true'", "'false'", "'if'", 
  "'else'", "'void'", "", "", "'''"
};

std::vector<std::string> DecafParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "CLASS", "PROGRAM", "STRUCT", 
  "TRUE", "FALSE", "IF", "ELSE", "VOID", "ID", "NUM", "APOSTROPHE", "CHAR", 
  "WHITESPACE"
};

dfa::Vocabulary DecafParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> DecafParser::_tokenNames;

DecafParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2c, 0xfa, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x3, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x33, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x36, 
    0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x3e, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x4f, 0xa, 0x4, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x55, 0xa, 0x5, 0xc, 0x5, 0xe, 
    0x5, 0x58, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x7, 0x8, 0x67, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x6a, 0xb, 0x8, 
    0x5, 0x8, 0x6c, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x78, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x7b, 0xb, 0xb, 0x3, 0xb, 0x7, 0xb, 0x7e, 
    0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x81, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 
    0xc, 0x8c, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x96, 0xa, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x5, 0xc, 0xa2, 0xa, 0xc, 0x3, 0xc, 0x5, 0xc, 0xa5, 0xa, 
    0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xb0, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xbe, 0xa, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xd2, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 
    0xd5, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
    0xf, 0xdc, 0xa, 0xf, 0x7, 0xf, 0xde, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 0xe1, 
    0xb, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x5, 0x14, 0xf0, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x2, 
    0x3, 0x1a, 0x18, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 
    0x2, 0xb, 0x4, 0x2, 0x8, 0xa, 0x27, 0x27, 0x3, 0x2, 0x8, 0xa, 0x3, 0x2, 
    0x12, 0x14, 0x3, 0x2, 0x15, 0x16, 0x3, 0x2, 0x12, 0x16, 0x3, 0x2, 0x18, 
    0x1b, 0x3, 0x2, 0x1c, 0x1d, 0x3, 0x2, 0x1e, 0x1f, 0x3, 0x2, 0x23, 0x24, 
    0x2, 0x106, 0x2, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x3d, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x8, 0x50, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x5c, 0x3, 0x2, 0x2, 0x2, 0xc, 0x5e, 0x3, 0x2, 0x2, 0x2, 0xe, 0x60, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0x70, 0x3, 0x2, 0x2, 0x2, 0x12, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x75, 0x3, 0x2, 0x2, 0x2, 0x16, 0xa4, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0xaf, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xbd, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0xd6, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xe4, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0xe6, 0x3, 0x2, 0x2, 0x2, 0x22, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0xea, 0x3, 0x2, 0x2, 0x2, 0x26, 0xef, 0x3, 0x2, 0x2, 0x2, 0x28, 0xf1, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0xf3, 0x3, 0x2, 0x2, 0x2, 0x2c, 0xf7, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x20, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x21, 
    0x2, 0x2, 0x30, 0x34, 0x7, 0x3, 0x2, 0x2, 0x31, 0x33, 0x5, 0x4, 0x3, 
    0x2, 0x32, 0x31, 0x3, 0x2, 0x2, 0x2, 0x33, 0x36, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 
    0x37, 0x3, 0x2, 0x2, 0x2, 0x36, 0x34, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 
    0x7, 0x4, 0x2, 0x2, 0x38, 0x39, 0x7, 0x2, 0x2, 0x3, 0x39, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x3a, 0x3e, 0x5, 0x8, 0x5, 0x2, 0x3b, 0x3e, 0x5, 0x6, 
    0x4, 0x2, 0x3c, 0x3e, 0x5, 0xe, 0x8, 0x2, 0x3d, 0x3a, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3c, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x40, 0x5, 0xa, 0x6, 0x2, 0x40, 
    0x41, 0x7, 0x28, 0x2, 0x2, 0x41, 0x42, 0x7, 0x5, 0x2, 0x2, 0x42, 0x4f, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x44, 0x5, 0xa, 0x6, 0x2, 0x44, 0x45, 0x7, 
    0x28, 0x2, 0x2, 0x45, 0x46, 0x7, 0x6, 0x2, 0x2, 0x46, 0x47, 0x7, 0x29, 
    0x2, 0x2, 0x47, 0x48, 0x7, 0x7, 0x2, 0x2, 0x48, 0x49, 0x7, 0x5, 0x2, 
    0x2, 0x49, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x22, 0x2, 0x2, 
    0x4b, 0x4c, 0x7, 0x28, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x28, 0x2, 0x2, 0x4d, 
    0x4f, 0x7, 0x5, 0x2, 0x2, 0x4e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x43, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x51, 0x7, 0x22, 0x2, 0x2, 0x51, 0x52, 0x7, 0x28, 
    0x2, 0x2, 0x52, 0x56, 0x7, 0x3, 0x2, 0x2, 0x53, 0x55, 0x5, 0x6, 0x4, 
    0x2, 0x54, 0x53, 0x3, 0x2, 0x2, 0x2, 0x55, 0x58, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x56, 0x57, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x59, 0x3, 0x2, 0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 
    0x7, 0x4, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x5, 0x2, 0x2, 0x5b, 0x9, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x5d, 0x9, 0x2, 0x2, 0x2, 0x5d, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x5f, 0x9, 0x2, 0x2, 0x2, 0x5f, 0xd, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x61, 0x5, 0xc, 0x7, 0x2, 0x61, 0x62, 0x7, 0x28, 0x2, 0x2, 
    0x62, 0x6b, 0x7, 0xb, 0x2, 0x2, 0x63, 0x68, 0x5, 0x10, 0x9, 0x2, 0x64, 
    0x65, 0x7, 0xc, 0x2, 0x2, 0x65, 0x67, 0x5, 0x10, 0x9, 0x2, 0x66, 0x64, 
    0x3, 0x2, 0x2, 0x2, 0x67, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x68, 0x66, 0x3, 
    0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6c, 0x3, 0x2, 
    0x2, 0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 0x2, 0x2, 0x2, 
    0x6d, 0x6e, 0x7, 0xd, 0x2, 0x2, 0x6e, 0x6f, 0x5, 0x14, 0xb, 0x2, 0x6f, 
    0xf, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x5, 0x12, 0xa, 0x2, 0x71, 0x72, 
    0x7, 0x28, 0x2, 0x2, 0x72, 0x11, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0x9, 
    0x3, 0x2, 0x2, 0x74, 0x13, 0x3, 0x2, 0x2, 0x2, 0x75, 0x79, 0x7, 0x3, 
    0x2, 0x2, 0x76, 0x78, 0x5, 0x6, 0x4, 0x2, 0x77, 0x76, 0x3, 0x2, 0x2, 
    0x2, 0x78, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 
    0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x7b, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7e, 0x5, 0x16, 0xc, 0x2, 0x7d, 0x7c, 
    0x3, 0x2, 0x2, 0x2, 0x7e, 0x81, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7d, 0x3, 
    0x2, 0x2, 0x2, 0x7f, 0x80, 0x3, 0x2, 0x2, 0x2, 0x80, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x7, 0x4, 0x2, 
    0x2, 0x83, 0x15, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0x25, 0x2, 0x2, 
    0x85, 0x86, 0x7, 0xb, 0x2, 0x2, 0x86, 0x87, 0x5, 0x1a, 0xe, 0x2, 0x87, 
    0x88, 0x7, 0xd, 0x2, 0x2, 0x88, 0x8b, 0x5, 0x14, 0xb, 0x2, 0x89, 0x8a, 
    0x7, 0x26, 0x2, 0x2, 0x8a, 0x8c, 0x5, 0x14, 0xb, 0x2, 0x8b, 0x89, 0x3, 
    0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0xa5, 0x3, 0x2, 
    0x2, 0x2, 0x8d, 0x8e, 0x7, 0xe, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0xb, 0x2, 
    0x2, 0x8f, 0x90, 0x5, 0x1a, 0xe, 0x2, 0x90, 0x91, 0x7, 0xd, 0x2, 0x2, 
    0x91, 0x92, 0x5, 0x14, 0xb, 0x2, 0x92, 0xa5, 0x3, 0x2, 0x2, 0x2, 0x93, 
    0x95, 0x7, 0xf, 0x2, 0x2, 0x94, 0x96, 0x5, 0x1a, 0xe, 0x2, 0x95, 0x94, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 
    0x2, 0x2, 0x2, 0x97, 0xa5, 0x7, 0x5, 0x2, 0x2, 0x98, 0x99, 0x5, 0x1c, 
    0xf, 0x2, 0x99, 0x9a, 0x7, 0x5, 0x2, 0x2, 0x9a, 0xa5, 0x3, 0x2, 0x2, 
    0x2, 0x9b, 0xa5, 0x5, 0x14, 0xb, 0x2, 0x9c, 0x9d, 0x5, 0x18, 0xd, 0x2, 
    0x9d, 0x9e, 0x7, 0x10, 0x2, 0x2, 0x9e, 0x9f, 0x5, 0x1a, 0xe, 0x2, 0x9f, 
    0xa5, 0x3, 0x2, 0x2, 0x2, 0xa0, 0xa2, 0x5, 0x1a, 0xe, 0x2, 0xa1, 0xa0, 
    0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa3, 0x3, 
    0x2, 0x2, 0x2, 0xa3, 0xa5, 0x7, 0x5, 0x2, 0x2, 0xa4, 0x84, 0x3, 0x2, 
    0x2, 0x2, 0xa4, 0x8d, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0x98, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x9b, 0x3, 0x2, 0x2, 0x2, 
    0xa4, 0x9c, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa5, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xb0, 0x7, 0x28, 0x2, 0x2, 0xa7, 0xa8, 
    0x7, 0x28, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x6, 0x2, 0x2, 0xa9, 0xaa, 0x5, 
    0x1a, 0xe, 0x2, 0xaa, 0xab, 0x7, 0x7, 0x2, 0x2, 0xab, 0xb0, 0x3, 0x2, 
    0x2, 0x2, 0xac, 0xad, 0x7, 0x28, 0x2, 0x2, 0xad, 0xae, 0x7, 0x11, 0x2, 
    0x2, 0xae, 0xb0, 0x5, 0x18, 0xd, 0x2, 0xaf, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0xaf, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xac, 0x3, 0x2, 0x2, 0x2, 0xb0, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb2, 0x8, 0xe, 0x1, 0x2, 0xb2, 0xbe, 
    0x5, 0x18, 0xd, 0x2, 0xb3, 0xbe, 0x5, 0x1c, 0xf, 0x2, 0xb4, 0xbe, 0x5, 
    0x26, 0x14, 0x2, 0xb5, 0xb6, 0x7, 0x16, 0x2, 0x2, 0xb6, 0xbe, 0x5, 0x1a, 
    0xe, 0x5, 0xb7, 0xb8, 0x7, 0x17, 0x2, 0x2, 0xb8, 0xbe, 0x5, 0x1a, 0xe, 
    0x4, 0xb9, 0xba, 0x7, 0xb, 0x2, 0x2, 0xba, 0xbb, 0x5, 0x1a, 0xe, 0x2, 
    0xbb, 0xbc, 0x7, 0xd, 0x2, 0x2, 0xbc, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xbd, 
    0xb1, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xb4, 
    0x3, 0x2, 0x2, 0x2, 0xbd, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xb7, 0x3, 
    0x2, 0x2, 0x2, 0xbd, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xd3, 0x3, 0x2, 
    0x2, 0x2, 0xbf, 0xc0, 0xc, 0xa, 0x2, 0x2, 0xc0, 0xc1, 0x9, 0x4, 0x2, 
    0x2, 0xc1, 0xd2, 0x5, 0x1a, 0xe, 0xb, 0xc2, 0xc3, 0xc, 0x9, 0x2, 0x2, 
    0xc3, 0xc4, 0x9, 0x5, 0x2, 0x2, 0xc4, 0xd2, 0x5, 0x1a, 0xe, 0xa, 0xc5, 
    0xc6, 0xc, 0x8, 0x2, 0x2, 0xc6, 0xc7, 0x5, 0x20, 0x11, 0x2, 0xc7, 0xc8, 
    0x5, 0x1a, 0xe, 0x9, 0xc8, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0xc, 
    0x7, 0x2, 0x2, 0xca, 0xcb, 0x5, 0x22, 0x12, 0x2, 0xcb, 0xcc, 0x5, 0x1a, 
    0xe, 0x8, 0xcc, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 0xc, 0x6, 0x2, 
    0x2, 0xce, 0xcf, 0x5, 0x24, 0x13, 0x2, 0xcf, 0xd0, 0x5, 0x1a, 0xe, 0x7, 
    0xd0, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xd1, 
    0xc2, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xc9, 
    0x3, 0x2, 0x2, 0x2, 0xd1, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd5, 0x3, 
    0x2, 0x2, 0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 
    0x2, 0x2, 0xd4, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 
    0x2, 0xd6, 0xd7, 0x7, 0x28, 0x2, 0x2, 0xd7, 0xdf, 0x7, 0xb, 0x2, 0x2, 
    0xd8, 0xdb, 0x5, 0x1a, 0xe, 0x2, 0xd9, 0xda, 0x7, 0xc, 0x2, 0x2, 0xda, 
    0xdc, 0x5, 0x1a, 0xe, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 
    0x3, 0x2, 0x2, 0x2, 0xdc, 0xde, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xd8, 0x3, 
    0x2, 0x2, 0x2, 0xde, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xdd, 0x3, 0x2, 
    0x2, 0x2, 0xdf, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe2, 0x3, 0x2, 0x2, 
    0x2, 0xe1, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x7, 0xd, 0x2, 0x2, 
    0xe3, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x9, 0x6, 0x2, 0x2, 0xe5, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x9, 0x7, 0x2, 0x2, 0xe7, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x9, 0x8, 0x2, 0x2, 0xe9, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0xea, 0xeb, 0x9, 0x9, 0x2, 0x2, 0xeb, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0xec, 0xf0, 0x5, 0x28, 0x15, 0x2, 0xed, 0xf0, 0x5, 0x2a, 0x16, 
    0x2, 0xee, 0xf0, 0x5, 0x2c, 0x17, 0x2, 0xef, 0xec, 0x3, 0x2, 0x2, 0x2, 
    0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf0, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x7, 0x29, 0x2, 0x2, 0xf2, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x7, 0x2a, 0x2, 0x2, 0xf4, 0xf5, 0x7, 
    0x2b, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0x2a, 0x2, 0x2, 0xf6, 0x2b, 0x3, 0x2, 
    0x2, 0x2, 0xf7, 0xf8, 0x9, 0xa, 0x2, 0x2, 0xf8, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0x15, 0x34, 0x3d, 0x4e, 0x56, 0x68, 0x6b, 0x79, 0x7f, 0x8b, 0x95, 
    0xa1, 0xa4, 0xaf, 0xbd, 0xd1, 0xd3, 0xdb, 0xdf, 0xef, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

DecafParser::Initializer DecafParser::_init;
