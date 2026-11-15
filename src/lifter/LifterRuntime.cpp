#include "LifterRuntime.h"
extern "C" void* malloc(SlSize);
extern "C" void* calloc(SlSize, SlSize);
extern "C" void free(void*);

static SlU64 round_shift(SlU64 n,unsigned shift) {
    if(!shift)return n;
    if(shift>64)return 0;
    if(shift==64)return n>(SlU64(1)<<63)?1:0;
    SlU64 quotient=n>>shift,remainder=n&((SlU64(1)<<shift)-1),half=SlU64(1)<<(shift-1);
    return quotient+(remainder>half || (remainder==half && (quotient&1)));
}
static SlU ext80_to_ieee(SlU bits,unsigned fraction_bits,unsigned bias,unsigned exponent_bits) {
    SlU64 significand=static_cast<SlU64>(bits);unsigned signexp=static_cast<unsigned>(bits>>64)&0xffff;
    SlU64 sign=SlU64(signexp>>15)<<(fraction_bits+exponent_bits),fraction_mask=(SlU64(1)<<fraction_bits)-1;
    SlU64 infinity=((SlU64(1)<<exponent_bits)-1)<<fraction_bits;unsigned exponent=signexp&0x7fff;
    if(exponent==0x7fff){if(significand==0x8000000000000000ULL)return sign|infinity;return sign|infinity|(SlU64(1)<<(fraction_bits-1))|((significand>>(63-fraction_bits))&fraction_mask);}
    if(!significand)return sign;
    int power=exponent?int(exponent)-16383:-16382;unsigned leading=63-__builtin_clzll(significand);int e=power+int(leading)-63;
    if(e>int(bias))return sign|infinity;
    if(e<1-int(bias)){
        int shift=64-int(bias)-int(fraction_bits)-power;
        SlU64 rounded=shift>=0?round_shift(significand,unsigned(shift)):significand<<unsigned(-shift);
        return sign|rounded;
    }
    SlU64 rounded=leading>=fraction_bits?round_shift(significand,leading-fraction_bits):significand<<(fraction_bits-leading);
    if(rounded==(SlU64(1)<<(fraction_bits+1))){rounded>>=1;++e;}
    if(e>int(bias))return sign|infinity;
    return sign|(SlU64(e+int(bias))<<fraction_bits)|(rounded&fraction_mask);
}
SlU sl_ext80_to_f64(SlU bits){return ext80_to_ieee(bits,52,1023,11);}
SlU sl_ext80_to_f32(SlU bits){return ext80_to_ieee(bits,23,127,8);}
SlU sl_integer_to_ext80(SlU value,unsigned input_bits) {
    // All current instruction inputs are signed 32-bit integers (FLDZ/FLD1).
    // The integer path also handles signed 64-bit values without rounding via double.
    const SlS signed_value=sl_signed(value,input_bits);
    const bool negative=signed_value<0;
    const SlU64 magnitude=negative?SlU64(0)-static_cast<SlU64>(signed_value):static_cast<SlU64>(signed_value);
    if(!magnitude)return 0;
    const unsigned leading=63-__builtin_clzll(magnitude);
    return SlU(magnitude<<(63-leading))|(SlU((negative?0x8000u:0u)|unsigned(16383+leading))<<64);
}
SlU sl_divide(SlCpu& c,SlU numerator,SlU denominator,unsigned input_bits,unsigned quotient_bits,bool is_signed,bool remainder) {
    // x86 IDIV/DIV narrow the quotient. Ghidra's raw p-code widens the
    // arithmetic first, so check the final architectural quotient width here.
    if(c.fault)return 0;
    if(!input_bits||input_bits>64||!quotient_bits||quotient_bits>64){c.fault=9;return 0;}
    numerator&=sl_mask(input_bits);denominator&=sl_mask(input_bits);
    if(!denominator){c.fault=9;return 0;}
    if(is_signed){
        const SlS a=sl_signed(numerator,input_bits),b=sl_signed(denominator,input_bits);
        // 128-bit arithmetic avoids host UB for INT64_MIN / -1.
        const SlS quotient=a/b;
        const SlS bound=SlS(1)<<(quotient_bits-1);
        if(quotient < -bound || quotient >= bound){c.fault=9;return 0;}
        return SlU(remainder?a%b:quotient)&sl_mask(input_bits);
    }
    const SlU quotient=numerator/denominator;
    if(quotient>sl_mask(quotient_bits)){c.fault=9;return 0;}
    return remainder?numerator%denominator:quotient;
}
SlU sl_sqrt_f32(SlU input) {
    const SlU32 bits=static_cast<SlU32>(input),magnitude=bits&0x7fffffffu;
    // Preserve/quiet an input NaN payload as x86 SQRTSS does. ARM's default
    // invalid-result NaN has a different sign, so form the x86 indefinite here.
    if(magnitude>0x7f800000u)return bits|0x00400000u;
    if((bits&0x80000000u)&&magnitude)return 0xffc00000u;
    if(!magnitude||magnitude==0x7f800000u)return bits;
    return sl_bits(__builtin_sqrtf(sl_float<float>(bits)));
}
SlU sl_fp_to_ext80(SlU input,unsigned source_bytes) {
    SlU64 bits=static_cast<SlU64>(input);unsigned f=source_bytes==4?23:52,bias=source_bytes==4?127:1023,ebits=source_bytes==4?8:11;
    SlU64 fraction=bits&((SlU64(1)<<f)-1);unsigned exponent=unsigned((bits>>f)&((1u<<ebits)-1)),sign=unsigned(bits>>(source_bytes*8-1)),e=0;SlU64 mantissa=0;
    if(exponent==((1u<<ebits)-1)){e=0x7fff;mantissa=(SlU64(1)<<63)|(fraction<<(63-f));}
    else if(exponent){e=exponent-bias+16383;mantissa=((SlU64(1)<<f)|fraction)<<(63-f);}
    else if(fraction){unsigned leading=63-__builtin_clzll(fraction);e=unsigned(int(leading)+1-int(bias)-int(f)+16383);mantissa=fraction<<(63-leading);}
    return SlU(mantissa)|(SlU((sign<<15)|e)<<64);
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
    __builtin_memset(c,0,sizeof(*c));c->memory=static_cast<SlU8*>(calloc(1,size));
    if(!c->memory){free(c);return nullptr;}c->memory_size=size;return c;
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

extern "C" void sl_push_double_return(SlCpu* c,double value) {
    SlU storage=sl_fp_to_ext80(sl_bits(value),8);
    for(int i=7;i>0;--i)__builtin_memcpy(c->reg+0x1100+i*16,c->reg+0x1100+(i-1)*16,10);
    sl_put<10>(c->reg,sizeof(c->reg),0x1100,storage,*c);
}
