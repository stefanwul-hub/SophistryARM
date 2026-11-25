#pragma once
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <string>

namespace cronox::probe {
struct FxpHeader {
  std::uint32_t version=0, fileID=0, pluginVersion=0, programCount=0, payloadBytes=0;
  static constexpr std::size_t payloadOffset=60;
};
inline std::uint32_t big32(const unsigned char* p){
  return std::uint32_t(p[0])<<24|std::uint32_t(p[1])<<16|std::uint32_t(p[2])<<8|p[3];
}
inline FxpHeader inspectFxp(const void* bytes,std::size_t size){
  if(!bytes||size<FxpHeader::payloadOffset)throw std::runtime_error("FXP header is truncated (expected at least 60 bytes)");
  const auto* p=static_cast<const unsigned char*>(bytes);
  if(std::memcmp(p,"CcnK",4)||std::memcmp(p+8,"FPCh",4))
    throw std::runtime_error("Expected a chunk-based FXP (CcnK / FPCh)");
  // Steinberg FPCh layout: VERSION at 12; VST FILE ID at 16. Neither is the
  // AU subtype. The real CronoX reference uses version=1, VST ID='Crx3'; its
  // AU subtype is 'CrX3'. Match the working CRX011 editor's structural checks;
  // leave interpretation/compatibility of the opaque chunk to the same engine.
  FxpHeader out{big32(p+12),big32(p+16),big32(p+20),big32(p+24),big32(p+56)};
  if(!out.payloadBytes||out.payloadBytes>1048576)
    throw std::runtime_error("FXP chunk is empty or exceeds the 1 MiB import limit");
  if(out.payloadBytes!=size-FxpHeader::payloadOffset)
    throw std::runtime_error("FXP chunk length at offset 56 differs from the file length");
  return out;
}
inline std::string fourCC(std::uint32_t value){
  std::string text;
  for(int shift=24;shift>=0;shift-=8){unsigned c=(value>>shift)&255;if(c<32||c>126){text="0x";for(int nibble=28;nibble>=0;nibble-=4)text+="0123456789abcdef"[(value>>nibble)&15];return text;}text+=char(c);}
  return text;
}
} // namespace cronox::probe
