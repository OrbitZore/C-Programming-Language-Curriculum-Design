#include "ui.h"

namespace ui{
    string getline(const string& msg,bool allow_empty){
        string str;
        while ([&](){
            cout<<msg<<"\n>";
            cout.flush();
            getline(cin,str);
            if (str.size()) return false;
            return true;
        }()&&(!allow_empty)){
            cout<<"输入为空\n";
        }
        return str;
    }

    istream& getline(string &str,const string& msg,bool allow_empty){
        while ([&](){
            cout<<msg<<"\n>";
            cout.flush();
            getline(cin,str);
            if (str.size()) return false;
            return true;
        }()&&(!allow_empty)){
            cout<<"输入为空\n";
        }
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
        cin.get();
        w--;
        println("选中 {}. {}",w+1,v[w]);
        return w;
    }

   size_t getint(size_t l,size_t r,const string& msg){
        while (true){
            string w=ui::getline("请输入将修改的编号");
            size_t wi;
            try{
                wi=stoull(w);
            }catch(...){
                println("请输入正整数！");
                continue;
            }
            if (!(l<=wi&&wi<r)) {
                println("请输入正确范围！");
                continue;
            }
            return wi;
        }
    }
}
