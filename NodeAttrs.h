#pragma once

#include "SymbolTableEntry.h"
#include <string>
#include "IcgInstr.h"

class NodeAttrs
{
public:
    NodeAttrs() = default;
    NodeAttrs(
        SymbolTableEntry *entry,
        std::string addr,
        std::string l_next,
        std::string l_true,
        std::string l_false);
    SymbolTableEntry *entry;
    std::string addr;
    std::string l_next;
    std::string l_true;
    std::string l_false;
    std::string l_begin;
    std::string value;
    std::string op;
    IcgInstr *instr;
    std::vector<IcgInstr *> l_code;
    std::vector<IcgInstr *> lj_code;
};