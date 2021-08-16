#include <cstddef>
#include <map>
#include <string>
#include "SymbolTableEntry.h"

#pragma once

class SymbolTable
{
private:
    std::size_t num_entries = 0;
    std::size_t offset = 0;
    std::map<std::string, SymbolTableEntry *> table;
    SymbolTable *parent;
    std::string name;

public:
    SymbolTable() = default;
    SymbolTable(SymbolTable *parent, std::string const &name);
    size_t get_num_entries();
    size_t get_offset();
    SymbolTable *get_parent();
    std::string const &get_name();
    bool put(
        int s_type,
        std::string const &id,
        std::string const &type,
        size_t size = 0);
    SymbolTableEntry *get(std::string const &lexeme);
    bool rm(std::string const &lexeme);
    bool add_method_param(std::string id, std::string type);
    void print_table();
};
