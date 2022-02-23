#include "cardinal.hpp"
#include "ui.h"
#include "data.h"
#include "mods/allmods.hpp"

const vec<string> main_menu={
    "输入信息",
    "查询信息",
    "查看全部信息",
    "修改信息",
    "删除信息",
    "更改密码",
    "退 出"
};
void(*menu_func[])(void)={
    input,
    search,
    printall,
    modify,
    erase,
    changepwd,
    [](){exit(0);}
};
int main(int argc, char** argv){
    inidb1();
    login();
    inidb2();
    while (true){
        int w=ui::choose(main_menu,"主菜单");
        menu_func[w]();
        syncdb();
        ui::getline("按回车键返回主菜单",true);
    }
    return 0;
}
