#pragma once

#include "SymbolTableEntry.h"
#include <string>

class IcgInstr
{
public:
    IcgInstr() = default;
    uint8_t op_code;
    std::string a0;
    std::string a1;
    std::string res;
};