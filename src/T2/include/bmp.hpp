#pragma once

namespace bmp{
using i32=int32_t;//LONG
using u32=uint32_t;//DWORD
using i16=int16_t;//
using u16=uint16_t;//WORD
struct BMP_INFO_HEADER{
    u32 Size={40};
    i32 width,height;
    u16 planes={1},bitcount;
    u32 compression={0},sizeimage;
    i32 XDPM={11811},YDPM={11811};
    u32 clrused={0},clrimportant={0};
};
inline string make_rgb_header(i32 n,i32 m){
    BMP_INFO_HEADER h;
    tie(h.height,h.width)=make_tuple(m,n);
    h.bitcount=8;
    h.sizeimage=0;
    return string(reinterpret_cast<char*>(&h),sizeof(h));
}

}
