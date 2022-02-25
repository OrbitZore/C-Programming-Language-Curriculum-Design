#pragma once
#include "cardinal.hpp"
#include "image.hpp"
inline optional<bitmap> find_bitmap(string hexcode){
    string header="CurCode: "+hexcode,cc;
    ifstream is("LiShu56.txt");
    while ((getline(is,cc),is)&&!cc.starts_with(header));
    if (cc.starts_with(header)){
        bitmap b;
        getline(is,cc);
        int cntm=0,cntn=0;
        while ((getline(is,cc),is)&&(cntm=[&](){
            int cnt=0;
            for (auto i:cc){
                if (i=='X')
                    b.c.push_back(1),cnt++;
                if (i=='_')
                    b.c.push_back(0),cnt++;
            }
            return cnt;
        }())){
            b.m=cntm;
            cntn++;
        }
        b.n=cntn;
        return b;
    }
    return {};
}
