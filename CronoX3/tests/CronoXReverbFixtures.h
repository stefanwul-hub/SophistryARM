#pragma once
// Artificial states of the original reverb class, never a synth or licence.
#include "../src/engine/CronoXNativeReverb.h"
#include <stdexcept>

namespace reverb_fixture {
using U=std::uint32_t;
constexpr U base=0x300000,size=0x20000,obj=base,vt=0x302000,bvt=0x302400;
constexpr unsigned cases=160;
struct Case {U entry;int frames;bool flush;};
inline Case prepare(sophistry::native_reverb::ReverbMemory m,unsigned number) {
  using namespace sophistry::native_reverb;
  if (number>=cases) throw std::runtime_error("Unknown reverb fixture");
  U seed=0x4c696e50u+number*197u;
  auto random=[&]() {seed^=seed<<13;seed^=seed>>17;seed^=seed<<5;return seed;};
  for (U i=0;i<size;i+=4) m.put(base+i,random());
  for (U i=0;i<0x8000;i+=4) {
    float v=(int(random()%65536)-32768)/65536.f;
    if (number>=120) {
      U bits=(random()&0x80000000u)|(random()%4?random()%0xffffffu:0);
      std::memcpy(&v,&bits,4);
    }
    m.put(0x310000+i,v);
  }
  auto put=[&](U at,U value){m.put(at,value);};
  auto f=[&](U at,float value){m.put(at,value);};
  const int frames=std::array<int,5>{1,7,32,64,256}[number%5];
  const bool mono=number%4==0,inplace=number%4==2,mix=number%8>=4;
  const bool replace=number%3!=0,mod=number%2!=0,flush=number%10>=5;
  const U in=0x303000,out=inplace?in:0x304000;
  std::memset(m.data+obj,0,0x900);
  put(obj,vt);put(vt+0x124,replace?0x86a84:0x11050);put(vt+0x128,0x3d450);put(vt+0x154,0x86848);
  put(obj+0x120,in);put(obj+0x128,out);m.data[obj+0x168]=1;
  put(bvt+0x4c,0xa1dac);put(bvt+0x54,0xa209e);put(bvt+0x58,0xa2124);put(bvt+0x64,0xa2388);
  const U global=0x302800;put(0x11c078,global);put(global,64);
  std::memset(m.data+0x302900,0,64*4);
  for (U b : {in,out}) {
    std::memset(m.data+b,0,0x54);
    put(b,bvt);put(b+0xc,0x302900);put(b+0x10,6);put(b+0x18,512);
    put(b+0x28,512);put(b+0x2c,512);put(b+0x30,number%7);
    m.data[b+0x20]=1;m.data[b+0x21]=1;
    m.data[b+0x22]=b==in && (mono || number%4==3);
    m.data[b+0x23]=!m.data[b+0x22];
    m.data[b+0x24]=b==out && mix && !inplace;
    m.data[b+0x25]=number%3==0;m.data[b+0x26]=number%3==1;
    const U first=(b==in?0x310000:0x314000);
    for (U i=0;i<8;++i) put(b+0x34+i*4,first+i*0x800);
  }
  U next=0x305000;
  auto array=[&](int n) {
    const U start=next;next+=U(n)*4+16;
    for (int i=0;i<n;++i) {
      float v=(int(random()%65536)-32768)/65536.f;
      if (number>=120) { // small/denormal states and signed zeros
        U bits=(random()&0x80000000u)|(random()%4?random()%0xffffffu:0);
        std::memcpy(&v,&bits,4);
      }
      f(start+U(i)*4,v);
    }
    return start;
  };
  for (U start : {obj+0x1d4,obj+0x3f4}) for (U i=0;i<8;++i) {
    U s=start+i*0x44;int n=19+int(random()%34);
    f(s,.5f+(random()%256)/1024.f);put(s+4,array(n));put(s+8,n);put(s+0x10,number%3?n-1:0);
    f(s+0x18,number>=120?0.f:.0625f);f(s+0x1c,(random()%256)/256.f);
    put(s+0x30,number%3==0?0:3);f(s+0x34,number%3==0?.0001f:.9999f);
    f(s+0x3c,number%3==0?-.017f:.013f);put(s+0x40,3);
  }
  for (U start : {obj+0x614,obj+0x6a4}) for (U i=0;i<6;++i) {
    U s=start+i*0x18;const int n=3+int(random()%16);
    f(s,.5f);put(s+4,array(n));put(s+8,n);put(s+0x10,n-1);
  }
  put(obj+0x738,array(11));put(obj+0x744,10);put(obj+0x74c,11);
  f(obj+0x1d0,.375f);m.data[obj+0x850]=mod;
  put(obj+0x854,std::array<U,3>{0,2,6}[(number/5)%3]);f(obj+0x858,.015f);
  // Five contiguous calls also exercise the caller of render12/render22.
  return {number%5==4?0xd42d8u:(mono?0xd3d70u:0xd400eu),frames,flush};
}
inline std::uint64_t hash(const std::uint8_t* p,std::size_t n) {
  std::uint64_t v=14695981039346656037ull;
  while(n--) {v^=*p++;v*=1099511628211ull;}return v;
}
} // namespace reverb_fixture
