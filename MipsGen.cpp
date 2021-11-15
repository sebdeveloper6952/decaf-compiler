#include "SymbolTable.h"
#include "MipsGen.h"
#include "DataTypes.h"

std::string MipsGen::gen_code(SymbolTable *st, TypeIcgVec &instrs)
{   
    std::string code = "";
    code += gen_data_section(st);
    code += gen_text_section(st, instrs);

    return code;
}

std::string MipsGen::gen_data_section(SymbolTable *st)
{
    std::string code = "";
    
    code += ".data\n";
    
    // global variables
    std::string mips_data = "";
    for (auto p : st->table)
    {
        if (p.second->obj_type == O_DATA)
        {
            mips_data += p.second->id + ": ";
            
            if (p.second->data_type == T_INT)
                mips_data += ".word 0";
            else if (p.second->data_type == T_BOOL)
                mips_data += ".byte 0";
            else if (p.second->data_type == T_CHAR)
                mips_data += ".byte 0";
        }
        else if (p.second->obj_type == O_ARRAY)
        {
            int arr_size = p.second->size;
            mips_data += p.second->id + ": .space ";

            if (p.second->data_type == T_INT)
                arr_size *= W_INT;

            mips_data += std::to_string(arr_size);
        }

        // accumulate code
        if (mips_data.length())
            code += mips_data + "\n";
        mips_data.clear();
    }

    // close data section with align
    code += ".align 2\n";

    return code;
}

std::string MipsGen::gen_text_section(SymbolTable *st, TypeIcgVec &instrs)
{
    std::string code = ".text\n";

    std::string macros = MipsGen::gen_macros();
    code += macros + "\n";

    code += MipsGen::gen_start_seq(0);

    for (IcgInstr *i : instrs)
    {
        code += i->to_string() + "\n";
        if (i->op_code == OP_FN)
        {
            std::cout << "size of fn: " << std::to_string(i->e_res->size) << " bytes" << std::endl;
        }
    }

    code += MipsGen::gen_exit_seq();

    return code;
}

std::string MipsGen::gen_macros()
{
    std::string macros = ".macro stalloc(%bytes)\n";
    macros += "\tadd $sp, $sp, %bytes\n";
    macros += ".end_macro\n";

    macros += ".macro stfree(%bytes)\n";
	macros += "\tsub	$sp, $sp, %bytes\n";
    macros += ".end_macro";

    return macros;
}

std::string MipsGen::gen_start_seq(uint bytes)
{
    std::string code = "_start_:\n";
    if (bytes > 0)
        code += "\tstalloc(" + std::to_string(bytes) + ")\n";
    code += "\tjal _main_\n";
    code += "j _exit_\n";

    return code;
}

std::string MipsGen::gen_exit_seq()
{
    std::string code = "_exit_:\n";
    code += "\tli $v0, 10\n";
    code += "\tsyscall\n";

    return code;
}
