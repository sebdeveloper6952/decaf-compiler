#include <string>

#include "DataTypes.h"

DataTypes *DataTypes::instance = 0;

DataTypes *DataTypes::get_instance()
{
    if (instance == 0)
        instance = new DataTypes();

    return instance;
}

DataTypes::DataTypes()
{
    // this->types[1] = "int";
    // this->types[2] = "bool";
    // this->types[3] = "char";
    // this->types[4] = "error";
    // this->types[5] = "void";
    add_type("int");
    add_type("bool");
    add_type("char");
    add_type("error");
    add_type("void");
    add_type("struct");
}

int DataTypes::add_type(std::string new_type)
{
    types[next_type] = new_type;
    r_types[new_type] = next_type;

    return next_type++;
}

std::string DataTypes::get_type(int type)
{
    if (types.count(type) > 0)
        return types[type];

    return NULL;
}

int DataTypes::get_type_int(std::string type)
{
    if (r_types.count(type) > 0)
        return r_types[type];

    return NULL;
}

// std::string DataTypes::int_to_type(int type)
// {
//     std::string t = "error";
//     if (type == T_INT)
//         t = "int";
//     if (type == T_BOOL)
//         t = "bool";
//     if (type == T_CHAR)
//         t = "char";
//     if (type == T_VOID)
//         t = "void";
//     if (type == T_STRUCT)
//         t = "struct";
//     return t;
// }

// int DataTypes::type_to_int(std::string type)
// {
//     if (type == "int")
//         return T_INT;
//     if (type == "bool")
//         return T_BOOL;
//     if (type == "char")
//         return T_CHAR;
//     if (type == "void")
//         return T_VOID;
//     if (type == "struct")
//         return T_STRUCT;
//     return T_ERROR;
// }

std::string DataTypes::int_to_obj_type(int type)
{
    std::string t = "";
    if (type == O_DATA)
        t = "DATA";
    if (type == O_ARRAY)
        t = "ARRAY";
    if (type == O_METHOD)
        t = "METHOD";
    if (type == O_STRUCT)
        t = "STRUCT";
    return t;
}