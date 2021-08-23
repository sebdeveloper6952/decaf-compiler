#pragma once

#define W_INT 4
#define W_BOOL 1
#define W_CHAR 1

#define O_DATA 0
#define O_METHOD 1
#define O_STRUCT 2
#define O_ARRAY 3
#define O_STRUCT_I 4

#define T_INT 1
#define T_BOOL 2
#define T_CHAR 3
#define T_ERROR 4
#define T_VOID 5

class DataTypes
{
public:
    static std::string int_to_type(int type);
    static int type_to_int(std::string type);
    static std::string int_to_obj_type(int type);
};
