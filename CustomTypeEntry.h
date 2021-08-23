#include <string>
#include <iostream>
#include <vector>

class CustomTypeEntry
{
    friend std::ostream &operator<<(std::ostream &_stream, CustomTypeEntry const &mc);

public:
    CustomTypeEntry(
        std::string id);

    std::string id;
};
