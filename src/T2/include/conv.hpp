#pragma once
#include "cardinal.hpp"
#include "iconv.h"
class conventer{
    iconv_t bg;
    public:
    inline conventer(const string& to,const string& from){
        bg=iconv_open(to.c_str(),from.c_str());
    }
    inline string operator()(const string& str){
        string w;w.resize(str.size());
        size_t wleft=w.size(),sleft=str.size();
        char *wc=const_cast<char*>(w.c_str());
        char* sc=const_cast<char*>(str.c_str());
        iconv(bg,&sc,&sleft,&wc,&wleft);
        w.resize(wc-w.c_str());
        return w;
    }
    inline ~conventer(){
        iconv_close(bg);
    }
};