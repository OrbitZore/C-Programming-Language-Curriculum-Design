#include "ui.h"

namespace ui{

    istream& getline(string &str){
        cout<<">";
        cout.flush();
        getline(cin,str);
        return cin;
    }

    int choose(const vec<string>& v,const string& name){
        println("***{}***",name);
        println("请输入选项编号 (1~{}):",v.size());
        for (size_t i=0;i<v.size();i++)
            println("{}. {}",i+1,v[i]);
        int w;
        while ((cout<<">").flush(),cin>>w,!(1<=w&&w<=v.size()))
            println("超出菜单范围!");
        w--;
        println("选中 {}. {}",w+1,v[w]);
        return w;
    }

}
