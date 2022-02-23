#pragma once
#include "cardinal.hpp"
#include "data.h"
#include "ui.h"
inline void input(){
    user_list.push_back(user{
        ui::getline("请输入新用户帐号位置"),
        ui::getline("请输入新用户帐号描述"),
        ui::getline("请输入新用户帐号名"),
        ui::getline("请输入新用户密码")
    });
    syncdb();
}