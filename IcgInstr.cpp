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

std::string IcgInstr::int_to_op(uint8_t op)
{
    if (op == OP_SUM)
        return "ADD";
    if (op == OP_SUB)
        return "SUB";
    if (op == OP_MUL)
        return "MUL";
    if (op == OP_DIV)
        return "DIV";
    if (op == OP_MOD)
        return "MOD";
    if (op == OP_GT)
        return "GT";
    if (op == OP_GTE)
        return "GTE";
    if (op == OP_LT)
        return "LT";
    if (op == OP_LTE)
        return "LTE";
    if (op == OP_AND)
        return "AND";
    if (op == OP_OR)
        return "OR";
    if (op == OP_EQ)
        return "EQ";
    if (op == OP_NEQ)
        return "NEQ";
    if (op == OP_IF)
        return "IF";
    if (op == OP_GOTO)
        return "GOTO";
    if (op == OP_PARM)
        return  "PARAM";
    if (op == OP_CALL)
        return "CALL";
    if (op == OP_RET)
        return "RETURN";
    if (op == OP_ASGN)
        return "ASSIGN";
    if (op == OP_LBL)
        return "LABEL";
    if (op == OP_EBL)
        return "ENDLABEL";
    if (op == OP_FN)
        return "FUNCTION";
    if (op == OP_EFN)
        return "ENDFUNCTION";
    
    return "NONE";
}

std::string IcgInstr::to_string()
{
    std::string s = "|";
    s += IcgInstr::int_to_op(this->op_code) + "|";
    s += this->a0.length() ? this->a0 : "NONE";
    s += "|";
    s += this->a1.length() ? this->a1 : "NONE";
    s += "|";
    s += this->res.length() ? this->res : "NONE";
    s += "|";
    return s;
}
