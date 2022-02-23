#pragma once
#include "cardinal.hpp"
#include "data.h"
#include "ui.h"
inline void modify(){
    size_t wi=ui::getint(0,user_list.size(),"请输入将修改的编号");
    auto& u=user_list[wi];
    println("选中) {} {} {} {} {} {}",wi,u.pos,u.description,u.name,u.pwd);
    size_t ci=ui::choose({
        "帐号位置","帐号描述","帐号名","密码"
    },"请选中将要修改的值");
    if (ci==0){
        u.pos=ui::getline("请输入新的帐号位置");
    }else if (ci==1){
        u.description=ui::getline("请输入新的帐号描述");
    }else if (ci==2){
        u.name=ui::getline("请输入新的帐号名");
    }else if (ci==3){
        u.pwd=ui::getline("请输入新的密码");
    }
    println("修改完毕，结果为\n) {} {} {} {} {} {}",wi,u.pos,u.description,u.name,u.pwd);
    syncdb();
}