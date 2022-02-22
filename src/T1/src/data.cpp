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
const string config_filename=config_dir+"pwdkeeper.cfg";
dbT::dbT():map<string,string>(default_kv){
    ifstream is(config_filename);
    while (is.good()){
        string str;
        getline(is,str);
        int w=str.find_first_of('=');
        (*this)[decode(str.substr(0,w))]=decode(str.substr(w));
    }
}

dbT::~dbT(){
    ofstream os(config_filename);
    for (auto &[k,v]:(*this)){
        os<<encode(k)<<"="<<encode(k)<<"\n";
    }
}

dbT data_base;

