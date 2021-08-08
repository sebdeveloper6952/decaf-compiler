#include "SymbolTableEntry.h"

SymbolTableEntry::SymbolTableEntry(
    std::string const &id,
    std::string const &type,
    size_t offset)
{
    this->id = id;
    this->type = type;
    this->offset = offset;
}

// Override << operator
std::ostream &operator<<(std::ostream &_stream, SymbolTableEntry const &mc)
{
    std::string s = mc.id + "|" + mc.type + "|" + std::to_string(mc.offset);
    _stream << s;

    return _stream;
}