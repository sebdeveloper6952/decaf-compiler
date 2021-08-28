#pragma once

#include <map>
#include <string>

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
#define T_STRUCT 6

#define T_INT_MIN -2147483648
#define T_INT_MAX 2147483647

class DataTypes
{
private:
    static DataTypes *instance;
    int next_type = 1;
    DataTypes();

public:
    static DataTypes *get_instance();
    std::map<int, std::string> types;
    std::map<std::string, int> r_types;
    int add_type(std::string new_type);
    std::string get_type(int type);
    int get_type_int(std::string type);
    // static std::string int_to_type(int type);
    // static int type_to_int(std::string type);
    static std::string int_to_obj_type(int type);
};