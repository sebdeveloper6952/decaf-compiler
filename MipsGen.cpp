#include "SymbolTable.h"
#include "MipsGen.h"
#include "DataTypes.h"

MipsGen::MipsGen()
{
    this->ad = new AddressDescriptor();
    this->rd = new RegisterDescriptor();
}

std::string MipsGen::gen_code(SymbolTable *st, TypeIcgVec &instrs)
{   
    std::string code = "";
    code += this->gen_data_section(st);
    code += this->gen_text_section(st, instrs);

    return code;
}

std::string MipsGen::gen_data_section(SymbolTable *st)
{
    std::string code = "";
    
    code += ".data\n";

    code += "\tprint_int_msg: .asciiz \"print_int(): \"\n";
    
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
            mips_data += ".align 2\n" + p.second->id + ": .space ";

            if (p.second->data_type == T_INT)
                arr_size *= W_INT;

            mips_data += std::to_string(arr_size);
        }

        // accumulate code
        if (mips_data.length())
            code += mips_data + "\n";
        mips_data.clear();
    }

    return code;
}

std::string MipsGen::gen_text_section(SymbolTable *st, TypeIcgVec &instrs)
{
    std::string code = ".text\n";

    std::string macros = this->gen_macros();
    code += macros + "\n";

    code += this->gen_start_seq(0);

    for (int j = 0; j < instrs.size(); j++)
    {   
        IcgInstr *i = instrs[j];
        std::cout << i->to_string() << std::endl;

        if (i->op_code <= OP_MOD)
        {
            GetRegRes *res = new GetRegRes();

            LocType *loc_a0 = this->get_loc_for_ste(i->e_a0, i->a0);
            LocType *loc_a1 = this->get_loc_for_ste(i->e_a1, i->a1);
            LocType *loc_res = this->get_loc_for_ste(i->e_res, i->res);

            LocType *r1 = this->get_reg_i(loc_a0, res);
            res->r1 = r1->value;
            LocType *r2 = this->get_reg_i(loc_a1, res);
            res->r2 = r2->value;
            LocType *r0 = this->get_reg_i(loc_res, res);
            res->r0 = r0->value;

            // set Rx to only hold loc_res
            this->rd->set_only_loc(res->r0, loc_res);

            // set address descriptor for loc_res to only hold Rx
            this->ad->set_only_loc(*loc_res, r0);

            // remove Rx from the address descriptor of every name except res
            this->ad->remove_from_all_except(*loc_res, res->r0);

            // any stores/loads that where necesary to get a register
            for (auto i : res->instrs)
                code += i->to_string();
            
            // generate mips op
            code += this->op_to_mips(i->op_code) + " " + res->r0 + ", " + res->r1 + ", " + res->r2 + "\n";

            // housekeeping
            if (loc_a0->type == LOC_LIT)
                this->rd->clear_reg(r1->value);
            if (loc_a1->type == LOC_LIT)
                this->rd->clear_reg(r2->value);
        }

        else if (i->op_code == OP_FN)
        {
            this->ad->clear();
            this->rd->clear();

            // calculate function size as WORD size + entry size
            uint fn_size = 4 + i->e_res->size;
            code += i->res + ":\n";
            code += "stalloc(" + std::to_string(fn_size) + ")\n";

            // save current function size
            this->fn_size = fn_size;
        }

        else if (i->op_code == OP_EFN)
        {
            uint fn_size = 4 + i->e_res->size;
            code += "stfree(" + std::to_string(fn_size) + ")\n";
            code += "jr $ra\n\n";
        }

        else if (i->op_code == OP_PARM)
        {
            std::cout << "param " << i->a0 << std::endl;
            this->params.push_back(i);
        }
        
        else if (i->op_code == OP_CALL)
        {
            uint fn_size = 4 + i->e_a0->size;
            for (int i = 0; i < this->params.size(); i++)
            {
                std::cout << "store param at -" << std::to_string(fn_size - 4 * i) << "($sp)" << std::endl;
                IcgInstr *icg = this->params[i];
                if (icg->e_a0 != NULL)
                {
                    std::cout << "\tid: " << icg->e_a0->id << std::endl;
                    LocType *loc = this->get_loc_for_ste(icg->e_a0, icg->a0);
                    GetRegRes *res = new GetRegRes();
                    LocType *reg = this->get_reg_i(loc, res);
                    std::cout << "\tkey: " << loc->to_key() << std::endl;

                    for (auto i : res->instrs)
                        code += i->to_string();
                    code += "sw " + reg->value + ", -" + std::to_string(fn_size - 4 * i) + "($sp)\n";
                }
            }
            this->params.clear();

            code += "sw $ra, " + std::to_string(this->fn_size - 4) + "($sp)\n";
            code += "jal " + i->a0 + "\n";
            code += "lw $ra, " + std::to_string(this->fn_size - 4) + "($sp)\n";
        }

        else if (i->op_code == OP_RET)
        {
            std::cout << "RETURN from fn " << i->e_res->id << std::endl;
            
            LocType *loc = this->get_loc_for_ste(i->e_a0, i->a0);
            GetRegRes *res = new GetRegRes();
            LocType *reg = this->get_reg_i(loc, res);

            code += "move $v0, " + reg->value + "\n";
        }
        
        else if (i->op_code == OP_ASGN)
        {
            GetRegRes *res = new GetRegRes();

            LocType *loc_a0 = this->get_loc_for_ste(i->e_a0, i->a0);
            LocType *loc_res = this->get_loc_for_ste(i->e_res, i->res);
            LocType *r1 = this->get_reg_i(loc_a0, res);
            
            res->r1 = r1->value;

            for (auto i : res->instrs)
                code += i->to_string();

            if (loc_res->type == LOC_GBL)
            {
                code += (new MipsInstr("sw " + r1->value + ", " + loc_res->value + "\n"))->to_string();
                
            }
            else if (loc_res->type == LOC_STK)
            {
                code += (new MipsInstr("sw " + r1->value + ", " + std::to_string(loc_res->offset) + "($sp)\n"))->to_string();
            }

            // update register descriptor of r1 to hold loc_res
            this->rd->add_loc(res->r1, loc_res);
            
            // update address descriptor for loc_res to only hold r1
            this->ad->set_only_loc(*loc_res, r1);
        }

        else if (i->op_code == OP_IF)
        {
            IcgInstr *prev = instrs[j - 1];
            GetRegRes *res = new GetRegRes();

            LocType *loc_a0 = this->get_loc_for_ste(prev->e_a0, prev->a0);
            LocType *loc_a1 = this->get_loc_for_ste(prev->e_a1, prev->a1);

            LocType *r1 = this->get_reg_i(loc_a0, res);
            res->r1 = r1->value;
            LocType *r2 = this->get_reg_i(loc_a1, res);
            res->r2 = r2->value;

            // any stores/loads that where necesary to get a register
            for (auto i : res->instrs)
                code += i->to_string();

            // gen branching code
            if (prev->op_code == OP_LT)
                code += "blt ";
            else if (prev->op_code == OP_LTE)
                code += "ble ";
            else if (prev->op_code == OP_GT)
                code += "bgt ";
            else if (prev->op_code == OP_GTE)
                code += "bge ";
            else if (prev->op_code == OP_EQ)
                code += "beq ";
            else if (prev->op_code == OP_NEQ)
                code += "bne ";

            // complete operation
            code += r1->value + ", " + r2->value + ", " + i->res + "\n";
        }

        else if (i->op_code == OP_GOTO)
        {
            code += "j " + i->res + "\n";
        }

        else if (i->op_code == OP_LBL)
        {
            code += i->res + ":\n";
        }
    }

    code += this->gen_exit_seq();

    return code;
}

std::string MipsGen::gen_macros()
{
    std::string macros = ".macro stalloc(%bytes)\n";
    macros += "\tsub $sp, $sp, %bytes\n";
    macros += ".end_macro\n";

    macros += ".macro stfree(%bytes)\n";
	macros += "\tadd $sp, $sp, %bytes\n";
    macros += ".end_macro\n";

    macros += ".macro print_int()\n";
    macros += "\tmove $a1, $a0\n";
    macros += "\tla $a0, print_int_msg\n";
    macros += "\tli $v0, 4\n";
    macros += "\tsyscall\n";
    macros += "\tmove $a0, $a1\n";
    macros += "\tli $v0, 1\n";
    macros += "\tsyscall\n";
    macros += ".end_macro\n";

    return macros;
}

std::string MipsGen::gen_start_seq(uint bytes)
{
    std::string code = "_start_:\n";
    code += "\tjal main\n";
    code += "\tj exit\n";

    return code;
}

std::string MipsGen::gen_exit_seq()
{
    std::string code = "exit:\n";
    code += "\tli $v0, 10\n";
    code += "\tsyscall\n";

    return code;
}

GetRegRes *MipsGen::get_reg_for_copy(IcgInstr *i)
{
    GetRegRes *res = new GetRegRes();

    LocType *loc_a0 = this->get_loc_for_ste(i->e_a0, i->a0);
    LocType *loc_res = this->get_loc_for_ste(i->e_res, i->res);
    LocType *r1 = this->get_reg_i(loc_a0, res);
    
    res->r1 = r1->value;

    // update register descriptor of r1 to hold loc_res
    this->rd->add_loc(res->r1, loc_res);
    
    // update address descriptor for loc_res to only hold r1
    this->ad->set_only_loc(*loc_res, r1);

    return res;
}

LocType *MipsGen::get_loc_for_ste(SymbolTableEntry *e, std::string l)
{
    LocType *loc = new LocType();
    if (e != NULL)
    {
        if (e->is_global)
        {
            loc->type = LOC_GBL;
            loc->value = e->id;
        }
        else
        {
            loc->type = LOC_STK;
            loc->offset = e->offset;    
        }
    }
    else
    {
        try
        {
            int i = std::stoi(l);
            loc->type = LOC_LIT;
            loc->value = l;
        }
        catch(const std::exception& e)
        {
            loc->type = LOC_TMP;
            loc->value = l;
        }
    }
    
    return loc;
}

LocType *MipsGen::get_reg_i(LocType *loc, GetRegRes *res)
{
    // already in register
    LocType *reg = NULL;
    std::string loc_key = loc->to_key();
    if (this->ad->is_in_register(loc))
    {
        std::cout << "[get_reg_i] " << loc_key << " already in register." << std::endl;
        reg = this->ad->get_register(loc);
    }
    // get a free register
    else if (this->rd->has_free())
    {
        std::cout << "[get_reg_i] " << loc_key << " not in register, getting a free one." << std::endl;
        reg = this->rd->get_one();
        
        if (loc->type == LOC_LIT)
        {
            res->instrs.push_back(new MipsInstr("li " + reg->value + ", " + loc->value + "\n"));

            // update register descriptor to include only loc
            this->rd->set_only_loc(reg->value, loc);
        }
        
        else if (loc->type != LOC_TMP)
        {
            std::string s = "lw " + reg->value + ", ";
            s += loc->to_key() + "\n";
            
            // generate load instruction
            MipsInstr *load = new MipsInstr(s);
            res->instrs.push_back(load);

            // update register descriptor to include only loc
            this->rd->set_only_loc(reg->value, loc);

            // update address descriptor of location to include new register
            this->ad->add_loc(*loc, reg);

        }
    }
    // fck
    else
    {
        std::cout << "[get_reg_i] " << loc_key << " not in register, getting a occupied one." << std::endl;
        std::vector<std::string> exc;
        if (res->r1.length()) exc.push_back(res->r1);
        if (res->r2.length()) exc.push_back(res->r2);
        reg = this->rd->get_occupied(&exc);
        std::vector<LocType *> *locs = this->rd->get_locs(reg->value);
        for (auto loc : *locs)
        {
            std::cout << "[get_reg_i] need to store " << loc->to_key() << std::endl;
            if (!this->ad->has_loc(*loc, loc))
            {
                res->instrs.push_back(new MipsInstr("sw " + reg->value + ", " + loc->to_key() + "\n"));
                // update address descriptor for loc to include its own memory location
                this->ad->add_loc(*loc, loc);
            }
        }

        if (loc->type != LOC_TMP)
        {
            // generate load
            res->instrs.push_back(new MipsInstr("lw " + reg->value + ", " + loc_key + "\n"));
        }
    }

    return reg;
}

std::string MipsGen::op_to_mips(uint8_t op)
{
    if (op == OP_SUM)
        return "add";
    if (op == OP_SUB)
        return "sub";
    if (op == OP_MUL)
        return "mul";
    if (op == OP_DIV)
        return "div";
    if (op == OP_MOD)
        return "div";
    if (op == OP_AND)
        return "and";
    if (op == OP_OR)
        return "or";
    return "not_implemented";
}


std::string MipsInstr::to_string()
{
    return rep;
}
