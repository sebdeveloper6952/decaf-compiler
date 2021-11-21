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
    
    size_t min_score = 999;
    LocType *best_reg = new LocType();
    best_reg->type = LOC_REG;

    for (auto reg : this->descriptor)
    {
        size_t curr_score = 0;
        if (std::find(exc->begin(), exc->end(), reg.first) == exc->end())
        {
            for (auto loc : *this->get_locs(reg.first))
            {
                if (loc->type != LOC_LIT)
                    curr_score += 1;
            }

            if (curr_score < min_score)
            {
                best_reg->value = reg.first;
                min_score = curr_score;
            }
        }
    }

    return best_reg;
}

void RegisterDescriptor::add_loc(std::string reg, LocType *loc)
{
    if (this->descriptor.count(reg))
        this->descriptor[reg].push_back(loc);
}

void RegisterDescriptor::set_only_loc(std::string reg, LocType *loc)
{
    if (this->descriptor.count(reg))
    {
        this->descriptor[reg].clear();
        this->descriptor[reg].push_back(loc);
    }
}

std::vector<LocType *> *RegisterDescriptor::get_locs(std::string reg)
{
    return &this->descriptor[reg];
}

LocType *RegisterDescriptor::get_loc(LocType *loc)
{
    for (auto p : this->descriptor)
    {
        for (auto l : this->descriptor[p.first])
        {
            if (l->type == loc->type && l->value == loc->value)
            {
                LocType *reg = new LocType();
                reg->type = LOC_REG;
                reg->value = p.first;
                
                return reg;
            }
        }
    }

    return NULL;
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
