
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
    match(DecafParser::T__0);
    setState(45);
    match(DecafParser::T__1);
    setState(46);
    match(DecafParser::T__2);
    setState(50);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__9)
      | (1ULL << DecafParser::T__10)
      | (1ULL << DecafParser::T__11))) != 0)) {
      setState(47);
      declaration();
      setState(52);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(53);
    match(DecafParser::T__3);
   
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


size_t DecafParser::DeclarationContext::getRuleIndex() const {
  return DecafParser::RuleDeclaration;
}

void DecafParser::DeclarationContext::copyFrom(DeclarationContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MethodDeclContext ------------------------------------------------------------------

DecafParser::MethodDeclarationContext* DecafParser::MethodDeclContext::methodDeclaration() {
  return getRuleContext<DecafParser::MethodDeclarationContext>(0);
}

DecafParser::MethodDeclContext::MethodDeclContext(DeclarationContext *ctx) { copyFrom(ctx); }

void DecafParser::MethodDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodDecl(this);
}
void DecafParser::MethodDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodDecl(this);
}

antlrcpp::Any DecafParser::MethodDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitMethodDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StructDeclContext ------------------------------------------------------------------

DecafParser::StructDeclarationContext* DecafParser::StructDeclContext::structDeclaration() {
  return getRuleContext<DecafParser::StructDeclarationContext>(0);
}

DecafParser::StructDeclContext::StructDeclContext(DeclarationContext *ctx) { copyFrom(ctx); }

void DecafParser::StructDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDecl(this);
}
void DecafParser::StructDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDecl(this);
}

antlrcpp::Any DecafParser::StructDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitStructDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarDeclContext ------------------------------------------------------------------

DecafParser::VarDeclarationContext* DecafParser::VarDeclContext::varDeclaration() {
  return getRuleContext<DecafParser::VarDeclarationContext>(0);
}

DecafParser::VarDeclContext::VarDeclContext(DeclarationContext *ctx) { copyFrom(ctx); }

void DecafParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}
void DecafParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}

antlrcpp::Any DecafParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
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
    setState(58);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<DeclarationContext *>(_tracker.createInstance<DecafParser::StructDeclContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(55);
      structDeclaration();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<DeclarationContext *>(_tracker.createInstance<DecafParser::VarDeclContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(56);
      varDeclaration();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<DeclarationContext *>(_tracker.createInstance<DecafParser::MethodDeclContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(57);
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

//----------------- NormalDeclContext ------------------------------------------------------------------

DecafParser::VarTypeContext* DecafParser::NormalDeclContext::varType() {
  return getRuleContext<DecafParser::VarTypeContext>(0);
}

tree::TerminalNode* DecafParser::NormalDeclContext::ID() {
  return getToken(DecafParser::ID, 0);
}

DecafParser::NormalDeclContext::NormalDeclContext(VarDeclarationContext *ctx) { copyFrom(ctx); }

void DecafParser::NormalDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNormalDecl(this);
}
void DecafParser::NormalDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNormalDecl(this);
}

antlrcpp::Any DecafParser::NormalDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitNormalDecl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ArrayDeclContext ------------------------------------------------------------------

DecafParser::VarTypeContext* DecafParser::ArrayDeclContext::varType() {
  return getRuleContext<DecafParser::VarTypeContext>(0);
}

tree::TerminalNode* DecafParser::ArrayDeclContext::ID() {
  return getToken(DecafParser::ID, 0);
}

tree::TerminalNode* DecafParser::ArrayDeclContext::NUM() {
  return getToken(DecafParser::NUM, 0);
}

DecafParser::ArrayDeclContext::ArrayDeclContext(VarDeclarationContext *ctx) { copyFrom(ctx); }

void DecafParser::ArrayDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayDecl(this);
}
void DecafParser::ArrayDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayDecl(this);
}

antlrcpp::Any DecafParser::ArrayDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitArrayDecl(this);
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
    setState(71);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<VarDeclarationContext *>(_tracker.createInstance<DecafParser::NormalDeclContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(60);
      varType();
      setState(61);
      match(DecafParser::ID);
      setState(62);
      match(DecafParser::T__4);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<VarDeclarationContext *>(_tracker.createInstance<DecafParser::ArrayDeclContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(64);
      varType();
      setState(65);
      match(DecafParser::ID);
      setState(66);
      match(DecafParser::T__5);
      setState(67);
      match(DecafParser::NUM);
      setState(68);
      match(DecafParser::T__6);
      setState(69);
      match(DecafParser::T__4);
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
    setState(73);
    match(DecafParser::T__7);
    setState(74);
    match(DecafParser::ID);
    setState(75);
    match(DecafParser::T__2);
    setState(79);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__9)
      | (1ULL << DecafParser::T__10)
      | (1ULL << DecafParser::T__11))) != 0)) {
      setState(76);
      varDeclaration();
      setState(81);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(82);
    match(DecafParser::T__3);
    setState(83);
    match(DecafParser::T__4);
   
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

tree::TerminalNode* DecafParser::VarTypeContext::ID() {
  return getToken(DecafParser::ID, 0);
}

DecafParser::StructDeclarationContext* DecafParser::VarTypeContext::structDeclaration() {
  return getRuleContext<DecafParser::StructDeclarationContext>(0);
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

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(92);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(85);
      match(DecafParser::T__8);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(86);
      match(DecafParser::T__9);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(87);
      match(DecafParser::T__10);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(88);
      match(DecafParser::T__7);
      setState(89);
      match(DecafParser::ID);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(90);
      structDeclaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(91);
      match(DecafParser::T__11);
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
  enterRule(_localctx, 10, DecafParser::RuleMethodDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(123);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(94);
      methodType();
      setState(95);
      match(DecafParser::ID);
      setState(96);
      match(DecafParser::T__12);
      setState(98);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DecafParser::T__11) {
        setState(97);
        match(DecafParser::T__11);
      }
      setState(100);
      match(DecafParser::T__13);
      setState(101);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(103);
      methodType();
      setState(104);
      match(DecafParser::ID);
      setState(105);
      match(DecafParser::T__12);
      setState(106);
      parameter();
      setState(107);
      match(DecafParser::T__13);
      setState(108);
      block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(110);
      methodType();
      setState(111);
      match(DecafParser::ID);
      setState(112);
      match(DecafParser::T__12);
      setState(113);
      parameter();
      setState(116); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(114);
        match(DecafParser::T__14);
        setState(115);
        parameter();
        setState(118); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == DecafParser::T__14);
      setState(120);
      match(DecafParser::T__13);
      setState(121);
      block();
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

//----------------- MethodTypeContext ------------------------------------------------------------------

DecafParser::MethodTypeContext::MethodTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
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
  enterRule(_localctx, 12, DecafParser::RuleMethodType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__9)
      | (1ULL << DecafParser::T__10)
      | (1ULL << DecafParser::T__11))) != 0))) {
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
    setState(127);
    parameterType();
    setState(128);
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
    setState(130);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__9)
      | (1ULL << DecafParser::T__10))) != 0))) {
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
    setState(132);
    match(DecafParser::T__2);
    setState(136);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__7)
      | (1ULL << DecafParser::T__8)
      | (1ULL << DecafParser::T__9)
      | (1ULL << DecafParser::T__10)
      | (1ULL << DecafParser::T__11))) != 0)) {
      setState(133);
      varDeclaration();
      setState(138);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(142);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__2)
      | (1ULL << DecafParser::T__4)
      | (1ULL << DecafParser::T__12)
      | (1ULL << DecafParser::T__15)
      | (1ULL << DecafParser::T__17)
      | (1ULL << DecafParser::T__18)
      | (1ULL << DecafParser::T__25)
      | (1ULL << DecafParser::T__26)
      | (1ULL << DecafParser::ID)
      | (1ULL << DecafParser::NUM)
      | (1ULL << DecafParser::APOSTROPHE)
      | (1ULL << DecafParser::TRUE)
      | (1ULL << DecafParser::FALSE))) != 0)) {
      setState(139);
      statement();
      setState(144);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(145);
    match(DecafParser::T__3);
   
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

DecafParser::ExpressionContext* DecafParser::StatementContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

std::vector<DecafParser::BlockContext *> DecafParser::StatementContext::block() {
  return getRuleContexts<DecafParser::BlockContext>();
}

DecafParser::BlockContext* DecafParser::StatementContext::block(size_t i) {
  return getRuleContext<DecafParser::BlockContext>(i);
}

DecafParser::MethodCallContext* DecafParser::StatementContext::methodCall() {
  return getRuleContext<DecafParser::MethodCallContext>(0);
}

DecafParser::LocationContext* DecafParser::StatementContext::location() {
  return getRuleContext<DecafParser::LocationContext>(0);
}


size_t DecafParser::StatementContext::getRuleIndex() const {
  return DecafParser::RuleStatement;
}

void DecafParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void DecafParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any DecafParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
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
    setState(179);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(147);
      match(DecafParser::T__15);
      setState(148);
      match(DecafParser::T__12);
      setState(149);
      expression(0);
      setState(150);
      match(DecafParser::T__13);
      setState(151);
      block();
      setState(154);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DecafParser::T__16) {
        setState(152);
        match(DecafParser::T__16);
        setState(153);
        block();
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(156);
      match(DecafParser::T__17);
      setState(157);
      match(DecafParser::T__12);
      setState(158);
      expression(0);
      setState(159);
      match(DecafParser::T__13);
      setState(160);
      block();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(162);
      match(DecafParser::T__18);
      setState(164);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << DecafParser::T__12)
        | (1ULL << DecafParser::T__25)
        | (1ULL << DecafParser::T__26)
        | (1ULL << DecafParser::ID)
        | (1ULL << DecafParser::NUM)
        | (1ULL << DecafParser::APOSTROPHE)
        | (1ULL << DecafParser::TRUE)
        | (1ULL << DecafParser::FALSE))) != 0)) {
        setState(163);
        expression(0);
      }
      setState(166);
      match(DecafParser::T__4);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(167);
      methodCall();
      setState(168);
      match(DecafParser::T__4);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(170);
      block();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(171);
      location();
      setState(172);
      match(DecafParser::T__19);
      setState(173);
      expression(0);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(176);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << DecafParser::T__12)
        | (1ULL << DecafParser::T__25)
        | (1ULL << DecafParser::T__26)
        | (1ULL << DecafParser::ID)
        | (1ULL << DecafParser::NUM)
        | (1ULL << DecafParser::APOSTROPHE)
        | (1ULL << DecafParser::TRUE)
        | (1ULL << DecafParser::FALSE))) != 0)) {
        setState(175);
        expression(0);
      }
      setState(178);
      match(DecafParser::T__4);
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

tree::TerminalNode* DecafParser::LocationContext::ID() {
  return getToken(DecafParser::ID, 0);
}

DecafParser::ExpressionContext* DecafParser::LocationContext::expression() {
  return getRuleContext<DecafParser::ExpressionContext>(0);
}

DecafParser::LocationContext* DecafParser::LocationContext::location() {
  return getRuleContext<DecafParser::LocationContext>(0);
}


size_t DecafParser::LocationContext::getRuleIndex() const {
  return DecafParser::RuleLocation;
}

void DecafParser::LocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLocation(this);
}

void DecafParser::LocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLocation(this);
}


antlrcpp::Any DecafParser::LocationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitLocation(this);
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
    enterOuterAlt(_localctx, 1);
    setState(187);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(181);
      match(DecafParser::ID);
      break;
    }

    case 2: {
      setState(182);
      match(DecafParser::ID);
      setState(183);
      match(DecafParser::T__5);
      setState(184);
      expression(0);
      setState(185);
      match(DecafParser::T__6);
      break;
    }

    }
    setState(191);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      setState(189);
      match(DecafParser::T__20);
      setState(190);
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

DecafParser::LocationContext* DecafParser::ExpressionContext::location() {
  return getRuleContext<DecafParser::LocationContext>(0);
}

DecafParser::MethodCallContext* DecafParser::ExpressionContext::methodCall() {
  return getRuleContext<DecafParser::MethodCallContext>(0);
}

DecafParser::LiteralContext* DecafParser::ExpressionContext::literal() {
  return getRuleContext<DecafParser::LiteralContext>(0);
}

std::vector<DecafParser::ExpressionContext *> DecafParser::ExpressionContext::expression() {
  return getRuleContexts<DecafParser::ExpressionContext>();
}

DecafParser::ExpressionContext* DecafParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<DecafParser::ExpressionContext>(i);
}

DecafParser::Rel_opContext* DecafParser::ExpressionContext::rel_op() {
  return getRuleContext<DecafParser::Rel_opContext>(0);
}

DecafParser::Eq_opContext* DecafParser::ExpressionContext::eq_op() {
  return getRuleContext<DecafParser::Eq_opContext>(0);
}

DecafParser::Cond_opContext* DecafParser::ExpressionContext::cond_op() {
  return getRuleContext<DecafParser::Cond_opContext>(0);
}


size_t DecafParser::ExpressionContext::getRuleIndex() const {
  return DecafParser::RuleExpression;
}

void DecafParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void DecafParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DecafListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any DecafParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<DecafVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
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
    setState(205);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      setState(194);
      location();
      break;
    }

    case 2: {
      setState(195);
      methodCall();
      break;
    }

    case 3: {
      setState(196);
      literal();
      break;
    }

    case 4: {
      setState(197);
      match(DecafParser::T__25);
      setState(198);
      expression(3);
      break;
    }

    case 5: {
      setState(199);
      match(DecafParser::T__26);
      setState(200);
      expression(2);
      break;
    }

    case 6: {
      setState(201);
      match(DecafParser::T__12);
      setState(202);
      expression(0);
      setState(203);
      match(DecafParser::T__13);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(227);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(225);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(207);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(208);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << DecafParser::T__21)
            | (1ULL << DecafParser::T__22)
            | (1ULL << DecafParser::T__23))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(209);
          expression(9);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(210);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(211);
          _la = _input->LA(1);
          if (!(_la == DecafParser::T__24

          || _la == DecafParser::T__25)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(212);
          expression(8);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(213);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(214);
          rel_op();
          setState(215);
          expression(7);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(217);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(218);
          eq_op();
          setState(219);
          expression(6);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpression);
          setState(221);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(222);
          cond_op();
          setState(223);
          expression(5);
          break;
        }

        } 
      }
      setState(229);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
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
    setState(248);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(230);
      match(DecafParser::ID);
      setState(231);
      match(DecafParser::T__27);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(232);
      match(DecafParser::ID);
      setState(233);
      match(DecafParser::T__12);
      setState(234);
      expression(0);
      setState(235);
      match(DecafParser::T__13);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(237);
      match(DecafParser::ID);
      setState(238);
      match(DecafParser::T__12);
      setState(239);
      expression(0);
      setState(242); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(240);
        match(DecafParser::T__14);
        setState(241);
        expression(0);
        setState(244); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == DecafParser::T__14);
      setState(246);
      match(DecafParser::T__13);
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
    setState(250);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__21)
      | (1ULL << DecafParser::T__22)
      | (1ULL << DecafParser::T__23)
      | (1ULL << DecafParser::T__24)
      | (1ULL << DecafParser::T__25))) != 0))) {
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
    setState(252);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << DecafParser::T__28)
      | (1ULL << DecafParser::T__29)
      | (1ULL << DecafParser::T__30)
      | (1ULL << DecafParser::T__31))) != 0))) {
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
    setState(254);
    _la = _input->LA(1);
    if (!(_la == DecafParser::T__32

    || _la == DecafParser::T__33)) {
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
    setState(256);
    _la = _input->LA(1);
    if (!(_la == DecafParser::T__34

    || _la == DecafParser::T__35)) {
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
    setState(261);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DecafParser::NUM: {
        enterOuterAlt(_localctx, 1);
        setState(258);
        int_literal();
        break;
      }

      case DecafParser::APOSTROPHE: {
        enterOuterAlt(_localctx, 2);
        setState(259);
        char_literal();
        break;
      }

      case DecafParser::TRUE:
      case DecafParser::FALSE: {
        enterOuterAlt(_localctx, 3);
        setState(260);
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
    setState(263);
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

tree::TerminalNode* DecafParser::Char_literalContext::CHAR_LITERAL() {
  return getToken(DecafParser::CHAR_LITERAL, 0);
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
    setState(265);
    match(DecafParser::APOSTROPHE);
    setState(266);
    match(DecafParser::CHAR_LITERAL);
    setState(267);
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
    setState(269);
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
  "methodDeclaration", "methodType", "parameter", "parameterType", "block", 
  "statement", "location", "expression", "methodCall", "arith_op", "rel_op", 
  "eq_op", "cond_op", "literal", "int_literal", "char_literal", "bool_literal"
};

std::vector<std::string> DecafParser::_literalNames = {
  "", "'class'", "'Program'", "'{'", "'}'", "';'", "'['", "']'", "'struct'", 
  "'int'", "'char'", "'boolean'", "'void'", "'('", "')'", "','", "'if'", 
  "'else'", "'while'", "'return'", "'='", "'.'", "'*'", "'/'", "'%'", "'+'", 
  "'-'", "'!'", "'()'", "'<'", "'>'", "'<='", "'>='", "'=='", "'!='", "'&&'", 
  "'||'", "", "", "'''", "", "'true'", "'false'"
};

std::vector<std::string> DecafParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "ID", "NUM", "APOSTROPHE", "CHAR_LITERAL", "TRUE", "FALSE", "WHITESPACE"
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
    0x3, 0x2d, 0x112, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x33, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
    0x36, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x3d, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x4a, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x50, 
    0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x53, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0x5f, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x5, 0x7, 0x65, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x6, 0x7, 0x77, 0xa, 0x7, 
    0xd, 0x7, 0xe, 0x7, 0x78, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x7e, 
    0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x89, 0xa, 0xb, 0xc, 0xb, 0xe, 
    0xb, 0x8c, 0xb, 0xb, 0x3, 0xb, 0x7, 0xb, 0x8f, 0xa, 0xb, 0xc, 0xb, 0xe, 
    0xb, 0x92, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x9d, 0xa, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 
    0xc, 0x5, 0xc, 0xa7, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 
    0xb3, 0xa, 0xc, 0x3, 0xc, 0x5, 0xc, 0xb6, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xbe, 0xa, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x5, 0xd, 0xc2, 0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xd0, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x7, 0xe, 0xe4, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xe7, 0xb, 
    0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x6, 0xf, 0xf5, 
    0xa, 0xf, 0xd, 0xf, 0xe, 0xf, 0xf6, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xfb, 
    0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 
    0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 
    0x108, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x2, 0x3, 0x1a, 0x18, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2, 0xb, 0x3, 0x2, 
    0xb, 0xe, 0x3, 0x2, 0xb, 0xd, 0x3, 0x2, 0x18, 0x1a, 0x3, 0x2, 0x1b, 
    0x1c, 0x3, 0x2, 0x18, 0x1c, 0x3, 0x2, 0x1f, 0x22, 0x3, 0x2, 0x23, 0x24, 
    0x3, 0x2, 0x25, 0x26, 0x3, 0x2, 0x2b, 0x2c, 0x2, 0x125, 0x2, 0x2e, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x6, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x4b, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5e, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0xe, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x10, 0x81, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x84, 0x3, 0x2, 0x2, 0x2, 0x14, 0x86, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0xb5, 0x3, 0x2, 0x2, 0x2, 0x18, 0xbd, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0xcf, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xfa, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x20, 0xfe, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x100, 0x3, 0x2, 0x2, 0x2, 0x24, 0x102, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x107, 0x3, 0x2, 0x2, 0x2, 0x28, 0x109, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x10b, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x7, 
    0x3, 0x2, 0x2, 0x2f, 0x30, 0x7, 0x4, 0x2, 0x2, 0x30, 0x34, 0x7, 0x5, 
    0x2, 0x2, 0x31, 0x33, 0x5, 0x4, 0x3, 0x2, 0x32, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x33, 0x36, 0x3, 0x2, 0x2, 0x2, 0x34, 0x32, 0x3, 0x2, 0x2, 0x2, 
    0x34, 0x35, 0x3, 0x2, 0x2, 0x2, 0x35, 0x37, 0x3, 0x2, 0x2, 0x2, 0x36, 
    0x34, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x7, 0x6, 0x2, 0x2, 0x38, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x39, 0x3d, 0x5, 0x8, 0x5, 0x2, 0x3a, 0x3d, 0x5, 
    0x6, 0x4, 0x2, 0x3b, 0x3d, 0x5, 0xc, 0x7, 0x2, 0x3c, 0x39, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3b, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0x5, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3f, 0x5, 0xa, 0x6, 0x2, 
    0x3f, 0x40, 0x7, 0x27, 0x2, 0x2, 0x40, 0x41, 0x7, 0x7, 0x2, 0x2, 0x41, 
    0x4a, 0x3, 0x2, 0x2, 0x2, 0x42, 0x43, 0x5, 0xa, 0x6, 0x2, 0x43, 0x44, 
    0x7, 0x27, 0x2, 0x2, 0x44, 0x45, 0x7, 0x8, 0x2, 0x2, 0x45, 0x46, 0x7, 
    0x28, 0x2, 0x2, 0x46, 0x47, 0x7, 0x9, 0x2, 0x2, 0x47, 0x48, 0x7, 0x7, 
    0x2, 0x2, 0x48, 0x4a, 0x3, 0x2, 0x2, 0x2, 0x49, 0x3e, 0x3, 0x2, 0x2, 
    0x2, 0x49, 0x42, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x4b, 0x4c, 0x7, 0xa, 0x2, 0x2, 0x4c, 0x4d, 0x7, 0x27, 0x2, 0x2, 0x4d, 
    0x51, 0x7, 0x5, 0x2, 0x2, 0x4e, 0x50, 0x5, 0x6, 0x4, 0x2, 0x4f, 0x4e, 
    0x3, 0x2, 0x2, 0x2, 0x50, 0x53, 0x3, 0x2, 0x2, 0x2, 0x51, 0x4f, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x52, 0x3, 0x2, 0x2, 0x2, 0x52, 0x54, 0x3, 0x2, 
    0x2, 0x2, 0x53, 0x51, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x7, 0x6, 0x2, 
    0x2, 0x55, 0x56, 0x7, 0x7, 0x2, 0x2, 0x56, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x57, 0x5f, 0x7, 0xb, 0x2, 0x2, 0x58, 0x5f, 0x7, 0xc, 0x2, 0x2, 0x59, 
    0x5f, 0x7, 0xd, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0xa, 0x2, 0x2, 0x5b, 0x5f, 
    0x7, 0x27, 0x2, 0x2, 0x5c, 0x5f, 0x5, 0x8, 0x5, 0x2, 0x5d, 0x5f, 0x7, 
    0xe, 0x2, 0x2, 0x5e, 0x57, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x5e, 0x59, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5a, 0x3, 0x2, 0x2, 
    0x2, 0x5e, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5d, 0x3, 0x2, 0x2, 0x2, 
    0x5f, 0xb, 0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x5, 0xe, 0x8, 0x2, 0x61, 
    0x62, 0x7, 0x27, 0x2, 0x2, 0x62, 0x64, 0x7, 0xf, 0x2, 0x2, 0x63, 0x65, 
    0x7, 0xe, 0x2, 0x2, 0x64, 0x63, 0x3, 0x2, 0x2, 0x2, 0x64, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x7, 0x10, 
    0x2, 0x2, 0x67, 0x68, 0x5, 0x14, 0xb, 0x2, 0x68, 0x7e, 0x3, 0x2, 0x2, 
    0x2, 0x69, 0x6a, 0x5, 0xe, 0x8, 0x2, 0x6a, 0x6b, 0x7, 0x27, 0x2, 0x2, 
    0x6b, 0x6c, 0x7, 0xf, 0x2, 0x2, 0x6c, 0x6d, 0x5, 0x10, 0x9, 0x2, 0x6d, 
    0x6e, 0x7, 0x10, 0x2, 0x2, 0x6e, 0x6f, 0x5, 0x14, 0xb, 0x2, 0x6f, 0x7e, 
    0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 0x5, 0xe, 0x8, 0x2, 0x71, 0x72, 0x7, 
    0x27, 0x2, 0x2, 0x72, 0x73, 0x7, 0xf, 0x2, 0x2, 0x73, 0x76, 0x5, 0x10, 
    0x9, 0x2, 0x74, 0x75, 0x7, 0x11, 0x2, 0x2, 0x75, 0x77, 0x5, 0x10, 0x9, 
    0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 0x2, 0x77, 0x78, 0x3, 0x2, 0x2, 0x2, 
    0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 
    0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x10, 0x2, 0x2, 0x7b, 0x7c, 
    0x5, 0x14, 0xb, 0x2, 0x7c, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x60, 0x3, 
    0x2, 0x2, 0x2, 0x7d, 0x69, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x70, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0xd, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x80, 0x9, 0x2, 0x2, 
    0x2, 0x80, 0xf, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x5, 0x12, 0xa, 0x2, 
    0x82, 0x83, 0x7, 0x27, 0x2, 0x2, 0x83, 0x11, 0x3, 0x2, 0x2, 0x2, 0x84, 
    0x85, 0x9, 0x3, 0x2, 0x2, 0x85, 0x13, 0x3, 0x2, 0x2, 0x2, 0x86, 0x8a, 
    0x7, 0x5, 0x2, 0x2, 0x87, 0x89, 0x5, 0x6, 0x4, 0x2, 0x88, 0x87, 0x3, 
    0x2, 0x2, 0x2, 0x89, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x88, 0x3, 0x2, 
    0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x90, 0x3, 0x2, 0x2, 
    0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x8f, 0x5, 0x16, 0xc, 0x2, 
    0x8e, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x92, 0x3, 0x2, 0x2, 0x2, 0x90, 
    0x8e, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 
    0x6, 0x2, 0x2, 0x94, 0x15, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x7, 0x12, 
    0x2, 0x2, 0x96, 0x97, 0x7, 0xf, 0x2, 0x2, 0x97, 0x98, 0x5, 0x1a, 0xe, 
    0x2, 0x98, 0x99, 0x7, 0x10, 0x2, 0x2, 0x99, 0x9c, 0x5, 0x14, 0xb, 0x2, 
    0x9a, 0x9b, 0x7, 0x13, 0x2, 0x2, 0x9b, 0x9d, 0x5, 0x14, 0xb, 0x2, 0x9c, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xb6, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x14, 0x2, 0x2, 0x9f, 0xa0, 0x7, 
    0xf, 0x2, 0x2, 0xa0, 0xa1, 0x5, 0x1a, 0xe, 0x2, 0xa1, 0xa2, 0x7, 0x10, 
    0x2, 0x2, 0xa2, 0xa3, 0x5, 0x14, 0xb, 0x2, 0xa3, 0xb6, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0xa6, 0x7, 0x15, 0x2, 0x2, 0xa5, 0xa7, 0x5, 0x1a, 0xe, 0x2, 
    0xa6, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 
    0xa8, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xb6, 0x7, 0x7, 0x2, 0x2, 0xa9, 0xaa, 
    0x5, 0x1c, 0xf, 0x2, 0xaa, 0xab, 0x7, 0x7, 0x2, 0x2, 0xab, 0xb6, 0x3, 
    0x2, 0x2, 0x2, 0xac, 0xb6, 0x5, 0x14, 0xb, 0x2, 0xad, 0xae, 0x5, 0x18, 
    0xd, 0x2, 0xae, 0xaf, 0x7, 0x16, 0x2, 0x2, 0xaf, 0xb0, 0x5, 0x1a, 0xe, 
    0x2, 0xb0, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb3, 0x5, 0x1a, 0xe, 0x2, 
    0xb2, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 
    0xb4, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb6, 0x7, 0x7, 0x2, 0x2, 0xb5, 0x95, 
    0x3, 0x2, 0x2, 0x2, 0xb5, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xa4, 0x3, 
    0x2, 0x2, 0x2, 0xb5, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xac, 0x3, 0x2, 
    0x2, 0x2, 0xb5, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb2, 0x3, 0x2, 0x2, 
    0x2, 0xb6, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xbe, 0x7, 0x27, 0x2, 0x2, 
    0xb8, 0xb9, 0x7, 0x27, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x8, 0x2, 0x2, 0xba, 
    0xbb, 0x5, 0x1a, 0xe, 0x2, 0xbb, 0xbc, 0x7, 0x9, 0x2, 0x2, 0xbc, 0xbe, 
    0x3, 0x2, 0x2, 0x2, 0xbd, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xb8, 0x3, 
    0x2, 0x2, 0x2, 0xbe, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x17, 
    0x2, 0x2, 0xc0, 0xc2, 0x5, 0x18, 0xd, 0x2, 0xc1, 0xbf, 0x3, 0x2, 0x2, 
    0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0xc3, 0xc4, 0x8, 0xe, 0x1, 0x2, 0xc4, 0xd0, 0x5, 0x18, 0xd, 0x2, 0xc5, 
    0xd0, 0x5, 0x1c, 0xf, 0x2, 0xc6, 0xd0, 0x5, 0x26, 0x14, 0x2, 0xc7, 0xc8, 
    0x7, 0x1c, 0x2, 0x2, 0xc8, 0xd0, 0x5, 0x1a, 0xe, 0x5, 0xc9, 0xca, 0x7, 
    0x1d, 0x2, 0x2, 0xca, 0xd0, 0x5, 0x1a, 0xe, 0x4, 0xcb, 0xcc, 0x7, 0xf, 
    0x2, 0x2, 0xcc, 0xcd, 0x5, 0x1a, 0xe, 0x2, 0xcd, 0xce, 0x7, 0x10, 0x2, 
    0x2, 0xce, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xc3, 0x3, 0x2, 0x2, 0x2, 
    0xcf, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xcf, 
    0xc7, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xcb, 
    0x3, 0x2, 0x2, 0x2, 0xd0, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0xc, 
    0xa, 0x2, 0x2, 0xd2, 0xd3, 0x9, 0x4, 0x2, 0x2, 0xd3, 0xe4, 0x5, 0x1a, 
    0xe, 0xb, 0xd4, 0xd5, 0xc, 0x9, 0x2, 0x2, 0xd5, 0xd6, 0x9, 0x5, 0x2, 
    0x2, 0xd6, 0xe4, 0x5, 0x1a, 0xe, 0xa, 0xd7, 0xd8, 0xc, 0x8, 0x2, 0x2, 
    0xd8, 0xd9, 0x5, 0x20, 0x11, 0x2, 0xd9, 0xda, 0x5, 0x1a, 0xe, 0x9, 0xda, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0xc, 0x7, 0x2, 0x2, 0xdc, 0xdd, 
    0x5, 0x22, 0x12, 0x2, 0xdd, 0xde, 0x5, 0x1a, 0xe, 0x8, 0xde, 0xe4, 0x3, 
    0x2, 0x2, 0x2, 0xdf, 0xe0, 0xc, 0x6, 0x2, 0x2, 0xe0, 0xe1, 0x5, 0x24, 
    0x13, 0x2, 0xe1, 0xe2, 0x5, 0x1a, 0xe, 0x7, 0xe2, 0xe4, 0x3, 0x2, 0x2, 
    0x2, 0xe3, 0xd1, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xd4, 0x3, 0x2, 0x2, 0x2, 
    0xe3, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xe3, 
    0xdf, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe3, 
    0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe6, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0xe7, 0xe5, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x7, 0x27, 
    0x2, 0x2, 0xe9, 0xfb, 0x7, 0x1e, 0x2, 0x2, 0xea, 0xeb, 0x7, 0x27, 0x2, 
    0x2, 0xeb, 0xec, 0x7, 0xf, 0x2, 0x2, 0xec, 0xed, 0x5, 0x1a, 0xe, 0x2, 
    0xed, 0xee, 0x7, 0x10, 0x2, 0x2, 0xee, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xef, 
    0xf0, 0x7, 0x27, 0x2, 0x2, 0xf0, 0xf1, 0x7, 0xf, 0x2, 0x2, 0xf1, 0xf4, 
    0x5, 0x1a, 0xe, 0x2, 0xf2, 0xf3, 0x7, 0x11, 0x2, 0x2, 0xf3, 0xf5, 0x5, 
    0x1a, 0xe, 0x2, 0xf4, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf6, 0x3, 0x2, 
    0x2, 0x2, 0xf6, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x3, 0x2, 0x2, 
    0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x10, 0x2, 0x2, 
    0xf9, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xfa, 
    0xea, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xef, 0x3, 0x2, 0x2, 0x2, 0xfb, 0x1d, 
    0x3, 0x2, 0x2, 0x2, 0xfc, 0xfd, 0x9, 0x6, 0x2, 0x2, 0xfd, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0xfe, 0xff, 0x9, 0x7, 0x2, 0x2, 0xff, 0x21, 0x3, 0x2, 
    0x2, 0x2, 0x100, 0x101, 0x9, 0x8, 0x2, 0x2, 0x101, 0x23, 0x3, 0x2, 0x2, 
    0x2, 0x102, 0x103, 0x9, 0x9, 0x2, 0x2, 0x103, 0x25, 0x3, 0x2, 0x2, 0x2, 
    0x104, 0x108, 0x5, 0x28, 0x15, 0x2, 0x105, 0x108, 0x5, 0x2a, 0x16, 0x2, 
    0x106, 0x108, 0x5, 0x2c, 0x17, 0x2, 0x107, 0x104, 0x3, 0x2, 0x2, 0x2, 
    0x107, 0x105, 0x3, 0x2, 0x2, 0x2, 0x107, 0x106, 0x3, 0x2, 0x2, 0x2, 
    0x108, 0x27, 0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x28, 0x2, 0x2, 
    0x10a, 0x29, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10c, 0x7, 0x29, 0x2, 0x2, 
    0x10c, 0x10d, 0x7, 0x2a, 0x2, 0x2, 0x10d, 0x10e, 0x7, 0x29, 0x2, 0x2, 
    0x10e, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x9, 0xa, 0x2, 0x2, 0x110, 
    0x2d, 0x3, 0x2, 0x2, 0x2, 0x18, 0x34, 0x3c, 0x49, 0x51, 0x5e, 0x64, 
    0x78, 0x7d, 0x8a, 0x90, 0x9c, 0xa6, 0xb2, 0xb5, 0xbd, 0xc1, 0xcf, 0xe3, 
    0xe5, 0xf6, 0xfa, 0x107, 
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
