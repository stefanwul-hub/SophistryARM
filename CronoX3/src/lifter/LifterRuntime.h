#pragma once
// Freestanding support for statically emitted p-code operations.
// There is no x86 instruction decoder or x86 bytecode execution in this runtime.
#if __BYTE_ORDER__ != __ORDER_LITTLE_ENDIAN__
#error This experimental lift currently requires a little-endian target.
#endif
using SlU8=__UINT8_TYPE__;
using SlU32=__UINT32_TYPE__;
using SlU64=__UINT64_TYPE__;
using SlSize=__SIZE_TYPE__;
using SlU=unsigned __int128;
using SlS=__int128;
struct SlCpu;
using SlCallback=void (*)(void*,SlU32,SlCpu*);
struct SlHook {SlU32 address;SlCallback function;void* user;};
struct SlCpu {
    SlU8* memory;SlSize memory_size;
    alignas(16) SlU8 reg[0x2000];
    alignas(16) SlU8 temp[0x200000];
    SlU8 seen[0x104000];
    SlU32 pc,stop,fault,hook_count;
    SlU64 steps,limit;
    SlHook hooks[64];
};
inline SlU sl_mask(unsigned bits) {return bits>=128?~SlU(0):(SlU(1)<<bits)-1;}
inline SlS sl_signed(SlU value,unsigned bits) {
    value&=sl_mask(bits);SlU sign=SlU(1)<<(bits-1);
    return static_cast<SlS>((value^sign)-sign);
}
template<unsigned N> inline SlU sl_get(const SlU8* bytes,SlSize size,SlU offset,SlCpu& c) {
    static_assert(N<=16,"p-code value exceeds 128 bits");
    if(offset>size || N>size-static_cast<SlSize>(offset)){c.fault=1;return 0;}
    SlU value=0;__builtin_memcpy(&value,bytes+static_cast<SlSize>(offset),N);return value;
}
template<unsigned N> inline void sl_put(SlU8* bytes,SlSize size,SlU offset,SlU value,SlCpu& c) {
    static_assert(N<=16,"p-code value exceeds 128 bits");
    if(offset>size || N>size-static_cast<SlSize>(offset)){c.fault=1;return;}
    __builtin_memcpy(bytes+static_cast<SlSize>(offset),&value,N);
}
template<class T> inline T sl_float(SlU bits){T value;__builtin_memcpy(&value,&bits,sizeof(T));return value;}
template<class T> inline SlU sl_bits(T value){SlU bits=0;__builtin_memcpy(&bits,&value,sizeof(T));return bits;}
inline SlU sl_popcount(SlU x){return __builtin_popcountll(static_cast<SlU64>(x))+__builtin_popcountll(static_cast<SlU64>(x>>64));}
inline SlU sl_lshift(SlU x,SlU n){return n>=128?0:x<<static_cast<unsigned>(n);}
inline SlU sl_rshift(SlU x,SlU n){return n>=128?0:x>>static_cast<unsigned>(n);}
inline SlU sl_sright(SlU x,SlU n,unsigned bits){
    const SlU mask=sl_mask(bits);x&=mask;const bool negative=(x>>(bits-1))&1;
    if(n>=bits)return negative?mask:0;
    if(!n)return x;
    const unsigned shift=static_cast<unsigned>(n);
    return (x>>shift)|(negative?(mask^sl_mask(bits-shift)):0);
}
inline bool sl_tick(SlCpu& c){if(c.fault||c.pc==c.stop)return false;if(c.pc<sizeof(c.seen))c.seen[c.pc]=1;if(++c.steps>c.limit){c.fault=4;return false;}return true;}
SlU sl_ext80_to_f64(SlU bits);
SlU sl_ext80_to_f32(SlU bits);
SlU sl_fp_to_ext80(SlU bits,unsigned source_bytes);
SlU sl_trunc_fp(SlU bits,unsigned source_bytes,unsigned output_bits);
SlU sl_integer_to_ext80(SlU value,unsigned input_bits);
SlU sl_divide(SlCpu& c,SlU numerator,SlU denominator,unsigned input_bits,unsigned quotient_bits,bool is_signed,bool remainder);
SlU sl_sqrt_f32(SlU bits);
SlU sl_sqrt_f64(SlU bits);
int sl_execute(SlCpu& c,SlU32 entry,SlU32 stop,SlU64 limit);
extern "C" {
SlCpu* sl_create(SlSize memory_size);
void sl_destroy(SlCpu* c);
int sl_mem_write(SlCpu* c,SlU32 address,const void* data,SlSize size);
int sl_mem_read(SlCpu* c,SlU32 address,void* data,SlSize size);
int sl_reg_write(SlCpu* c,SlU32 offset,const void* data,SlSize size);
int sl_reg_read(SlCpu* c,SlU32 offset,void* data,SlSize size);
int sl_hook(SlCpu* c,SlU32 address,SlCallback callback,void* user);
void sl_set_pc(SlCpu* c,SlU32 address);
void sl_push_double_return(SlCpu* c,double value);
SlU32 sl_get_pc(SlCpu* c);
SlU32 sl_get_fault(SlCpu* c);
SlU64 sl_get_steps(SlCpu* c);
SlU32 sl_coverage_count(SlCpu* c);
int sl_run(SlCpu* c,SlU32 entry,SlU32 stop,SlU64 limit);
}
