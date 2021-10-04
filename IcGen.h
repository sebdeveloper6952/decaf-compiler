#pragma once

#include <vector>
#include <string>
#include "IcgInstr.h"

class IcGen
{
public:
    IcGen() = default;
    static std::vector<std::string> gen_code(std::vector<IcgInstr *> &icg_instrs);
};