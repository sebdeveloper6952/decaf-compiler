#include <iostream>
#include <fstream>
#include "Utils.h"

int Utils::write_to_file(std::string name, std::vector<std::string> lines)
{
    std::ofstream output_file(name);
    if (output_file.is_open())
    {
        for (std::string line : lines)
            output_file << line << std::endl;
        output_file.close();
        
        return 0;
    }

    return -1;
}