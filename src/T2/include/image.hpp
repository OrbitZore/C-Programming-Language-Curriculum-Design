#pragma once
#include "cardinal.hpp"
#include "vector.hpp"
#include "bmp.hpp"

using rgb=array<uint8_t,3>;
inline ostream& operator<<(ostream& os,const rgb& a){
    return os<<"("<<a[0]<<","<<a[1]<<","<<a[2]<<")";
}
template<class T>
inline void dump_to_string(const T& m,string a){
    const char *c=reinterpret_cast<const char*>(&m[0]);
    for (size_t i=0;i<sizeof(m);i++)
        a+=c[i];
}

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
                cout<<(*this)(i,j);
            cout<<endl;
        }
    }
    string to_bmp();
};
template<>
inline string _bitmap<rgb>::to_bmp(){
    string str=bmp::make_rgb_header(n,m);
    for (int i=n-1;i>=0;i--)
        for (int j=0;j<m;j++)
            dump_to_string((*this)(i,j),str);
    return str;
}

using bitmap=_bitmap<bool>;
using rgbmap=_bitmap<rgb>;
