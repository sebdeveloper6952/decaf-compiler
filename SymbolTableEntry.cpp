#include "SymbolTableEntry.h"
#include "DataTypes.h"

SymbolTableEntry::SymbolTableEntry(
    std::string const &id,
    int obj_type,
    int data_type,
    std::string const &type,
    size_t offset,
    size_t size = 0)
{
    this->id = id;
    this->obj_type = obj_type;
    this->data_type = data_type;
    this->type = type;
    this->offset = offset;
    this->size = size;
}

// Override << operator
std::ostream &operator<<(std::ostream &_stream, SymbolTableEntry const &e)
{
    std::string s = DataTypes::int_to_obj_type(e.obj_type) + "|" + e.id + "|" + e.type + "|" + std::to_string(e.offset);
    _stream << s;

    return _stream;
}