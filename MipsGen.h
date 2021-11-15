#pragma once

#include <vector>
#include <string>
#include "SymbolTable.h"
#include "Typedefs.h"

class MipsGen
{
public:
    MipsGen() = default;
    static std::string gen_code(SymbolTable *table, TypeIcgVec &instrs);
    static std::string gen_data_section(SymbolTable *st);
    static std::string gen_text_section(SymbolTable *st, TypeIcgVec &instrs);
    static std::string gen_macros();
    static std::string gen_start_seq(uint bytes);
    static std::string gen_exit_seq();
};