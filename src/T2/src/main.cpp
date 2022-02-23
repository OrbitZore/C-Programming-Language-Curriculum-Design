#include "cardinal.hpp"
#include "conv.hpp"
#include "fonts.h"
#include "bmp.hpp"
int main(int argc, char** argv){
    vec<string> args(argv,argv+argc);
    print("{{}\n}\n",args);
    if (args.size()<2||args[1].size()>=100){
        println("请输入4个汉字");
        return 0;
    }
    string buff;
    buff=conventer("GB18030","UTF-8")(args[1]);
    if (buff.size()!=4*2){
        println("请输入4个汉字");
        return 0;
    }
    string hexbuff[4];
    for (size_t i=0;i<8;i+=2){
        ostringstream os;
        os<<hex<<(int)(unsigned char)buff[i]<<(int)(unsigned char)buff[i+1];
        hexbuff[i>>1]=os.str();
    }
    auto w=find_bitmap(hexbuff[0]);
    if (w){
        for (size_t i=0;i<w->n;i++,cout<<endl)
            for (size_t j=0;j<w->m;j++)
                cout<<w.value()(i,j);
    }
    else cerr<<"NO";
    return 0;
}
