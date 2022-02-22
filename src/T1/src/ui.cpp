#include "ui.h"

namespace ui{

int choose(const vec<string>& v){
    println("choose to continue(1..{}):",v.size());
    for (size_t i=0;i<v.size();i++)
        println("{}. {}",i+1,v[i]);
    int w;
    while (cout<<">",cin>>w,!(1<=w&&w<=v.size()))
        println("out of range!");
    w--;
    println("choose {}. {}",w,v[w]);
    return w;
}

}
