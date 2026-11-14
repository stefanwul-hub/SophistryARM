#include "LifterRuntime.h"
extern "C" void* malloc(SlSize);
extern "C" void free(void*);

static SlU64 round_shift(SlU64 n,unsigned shift) {
    if(!shift)return n;
    if(shift>64)return 0;
    if(shift==64)return n>(SlU64(1)<<63)?1:0;
    SlU64 quotient=n>>shift,remainder=n&((SlU64(1)<<shift)-1),half=SlU64(1)<<(shift-1);
    return quotient+(remainder>half || (remainder==half && (quotient&1)));
}
SlU sl_ext80_to_f64(SlU bits) {
    // Exact integer rounding of x87 80-bit storage to IEEE binary64,
    // round-to-nearest-even. No reliance on the host long-double format.
    SlU64 significand=static_cast<SlU64>(bits);
    unsigned signexp=static_cast<unsigned>(bits>>64)&0xffff;
    SlU64 sign=SlU64(signexp>>15)<<63;unsigned exponent=signexp&0x7fff;
    if(exponent==0x7fff) {
        if(significand==0x8000000000000000ULL)return sign|0x7ff0000000000000ULL;
        return sign|0x7ff8000000000000ULL|((significand>>11)&0x0007ffffffffffffULL);
    }
    if(!significand)return sign;
    int power=exponent?int(exponent)-16383:-16382;
    unsigned leading=63-__builtin_clzll(significand);
    int e=power+int(leading)-63;
    if(e>1023)return sign|0x7ff0000000000000ULL;
    if(e< -1022) {
        int shift= -power-1011;
        SlU64 rounded=shift>=0?round_shift(significand,static_cast<unsigned>(shift)):significand<<unsigned(-shift);
        return sign|rounded;
    }
    SlU64 rounded=leading>=52?round_shift(significand,leading-52):significand<<(52-leading);
    if(rounded==(SlU64(1)<<53)){rounded>>=1;++e;}
    if(e>1023)return sign|0x7ff0000000000000ULL;
    return sign|(SlU64(e+1023)<<52)|(rounded&0x000fffffffffffffULL);
}
SlU sl_trunc_fp(SlU bits,unsigned source_bytes,unsigned output_bits) {
    unsigned fraction_bits=source_bytes==4?23:52,bias=source_bytes==4?127:1023;
    SlU64 raw=static_cast<SlU64>(bits),fraction_mask=(SlU64(1)<<fraction_bits)-1;
    unsigned exponent=unsigned((raw>>fraction_bits)&(source_bytes==4?0xff:0x7ff));
    bool negative=(raw>>(source_bytes*8-1))&1;
    int e=int(exponent)-int(bias);
    if(e<0)return 0;
    if(e>=int(output_bits)-1)return SlU(1)<<(output_bits-1); // x86 indefinite integer, also exact INT_MIN
    SlU64 mantissa=(SlU64(1)<<fraction_bits)|(raw&fraction_mask);
    SlU magnitude=e>=int(fraction_bits)?SlU(mantissa)<<(e-fraction_bits):SlU(mantissa)>>(fraction_bits-e);
    return (negative?SlU(0)-magnitude:magnitude)&sl_mask(output_bits);
}
extern "C" SlCpu* sl_create(SlSize size) {
    auto* c=static_cast<SlCpu*>(malloc(sizeof(SlCpu)));if(!c)return nullptr;
    __builtin_memset(c,0,sizeof(*c));c->memory=static_cast<SlU8*>(malloc(size));
    if(!c->memory){free(c);return nullptr;}c->memory_size=size;__builtin_memset(c->memory,0,size);return c;
}
extern "C" void sl_destroy(SlCpu* c){if(c){free(c->memory);free(c);}}
extern "C" int sl_mem_write(SlCpu* c,SlU32 a,const void* p,SlSize n){if(!c||a>c->memory_size||n>c->memory_size-a)return 1;__builtin_memcpy(c->memory+a,p,n);return 0;}
extern "C" int sl_mem_read(SlCpu* c,SlU32 a,void* p,SlSize n){if(!c||a>c->memory_size||n>c->memory_size-a)return 1;__builtin_memcpy(p,c->memory+a,n);return 0;}
extern "C" int sl_reg_write(SlCpu* c,SlU32 a,const void* p,SlSize n){if(!c||a>sizeof(c->reg)||n>sizeof(c->reg)-a)return 1;__builtin_memcpy(c->reg+a,p,n);return 0;}
extern "C" int sl_reg_read(SlCpu* c,SlU32 a,void* p,SlSize n){if(!c||a>sizeof(c->reg)||n>sizeof(c->reg)-a)return 1;__builtin_memcpy(p,c->reg+a,n);return 0;}
extern "C" int sl_hook(SlCpu* c,SlU32 a,SlCallback f,void* u){if(!c||!f||c->hook_count>=64)return 1;c->hooks[c->hook_count++]={a,f,u};return 0;}
extern "C" void sl_set_pc(SlCpu* c,SlU32 a){c->pc=a;}
extern "C" SlU32 sl_get_pc(SlCpu* c){return c->pc;}
extern "C" SlU32 sl_get_fault(SlCpu* c){return c->fault;}
extern "C" SlU64 sl_get_steps(SlCpu* c){return c->steps;}
extern "C" SlU32 sl_coverage_count(SlCpu* c){SlU32 n=0;for(SlSize i=0;i<sizeof(c->seen);++i)n+=c->seen[i]!=0;return n;}
extern "C" int sl_run(SlCpu* c,SlU32 e,SlU32 s,SlU64 limit){if(!c)return 1;return sl_execute(*c,e,s,limit);}
