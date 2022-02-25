#pragma once

template<class T>
inline void dump_to_string(const T& m,string& a){
    const char *c=reinterpret_cast<const char*>(&m);
    for (size_t i=0;i<sizeof(m);i++)
        a+=c[i];
}

namespace bmp{
    using i32=int32_t;//LONG
    using u32=uint32_t;//DWORD
    using i16=int16_t;//
    using u16=uint16_t;//WORD
    #pragma pack(push,1)
    struct BMP_HEADER{
        u16 bfType{0x4D42};
        u32 bfSize;//
        u16 bfReserved1{0};
        u16 bfReserved2{0};
        u32 bfOffBits;
    };
    struct BMP_INFO_HEADER{
        u32 biSize{40};
        i32 biWidth;
        i32 biHeight;
        u16 biPlanes{1};
        u16 biBitCount;
        u32 biCompression{0};
        u32 biSizeImage;
        i32 biXPelsPerMeter{11811},biYPelsPerMeter{11811};
        u32 biClrUsed;//
        u32 biClrImportant{0};
    };
    struct BMP_FILE_HEADER{
        BMP_HEADER h1;
        BMP_INFO_HEADER h2;
    };
    #pragma pack(pop)
    inline BMP_FILE_HEADER make_rgb_header(i32 n,i32 m){
        BMP_FILE_HEADER a;
        tie(a.h2.biHeight,a.h2.biWidth)=make_tuple(n,m);
        a.h1.bfOffBits=sizeof(a.h1)+sizeof(a.h2);
        return a;
    }

}
