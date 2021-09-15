#include <iostream>
#include <fstream>

#include "antlr4-runtime/antlr4-runtime.h"
#include "DecafLexer.h"
#include "DecafParser.h"
#include "DecafBaseVisitor.h"
#include "DecafBaseListener.h"
#include "CustomListener.h"
#include "SymbolTable.h"
#include "SymbolTableListener.h"
#include "DataTypes.h"

using namespace antlr4;

int main(int argc, const char *argv[])
{
    // TODO: validate argv length
    // open file specified.
    std::ifstream stream;
    stream.open(argv[1]);

    // std::stringstream stream;
    // stream << argv[1];

    // input stream
    ANTLRInputStream input(stream);

    // Create a lexer which scans the input stream
    // to create a token stream.
    DecafLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    // TODO: remove, only for debugging.
    // tokens.fill();
    // for (antlr4::Token *token : tokens.getTokens())
    // {
    //     std::cout << token->toString() << std::endl;
    // }

    // Create a parser which parses the token stream
    DecafParser parser(&tokens);

    // Create parse tree from the top production of our grammar
    tree::ParseTree *tree = parser.program();

    // SymbolTable declaration
    SymbolTable *table = new SymbolTable(NULL, "global");

    // walk the tree
    SymbolTableListener st_listener(table);
    tree::ParseTreeWalker::DEFAULT.walk(&st_listener, tree);

    // TODO: remove
    table->print_table();

    return 0;
}