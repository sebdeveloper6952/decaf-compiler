#include <string>
#include <iostream>
#include <vector>

class SymbolTableEntry
{
    friend std::ostream &operator<<(std::ostream &_stream, SymbolTableEntry const &mc);

public:
    SymbolTableEntry(
        std::string const &id,
        int obj_type,
        int data_type,
        std::string const &type,
        size_t offset,
        size_t size);

    std::string id;
    int obj_type;
    int data_type;
    std::string type;
    std::size_t offset;
    std::size_t size;
    std::vector<int> m_params;
};
