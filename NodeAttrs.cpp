#include "NodeAttrs.h"

NodeAttrs::NodeAttrs(
    SymbolTableEntry *entry,
    std::string addr,
    std::string code,
    std::string l_next,
    std::string l_true,
    std::string l_false)
{
    this->entry = entry;
    this->addr = addr;
    this->code = code;
    this->l_next = l_next;
    this->l_true = l_true;
    this->l_false = l_false;
}
