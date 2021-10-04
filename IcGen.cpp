#include "IcGen.h"

std::vector<std::string> IcGen::gen_code(std::vector<IcgInstr *> &instrs)
{
    std::vector<std::string> code;
    uint tc = 0;

    for (const auto i : instrs)
    {
        std::string c;
        for (int i = 0; i < tc; i++)
            c.insert(0, "  ");

        switch (i->op_code)
        {
        case OP_SUM:
            c += i->res + " = " + i->a0 + " + " + i->a1 + "\n";
            break;
        case OP_SUB:
            c += i->res + " = " + i->a0 + " - " + i->a1 + "\n";
            break;
        case OP_MUL:
            c += i->res + " = " + i->a0 + " * " + i->a1 + "\n";
            break;
        case OP_DIV:
            c += i->res + " = " + i->a0 + " / " + i->a1 + "\n";
            break;
        case OP_MOD:
            c += i->res + " = " + i->a0 + " % " + i->a1 + "\n";
            break;
        case OP_GT:
            c += i->res + " = " + i->a0 + " > " + i->a1 + "\n";
            break;
        case OP_GTE:
            c += i->res + " = " + i->a0 + " >= " + i->a1 + "\n";
            break;
        case OP_LT:
            c += i->res + " = " + i->a0 + " < " + i->a1 + "\n";
            break;
        case OP_LTE:
            c += i->res + " = " + i->a0 + " <= " + i->a1 + "\n";
            break;
        case OP_EQ:
            c += i->res + " = " + i->a0 + " == " + i->a1 + "\n";
            break;
        case OP_NEQ:
            c += i->res + " = " + i->a0 + " != " + i->a1 + "\n";
            break;
        case OP_MIN:
            c += i->res + " = -" + i->a0 + "\n";
            break;
        case OP_NEG:
            c += i->res + " = !" + i->a0 + "\n";
            break;
        case OP_IF:
            c += "if " + i->a0 + " goto " + i->res + "\n";
            break;
        case OP_GOTO:
            c += "goto " + i->res + "\n";
            break;
        case OP_PARM:
            c += "param " + i->a0 + "\n";
            break;
        case OP_CALL:
            if (i->res != "")
                c += i->res + " = ";
            c += "call " + i->a0 + ", " + i->a1 + "\n";
            break;
        case OP_RET:
            c += "ret " + i->a0 + "\n";
            break;
        case OP_ASGN:
            c += i->res + " = " + i->a0 + "\n";
            break;
        case OP_LBL:
            // ++tc;
            c += i->res + ":\n";
            break;
        case OP_EBL:
            // --tc;
            break;
        case OP_EFN:
            // --tc;
            c += "end_" + i->res + "\n";
            break;
        default:
            break;
        }
        code.push_back(c);
    }

    return code;
}