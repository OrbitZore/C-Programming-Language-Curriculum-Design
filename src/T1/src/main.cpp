#include "cardinal.hpp"
#include "ui.h"
#include "data.h"
#include "login.h"

const vec<string> main_menu={
    "Add a user",
    "Get average score",
    "Sort",
    "Search",
    "Print"
};

int main(int argc, char** argv){
    while (true){
        login();
        int w=ui::choose(main_menu);
        if (w==0){
        }else if (w==1){
        }else if (w==2){
        }else if (w==3){
        }else if (w==4){
        }
    }
    return 0;
}
