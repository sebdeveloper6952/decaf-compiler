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

    return "error";
}

int DataTypes::get_type_int(std::string type)
{
    if (r_types.count(type) > 0)
        return r_types[type];

    return -1;
}

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