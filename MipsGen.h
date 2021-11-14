#pragma once

#include <vector>
#include <string>
#include "IcgInstr.h"

class MipsGen
{
public:
    MipsGen() = default;
    static void gen_code(std::vector<IcgInstr *> &instrs);
};