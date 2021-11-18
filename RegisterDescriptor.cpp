#include <vector>
#include <algorithm>
#include "MipsGen.h"
#include "Utils.h"

RegisterDescriptor::RegisterDescriptor()
{
    this->descriptor["$t0"] = std::vector<LocType *>();
    this->descriptor["$t1"] = std::vector<LocType *>();
    this->descriptor["$t2"] = std::vector<LocType *>();
    this->descriptor["$t3"] = std::vector<LocType *>();
    this->descriptor["$t4"] = std::vector<LocType *>();
    this->descriptor["$t5"] = std::vector<LocType *>();
    this->descriptor["$t6"] = std::vector<LocType *>();
    this->descriptor["$t7"] = std::vector<LocType *>();
    this->descriptor["$t8"] = std::vector<LocType *>();
    this->descriptor["$t9"] = std::vector<LocType *>();
}

bool RegisterDescriptor::has_free()
{
    for (auto p : this->descriptor)
        if (this->descriptor[p.first].size() == 0)
            return true;
    
    return false;
}

LocType *RegisterDescriptor::get_one()
{
    for (auto p : this->descriptor)
    {
        if (this->descriptor[p.first].size() == 0)
        {
            LocType *loc = new LocType();
            loc->type = LOC_REG;
            loc->value = p.first;

            return loc;
        }
    }

    return NULL;
}

LocType *RegisterDescriptor::get_occupied(std::vector<std::string> *exc)
{
    LocType *loc = NULL;

    for (auto reg : *exc)
    {
        std::cout << "[RegDes] give me one that is not " << reg << std::endl;
    }

    for (auto reg : this->descriptor)
    {
        if (std::find(exc->begin(), exc->end(), reg.first) == exc->end())
        {
            std::cout << "[RegDes] found a register " << reg.first << std::endl;
            loc = new LocType();
            loc->type = LOC_REG;
            loc->value = reg.first;

            return loc;
        }
    }

    return loc;
}

void RegisterDescriptor::add_loc(std::string reg, LocType *loc)
{
    if (this->descriptor.count(reg))
        this->descriptor[reg].push_back(loc);

    this->to_string();
}

void RegisterDescriptor::set_only_loc(std::string reg, LocType *loc)
{
    if (this->descriptor.count(reg))
    {
        this->descriptor[reg].clear();
        this->descriptor[reg].push_back(loc);
    }

    this->to_string();
}

std::vector<LocType *> *RegisterDescriptor::get_locs(std::string reg)
{
    return &this->descriptor[reg];
}

void RegisterDescriptor::clear_reg(std::string reg)
{
    if (this->descriptor.count(reg))
        this->descriptor[reg].clear();
}

void RegisterDescriptor::clear()
{
    for (auto i : this->descriptor)
        this->descriptor[i.first].clear();
}
