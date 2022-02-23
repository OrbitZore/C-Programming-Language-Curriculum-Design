#include "cardinal.hpp"
#include "ui.h"
#include "data.h"
#include "login.hpp"
#include "input.hpp"
//#include "sort.hpp"
//#include "search.hpp"
//#include "print.hpp"

const vec<string> main_menu={
    "输入信息",
    "求平均分",
    "排 序",
    "查 询",
    "输 出",
    "退 出"
};

int main(int argc, char** argv){
    login();
    while (true){
        int w=ui::choose(main_menu,"主菜单");
        if (w==0){
            
        }else if (w==1){

        }else if (w==2){

        }else if (w==3){

        }else if (w==4){

        }else if (w==5){
            break;
        }
    }
    return 0;
}
