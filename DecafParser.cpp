
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
    setState(42);
    match(DecafParser::CLASS);
    setState(43);
    match(DecafParser::PROGRAM);
    setState(44);
    match(DecafParser::T__0);
    setState(48);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__5)
      | (1ULL << DecafParser::T__6)
      | (1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::STRUCT)
      | (1ULL << DecafParser::VOID))) != 0)) {
      setState(45);
      declaration();
      setState(50);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(51);
    match(DecafParser::T__1);
    setState(52);
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
    setState(57);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(54);
      structDeclaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(55);
      varDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(56);
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

tree::TerminalNode* DecafParser::Var_struct_declContext::NUM() {
  return getToken(DecafParser::NUM, 0);
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
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(79);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarDeclarationContext *>(_tracker.createInstance<DecafParser::Var_declContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(59);
      varType();
      setState(60);
      match(DecafParser::ID);
      setState(61);
      match(DecafParser::T__2);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarDeclarationContext *>(_tracker.createInstance<DecafParser::Var_arr_declContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(63);
      varType();
      setState(64);
      match(DecafParser::ID);
      setState(65);
      match(DecafParser::T__3);
      setState(66);
      match(DecafParser::NUM);
      setState(67);
      match(DecafParser::T__4);
      setState(68);
      match(DecafParser::T__2);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<VarDeclarationContext *>(_tracker.createInstance<DecafParser::Var_struct_declContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(70);
      match(DecafParser::STRUCT);
      setState(71);
      match(DecafParser::ID);
      setState(72);
      match(DecafParser::ID);
      setState(76);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DecafParser::T__3) {
        setState(73);
        match(DecafParser::T__3);
        setState(74);
        match(DecafParser::NUM);
        setState(75);
        match(DecafParser::T__4);
      }
      setState(78);
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
    setState(81);
    match(DecafParser::STRUCT);
    setState(82);
    match(DecafParser::ID);
    setState(83);
    match(DecafParser::T__0);
    setState(87);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__5)
      | (1ULL << DecafParser::T__6)
      | (1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::STRUCT)
      | (1ULL << DecafParser::VOID))) != 0)) {
      setState(84);
      varDeclaration();
      setState(89);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(90);
    match(DecafParser::T__1);
    setState(91);
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
    setState(93);
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
    setState(95);
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
    setState(97);
    methodType();
    setState(98);
    match(DecafParser::ID);
    setState(99);
    match(DecafParser::T__8);
    setState(108);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__5)
      | (1ULL << DecafParser::T__6)
      | (1ULL << DecafParser::T__7))) != 0)) {
      setState(100);
      parameter();
      setState(105);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DecafParser::T__9) {
        setState(101);
        match(DecafParser::T__9);
        setState(102);
        parameter();
        setState(107);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(110);
    match(DecafParser::T__10);
    setState(111);
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
    setState(113);
    parameterType();
    setState(114);
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
    setState(116);
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
    setState(118);
    match(DecafParser::T__0);
    setState(122);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__5)
      | (1ULL << DecafParser::T__6)
      | (1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::STRUCT)
      | (1ULL << DecafParser::VOID))) != 0)) {
      setState(119);
      varDeclaration();
      setState(124);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(128);
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
      | (1ULL << DecafParser::CHAR)
      | (1ULL << DecafParser::NUM))) != 0)) {
      setState(125);
      statement();
      setState(130);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(131);
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
    setState(165);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::St_ifContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(133);
      match(DecafParser::IF);
      setState(134);
      match(DecafParser::T__8);
      setState(135);
      expression(0);
      setState(136);
      match(DecafParser::T__10);
      setState(137);
      block();
      setState(140);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DecafParser::ELSE) {
        setState(138);
        match(DecafParser::ELSE);
        setState(139);
        block();
      }
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::St_whileContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(142);
      match(DecafParser::T__11);
      setState(143);
      match(DecafParser::T__8);
      setState(144);
      expression(0);
      setState(145);
      match(DecafParser::T__10);
      setState(146);
      block();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::St_returnContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(148);
      match(DecafParser::T__12);
      setState(150);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << DecafParser::T__8)
        | (1ULL << DecafParser::T__19)
        | (1ULL << DecafParser::T__20)
        | (1ULL << DecafParser::TRUE)
        | (1ULL << DecafParser::FALSE)
        | (1ULL << DecafParser::ID)
        | (1ULL << DecafParser::CHAR)
        | (1ULL << DecafParser::NUM))) != 0)) {
        setState(149);
        expression(0);
      }
      setState(152);
      match(DecafParser::T__2);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::St_method_callContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(153);
      methodCall();
      setState(154);
      match(DecafParser::T__2);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::St_blockContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(156);
      block();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::St_assignmentContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(157);
      location();
      setState(158);
      match(DecafParser::T__13);
      setState(159);
      expression(0);
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<DecafParser::St_expressionContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(162);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << DecafParser::T__8)
        | (1ULL << DecafParser::T__19)
        | (1ULL << DecafParser::T__20)
        | (1ULL << DecafParser::TRUE)
        | (1ULL << DecafParser::FALSE)
        | (1ULL << DecafParser::ID)
        | (1ULL << DecafParser::CHAR)
        | (1ULL << DecafParser::NUM))) != 0)) {
        setState(161);
        expression(0);
      }
      setState(164);
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

DecafParser::ExpressionContext* DecafParser::Loc_memberContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
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
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(182);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<LocationContext *>(_tracker.createInstance<DecafParser::Loc_memberContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(167);
      match(DecafParser::ID);
      setState(172);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DecafParser::T__3) {
        setState(168);
        match(DecafParser::T__3);
        setState(169);
        expression(0);
        setState(170);
        match(DecafParser::T__4);
      }
      setState(174);
      match(DecafParser::T__14);
      setState(175);
      location();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<LocationContext *>(_tracker.createInstance<DecafParser::Loc_arrayContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(176);
      match(DecafParser::ID);
      setState(177);
      match(DecafParser::T__3);
      setState(178);
      expression(0);
      setState(179);
      match(DecafParser::T__4);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<LocationContext *>(_tracker.createInstance<DecafParser::Loc_varContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(181);
      match(DecafParser::ID);
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
    setState(196);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<Expr_method_callContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(185);
      methodCall();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<Expr_locContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(186);
      location();
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<Expr_literalContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(187);
      literal();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<Expr_negContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(188);
      match(DecafParser::T__19);
      setState(189);
      expression(3);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<Expr_notContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(190);
      match(DecafParser::T__20);
      setState(191);
      expression(2);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<Expr_parContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(192);
      match(DecafParser::T__8);
      setState(193);
      expression(0);
      setState(194);
      match(DecafParser::T__10);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(218);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(216);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<Expr_arith_0Context>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(198);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(199);
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
          setState(200);
          expression(9);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<Expr_arith_1Context>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(201);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(202);
          _la = _input->LA(1);
          if (!(_la == DecafParser::T__18

          || _la == DecafParser::T__19)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(203);
          expression(8);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<Expr_relContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(204);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(205);
          rel_op();
          setState(206);
          expression(7);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<Expr_eqContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(208);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(209);
          eq_op();
          setState(210);
          expression(6);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<Expr_condContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(212);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(213);
          cond_op();
          setState(214);
          expression(5);
          break;
        }

        } 
      }
      setState(220);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
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
    setState(221);
    match(DecafParser::ID);
    setState(222);
    match(DecafParser::T__8);
    setState(231);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__19)
      | (1ULL << DecafParser::T__20)
      | (1ULL << DecafParser::TRUE)
      | (1ULL << DecafParser::FALSE)
      | (1ULL << DecafParser::ID)
      | (1ULL << DecafParser::CHAR)
      | (1ULL << DecafParser::NUM))) != 0)) {
      setState(223);
      expression(0);
      setState(228);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DecafParser::T__9) {
        setState(224);
        match(DecafParser::T__9);
        setState(225);
        expression(0);
        setState(230);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(233);
    match(DecafParser::T__10);
   
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
  enterRule(_localctx, 28, DecafParser::RuleRel_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
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
  enterRule(_localctx, 30, DecafParser::RuleEq_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(237);
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
  enterRule(_localctx, 32, DecafParser::RuleCond_op);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(239);
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
  enterRule(_localctx, 34, DecafParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(244);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::NUM: {
        enterOuterAlt(_localctx, 1);
        setState(241);
        int_literal();
        break;
      }

      case DecafParser::CHAR: {
        enterOuterAlt(_localctx, 2);
        setState(242);
        char_literal();
        break;
      }

      case DecafParser::TRUE:
      case DecafParser::FALSE: {
        enterOuterAlt(_localctx, 3);
        setState(243);
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
  enterRule(_localctx, 36, DecafParser::RuleInt_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
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
  enterRule(_localctx, 38, DecafParser::RuleChar_literal);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    match(DecafParser::CHAR);
   
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
  enterRule(_localctx, 40, DecafParser::RuleBool_literal);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
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
  "statement", "location", "expression", "methodCall", "rel_op", "eq_op", 
  "cond_op", "literal", "int_literal", "char_literal", "bool_literal"
};

std::vector<std::string> DecafParser::_literalNames = {
  "", "'{'", "'}'", "';'", "'['", "']'", "'int'", "'char'", "'bool'", "'('", 
  "','", "')'", "'while'", "'return'", "'='", "'.'", "'*'", "'/'", "'%'", 
  "'+'", "'-'", "'!'", "'<'", "'>'", "'<='", "'>='", "'=='", "'!='", "'&&'", 
  "'||'", "'class'", "'Program'", "'struct'", "'true'", "'false'", "'if'", 
  "'else'", "'void'"
};

std::vector<std::string> DecafParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "CLASS", "PROGRAM", "STRUCT", 
  "TRUE", "FALSE", "IF", "ELSE", "VOID", "ID", "CHAR", "NUM", "WHITESPACE"
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
    0x3, 0x2b, 0xff, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 0x12, 
    0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 0x9, 
    0x15, 0x4, 0x16, 0x9, 0x16, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 
    0x7, 0x2, 0x31, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x34, 0xb, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x3c, 0xa, 
    0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x4f, 0xa, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0x52, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 
    0x5, 0x58, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x5b, 0xb, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x6a, 0xa, 0x8, 
    0xc, 0x8, 0xe, 0x8, 0x6d, 0xb, 0x8, 0x5, 0x8, 0x6f, 0xa, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x7b, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x7e, 
    0xb, 0xb, 0x3, 0xb, 0x7, 0xb, 0x81, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x84, 
    0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x8f, 0xa, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 
    0xc, 0x99, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xa5, 0xa, 
    0xc, 0x3, 0xc, 0x5, 0xc, 0xa8, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xaf, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xb9, 
    0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 
    0xc7, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xdb, 
    0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xde, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xe5, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 
    0xe8, 0xb, 0xf, 0x5, 0xf, 0xea, 0xa, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 
    0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x13, 0x5, 0x13, 0xf7, 0xa, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x2, 0x3, 0x1a, 0x17, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2, 0xa, 0x4, 0x2, 
    0x8, 0xa, 0x27, 0x27, 0x3, 0x2, 0x8, 0xa, 0x3, 0x2, 0x12, 0x14, 0x3, 
    0x2, 0x15, 0x16, 0x3, 0x2, 0x18, 0x1b, 0x3, 0x2, 0x1c, 0x1d, 0x3, 0x2, 
    0x1e, 0x1f, 0x3, 0x2, 0x23, 0x24, 0x2, 0x10e, 0x2, 0x2c, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x6, 0x51, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x53, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5f, 0x3, 0x2, 0x2, 0x2, 0xc, 0x61, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x63, 0x3, 0x2, 0x2, 0x2, 0x10, 0x73, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x76, 0x3, 0x2, 0x2, 0x2, 0x14, 0x78, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x18, 0xb8, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xc6, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xdf, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xed, 0x3, 0x2, 0x2, 0x2, 0x20, 0xef, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xf1, 0x3, 0x2, 0x2, 0x2, 0x24, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x26, 0xf8, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xfc, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0x2d, 0x7, 0x20, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x21, 
    0x2, 0x2, 0x2e, 0x32, 0x7, 0x3, 0x2, 0x2, 0x2f, 0x31, 0x5, 0x4, 0x3, 
    0x2, 0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x34, 0x3, 0x2, 0x2, 0x2, 
    0x32, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x3, 0x2, 0x2, 0x2, 0x33, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 0x35, 0x36, 
    0x7, 0x4, 0x2, 0x2, 0x36, 0x37, 0x7, 0x2, 0x2, 0x3, 0x37, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x38, 0x3c, 0x5, 0x8, 0x5, 0x2, 0x39, 0x3c, 0x5, 0x6, 
    0x4, 0x2, 0x3a, 0x3c, 0x5, 0xe, 0x8, 0x2, 0x3b, 0x38, 0x3, 0x2, 0x2, 
    0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x3a, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3d, 0x3e, 0x5, 0xa, 0x6, 0x2, 0x3e, 
    0x3f, 0x7, 0x28, 0x2, 0x2, 0x3f, 0x40, 0x7, 0x5, 0x2, 0x2, 0x40, 0x52, 
    0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x5, 0xa, 0x6, 0x2, 0x42, 0x43, 0x7, 
    0x28, 0x2, 0x2, 0x43, 0x44, 0x7, 0x6, 0x2, 0x2, 0x44, 0x45, 0x7, 0x2a, 
    0x2, 0x2, 0x45, 0x46, 0x7, 0x7, 0x2, 0x2, 0x46, 0x47, 0x7, 0x5, 0x2, 
    0x2, 0x47, 0x52, 0x3, 0x2, 0x2, 0x2, 0x48, 0x49, 0x7, 0x22, 0x2, 0x2, 
    0x49, 0x4a, 0x7, 0x28, 0x2, 0x2, 0x4a, 0x4e, 0x7, 0x28, 0x2, 0x2, 0x4b, 
    0x4c, 0x7, 0x6, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x2a, 0x2, 0x2, 0x4d, 0x4f, 
    0x7, 0x7, 0x2, 0x2, 0x4e, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4f, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x52, 0x7, 0x5, 
    0x2, 0x2, 0x51, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x51, 0x41, 0x3, 0x2, 0x2, 
    0x2, 0x51, 0x48, 0x3, 0x2, 0x2, 0x2, 0x52, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x53, 0x54, 0x7, 0x22, 0x2, 0x2, 0x54, 0x55, 0x7, 0x28, 0x2, 0x2, 0x55, 
    0x59, 0x7, 0x3, 0x2, 0x2, 0x56, 0x58, 0x5, 0x6, 0x4, 0x2, 0x57, 0x56, 
    0x3, 0x2, 0x2, 0x2, 0x58, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x5c, 0x3, 0x2, 
    0x2, 0x2, 0x5b, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x4, 0x2, 
    0x2, 0x5d, 0x5e, 0x7, 0x5, 0x2, 0x2, 0x5e, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x5f, 0x60, 0x9, 0x2, 0x2, 0x2, 0x60, 0xb, 0x3, 0x2, 0x2, 0x2, 0x61, 
    0x62, 0x9, 0x2, 0x2, 0x2, 0x62, 0xd, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 
    0x5, 0xc, 0x7, 0x2, 0x64, 0x65, 0x7, 0x28, 0x2, 0x2, 0x65, 0x6e, 0x7, 
    0xb, 0x2, 0x2, 0x66, 0x6b, 0x5, 0x10, 0x9, 0x2, 0x67, 0x68, 0x7, 0xc, 
    0x2, 0x2, 0x68, 0x6a, 0x5, 0x10, 0x9, 0x2, 0x69, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 
    0x6b, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6d, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x66, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 
    0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x7, 
    0xd, 0x2, 0x2, 0x71, 0x72, 0x5, 0x14, 0xb, 0x2, 0x72, 0xf, 0x3, 0x2, 
    0x2, 0x2, 0x73, 0x74, 0x5, 0x12, 0xa, 0x2, 0x74, 0x75, 0x7, 0x28, 0x2, 
    0x2, 0x75, 0x11, 0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x9, 0x3, 0x2, 0x2, 
    0x77, 0x13, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7c, 0x7, 0x3, 0x2, 0x2, 0x79, 
    0x7b, 0x5, 0x6, 0x4, 0x2, 0x7a, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x7e, 
    0x3, 0x2, 0x2, 0x2, 0x7c, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 0x3, 
    0x2, 0x2, 0x2, 0x7d, 0x82, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7c, 0x3, 0x2, 
    0x2, 0x2, 0x7f, 0x81, 0x5, 0x16, 0xc, 0x2, 0x80, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x81, 0x84, 0x3, 0x2, 0x2, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 0x2, 
    0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x85, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x82, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 0x7, 0x4, 0x2, 0x2, 0x86, 0x15, 
    0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 0x7, 0x25, 0x2, 0x2, 0x88, 0x89, 0x7, 
    0xb, 0x2, 0x2, 0x89, 0x8a, 0x5, 0x1a, 0xe, 0x2, 0x8a, 0x8b, 0x7, 0xd, 
    0x2, 0x2, 0x8b, 0x8e, 0x5, 0x14, 0xb, 0x2, 0x8c, 0x8d, 0x7, 0x26, 0x2, 
    0x2, 0x8d, 0x8f, 0x5, 0x14, 0xb, 0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 0x2, 
    0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0xa8, 0x3, 0x2, 0x2, 0x2, 0x90, 
    0x91, 0x7, 0xe, 0x2, 0x2, 0x91, 0x92, 0x7, 0xb, 0x2, 0x2, 0x92, 0x93, 
    0x5, 0x1a, 0xe, 0x2, 0x93, 0x94, 0x7, 0xd, 0x2, 0x2, 0x94, 0x95, 0x5, 
    0x14, 0xb, 0x2, 0x95, 0xa8, 0x3, 0x2, 0x2, 0x2, 0x96, 0x98, 0x7, 0xf, 
    0x2, 0x2, 0x97, 0x99, 0x5, 0x1a, 0xe, 0x2, 0x98, 0x97, 0x3, 0x2, 0x2, 
    0x2, 0x98, 0x99, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 0x2, 0x2, 
    0x9a, 0xa8, 0x7, 0x5, 0x2, 0x2, 0x9b, 0x9c, 0x5, 0x1c, 0xf, 0x2, 0x9c, 
    0x9d, 0x7, 0x5, 0x2, 0x2, 0x9d, 0xa8, 0x3, 0x2, 0x2, 0x2, 0x9e, 0xa8, 
    0x5, 0x14, 0xb, 0x2, 0x9f, 0xa0, 0x5, 0x18, 0xd, 0x2, 0xa0, 0xa1, 0x7, 
    0x10, 0x2, 0x2, 0xa1, 0xa2, 0x5, 0x1a, 0xe, 0x2, 0xa2, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0xa3, 0xa5, 0x5, 0x1a, 0xe, 0x2, 0xa4, 0xa3, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0xa8, 0x7, 0x5, 0x2, 0x2, 0xa7, 0x87, 0x3, 0x2, 0x2, 0x2, 0xa7, 
    0x90, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x96, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x9b, 
    0x3, 0x2, 0x2, 0x2, 0xa7, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x9f, 0x3, 
    0x2, 0x2, 0x2, 0xa7, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x17, 0x3, 0x2, 
    0x2, 0x2, 0xa9, 0xae, 0x7, 0x28, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x6, 0x2, 
    0x2, 0xab, 0xac, 0x5, 0x1a, 0xe, 0x2, 0xac, 0xad, 0x7, 0x7, 0x2, 0x2, 
    0xad, 0xaf, 0x3, 0x2, 0x2, 0x2, 0xae, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xae, 
    0xaf, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 
    0x7, 0x11, 0x2, 0x2, 0xb1, 0xb9, 0x5, 0x18, 0xd, 0x2, 0xb2, 0xb3, 0x7, 
    0x28, 0x2, 0x2, 0xb3, 0xb4, 0x7, 0x6, 0x2, 0x2, 0xb4, 0xb5, 0x5, 0x1a, 
    0xe, 0x2, 0xb5, 0xb6, 0x7, 0x7, 0x2, 0x2, 0xb6, 0xb9, 0x3, 0x2, 0x2, 
    0x2, 0xb7, 0xb9, 0x7, 0x28, 0x2, 0x2, 0xb8, 0xa9, 0x3, 0x2, 0x2, 0x2, 
    0xb8, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb9, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x8, 0xe, 0x1, 0x2, 0xbb, 0xc7, 
    0x5, 0x1c, 0xf, 0x2, 0xbc, 0xc7, 0x5, 0x18, 0xd, 0x2, 0xbd, 0xc7, 0x5, 
    0x24, 0x13, 0x2, 0xbe, 0xbf, 0x7, 0x16, 0x2, 0x2, 0xbf, 0xc7, 0x5, 0x1a, 
    0xe, 0x5, 0xc0, 0xc1, 0x7, 0x17, 0x2, 0x2, 0xc1, 0xc7, 0x5, 0x1a, 0xe, 
    0x4, 0xc2, 0xc3, 0x7, 0xb, 0x2, 0x2, 0xc3, 0xc4, 0x5, 0x1a, 0xe, 0x2, 
    0xc4, 0xc5, 0x7, 0xd, 0x2, 0x2, 0xc5, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xc6, 
    0xba, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xbd, 
    0x3, 0x2, 0x2, 0x2, 0xc6, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc0, 0x3, 
    0x2, 0x2, 0x2, 0xc6, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xdc, 0x3, 0x2, 
    0x2, 0x2, 0xc8, 0xc9, 0xc, 0xa, 0x2, 0x2, 0xc9, 0xca, 0x9, 0x4, 0x2, 
    0x2, 0xca, 0xdb, 0x5, 0x1a, 0xe, 0xb, 0xcb, 0xcc, 0xc, 0x9, 0x2, 0x2, 
    0xcc, 0xcd, 0x9, 0x5, 0x2, 0x2, 0xcd, 0xdb, 0x5, 0x1a, 0xe, 0xa, 0xce, 
    0xcf, 0xc, 0x8, 0x2, 0x2, 0xcf, 0xd0, 0x5, 0x1e, 0x10, 0x2, 0xd0, 0xd1, 
    0x5, 0x1a, 0xe, 0x9, 0xd1, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd3, 0xc, 
    0x7, 0x2, 0x2, 0xd3, 0xd4, 0x5, 0x20, 0x11, 0x2, 0xd4, 0xd5, 0x5, 0x1a, 
    0xe, 0x8, 0xd5, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xd7, 0xc, 0x6, 0x2, 
    0x2, 0xd7, 0xd8, 0x5, 0x22, 0x12, 0x2, 0xd8, 0xd9, 0x5, 0x1a, 0xe, 0x7, 
    0xd9, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xda, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xda, 
    0xcb, 0x3, 0x2, 0x2, 0x2, 0xda, 0xce, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd2, 
    0x3, 0x2, 0x2, 0x2, 0xda, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xde, 0x3, 
    0x2, 0x2, 0x2, 0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 0x3, 0x2, 
    0x2, 0x2, 0xdd, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 
    0x2, 0xdf, 0xe0, 0x7, 0x28, 0x2, 0x2, 0xe0, 0xe9, 0x7, 0xb, 0x2, 0x2, 
    0xe1, 0xe6, 0x5, 0x1a, 0xe, 0x2, 0xe2, 0xe3, 0x7, 0xc, 0x2, 0x2, 0xe3, 
    0xe5, 0x5, 0x1a, 0xe, 0x2, 0xe4, 0xe2, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe8, 
    0x3, 0x2, 0x2, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 
    0x2, 0x2, 0x2, 0xe7, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0xe9, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 
    0x2, 0xea, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0xd, 0x2, 0x2, 
    0xec, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x9, 0x6, 0x2, 0x2, 0xee, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x9, 0x7, 0x2, 0x2, 0xf0, 0x21, 
    0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x9, 0x8, 0x2, 0x2, 0xf2, 0x23, 0x3, 
    0x2, 0x2, 0x2, 0xf3, 0xf7, 0x5, 0x26, 0x14, 0x2, 0xf4, 0xf7, 0x5, 0x28, 
    0x15, 0x2, 0xf5, 0xf7, 0x5, 0x2a, 0x16, 0x2, 0xf6, 0xf3, 0x3, 0x2, 0x2, 
    0x2, 0xf6, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf5, 0x3, 0x2, 0x2, 0x2, 
    0xf7, 0x25, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x2a, 0x2, 0x2, 0xf9, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x29, 0x2, 0x2, 0xfb, 0x29, 
    0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x9, 0x9, 0x2, 0x2, 0xfd, 0x2b, 0x3, 
    0x2, 0x2, 0x2, 0x17, 0x32, 0x3b, 0x4e, 0x51, 0x59, 0x6b, 0x6e, 0x7c, 
    0x82, 0x8e, 0x98, 0xa4, 0xa7, 0xae, 0xb8, 0xc6, 0xda, 0xdc, 0xe6, 0xe9, 
    0xf6, 
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
