#include <iostream>
#include <fstream>
#include <random>
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

/**
 * https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
 */
int Utils::random_int(int max)
{
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, max - 1); // define the range

    return distr(gen);
}