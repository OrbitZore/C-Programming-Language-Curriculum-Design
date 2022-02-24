#include "cardinal.hpp"
#include "conv.hpp"
#include "fonts.h"
#include "image.hpp"
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
    string hexbuff[2][2];
    for (size_t i=0;i<8;i+=2){
        ostringstream os;
        os<<hex<<(int)(unsigned char)buff[i]<<(int)(unsigned char)buff[i+1];
        (hexbuff[0][i>>1]=os.str()).resize(4);
    }
    bitmap bmbuff[2][2];int pn,pm;
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            auto w=find_bitmap(hexbuff[i][j]);
            if (w){
                bmbuff[i][j]=*w;
                pn=w->n;
                pm=w->m;
            }
            else cerr<<"NO";
        }
    }
#define REDW 20
#define WITW 20
#define BLK2W (REDW*2+WITW*2)
#define BLK1W (REDW+WITW)
#define RED rgb{255,0,0}
#define WIT rgb{255,255,255}
    rgbmap a(pn*2+BLK2W,pm*2+BLK2W);//(20,20,20,20)
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++){
            int bi=BLK1W+i*pn,bj=BLK1W+j*pm;
            for (int ii=0;ii<pn;ii++)
                for (int jj=0;jj<pm;jj++)
                    a[bi+ii][bj+jj]=bmbuff[i][j][ii][jj]?RED:WIT;
        }
    for (int i=0;i<a.n;i++) for (int j=0;j<REDW;j++) a[i][j]=RED;
    for (int i=0;i<REDW;i++) for (int j=0;j<a.m;j++) a[i][j]=RED;
    a.print();
    return 0;
}
