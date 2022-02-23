#include "data.h"
#include "math.hpp"
#include "mint.hpp"
#include "misc.hpp"
#include "os.hpp"
#include "mods/login.hpp"

string encrypt(const string& a,const string& key){
    using mchar=_mint<char,int,127>;
    mchar num=hash<string>()(key);
    string w;
    for (auto i:a)
        w+=(mchar(i)*num).v;
    return w;
}

string decrypt(const string& a,const string& key){
    using mchar=_mint<int,int,127>;
    mchar num=hash<string>()(key);
    num=num.inverse();
    string w;
    for (auto i:a)
        w+=(mchar(i)*num).v;
    return w;
}

string shash(const string& a){
    return to_string(hash<string>()(a));
}

string encode(const string& a){//del \n
    string r;
    for (auto &i:a){
        if (i=='\\'){
            r+="\\\\";
        }else if (i=='\n'){
            r+="\\n";
        }else r+=i;
    }
    return r;
}

string decode(const string& a){//gen \n
    string r;
    for (size_t i=0;i<a.size();i++){
        auto ai=a[i];
        if (ai=='\\'){
            if (i+1<a.size()){
                if (a[i+1]=='n'){
                    i++;
                    r+='\n';
                }else if (a[i+1]=='\\'){
                    i++;
                    r+='\\';
                }
            }
        }else r+=ai;
    }
    return r;
}

vec<string> decodep(const string& a){//gen \n
    vec<string> r;string w;
    for (size_t i=0;i<a.size();i++){
        auto ai=a[i];
        if (ai=='\\'){
            if (i+1<a.size()){
                if (a[i+1]=='n'){
                    i++;
                    w+='\n';
                }else if (a[i+1]=='\\'){
                    i++;
                    w+='\\';
                }else{
                    if (w.size()){
                        r.push_back(move(w));
                        w=string();
                    }
                }
            }
        }else w+=ai;
    }
    if (w.size()) r.push_back(move(w));
    return r;
}

#define config_filename (config_dir+"pwdkeeper.cfg")

string user::to_string()const{
    return
    encode(pos)+"\\"+
    encode(description)+"\\"+
    encode(name)+"\\"+
    encode(pwd);
}

user user::from_string(string str){
    user u;
    auto v=decodep(str);
    u.pos=move(v.at(0));
    u.description=move(v.at(1));
    u.name=move(v.at(2));
    u.pwd=move(v.at(3));
    return u;
}

string encode_users(const vec<user>& v){
    string str;
    for (size_t i=0;i<v.size();i++)
        str+=encode(v[i].to_string())+"\\";
    return str;
}

vec<user> decode_users(const string& str){
    vec<user> v;
    auto w=decodep(str);
    for (auto& i:w)
        v.push_back(user::from_string(i));
    return v;
}

void syncdb(){
    ofstream os(config_filename);
    string out;
    data_base["users"]=encode_users(user_list);
    for (auto &[k,v]:data_base){
        out+=encode(k)+"="+encode(v)+"\n";
    }
    os<<data_base["username"]<<endl<<data_base["password"]<<endl<<
    encrypt(out,decrypt_key);
}

void inidb1(){
    data_base=default_kv;
    ifstream is(config_filename);
    string a;
    getline(is,a);
    if (a.size()){
        data_base["username"]=a;
    }else return ;
    a.clear();
    getline(is,a);
    if (a.size()){
        data_base["password"]=a;
    }else return ;
}
void inidb2(){
    string input;
    {
        ifstream is(config_filename);
        while (is&&is.get()!='\n');
        while (is&&is.get()!='\n');
        while (is) input+=is.get();
    }
    auto w=split(decrypt(input,decrypt_key),"\n");
    for (auto& str:w){
        int w=str.find('=');
        if (str.size()&&(0<=w&&w<str.size()))
            data_base[decode(str.substr(0,w))]=decode(str.substr(w+1));
    }
    user_list=decode_users(data_base["users"]);
}

dbT data_base;
vec<user> user_list;