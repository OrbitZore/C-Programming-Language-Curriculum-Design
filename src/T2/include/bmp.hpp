#pragma once
#include "cardinal.hpp"
#include "vector.hpp"

using rgb=array<uint8_t,3>;

template<class T>
struct _bitmap{
    size_t n,m;
    vec<T> c;
    _bitmap()=default;
    _bitmap(size_t n,size_t m):n(n),m(m){
        c.resize(n*m);
    }
    auto operator()(size_t i,size_t j){
        return c[i*m+j];
    }
    void print(){
        for (size_t i=0;i<n;i++){
            for (size_t j=0;j<n;j++)
                cout<<c[i][j];
            cout<<endl;
        }
    }
    string to_bmp(){
    }
};

using bitmap=_bitmap<bool>;
using rgbmap=_bitmap<rgb>;