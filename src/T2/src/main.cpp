#include "cardinal.hpp"
#include "conv.hpp"
#include "fonts.hpp"
#include "image.hpp"
string name,filename="out.bmp";
string dump_to_hex(uint8_t c){
    auto single_to_hex=[](uint8_t a)->char{
        return a<10?a+'0':(a-10+'a');
    };
    return string()+single_to_hex(c/16)+single_to_hex(c%16);
}

template<class T>
string dump_to_hex(const T& a){
    string w;
    auto c=reinterpret_cast<uint8_t*>(&a);
    for (size_t i=0;i<sizeof(a);i++)
        w+=dump_to_hex(c[i]);
    return w;
}
string dump_to_hex(void* a,size_t n){
    string w;
    uint8_t* c=(uint8_t*)a;
    for (size_t i=0;i<n;i++)
        w+=dump_to_hex(c[i]);
    return w;
}

void help(){
    println("使用: $seal [options] [name]");
    println("options:");
    println("   -o [filename]       输出到filename");
}

void parse(vec<string> args){
#define byebye {help();exit(-1);}
    array<bool,2> ba={};
    if (args.size()==1) byebye;
    for (size_t i=1;i<args.size();i++){
        if (args[i]=="-o"){
            if (i+1==args.size()||ba[0]) byebye;
            filename=args[i+1];
            i++;
            ba[0]=1;
        }else{
            if (ba[1]) byebye;
            name=args[i];
            ba[1]=1;
        }
    }
    return ;
#undef byebye
}

constexpr auto REDW=20;
constexpr auto WITW=10;
constexpr auto BLK1W=REDW+WITW;
constexpr auto BLK2W=BLK1W*2;
constexpr auto RED=rgb{0,0,255};
constexpr auto WIT=rgb{255,255,255};

int main(int argc, char** argv){
    parse({argv,argv+argc});
    string buff;
    buff=conventer("GB18030","UTF-8")(name);
    string hexbuff[2][2];
    for (size_t i=0;i<8;i+=2)
        hexbuff[0][i>>1]=dump_to_hex(&buff[i],2);

    bitmap bmbuff[2][2];int pn=0,pm=0;

    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            auto w=find_bitmap(hexbuff[i][j]);
            if (w){
                pn=w->n;
                pm=w->m;
                bmbuff[i][j]=move(*w);
            }
        }
    }

    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            bmbuff[i][j].c.resize(pn*pm);
    swap(bmbuff[0][0],bmbuff[0][1]);
    swap(bmbuff[1][0],bmbuff[1][1]);
    swap(bmbuff[0][0],bmbuff[1][1]);
    rgbmap a(pn*2+BLK2W,pm*2+BLK2W,WIT);
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++){
            int bi=BLK1W+i*pn,bj=BLK1W+j*pm;
            for (int ii=0;ii<pn;ii++)
                for (int jj=0;jj<pm;jj++)
                    a(bi+ii,bj+jj)=bmbuff[i][j](ii,jj)?RED:WIT;
        }
    for (int i=0;i<REDW;i++) for (int j=0;j<a.m;j++) a(i,j)=RED;
    for (int i=0;i<a.n;i++) for (int j=0;j<REDW;j++) a(i,j)=RED;
    for (int i=0;i<REDW;i++) for (int j=0;j<a.m;j++) a(a.n-i-1,j)=RED;
    for (int i=0;i<a.n;i++) for (int j=0;j<REDW;j++) a(i,a.m-j-1)=RED;
    ofstream(filename,ios::binary)<<a.to_bmp();
    return 0;
}
