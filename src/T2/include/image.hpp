#pragma once
#include "cardinal.hpp"
#include "vector.hpp"
#include "bmp.hpp"

using rgb=array<uint8_t,3>;
inline ostream& operator<<(ostream& os,const rgb& a){
    return os<<"("<<(uint32_t)a[0]<<","<<(uint32_t)a[1]<<","<<(uint32_t)a[2]<<")";
}

template<class T>
struct _bitmap{
    size_t n,m;
    vec<T> c;
    inline _bitmap()=default;
    inline _bitmap(size_t n,size_t m):n(n),m(m){
        c.resize(n*m);
    }
    inline _bitmap(size_t n,size_t m,T a):n(n),m(m){
        c.resize(n*m,a);
    }
    inline decltype(auto) operator()(size_t i,size_t j){
        return c[i*m+j];
    }
    inline decltype(auto) operator()(size_t i,size_t j)const{
        return c[i*m+j];
    }
    inline void print(){
        for (size_t i=0;i<n;i++){
            for (size_t j=0;j<m;j++)
                cout<<(*this)(i,j)<<" ";
            cout<<endl;
        }
    }
    inline string to_bmp();
};
template<>
inline string _bitmap<rgb>::to_bmp(){
    set<rgb> s;
    string str;
    auto h=bmp::make_rgb_header(n,m);
    for (int i=n-1;i>=0;i--)
        for (int j=0;j<m;j++)
            s.insert((*this)(i,j));
    h.h1.bfSize=str.size()+sizeof(h);
    h.h2.biClrUsed=s.size();
    h.h2.biSizeImage=0;
    h.h2.biBitCount=24;
    dump_to_string(h,str);
    for (int i=n-1;i>=0;i--)
        for (int j=0;j<m;j++)
            dump_to_string((*this)(i,j),str);
    return str;
}

using bitmap=_bitmap<bool>;
using rgbmap=_bitmap<rgb>;
