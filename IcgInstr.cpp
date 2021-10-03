#include "IcgInstr.h"

IcgInstr::IcgInstr(uint8_t op_code, std::string a0, std::string a1, std::string res)
{
    this->op_code = op_code;
    this->a0 = a0;
    this->a1 = a1;
    this->res = res;
}

uint8_t IcgInstr::op_to_int(std::string op)
{
    if (op == "+")
        return OP_SUM;
    if (op == "-")
        return OP_SUB;
    if (op == "*")
        return OP_MUL;
    if (op == "/")
        return OP_DIV;
    if (op == "%")
        return OP_MOD;
    if (op == ">")
        return OP_GT;
    if (op == ">=")
        return OP_GTE;
    if (op == "<")
        return OP_LT;
    if (op == "<=")
        return OP_LTE;
    if (op == "&&")
        return OP_AND;
    if (op == "||")
        return OP_OR;
    if (op == "==")
        return OP_EQ;
    if (op == "!=")
        return OP_NEQ;
    return 99;
}
