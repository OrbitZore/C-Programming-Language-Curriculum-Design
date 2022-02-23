#include "data.h"

#ifdef linux
fauhfasdigu
#endif

string encrypt(const string& a){
    return a;
}

string decrypt(const string& a){
    return a;
}

string encode(const string& a){//'\'->'\''\'
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

string decode(const string& a){
    string r;
    for (size_t i=0;i<a.size();i++){
        auto ai=a[i];
        if (ai=='\\'){
            if (i!=a.size()){
                if (a[i+1]=='n'){
                    r+='\n';
                }else if (a[i+1]=='\\'){
                    r+='\\';
                }
            }
        }else r+=ai;
    }
    return r;
}
#define config_filename (config_dir+"pwdkeeper.cfg")

dbT::dbT():map<string,string>(default_kv){
    ifstream is(config_filename);
    while (is.good()){  
        string str;
        getline(is,str);
        int w=str.find_first_of('=');
        if (str.size()&&(0<=w&&w<str.size()))
            (*this)[decode(str.substr(0,w))]=decode(str.substr(w+1));
    }
}

void syncdb(){
    ofstream os(config_filename);
    for (auto &[k,v]:data_base){
        os<<encode(k)<<"="<<encode(v)<<"\n";
    }
}

dbT::~dbT(){
    syncdb();
}

dbT data_base;
