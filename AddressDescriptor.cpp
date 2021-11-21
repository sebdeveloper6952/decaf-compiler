#include <vector>
#include <algorithm>
#include "MipsGen.h"

AddressDescriptor::AddressDescriptor()
{}

bool AddressDescriptor::is_in_register(LocType *loc)
{
    std::string key = loc->to_key();

    if (this->descriptor.count(key))
    {
        for (auto loc : this->descriptor[key])
        {
            if (loc->type == LOC_REG)
                return true;
        }
    }

    return false;
}

LocType *AddressDescriptor::get_register(LocType *loc)
{
    std::string key = loc->to_key();
    if (this->descriptor.count(key))
    {
        for (auto loc : this->descriptor[key])
        {
            if (loc->type == LOC_REG)
                return loc;
        }
    }

    return NULL;
}

void AddressDescriptor::add_loc(LocType loc, LocType *new_loc)
{

    std::string key = loc.to_key();
    if (this->descriptor.count(key) == 0)
        this->descriptor[key] = std::vector<LocType *>();
    this->descriptor[key].push_back(new_loc);
}

void AddressDescriptor::set_only_loc(LocType loc, LocType *new_loc)
{
    std::string key = loc.to_key();
    
    if (this->descriptor.count(key) == 0)
        this->descriptor[key] = std::vector<LocType *>();
    
    this->descriptor[key].clear();
    this->descriptor[key].push_back(new_loc);
}

/**
 * Remove a register reg from all address descriptors except the one identified
 * by loc. 
 */
void AddressDescriptor::remove_from_all_except(LocType loc, std::string reg)
{
    std::string key = loc.to_key();
    for (auto loc : this->descriptor)
    {
        if (loc.first != key)
        {
            int i = 0;
            for (i; i < this->descriptor[loc.first].size(); i++)
            {
                LocType *lloc = this->descriptor[loc.first].at(i);
                if (lloc->type == LOC_REG && lloc->value == reg)
                    break;
            }
            if (i != this->descriptor[loc.first].size())
                this->descriptor[loc.first].erase(this->descriptor[loc.first].begin() + i);
        }
    }
}

bool AddressDescriptor::has_loc(LocType loc_0, LocType *loc_1)
{
    std::string key = loc_0.to_key();
    if (this->descriptor.count(key))
    {
        for (auto loc : this->descriptor[key])
            if (key == loc_1->to_key())
                return true;
    }

    return false;
}

void AddressDescriptor::clear()
{
    this->descriptor.clear();
}

std::vector<LocType *> *AddressDescriptor::get_locs(LocType *loc)
{
    return &this->descriptor[loc->to_key()];
}
