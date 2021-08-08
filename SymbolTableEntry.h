#include <string>
#include <iostream>

#pragma once

class SymbolTableEntry
{
    friend std::ostream &operator<<(std::ostream &_stream, SymbolTableEntry const &mc);

public:
    SymbolTableEntry(std::string const &id, std::string const &type, size_t offset);

    std::string id;
    std::string type;
    std::size_t offset;
};
