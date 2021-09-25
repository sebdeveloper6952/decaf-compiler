#pragma once

#include "SymbolTableEntry.h"
#include <string>

class NodeAttrs
{
public:
    NodeAttrs() = default;
    NodeAttrs(SymbolTableEntry *entry, std::string addr, std::string code);
    SymbolTableEntry *entry;
    std::string addr;
    std::string code;
};