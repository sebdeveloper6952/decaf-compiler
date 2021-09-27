#pragma once

#include "SymbolTableEntry.h"
#include <string>

class NodeAttrs
{
public:
    NodeAttrs() = default;
    NodeAttrs(
        SymbolTableEntry *entry,
        std::string addr,
        std::string code,
        std::string l_next,
        std::string l_true,
        std::string l_false);
    SymbolTableEntry *entry;
    std::string addr;
    std::string code;
    std::string l_next;
    std::string l_true;
    std::string l_false;
    std::string value;
};