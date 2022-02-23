#pragma once
#include "cardinal.hpp"
#include "data.h"
#include "ui.h"
inline string decrypt_key;
inline void update_decrypt_key(const string& rawpwd){
    decrypt_key=shash(rawpwd+"salt"+shash(rawpwd));
}
inline void login(){
    while ([](){
        string password;
        ui::getline(password,"请输入密码:"s);
        if (data_base["password"]==shash(password)){
                println("登陆成功");
                update_decrypt_key(password);
                return false;
            }
        println("用户名或密码错误，登陆失败");
        return true;
    }());
}

