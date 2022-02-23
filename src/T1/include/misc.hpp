#pragma once
#include "cardinal.hpp"
inline vec<string>  split(const string& str,const string& c){
    vec<string> a;
    for (size_t i=0,j=0;i<str.size();){
        i=str.find(c,j);
        if (i!=j)
            a.push_back(str.substr(j,i-j));
        if (i<str.size())
            i=j=i+c.size();
        else 
            break;
    }
    return a;
}