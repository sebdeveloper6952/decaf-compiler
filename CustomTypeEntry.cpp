#include "CustomTypeEntry.h"
#include "DataTypes.h"

CustomTypeEntry::CustomTypeEntry(
    std::string id)
{
    this->id = id;
}

// Override << operator
std::ostream &operator<<(std::ostream &_stream, CustomTypeEntry const &e)
{
    _stream << e.id;

    return _stream;
}