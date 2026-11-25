#pragma once
#include <cstddef>
#include <cstring>
#include <string>
namespace cronox {
inline bool usablePresetName(std::string name) {
  const auto begin=name.find_first_not_of(" \t\r\n");
  if(begin==std::string::npos)return false;
  name=name.substr(begin,name.find_last_not_of(" \t\r\n")-begin+1);
  for(char& c:name)if(c>='A'&&c<='Z')c+=32;
  return name!="unknown"&&name!="empty"&&name!="default"&&name!="defaut"&&name!="défaut";
}
// Steinberg FPCh header: 28 program-name bytes at offset28, chunk size at56.
// The native importer already validates the complete container before using this label.
inline std::string fxpProgramName(const void* bytes,std::size_t size) {
  if(!bytes||size<60)return {};
  const auto* p=static_cast<const char*>(bytes);
  if(std::memcmp(p,"CcnK",4)||std::memcmp(p+8,"FPCh",4))return {};
  std::string name(p+28,strnlen(p+28,28));
  return usablePresetName(name)?name:std::string();
}
}
