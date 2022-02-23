#include "cardinal.hpp"

int main(int argc, char** argv){
    vec<string> args(argv[0],argv[argc]);
    print("{{} }\n",args);
    return 0;
}
