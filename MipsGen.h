#pragma once

#include <vector>
#include <string>
#include "SymbolTable.h"
#include "Typedefs.h"

// memory location types
#define LOC_GBL 0
#define LOC_STK 1
#define LOC_REG 2
#define LOC_TMP 3
#define LOC_LIT 4

class LocType {
public:
    uint8_t type;
    uint8_t offset;
    bool is_array;
    std::string value;
    std::string arr_offset;
    
    bool operator<(const LocType &ob) const {
        if (type != ob.type)
            return true;

        return offset != ob.offset || value != ob.value;
    }

    std::string to_key()
    {
        std::string key = "";
        if (this->type == LOC_GBL)
        {
            // key += this->value;
            key += "global";
        }
        else if(this->type == LOC_STK)
        {
            key += std::to_string(this->offset);
            key += "($sp)";
        }
        else if (this->type == LOC_REG)
        {
            key += this->value;
        }
        else if (this->type == LOC_TMP)
        {
            key += this->value;
        }
        else if (this->type == LOC_LIT)
        {
            key += this->value;
        }

        if (this->is_array)
            key += "[" + this->arr_offset + "]";

        return key;
    }
};

class MipsInstr {
public:
    MipsInstr(std::string c);
    std::string rep;
    std::string to_string();
};

class GetRegRes {
public:
    std::vector<MipsInstr *> instrs;
    std::string r0, r1, r2;
};

class AddressDescriptor {
public:
    AddressDescriptor();
    bool is_in_register(LocType *loc);
    LocType *get_register(LocType *loc);
    void add_loc(LocType loc, LocType *new_loc);
    void set_only_loc(LocType loc, LocType *new_loc);
    void remove_from_all_except(LocType loc, std::string reg);
    bool has_loc(LocType loc_0, LocType *loc_1);
    std::vector<LocType *> *get_locs(LocType *loc);
    void clear();
    void to_string()
    {
        for (auto p : this->descriptor)
        {
            std::cout << "\t[AddrDes] " << p.first << " => ";
            for (auto l : this->descriptor[p.first])
            {
                std::cout << l->to_key() << ",";
            }
            std::cout << std::endl;
        }
    }
private:
    std::map<std::string, std::vector<LocType *>> descriptor;
};

class RegisterDescriptor {
public:
    RegisterDescriptor();
    bool has_free();
    LocType *get_one();
    LocType *get_occupied(std::vector<std::string> *exc);
    std::vector<LocType *> *get_locs(std::string reg);
    LocType *get_loc(LocType *loc);
    void add_loc(std::string reg, LocType *loc);
    void set_only_loc(std::string reg, LocType *loc);
    void clear_reg(std::string reg);
    void clear();
    void to_string()
    {
        for (auto p : this->descriptor)
        {
            std::cout << "\t[RegDes] " << p.first << " => ";
            for (auto l : this->descriptor[p.first])
            {
                // if (l->type == LOC_STK)
                //     std::cout << std::to_string(l->offset) << "($sp)";
                // else
                //     std::cout << l->value << ",";
                std::cout << l->to_key() + ",";
            }
            std::cout << std::endl;
        }
    }
private:
    std::map<std::string, std::vector<LocType *>> descriptor;
};

class MipsGen
{
public:
    MipsGen();
    uint fn_size;
    std::vector<IcgInstr *> params;
    std::string gen_code(SymbolTable *table, TypeIcgVec &instrs);
    std::string gen_data_section(SymbolTable *st);
    std::string gen_text_section(SymbolTable *st, TypeIcgVec &instrs);
    std::string gen_macros();
    std::string gen_start_seq(uint bytes);
    std::string gen_exit_seq();
private:
    AddressDescriptor *ad;
    RegisterDescriptor *rd;
    LocType *get_reg_i(LocType *loc, GetRegRes *res);
    LocType *get_loc_for_ste(SymbolTableEntry *e, std::string l);
    GetRegRes *get_reg_for_copy(IcgInstr *i);
    std::string op_to_mips(uint8_t op);
};
