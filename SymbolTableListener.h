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

public:
    SymbolTableListener(SymbolTable *table);
    virtual void enterVarDeclaration(DecafParser::VarDeclarationContext *ctx);
    virtual void exitVarDeclaration(DecafParser::VarDeclarationContext *ctx);
    virtual void enterBlock(DecafParser::BlockContext *ctx);
    virtual void exitBlock(DecafParser::BlockContext *ctx);
};
