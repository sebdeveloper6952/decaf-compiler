#include <iostream>

#include "SymbolTable.h"
#include "SymbolTableEntry.h"
#include "DataTypes.h"

SymbolTable::SymbolTable(SymbolTable *parent, std::string const &name)
{
    this->parent = parent;
    this->name = name;
}

SymbolTable *SymbolTable::get_parent()
{
    return this->parent;
}

std::string const &SymbolTable::get_name()
{
    return this->name;
}

bool SymbolTable::put(
    int obj_type,
    std::string const &id,
    std::string const &type,
    size_t size)
{
    std::cout << "[ST '" << this->name << "']: put(): " << id << std::endl;
    if (this->table.count(id))
        return false;

    int data_type = DataTypes::type_to_int(type);
    SymbolTableEntry *entry = new SymbolTableEntry(
        id,
        obj_type,
        data_type,
        type,
        this->offset,
        size);
    this->table[id] = entry;

    // update the offset for the next data
    size_t new_offset = 0;
    if (type == "int")
        new_offset += W_INT;
    else if (type == "bool")
        new_offset += W_BOOL;
    else if (type == "char")
        new_offset += W_CHAR;

    // if obj is an array, multiply offset by array size
    if (obj_type == O_ARRAY)
        new_offset *= size;
    this->offset += new_offset;

    return true;
}

SymbolTableEntry *SymbolTable::get(std::string const &id)
{
    SymbolTable *top = this;
    while (top != NULL)
    {
        std::cout << "[ST '" << top->get_name() << "']: searching id: " << id << std::endl;

        if (top->table.count(id))
            return top->table[id];
        top = top->parent;
    }

    return NULL;
}

bool SymbolTable::rm(std::string const &id)
{
    this->table.erase(id);

    return true;
}

void SymbolTable::print_table()
{
    for (const auto &elem : this->table)
    {
        std::cout << elem.first << " => " << *elem.second << std::endl;
    }
}
