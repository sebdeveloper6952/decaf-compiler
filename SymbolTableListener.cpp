#include <iostream>

#include "SymbolTableListener.h"
#include "SymbolTable.h"
#include "SymbolTableListener.h"
#include "DataTypes.h"

SymbolTableListener::SymbolTableListener(SymbolTable *table)
{
    this->table = table;
}

// Enter a new block
void SymbolTableListener::enterBlock(DecafParser::BlockContext *ctx)
{
    // push a new symbol table for this block
    this->push_table();

    // if this node parent is a methodDeclaration, handle its parameters
    // as if they were local variables of this block
    if (ctx->parent != NULL)
    {
        DecafParser::MethodDeclarationContext *p = (DecafParser::MethodDeclarationContext *)ctx->parent;
        std::vector<DecafParser::ParameterContext *> params = p->parameter();
        if (params.size())
        {
            std::cout << "put() params: ";
            for (DecafParser::ParameterContext *p : params)
            {
                this->table->put(
                    S_DATA,
                    p->ID()->getText(),
                    p->parameterType()->getText());
            }
            std::cout << std::endl;
        }
    }
}

// exit the current block
void SymbolTableListener::exitBlock(DecafParser::BlockContext *ctx)
{
    this->pop_table();
}

// New var declaration
void SymbolTableListener::enterVarDeclaration(DecafParser::VarDeclarationContext *ctx)
{
    DecafParser::VarTypeContext *var_type = ctx->varType();
    antlr4::tree::TerminalNode *id = ctx->ID();

    if (!this->table->put(S_DATA, id->getText(), var_type->getText()))
    {
        std::cout << "error: varDeclaration id ("
                  << id->getText()
                  << ") is already declared."
                  << std::endl;

        return;
    }

    std::cout << this->table->get_name() << "->push(): " << id->getText() << std::endl;
}

// Finish new var declaration
void SymbolTableListener::exitVarDeclaration(DecafParser::VarDeclarationContext *ctx) {}

// location
void SymbolTableListener::enterLocation(DecafParser::LocationContext *ctx)
{
    std::string id = ctx->ID()->getText();
    std::cout << "enterLocation: " << id << std::endl;

    SymbolTableEntry *entry = this->table->get(id);
    if (entry == NULL)
    {
        std::cout << "error: id ("
                  << id
                  << ") no declaration found."
                  << std::endl;
    }
    else
    {
        std::cout << id << " was found" << std::endl;
    }
}

void SymbolTableListener::exitLocation(DecafParser::LocationContext *ctx) {}

// Method declaration
void SymbolTableListener::enterMethodDeclaration(DecafParser::MethodDeclarationContext *ctx)
{
    std::string method_type = ctx->methodType()->getText();
    std::string id = ctx->ID()->getText();
    if (this->table->put(S_METHOD, id, method_type))
    {
        std::cout << "methodDeclaration saved in symbol table: "
                  << method_type
                  << "|"
                  << id
                  << std::endl;
    }
}

void SymbolTableListener::exitMethodDeclaration(DecafParser::MethodDeclarationContext *ctx) {}

// ------------------------------------------ Private auxiliary methods -----------------------------------------_
// Node Type association
void SymbolTableListener::put_node_type(antlr4::tree::ParseTree *node, int type)
{
    this->node_types.put(node, type);
}

void SymbolTableListener::get_node_type(antlr4::tree::ParseTree *node)
{
    auto t = this->node_types.get(node);
    std::cout << "Node type: " << t << std::endl;
}

// Auxiliary methods.
void SymbolTableListener::push_table()
{
    // push a new table
    SymbolTable *new_top =
        new SymbolTable(this->table, "table_" + std::to_string(this->num_tables++));
    this->table = new_top;

    std::cout << "------------------ "
              << "push() " << this->table->get_name()
              << " ------------------"
              << std::endl;
}

void SymbolTableListener::pop_table()
{
    // pop the top table
    SymbolTable *old = this->table;
    this->table = this->table->get_parent();

    std::cout << "pop(): " << old->get_name() << " | contents:" << std::endl;
    old->print_table();
    std::cout << "----------------------------------------------------" << std::endl;
}