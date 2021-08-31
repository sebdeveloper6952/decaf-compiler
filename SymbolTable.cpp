#include <iostream>
#include "SymbolTable.h"
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
    int data_type,
    std::string const &id,
    std::string const &type,
    size_t size)
{
    // std::cout << "[ST '" << this->name << "']: put(): " << id << std::endl;
    if (this->table.count(id))
        return false;

    // save entry in table
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
        // std::cout << "[ST '" << top->get_name() << "']: searching id: " << id << std::endl;

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

bool SymbolTable::add_method_param(std::string id, std::string type)
{
    if (this->table.count(id) == 0)
        return false;

    // int p_type = DataTypes::type_to_int(type);
    int p_type = DataTypes::get_instance()->get_type_int(type);
    this->table[id]->m_params.push_back(p_type);

    // std::cout
    //     << "[ST '"
    //     << this->name
    //     << "']: add_param: ("
    //     << id
    //     << ", "
    //     << type
    //     << ")"
    //     << std::endl;

    return true;
}

/**
 * 
 */
bool SymbolTable::add_struct_table(std::string id, SymbolTable *table)
{
    this->struct_tables[id] = table;

    return true;
}

/**
 */
SymbolTable *SymbolTable::get_struct_table(std::string id)
{
    // std::cout
    //     << "[ST '"
    //     << this->name
    //     << "']: get_struct_table: '"
    //     << id
    //     << "'"
    //     << std::endl;

    SymbolTable *top = this;
    while (top != NULL)
    {
        // std::cout << "[ST '" << top->get_name() << "']: searching id: " << id << std::endl;

        if (top->table.count(id))
            return top->struct_tables[id];
        top = top->parent;
    }

    return NULL;
}

/**
 * Print the entries of a symbol table.
 */
void SymbolTable::print_table()
{
    for (const auto &elem : this->table)
    {
        std::cout << elem.first << " => " << *elem.second << std::endl;
    }
}
