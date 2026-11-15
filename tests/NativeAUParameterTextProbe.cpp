// Compare this output with probe_au_parameter_text.py's original i386 vectors.
#include "../src/engine/LegacyEngine.h"
#include <iostream>
#include <optional>
#include <stdexcept>
#include <string>
namespace {
std::string quote(const std::string &text) {
  std::string result = "\"";
  for (unsigned char c : text) {
    if (c == '\\' || c == '"')
      result += '\\';
    if (c < 32)
      throw std::runtime_error("Unexpected control character");
    result += char(c);
  }
  return result + "\"";
}
} // namespace
int main() {
  try {
    sophistry::LegacyEngineConfig config;
    config.audioUnitMode = true;
    sophistry::LegacyEngine engine(config);
    engine.initialize();
    bool first = true;
    std::cout << '[';
    auto check = [&](unsigned id, const char *mode,
                     std::optional<float> value) {
      auto result = engine.auParameterText(id, value);
      if (!first)
        std::cout << ',';
      first = false;
      std::cout << "{\"id\":" << id << ",\"case\":" << quote(mode)
                << ",\"status\":" << result.status
                << ",\"has_text\":" << (result.text ? "true" : "false")
                << ",\"text\":" << quote(result.text.value_or("")) << '}';
    };
    for (auto id : engine.auParameterIds()) {
      auto p = engine.auParameterInfo(id);
      if (!(p.flags & (1u << 21)))
        continue;
      check(id, "minimum", p.minimum);
      check(id, "default", p.defaultValue);
      check(id, "maximum", p.maximum);
      check(id, "below", p.minimum - 1);
      check(id, "above", p.maximum + 1);
      check(id, "current", std::nullopt);
    }
    check(0, "ordinary", 0);
    check(603, "invalid", std::nullopt);
    std::cout << "]\n";
    return 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
