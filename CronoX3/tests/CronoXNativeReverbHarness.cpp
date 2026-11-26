// Shared harness for exact comparisons with the original i386 instructions.
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <optional>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>
#define private public
#include "../src/engine/LegacyEngine.h"
#undef private
#include "../src/engine/LegacyEngine.cpp"
#include "CronoXReverbFixtures.h"
using namespace sophistry;
static std::string failure;
extern "C" {
void* cr_reverb_create(int native) {
  try {LegacyEngineConfig c;c.nativeCronoXReverb=native;c.collectDiagnostics=false;return new LegacyEngine::Impl(c);}
  catch(const std::exception& e){failure=e.what();return nullptr;}
}
void cr_reverb_destroy(void* p){delete static_cast<LegacyEngine::Impl*>(p);}
void* cr_reverb_cpu(void* p){return static_cast<LegacyEngine::Impl*>(p)->cpu;}
const char* cr_reverb_error(){return failure.c_str();}
int cr_reverb_case(void* p,unsigned number) {
  try {auto& h=*static_cast<LegacyEngine::Impl*>(p);reverb_fixture::prepare({h.cpu->memory,h.cpu->memory_size},number);return 0;}
  catch(const std::exception& e){failure=e.what();return 1;}
}
int cr_reverb_run(void* p,unsigned entry,unsigned self,unsigned frames,int flush) {
  try {
    auto& h=*static_cast<LegacyEngine::Impl*>(p);
    const auto previous=nativeAudioFloatState();auto mode=previous;
    mode.control&=~ScopedOriginalAudioFloatMode::mask;
    restoreNativeAudioFloatState(mode);
    try {ScopedOriginalAudioFloatMode scope(flush);h.run(entry,{self,frames});}
    catch(...) {restoreNativeAudioFloatState(previous);throw;}
    restoreNativeAudioFloatState(previous);return 0;
  } catch(const std::exception& e){failure=e.what();return 1;}
}
std::uint64_t cr_reverb_blocks(void* p){return static_cast<LegacyEngine::Impl*>(p)->nativeReverbBlocks;}
std::uint64_t cr_reverb_fallbacks(void* p){return static_cast<LegacyEngine::Impl*>(p)->nativeReverbFallbacks;}
}
