#include "fonts.h"
optional<bitmap> find_bitmap(string hexcode){
    string header="CurCode: "+hexcode,cc;
    cout<<header<<endl;
    ifstream is("LiShu56.txt");
    while (getline(is,cc)&&headers!=cc);
    if (header==cc){
        bitmap b;
        getline(is,cc);
        while (getline(is,cc)&&c.size()!=0){
            int cnt=0;

        }
        return b;
    }
    return {};
}