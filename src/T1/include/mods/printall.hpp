#pragma once
#include "cardinal.hpp"
#include "data.h"
#include "ui.h"
inline void printall(){
    println("共 {} 条信息",user_list.size());
    println("( {} {} {} {} {}","编号","帐号位置","帐号描述","帐号名","密码");
    for (size_t i=0;i<user_list.size();i++){
        auto& u=user_list[i];
        println("( {} {} {} {} {}",i,u.pos,u.description,u.name,u.pwd);
    }
}