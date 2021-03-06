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
#include "IcGen.h"
#include "MipsGen.h"
#include "Utils.h"

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

    if (instrs.size() == 0)
        return -1;

    // intermmediate code
    std::vector<std::string> ic = IcGen::gen_code(instrs);
    std::cout << "__icg__" << std::endl;
    for (auto i : ic)
        std::cout << i;

    // target code generation
    MipsGen *mips_gen = new MipsGen();
    std::string target_code = mips_gen->gen_code(table, instrs);

    // print mips code
    std::cout << "__mips__" << std::endl;
    std::cout << target_code;

    // write code to file
    Utils::write_to_file("mips/output.asm", target_code);

    return 0;
}