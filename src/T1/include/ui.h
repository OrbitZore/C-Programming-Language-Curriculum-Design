#pragma once

#include "cardinal.hpp"
namespace ui{

string getline(const string& msg,bool allow_empty=false);

istream& getline(string &str,const string& msg,bool allow_empty=false);

int choose(const vec<string>& v,const string& name="");

size_t getint(size_t l,size_t r,const string& msg="");
}
