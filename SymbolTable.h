#pragma once
#include <cstddef>
#include <map>
#include <string>
#include "SymbolTableEntry.h"

class SymbolTable
{
private:
    uint num_entries = 0;
    uint offset = 0;
    SymbolTable *parent;
    std::string name;

public:
    SymbolTable() = default;
    SymbolTable(SymbolTable *parent, std::string const &name, uint offset = 0);
    std::map<std::string, SymbolTableEntry *> table;
    std::map<std::string, SymbolTable *> struct_tables;
    size_t get_num_entries();
    size_t get_offset();
    SymbolTable *get_parent();
    std::string const &get_name();
    bool put(
        int obj_type,
        int data_type,
        std::string const &id,
        std::string const &type,
        size_t size = 0);
    SymbolTableEntry *get(std::string const &lexeme);
    bool rm(std::string const &lexeme);
    bool add_method_param(std::string id, std::string type);
    bool add_struct_table(std::string id, SymbolTable *table);
    SymbolTable *get_struct_table(std::string id);
    void print_table();
};
