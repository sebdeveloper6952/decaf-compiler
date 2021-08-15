#include <string>

#include "DataTypes.h"

std::string DataTypes::int_to_type(int type)
{
    std::string t = "error";

    if (type == T_INT)
        t = "INTEGER";
    if (type == T_BOOL)
        t = "BOOLEAN";
    if (type == T_CHAR)
        t = "CHAR";
    if (type == T_VOID)
        t = "VOID";

    return t;
}

int DataTypes::type_to_int(std::string type)
{
    if (type == "int")
        return T_INT;
    if (type == "boolean")
        return T_BOOL;
    if (type == "char")
        return T_CHAR;
    if (type == "void")
        return T_VOID;
    return T_ERROR;
}