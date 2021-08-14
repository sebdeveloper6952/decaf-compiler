#include "SymbolTableEntry.h"

SymbolTableEntry::SymbolTableEntry(
    std::string const &id,
    int obj_type,
    int data_type,
    std::string const &type,
    size_t offset)
{
    this->id = id;
    this->obj_type = obj_type;
    this->data_type = data_type;
    this->type = type;
    this->offset = offset;
}

// Override << operator
std::ostream &operator<<(std::ostream &_stream, SymbolTableEntry const &mc)
{
    std::string s = std::to_string(mc.obj_type) + "|" + mc.id + "|" + mc.type + "|" + std::to_string(mc.offset);
    _stream << s;

    return _stream;
}