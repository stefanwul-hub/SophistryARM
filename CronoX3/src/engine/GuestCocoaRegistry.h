#pragma once
// Replay the old VSTGUI startup class registry with opaque 32-bit handles.
// Native Cocoa owns the actual new UI. Unsupported old object messages fail
// explicitly; this registry does not claim to execute arbitrary AppKit code.
#include <cstdint>
#include <string>
#include <stdexcept>

namespace sophistry {
template<class Host>
bool guestCocoaRegistryService(Host& h,const std::string& name,std::uint32_t sp,
                              std::uint32_t& result) {
  using U32=std::uint32_t;
  const auto arg=[&](unsigned n){return h.word(sp+4+n*4);};
  const auto make=[&](const std::string& type,const std::string& text,U32 parent=0) {
    U32 p=h.allocate(16);typename Host::Value v;
    v.type=type;v.text=text;v.number=parent;h.values.emplace(p,std::move(v));return p;
  };
  const auto stringValue=[&](U32 p) {
    auto found=h.values.find(p);
    if(found!=h.values.end())return found->second.text;
    if(h.word(p+4)==0x7c8)return h.cfString(p);
    return h.string(p);
  };
  const auto classValue=[&](U32 p) {
    auto found=h.values.find(p);
    if(found!=h.values.end()&&found->second.type=="ObjCClass")return p;
    const auto text=stringValue(p);
    auto known=h.objcClasses.find(text);
    if(known!=h.objcClasses.end())return known->second;
    U32 token=make("ObjCClass",text);h.objcClasses.emplace(text,token);return token;
  };
  const auto autorelease=[&](U32 p) {
    if(!h.objcPools.empty())h.values.at(h.objcPools.back()).array.push_back(p);
    return p;
  };
  if(name=="_objc_lookUpClass") {
    auto known=h.objcClasses.find(h.string(arg(0)));
    result=known==h.objcClasses.end()?0:known->second;
  } else if(name=="_objc_allocateClassPair") {
    auto text=h.string(arg(1));
    if(h.objcClasses.count(text))result=0;
    else {result=make("ObjCClass",text,arg(0));h.objcClasses.emplace(text,result);}
  } else if(name=="_class_addMethod") {
    h.objcMethods[arg(0)][h.string(arg(1))]=arg(2);result=1;
  } else if(name=="_class_addIvar") {
    h.objcIvars[arg(0)][h.string(arg(1))]=arg(2);result=1;
  } else if(name=="_objc_registerClassPair") {
    if(!h.values.count(arg(0))||h.values.at(arg(0)).type!="ObjCClass")
      throw std::runtime_error("Invalid legacy Cocoa class registration");
    result=0;
  } else if(name=="_objc_disposeClassPair") {
    auto f=h.values.find(arg(0));
    if(f!=h.values.end()) {h.objcClasses.erase(f->second.text);h.values.erase(f);}
    h.objcMethods.erase(arg(0));h.objcIvars.erase(arg(0));result=0;
  } else if(name=="_class_getSuperclass")result=U32(h.values.at(classValue(arg(0))).number);
  else if(name=="_objc_msgSend") {
    U32 receiver=arg(0);const auto selector=h.string(arg(1));
    if(!receiver){result=0;return true;}
    if(selector=="class")result=classValue(receiver);
    else if(selector=="alloc") {
      U32 type=classValue(receiver);
      const auto text=h.values.at(type).text;
      result=make(text=="NSAutoreleasePool"?"ObjCPool":"ObjCObject",text,type);
    } else if(selector=="init") {
      result=receiver;
      if(h.values.at(receiver).type=="ObjCPool")h.objcPools.push_back(receiver);
    } else if(selector=="initWithString:") {
      auto& value=h.values.at(receiver);value.type="CFString";value.text=stringValue(arg(2));value.number=0;result=receiver;
    } else if(selector=="stringWithString:")result=autorelease(h.newString(stringValue(arg(2))));
    else if(selector=="autorelease")result=autorelease(receiver);
    else if(selector=="retain") {h.retainValue(receiver);result=receiver;}
    else if(selector=="release"||selector=="drain") {
      auto f=h.values.find(receiver);
      if(f!=h.values.end()&&f->second.type=="ObjCPool") {
        if(h.objcPools.empty()||h.objcPools.back()!=receiver)throw std::runtime_error("Legacy Cocoa pool order");
        h.objcPools.pop_back();
      }
      h.releaseValue(receiver);result=0;
    } else if(selector=="UTF8String") {
      auto& value=h.values.at(receiver);
      if(!value.number) {U32 p=h.allocate(U32(value.text.size())+1);h.string(p,value.text);value.number=p;}
      result=U32(value.number);
    } else if(selector=="setString:") {
      auto& value=h.values.at(receiver);auto text=stringValue(arg(2));
      if(value.number)h.release(U32(value.number));value.number=0;value.text=std::move(text);result=0;
    } else if(selector=="stringWithFormat:") {
      auto format=stringValue(arg(2));auto text=stringValue(arg(3));
      if(format!="%@_%d")throw std::runtime_error("Unsupported legacy Cocoa string format");
      result=autorelease(h.newString(text+"_"+std::to_string(std::int32_t(arg(4)))));
    } else throw std::runtime_error("Unsupported legacy Cocoa startup selector "+selector);
  } else return false;
  return true;
}
}
