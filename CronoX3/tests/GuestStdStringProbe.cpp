#include "../src/engine/GuestStdString.h"
#include <array>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
struct Host {
  using U32=std::uint32_t;
  std::vector<unsigned char> memory=std::vector<unsigned char>(0x100000);
  U32 cursor=0x10000,guestEmptyStringData=0;
  std::set<U32> guestStringData;
  const unsigned char* data(U32 p,std::size_t n)const {
    if(p>memory.size()||n>memory.size()-p)throw std::runtime_error("test memory bounds");return memory.data()+p;
  }
  U32 word(U32 p)const {U32 v;std::memcpy(&v,data(p,4),4);return v;}
  template<class T>void put(U32 p,T v){(void)data(p,sizeof(v));std::memcpy(memory.data()+p,&v,sizeof(v));}
  void write(U32 p,const void* v,std::size_t n){(void)data(p,n);std::memcpy(memory.data()+p,v,n);}
  void zero(U32 p,std::size_t n){(void)data(p,n);std::memset(memory.data()+p,0,n);}
  U32 allocate(U32 n){U32 p=cursor;cursor+=(n+15)&~15u;(void)data(p,n);return p;}
  void release(U32 p){(void)data(p,1);}
  std::string string(U32 p)const{return reinterpret_cast<const char*>(data(p,1));}
  std::string text(U32 object)const {U32 p=word(object);return {reinterpret_cast<const char*>(data(p,word(p-12))),word(p-12)};}
};
int main() {
  try {
    Host h;unsigned checks=0;
    const auto require=[&](bool value){if(!value)throw std::runtime_error("string ABI mismatch");++checks;};
    const auto call=[&](const char* name,std::initializer_list<std::uint32_t> args) {
      std::uint32_t p=0x70004,result=0,pop=0;
      for(auto v:args){h.put(p,v);p+=4;}
      if(!sophistry::guestStdStringService(h,name,0x70000,result,pop))throw std::runtime_error("unhandled string import");
      return std::array<std::uint32_t,2>{result,pop};
    };
    h.write(0x8000,"alpha.beta",11);
    call("__ZNSsC1EPKcRKSaIcE",{0x1000,0x8000,0});require(h.text(0x1000)=="alpha.beta");
    call("__ZNSsC1ERKSs",{0x1100,0x1000});require(h.word(0x1000)==h.word(0x1100));
    require(h.word(h.word(0x1000)-4)==1);
    auto index=call("__ZNSsixEm",{0x1100,0})[0];h.put(index,std::uint8_t('A'));
    require(h.text(0x1000)=="alpha.beta"&&h.text(0x1100)=="Alpha.beta");
    require(h.word(0x1000)!=h.word(0x1100));
    call("__ZNSsC1ERKSs",{0x1200,0x1100});require(h.word(0x1200)!=h.word(0x1100));
    auto sub=call("__ZNKSs6substrEmm",{0x1300,0x1100,6,4});require(sub[0]==0x1300&&sub[1]==4);
    require(h.text(0x1300)=="beta");
    require(call("__ZNKSs12find_last_ofEcm",{0x1100,'.',0xffffffff})[0]==5);
    require(std::int32_t(call("__ZNKSs7compareERKSs",{0x1100,0x1000})[0])<0);
    call("__ZNSspLERKSs",{0x1200,0x1200});require(h.text(0x1200)=="Alpha.betaAlpha.beta");
    call("__ZNSs6resizeEm",{0x1300,7});require(h.text(0x1300)==std::string("beta\0\0\0",7));
    call("__ZNSs5eraseEmm",{0x1300,4,0xffffffff});require(h.text(0x1300)=="beta");
    for(auto object:{0x1000u,0x1100u,0x1200u,0x1300u})call("__ZNSsD1Ev",{object});
    require(h.guestStringData.empty());
    std::printf("{\"scope\":\"32-bit libstdc++ guest string ABI contract\",\"checks\":%u,\"passed\":true}\n",checks);
    return 0;
  } catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}
}
