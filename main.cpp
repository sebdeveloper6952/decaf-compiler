#include <iostream>
#include <fstream>
#include <vector>

#include "antlr4-runtime/antlr4-runtime.h"
#include "DecafLexer.h"
#include "DecafParser.h"
#include "DecafBaseVisitor.h"
#include "DecafBaseListener.h"
#include "CustomListener.h"
#include "SymbolTable.h"
#include "SymbolTableListener.h"
#include "DataTypes.h"
#include "IcgInstr.h"

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

    // Create a parser which parses the token stream
    DecafParser parser(&tokens);

    // Create parse tree from the top production of our grammar
    tree::ParseTree *tree = parser.program();

    // SymbolTable declaration
    SymbolTable *table = new SymbolTable(NULL, "global");

    // walk the tree
    std::vector<IcgInstr *> instrs;
    SymbolTableListener st_listener(table, &instrs);
    tree::ParseTreeWalker::DEFAULT.walk(&st_listener, tree);

    // intermmediate code
    std::cout << "icg instructions: " << std::endl;
    for (auto i : instrs)
    {
        std::cout << "|op: " << std::to_string(i->op_code) << "|a0: " << i->a0 << "|a1: " << i->a1 << "|res: " << i->res << "|" << std::endl;
    }

    return 0;
}