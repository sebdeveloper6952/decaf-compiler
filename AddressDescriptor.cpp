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
    std::cout << "[AddrDes] updating descriptor for ";
    std::cout << loc.to_key() << ", adding ";
    std::cout << new_loc->to_key() << std::endl;

    std::string key = loc.to_key();
    if (this->descriptor.count(key) == 0)
        this->descriptor[key] = std::vector<LocType *>();
    this->descriptor[key].push_back(new_loc);

    this->to_string();
}

void AddressDescriptor::set_only_loc(LocType loc, LocType *new_loc)
{
    std::string key = loc.to_key();
    
    if (this->descriptor.count(key) == 0)
        this->descriptor[key] = std::vector<LocType *>();
    
    std::cout << "[AddrDes] setting " << key << " to only location " << new_loc->to_key() << std::endl;
    this->descriptor[key].clear();
    this->descriptor[key].push_back(new_loc);

    this->to_string();
}

/**
 * Remove a register reg from all address descriptors except the one identified
 * by loc. 
 */
void AddressDescriptor::remove_from_all_except(LocType loc, std::string reg)
{
    std::string key = loc.to_key();

    std::cout << "[AddrDes] removing " << reg << " from all descriptors except " << key << std::endl;

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

    this->to_string();
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
