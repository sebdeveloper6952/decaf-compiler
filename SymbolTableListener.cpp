#include <iostream>

#include "SymbolTableListener.h"
#include "SymbolTable.h"
#include "SymbolTableListener.h"

SymbolTableListener::SymbolTableListener(SymbolTable *table)
{
    this->table = table;
}

// Enter a new block
void SymbolTableListener::enterBlock(DecafParser::BlockContext *ctx)
{
    this->num_tables++;

    // push a new table
    std::string new_name = "table_" + std::to_string(this->num_tables);
    SymbolTable *new_top = new SymbolTable(this->table, new_name);
    this->table = new_top;

    std::cout << "push() " << this->table->get_name() << std::endl;
}

// exit the current block
void SymbolTableListener::exitBlock(DecafParser::BlockContext *ctx)
{
    // pop the top table
    SymbolTable *old = this->table;
    this->table = this->table->get_parent();

    std::cout << "pop() " << old->get_name() << std::endl;
    old->print_table();
    std::cout << "-------------------------------" << std::endl;
}

// New var declaration
void SymbolTableListener::enterVarDeclaration(DecafParser::VarDeclarationContext *ctx)
{
    DecafParser::VarTypeContext *var_type = ctx->varType();
    antlr4::tree::TerminalNode *id = ctx->ID();

    this->table->put(id->getText(), var_type->getText());
    SymbolTableEntry *entry = this->table->get(id->getText());

    std::cout << this->table->get_name() << "->push(): " << id->getText() << std::endl;
}

// Finish new var declaration
void SymbolTableListener::exitVarDeclaration(DecafParser::VarDeclarationContext *ctx)
{
}