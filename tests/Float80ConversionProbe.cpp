#include "LifterRuntime.h"
#include <stdio.h>
#include <string.h>
#include <fenv.h>
// This oracle uses Intel's native extended type; it is intentionally unavailable
// on platforms where long double is not x87 extended precision.
int sl_execute(SlCpu&,SlU32,SlU32,SlU64){return 3;}
int main() {
#if __LDBL_MANT_DIG__ == 64 && __LDBL_MAX_EXP__ == 16384
    fesetround(FE_TONEAREST);SlU64 seed=0x53594e54485ULL;unsigned failures=0;
    auto next=[&](){seed^=seed<<13;seed^=seed>>7;seed^=seed<<17;return seed;};
    for(unsigned i=0;i<20000;++i) {
        int power=i%3==0?int(next()%2400)-1200:i%3==1?int(next()%400)-200:int(next()%32766)-16382;
        unsigned exponent=unsigned(power+16383);SlU64 mantissa=next()|0x8000000000000000ULL;
        unsigned sign=unsigned(next()&1);SlU raw=SlU(mantissa)|(SlU(exponent|(sign<<15))<<64);
        long double extended=0;__builtin_memcpy(&extended,&raw,10);
        volatile long double original=extended;float a=static_cast<float>(original);double b=static_cast<double>(original);
        SlU aa=sl_bits(a),bb=sl_bits(b);
        if(aa!=sl_ext80_to_f32(raw)||bb!=sl_ext80_to_f64(raw)){if(failures<4)fprintf(stderr,"Mismatch at %u power %d\n",i,power);++failures;}
        // Exact IEEE -> extended storage for the finite native reference values.
        if(__builtin_isfinite(a)){long double x=static_cast<long double>(a);SlU bits=0;memcpy(&bits,&x,10);if(bits!=sl_fp_to_ext80(aa,4))++failures;}
        if(__builtin_isfinite(b)){long double x=static_cast<long double>(b);SlU bits=0;memcpy(&bits,&x,10);if(bits!=sl_fp_to_ext80(bb,8))++failures;}
    }
    for(unsigned i=0;i<20000;++i){
        SlU64 bits=i==0?0x8000000000000000ULL:i==1?0x7fffffffffffffffULL:i==2?0:i==3?~SlU64(0):next();
        __INT64_TYPE__ v64;__INT32_TYPE__ v32;memcpy(&v64,&bits,8);memcpy(&v32,&bits,4);
        long double a=static_cast<long double>(v64),b=static_cast<long double>(v32);
        SlU aa=0,bb=0;memcpy(&aa,&a,10);memcpy(&bb,&b,10);
        if(aa!=sl_integer_to_ext80(bits,64)||bb!=sl_integer_to_ext80(bits,32))++failures;
    }
    printf("{\"scope\":\"finite canonical ext80 storage and integer conversions\",\"float_cases\":20000,\"integer_cases\":40000,\"mismatches\":%u,\"native_x87_type_oracle\":true,\"rounding\":\"nearest-even\",\"passed\":%s}\n",failures,failures?"false":"true");return failures?1:0;
#else
    puts("{\"native_x87_type_oracle\":false,\"skipped\":true}");return 77;
#endif
}
