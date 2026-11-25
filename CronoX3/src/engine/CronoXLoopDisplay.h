#pragma once
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
namespace sophistry::cronoxLoop {
// Original CSampleDisplayKj_c::getMaxMin 0x9c8c4, differential mode 1
// selected by createLopEdits 0x78c3e. This is drawing data only, never DSP.
template<class Read> std::array<float,2> column(float first,float last,Read read) {
  int begin=int(first+.5f), end=std::max(int(last+.5f),begin+1);
  float previous=read(begin),lo=1.f,hi=-1.f;
  for(int i=begin+1;i<=end;++i) {
    const float sample=read(i),difference=sample-previous;
    if(hi<difference)hi=difference;
    if(difference<lo)lo=difference;
    if(hi < -1.f)hi=-1.f;else if(hi>1.1f)hi=1.1f;
    if(lo < -1.1f)lo=-1.1f;
    else if(lo>1.f)lo=1.f;
    if(hi < -1.f)hi=-1.f;else if(hi>1.f)hi=1.f;
    previous=sample;
  }
  return {lo,hi};
}
inline bool displayAlias(unsigned tag){return tag>=953&&tag<=960;}
inline unsigned parameter(unsigned generator,unsigned marker) {
  return (marker==3?835:815+marker*2)+generator;
}
inline unsigned aliasParameter(unsigned tag) {
  return displayAlias(tag)?parameter((tag-953)%2,(tag-953)/2):tag;
}
// 0x9d33e: nearest marker, ties prefer the later marker; top 12 px
// select crossfade. Coincident sample/loop starts have a directional tie rule.
inline unsigned hit(float position,float y,const std::array<float,3>& values) {
  if(y<=12)return 3;
  unsigned slot=0;float distance=std::abs(position-values[0]);
  for(unsigned i=1;i<3;++i)if(std::abs(position-values[i])<=distance){slot=i;distance=std::abs(position-values[i]);}
  if(values[0]==values[1]&&slot<2)slot=position>=values[0]?1:0;
  return slot;
}
// 0x9d21e: viewport position -> normalized sample position. Crossfade is
// relative to loop start; original setters enforce ordering/zero crossings.
inline float drag(float first,float span,float duration,float x,float width,
                  unsigned slot,float loopStart) {
  if(!(duration>0&&width>0))return 0;
  float value=(first+span*(x/width))/duration;
  if(slot==3)value-=loopStart;
  return std::clamp(value,0.f,1.f);
}
} // namespace sophistry::cronoxLoop
