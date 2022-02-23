#pragma once
#include "cardinal.hpp"
#include "data.h"
#include "ui.h"
void login(){
    while ([](){
        string username,password;
        println("请输入用户名:");
        ui::getline(username);
        println("请输入密码:");
        ui::getline(password);
        if (data_base["username"]==username&&
            data_base["password"]==password){
                println("登陆成功");
                return false;
            }
        println("用户名或密码错误，登陆失败");
        return true;
    }());
}

