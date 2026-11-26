#pragma once
// Direct transcription of CronoX 3.6.6 i386 render12 0xd3d70, render22
// 0xd400e and comb::processMod 0xd6912. Every add/sub/mul is binary32;
// compile with -fno-fast-math -ffp-contract=off. No new reverb algorithm,
// silence threshold, tail timer, parameter smoothing or voice policy.
#include <array>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <initializer_list>

namespace sophistry::native_reverb {
struct ReverbMemory {
  std::uint8_t* data;
  std::size_t size;
  using U = std::uint32_t;
  bool range(U at, std::uint64_t n) const {
    return at > 0 && at <= size && n <= size-at;
  }
  template<class T> T get(U at) const { T v; std::memcpy(&v,data+at,sizeof(v)); return v; }
  template<class T> void put(U at,T v) const { std::memcpy(data+at,&v,sizeof(v)); }
  U word(U at) const { return get<U>(at); }
  int integer(U at) const { return get<std::int32_t>(at); }
  float value(U at) const { return get<float>(at); }
  bool flag(U at) const { return data[at] != 0; }
  bool floats(U at,int n) const { return n >= 0 && range(at,std::uint64_t(n)*4); }
};

struct NativeReverbPlan {
  using U = ReverbMemory::U;
  U self=0, input=0, output=0;
  U wantWrite=0, wantRead=0, doneWrite=0;
  int frames=0;
  bool mono=false, replace=false;

  // Reject an unfamiliar layout BEFORE any state is changed. Such calls
  // continue in the complete original generated implementation.
  bool prepare(ReverbMemory m,U entry,U object,int count) {
    if ((entry!=0xd3d70 && entry!=0xd400e) || count<=0 || count>65536 ||
        !m.range(object,0x85c)) return false;
    self=object; frames=count; mono=entry==0xd3d70;
    const U vt=m.word(self);
    if (!m.range(vt,0x158)) return false;
    U writer=m.word(vt+0x124);
    if (mono) {
      const U dw=m.word(vt+0x154);
      if (dw==0x41a38) writer=m.word(vt+0x128);
      else if (dw!=0x86848) return false;
    }
    if (writer==0x86a84) writer=m.word(vt+0x128);
    if (writer!=0x11050 && writer!=0x3d450) return false;
    replace=writer==0x3d450;
    input=m.word(self+0x120); output=m.word(self+0x128);
    if (!m.range(input,0x54) || !m.range(output,0x54) || (mono && input==output)) return false;
    const U ivt=m.word(input),ovt=m.word(output);
    if (!m.range(ivt,0x68) || !m.range(ovt,0x68)) return false;
    wantWrite=m.word(ovt+0x4c); wantRead=m.word(ivt+(mono?0x54:0x58));
    doneWrite=m.word(ovt+0x64);
    if (wantWrite!=0xa1dac || wantRead!=(mono?0xa209e:0xa2124) || doneWrite!=0xa2388)
      return false;
    if (!buffer(m,input,false) || !buffer(m,output,true)) return false;
    if (m.flag(input+0x24) || (mono && m.flag(input+0x23))) return false;
    if (m.integer(self+0x854)<0 || m.integer(self+0x854)>6 ||
        !std::isfinite(m.value(self+0x1d0)) || !std::isfinite(m.value(self+0x858))) return false;
    const int pn=m.integer(self+0x74c),pi=m.integer(self+0x744);
    if (pn<1 || pi<0 || pi>=pn || !m.floats(m.word(self+0x738),pn)) return false;
    struct Span {U at;std::uint64_t bytes;};
    std::array<Span,29> delays{};unsigned delayCount=0;
    auto overlaps=[](Span a,Span b) {return std::uint64_t(a.at)<std::uint64_t(b.at)+b.bytes && std::uint64_t(b.at)<std::uint64_t(a.at)+a.bytes;};
    auto audioRange=[&](Span a) {
      // Original allocations are disjoint from code, metadata and the guest
      // call stack. Keep unusual aliasing layouts in the generic lift.
      if (a.at<0x200000 || overlaps(a,{0x700000,0x10000}) ||
          overlaps(a,{self,0x85c}) || overlaps(a,{input,0x54}) || overlaps(a,{output,0x54})) return false;
      return true;
    };
    auto addDelay=[&](U at,int n) {
      const Span a{at,std::uint64_t(n)*4};
      if (!audioRange(a)) return false;
      for (unsigned i=0;i<delayCount;++i) if (overlaps(a,delays[i])) return false;
      delays[delayCount++]=a;return true;
    };
    if (!addDelay(m.word(self+0x738),pn)) return false;
    for (U base : {self+0x1d4,self+0x3f4}) for (U i=0;i<8;++i) {
      const U s=base+i*0x44;
      const int n=m.integer(s+8),index=m.integer(s+0x10);
      if (n<1 || n>0x1000000 || index<0 || index>=n || !m.floats(m.word(s+4),n) ||
          !std::isfinite(m.value(s)) || !std::isfinite(m.value(s+0x1c)) || !addDelay(m.word(s+4),n)) return false;
      if (m.flag(self+0x850)) {
        const int offset=m.integer(s+0x30),maximum=m.integer(s+0x40);
        const float fraction=m.value(s+0x34),delta=m.value(s+0x3c);
        if (maximum<0 || maximum>=n || offset<0 || offset>maximum ||
            !(fraction>=0 && fraction<1) || !std::isfinite(delta) || std::fabs(delta)>=1) return false;
      }
    }
    for (U base : {self+0x614,self+0x6a4}) for (int i=0;i<m.integer(self+0x854);++i) {
      const U s=base+U(i)*0x18;
      const int n=m.integer(s+8),index=m.integer(s+0x10);
      if (n<1 || index<0 || index>=n || !m.floats(m.word(s+4),n) || !std::isfinite(m.value(s)) || !addDelay(m.word(s+4),n)) return false;
    }
    for (U b : {input,output}) for (U slot : {0x34u,0x38u,0x3cu,0x40u,0x4cu,0x50u}) {
      if (slot!=0x34 && !(b==output || (!mono && !m.flag(b+0x22) && slot==0x3c))) continue;
      if (slot!=0x34 && slot!=0x3c && !m.flag(b+0x24)) continue;
      const Span a{m.word(b+slot),std::uint64_t(m.integer(b+0x18))*4};
      if (!audioRange(a)) return false;
      for (unsigned i=0;i<delayCount;++i) if (overlaps(a,delays[i])) return false;
    }
    return true;
  }

  bool buffer(ReverbMemory m,U b,bool writing) const {
    const int capacity=m.integer(b+0x18),block=m.integer(b+0x28),offset=m.integer(b+0x30);
    if (!m.flag(b+0x20) || m.integer(b+0x10)<(writing||!mono?2:1) ||
        capacity<1 || block<1 || block>capacity || offset<0 || offset>block || frames>block-offset ||
        !m.floats(m.word(b+0x34),capacity)) return false;
    if ((writing || (!mono && !m.flag(b+0x22))) && !m.floats(m.word(b+0x3c),capacity)) return false;
    if (writing && m.flag(b+0x24)) {
      for (U slot : {0x38u,0x40u,0x4cu,0x50u}) if (!m.floats(m.word(b+slot),capacity)) return false;
      if (!m.range(0x11c078,4) || !m.range(m.word(0x11c078),4)) return false;
      const int chunk=m.integer(m.word(0x11c078));
      if (chunk<1 || !m.floats(m.word(b+0xc),chunk)) return false;
    }
    return true;
  }

  static float negate(float v) {
    U bits; std::memcpy(&bits,&v,4); bits^=0x80000000u; std::memcpy(&v,&bits,4); return v;
  }
  static float comb(ReverbMemory m,U s,float input,bool modulate) {
    const U delay=m.word(s+4);
    const int index=m.integer(s+0x10),n=m.integer(s+8);
    float result;
    if (!modulate) result=m.value(delay+U(index)*4);
    else {
      int offset=m.integer(s+0x30);
      float fraction=m.value(s+0x34),delta=m.value(s+0x3c);
      const int a=(offset+index)%n,b=(a+1)%n;
      const float left=(1.f-fraction)*m.value(delay+U(a)*4);
      const float right=m.value(delay+U(b)*4)*fraction;
      result=right+left;
      fraction=fraction+delta;
      if (fraction>=1.f) {fraction=fraction+-1.f;++offset;}
      if (fraction<0.f) {fraction=fraction+1.f;--offset;}
      if (offset>m.integer(s+0x40) || offset<0) {
        fraction=fraction-delta;
        delta=negate(delta);
        if (fraction>=1.f) {fraction=fraction+-1.f;++offset;}
        if (fraction<0.f) {fraction=fraction+1.f;--offset;}
      }
      m.put(s+0x30,offset);m.put(s+0x34,fraction);m.put(s+0x3c,delta);
    }
    const float damping=m.value(s+0x1c);
    const float old=damping*m.value(s+0x18);
    const float fresh=(1.f-damping)*result;
    const float filtered=fresh+old;
    m.put(s+0x18,filtered);
    const float feedback=filtered*m.value(s);
    m.put(delay+U(index)*4,feedback+input);
    m.put(s+0x10,index+1<n?index+1:0);
    return result;
  }

  void render(ReverbMemory m,U inLeft,U inRight,U outLeft,U outRight) const {
    for (int frame=0;frame<frames;++frame) {
      const U pd=m.word(self+0x738),pi=m.word(self+0x744);
      const float delayed=m.value(pd+pi*4);
      float incoming=m.value(inLeft);
      if (!mono) {incoming=incoming+m.value(inRight);incoming=incoming*.5f;}
      m.put(pd+pi*4,incoming);
      m.put(self+0x744,int(pi)+1<m.integer(self+0x74c)?int(pi)+1:0);
      const float inputSample=delayed*m.value(self+0x858);
      float left=0,right=0;
      for (U i=0;i<8;++i) {
        const float l=comb(m,self+0x1d4+i*0x44,inputSample,m.flag(self+0x850));
        const float r=comb(m,self+0x3f4+i*0x44,inputSample,m.flag(self+0x850));
        left=left+l;right=right+r;
      }
      for (int i=0;i<m.integer(self+0x854);++i) {
        const U ls=self+0x614+U(i)*0x18,rs=self+0x6a4+U(i)*0x18;
        const U ld=m.word(ls+4),rd=m.word(rs+4),li=m.word(ls+0x10),ri=m.word(rs+0x10);
        const float oldLeft=m.value(ld+li*4),oldRight=m.value(rd+ri*4);
        const float lf=m.value(ls)*oldLeft,rf=m.value(rs)*oldRight;
        m.put(ld+li*4,lf+left);
        m.put(ls+0x10,int(li)+1<m.integer(ls+8)?int(li)+1:0);
        m.put(rd+ri*4,rf+right);
        m.put(rs+0x10,int(ri)+1<m.integer(rs+8)?int(ri)+1:0);
        left=oldLeft-left;right=oldRight-right;
      }
      const float wetLeft=left*m.value(self+0x1d0);
      const float valueLeft=mono?m.value(inLeft)+wetLeft:wetLeft+m.value(inLeft);
      m.put(outLeft,replace?valueLeft:m.value(outLeft)+valueLeft);
      const float wetRight=right*m.value(self+0x1d0);
      const float valueRight=mono?m.value(inLeft)+wetRight:wetRight+m.value(inRight);
      m.put(outRight,replace?valueRight:m.value(outRight)+valueRight);
      inLeft+=4;inRight+=4;outLeft+=4;outRight+=4;
    }
  }
};
} // namespace sophistry::native_reverb
