#pragma once

#include "SymbolTableEntry.h"
#include <string>

#define OP_SUM 0
#define OP_SUB 1
#define OP_MUL 2
#define OP_DIV 3
#define OP_MOD 4
#define OP_GT 5
#define OP_GTE 6
#define OP_LT 7
#define OP_LTE 8
#define OP_EQ 9
#define OP_NEQ 10
#define OP_AND 11
#define OP_OR 12
#define OP_MIN 13
#define OP_NEG 14
#define OP_IF 15
#define OP_GOTO 16
#define OP_PARM 17
#define OP_CALL 18
#define OP_RET 19
#define OP_ASGN 20
#define OP_LBL 21
#define OP_EBL 22
#define OP_EFN 23

class IcgInstr
{
public:
    IcgInstr() = default;
    IcgInstr(uint8_t op_code, std::string a0, std::string a1, std::string res);
    uint8_t op_code;
    std::string a0;
    std::string a1;
    std::string res;

    static uint8_t op_to_int(std::string op);
};