#include "CustomListener.h"
#include <iostream>

void CustomListener::enterProgram(DecafParser::ProgramContext *ctx)
{
    std::cout << "enterProgram" << std::endl;
}

void CustomListener::exitProgram(DecafParser::ProgramContext *ctx)
{
    std::cout << "exitProgram" << std::endl;
}
