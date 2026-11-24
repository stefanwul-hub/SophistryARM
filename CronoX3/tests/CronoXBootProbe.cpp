#include "../src/engine/LegacyEngine.h"
#include <cstdio>
#include <exception>
int main() {
  try {
    sophistry::LegacyEngineConfig config;
    sophistry::LegacyEngine engine(config);
    engine.initialize();
    const auto preset=engine.presetName();
    const auto state=engine.saveProgram();
    std::printf("{\"project\":\"CronoX 3 ARM64\",\"engine_initialized\":true,\"program_bytes\":%zu,\"output_channels\":%u,\"au_tested\":false}\n",
                state.size(),engine.outputChannels());
    return 0;
  } catch(const std::exception& error) {
    std::fprintf(stderr,"CronoX engine startup: %s\n",error.what());
    return 1;
  }
}
