#pragma once
#include "cardinal.hpp"
#include "vector.hpp"

using rgb=array<uint8_t,3>;

struct bitmap{
    int n,m;
    vec<rgb> c;
    bitmap(int n,int m):n(n),m(m){
        c.resize(n*m);
    }
    rgb& operator()(int i,int j){
        return c[i*m+j];
    }
    string to_bmp(){
    }
};
