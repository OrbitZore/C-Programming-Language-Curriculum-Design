#pragma once
#include "cardinal.hpp"
#include "data.h"
#include "ui.h"
inline void erase(){
    size_t wi=ui::getint(0,user_list.size(),"请输入将修改的编号");
    auto& u=user_list[wi];
    println("选中) {} {} {} {} {} {}",wi,u.pos,u.description,u.name,u.pwd);
    string str=ui::getline("输入yes（小写）删除");
    if (str=="yes"){
        user_list.erase(user_list.begin()+wi);
        println("删除完毕");
    }else{
        println("用户取消删除");
    }
    syncdb();
}