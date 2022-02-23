#pragma once
#include "cardinal.hpp"

string encrypt(const string& a,const string& key="");
string decrypt(const string& a,const string& key="");
string shash(const string& a);

string encode(const string& a);
string decode(const string& a);

inline const map<string,string> default_kv={
    {"password",shash("passwd")},
};

using dbT=map<string,string>;

extern dbT data_base;

struct user{
    string pos,description,name,pwd;
    string to_string() const;
    static user from_string(string str);
};

extern vec<user> user_list;

void syncdb();

void inidb1();
void inidb2();
