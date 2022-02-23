#pragma once
#include "cardinal.hpp"
#include "data.h"
#include "ui.h"
inline void search(){
    string str=ui::getline("请输入帐号位置");
    vec<pair<int,reference_wrapper<user>>> v;
    for (size_t i=0;i<user_list.size();i++){
        auto &ui=user_list[i];
        if (ui.pos.find(str)!=string::npos)
            v.push_back({i,ref(ui)});
    }
    println("查询 {} ,总共 {} 条信息",str,v.size());
    println(") {} {} {} {} {}","编号","帐号位置","帐号描述","帐号名","密码");
    for (size_t i=0;i<v.size();i++){
        int ii=v[i].first;
        user& u=v[i].second.get();
        println(") {} {} {} {} {} {}",ii,u.pos,u.description,u.name,u.pwd);
    }
}