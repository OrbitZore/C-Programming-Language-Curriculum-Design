#pragma once
#include "cardinal.hpp"
#include "os.hpp"
string encrypt(const string& a);
string decrypt(const string& a);
string encode(const string& a);
string decode(const string& a);

inline const map<string,string> default_kv={
    {"username","root"},
    {"password","passwd"},
};

struct dbT:map<string,string>{
    dbT();
    ~dbT();
};

extern dbT data_base;

void syncdb();

void ini_user_data();
