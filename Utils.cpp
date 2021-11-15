#include <iostream>
#include <fstream>
#include "Utils.h"

int Utils::write_to_file(std::string name, std::string text)
{
    std::ofstream output_file(name);
    if (output_file.is_open())
    {
        output_file << text << std::endl;
        output_file.close();
        
        return 0;
    }

    return -1;
}