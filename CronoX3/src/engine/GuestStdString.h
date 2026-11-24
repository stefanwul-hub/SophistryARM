#pragma once
// Adapter for the 32-bit libstdc++ string ABI imported by CronoX 3.6.6.
// This is platform support, not replacement DSP. Guest pointers stay 32-bit.
#include <algorithm>
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <string>

namespace sophistry {
template<class Host>
bool guestStdStringService(Host& h,const std::string& name,std::uint32_t sp,
                           std::uint32_t& result,std::uint32_t& extraPop) {
  using U32=std::uint32_t;
  using I32=std::int32_t;
  const auto arg=[&](unsigned n){return h.word(sp+4+n*4);};
  if(name=="__ZNSaIcEC1Ev"||name=="__ZNSaIcED1Ev") {result=arg(0);return true;}
  if(name.rfind("__ZNSs",0)!=0&&name.rfind("__ZNKSs",0)!=0)return false;
  constexpr U32 limit=0x1ffffe0;
  const auto empty=[&]() {
    if(!h.guestEmptyStringData) {
      U32 p=h.allocate(16);h.zero(p,16);h.guestEmptyStringData=p+12;
    }
    return h.guestEmptyStringData;
  };
  const auto text=[&](U32 object) {
    U32 p=h.word(object);
    if(!p)return std::string();
    U32 n=h.word(p-12);
    if(n>limit)throw std::runtime_error("Invalid guest std::string length");
    return std::string(reinterpret_cast<const char*>(h.data(p,n)),n);
  };
  const auto dispose=[&](U32 p) {
    if(!p||p==h.guestEmptyStringData)return;
    if(!h.guestStringData.count(p))throw std::runtime_error("Unknown guest string representation");
    I32 refs=I32(h.word(p-4));
    if(refs>0)h.put(p-4,U32(refs-1));
    else {h.guestStringData.erase(p);h.release(p-12);}
  };
  const auto assign=[&](U32 object,const std::string& value,bool releaseOld) {
    if(value.size()>limit)throw std::runtime_error("Guest std::string exceeds limit");
    U32 p;
    if(value.empty())p=empty();
    else {
      U32 base=h.allocate(U32(value.size())+13);p=base+12;
      h.put(base,U32(value.size()));h.put(base+4,U32(value.size()));h.put(base+8,U32(0));
      h.write(p,value.data(),value.size());h.put(p+U32(value.size()),std::uint8_t(0));
      h.guestStringData.insert(p);
    }
    U32 previous=releaseOld?h.word(object):0;
    h.put(object,p);
    if(releaseOld)dispose(previous);
  };
  const auto copy=[&](U32 target,U32 source,bool releaseOld) {
    if(target==source)return;
    U32 p=h.word(source);
    if(!p){assign(target,{},releaseOld);return;}
    if(p!=h.guestEmptyStringData&&I32(h.word(p-4))<0) {assign(target,text(source),releaseOld);return;}
    if(p!=h.guestEmptyStringData) {
      if(!h.guestStringData.count(p))throw std::runtime_error("Unknown shared guest string");
      h.put(p-4,h.word(p-4)+1);
    }
    U32 previous=releaseOld?h.word(target):0;
    h.put(target,p);if(releaseOld)dispose(previous);
  };
  U32 object=arg(0);result=object;
  if(name=="__ZNSsC1Ev")assign(object,{},false);
  else if(name=="__ZNSsC1EPKcRKSaIcE")assign(object,h.string(arg(1)),false);
  else if(name=="__ZNSsC1ERKSs")copy(object,arg(1),false);
  else if(name=="__ZNSsC1EmcRKSaIcE") {
    if(arg(1)>limit)throw std::runtime_error("Guest string fill too large");
    assign(object,std::string(arg(1),char(arg(2))),false);
  }
  else if(name=="__ZNSsD1Ev")dispose(h.word(object));
  else if(name=="__ZNSsaSERKSs")copy(object,arg(1),true);
  else if(name=="__ZNSsaSEPKc"||name=="__ZNSs6assignEPKc")assign(object,h.string(arg(1)),true);
  else if(name=="__ZNSs5clearEv")assign(object,{},true);
  else if(name=="__ZNKSs5c_strEv")result=h.word(object);
  else if(name=="__ZNKSs4sizeEv"||name=="__ZNKSs6lengthEv")result=U32(text(object).size());
  else if(name=="__ZNKSsixEm"||name=="__ZNSsixEm") {
    auto value=text(object);
    if(arg(1)>value.size())throw std::runtime_error("Guest string index out of range");
    if(name=="__ZNSsixEm"&&h.word(object)!=h.guestEmptyStringData) {
      if(I32(h.word(h.word(object)-4))>0)assign(object,value,true);
      h.put(h.word(object)-4,U32(-1)); // libstdc++ leaked, unique representation.
    }
    result=h.word(object)+arg(1);
  }
  else if(name=="__ZNKSs6substrEmm") {
    // Nontrivial i386 C++ return: hidden result pointer, then this/pos/count;
    // the original caller compensates for RET 4 after this library call.
    auto value=text(arg(1));U32 pos=arg(2),count=arg(3);
    if(pos>value.size())throw std::runtime_error("Guest substr position out of range");
    assign(object,value.substr(pos,count),false);extraPop=4;
  }
  else if(name=="__ZNKSs7compareERKSs") {
    const auto a=text(object),b=text(arg(1));I32 comparison=0;
    for(std::size_t i=0;i<std::min(a.size(),b.size());++i)
      if(a[i]!=b[i]){comparison=I32(static_cast<unsigned char>(a[i]))-I32(static_cast<unsigned char>(b[i]));break;}
    if(!comparison)comparison=I32(a.size())-I32(b.size());
    result=U32(comparison);
  }
  else if(name=="__ZNKSs4findERKSsm")result=U32(text(object).find(text(arg(1)),arg(2)));
  else if(name=="__ZNKSs12find_last_ofEcm")result=U32(text(object).find_last_of(char(arg(1)),arg(2)));
  else if(name=="__ZNKSs13find_first_ofEcm")result=U32(text(object).find_first_of(char(arg(1)),arg(2)));
  else if(name=="__ZNKSs17find_first_not_ofEcm")result=U32(text(object).find_first_not_of(char(arg(1)),arg(2)));
  else {
    auto value=text(object);
    if(name=="__ZNSs6appendEPKc"||name=="__ZNSspLEPKc")value+=h.string(arg(1));
    else if(name=="__ZNSs6appendERKSs"||name=="__ZNSspLERKSs")value+=text(arg(1));
    else if(name=="__ZNSs6appendEmc") {
      if(arg(1)>limit-value.size())throw std::runtime_error("Guest append exceeds limit");
      value.append(arg(1),char(arg(2)));
    }
    else if(name=="__ZNSs6resizeEm") {
      if(arg(1)>limit)throw std::runtime_error("Guest resize exceeds limit");
      value.resize(arg(1));
    }
    else if(name=="__ZNSs5eraseEmm")value.erase(arg(1),arg(2));
    else if(name=="__ZNSs7replaceEmmRKSsmm")value.replace(arg(1),arg(2),text(arg(3)),arg(4),arg(5));
    else return false;
    assign(object,value,true);
  }
  return true;
}
}
