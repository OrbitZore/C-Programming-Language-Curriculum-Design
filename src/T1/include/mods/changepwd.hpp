#pragma once
#include "cardinal.hpp"
#include "data.h"
#include "ui.h"
inline void changepwd(){
    string pwdnew=ui::getline("请输入新密码:"s);
    data_base["password"]=shash(pwdnew);
    update_decrypt_key(pwdnew);
    println("更改密码成功");
}