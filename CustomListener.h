#pragma once

#include "antlr4-runtime.h"
#include "DecafBaseListener.h"

/**
 * This class provides an empty implementation of DecafListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class CustomListener : public DecafBaseListener
{
public:
    void enterProgram(DecafParser::ProgramContext *ctx);
    void exitProgram(DecafParser::ProgramContext *ctx);
};
