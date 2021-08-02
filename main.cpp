#include <iostream>
#include <fstream>

#include "antlr4-runtime/antlr4-runtime.h"
#include "DecafLexer.h"
#include "DecafParser.h"
#include "DecafBaseVisitor.h"
#include "DecafBaseListener.h"
#include "CustomListener.h"

using namespace std;
using namespace antlr4;

int main(int argc, const char *argv[])
{
    ifstream stream;

    // TODO: validate argv length
    // open file specified.
    stream.open(argv[1]);

    // input stream
    ANTLRInputStream input(stream);

    // Create a lexer which scans the input stream
    // to create a token stream.
    DecafLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    // Create a parser which parses the token stream
    DecafParser parser(&tokens);

    // Create parse tree from top production of our grammar
    tree::ParseTree *tree = parser.program();

    // Listener Pattern
    CustomListener custom_listener;
    tree::ParseTreeWalker::DEFAULT.walk(&custom_listener, tree);

    // visitor pattern
    // DecafParser::ProgramContext *ctx = parser.program();
    // DecafBaseVisitor visitor;
    // visitor.visitProgram(ctx);

    return 0;
}