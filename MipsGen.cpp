#include "MipsGen.h"

void MipsGen::gen_code(std::vector<IcgInstr *> &instrs)
{
    for (IcgInstr *i : instrs)
        std::cout << i->to_string() << std::endl;
}