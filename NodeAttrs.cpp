#include "NodeAttrs.h"

NodeAttrs::NodeAttrs(SymbolTableEntry *entry, std::string addr, std::string code)
{
    this->entry = entry;
    this->addr = addr;
    this->code = code;
}
