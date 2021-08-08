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

bool SymbolTable::put(std::string const &id, std::string const &type)
{
    if (this->table.find(id) != this->table.end())
        return false;

    SymbolTableEntry *entry = new SymbolTableEntry(id, type, this->offset);
    this->table[id] = entry;

    // update the offset for the next data
    if (type == "int")
        this->offset += W_INT;
    else if (type == "boolean")
        this->offset += W_BOOL;
    else if (type == "char")
        this->offset += W_CHAR;

    return true;
}

SymbolTableEntry *SymbolTable::get(std::string const &id)
{
    SymbolTable *top = this;
    while (top != NULL)
    {
        std::cout << "searching " << id << " in " << top->get_name() << std::endl;

        if (top->table.count(id) > 0)
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