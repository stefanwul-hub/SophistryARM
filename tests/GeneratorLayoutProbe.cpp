#include "../src/engine/GeneratorControls.h"
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <set>
#include <stdexcept>
static unsigned big(const unsigned char *p) {
  return unsigned(p[0]) << 24 | unsigned(p[1]) << 16 | unsigned(p[2]) << 8 |
         p[3];
}
int main(int argc, char **argv) {
  try {
    if (argc != 2)
      throw std::runtime_error("Expected original image folder");
    unsigned bindings = 0, layouts = 0;
    const std::filesystem::path root = argv[1];
    auto size = [&](unsigned number, unsigned width, unsigned height) {
      char name[32];
      std::snprintf(name, sizeof(name), "bmp%05u.png", number);
      std::ifstream f(root / name, std::ios::binary);
      unsigned char bytes[24]{};
      f.read(reinterpret_cast<char *>(bytes), sizeof(bytes));
      if (!f || big(bytes + 16) != width || big(bytes + 20) != height)
        throw std::runtime_error("Original bitmap dimensions differ: " +
                                 std::string(name));
    };
    for (unsigned g = 0; g < 4; ++g)
      for (unsigned type = 0; type < (g < 2 ? 4u : 3u); ++type) {
        size(220 + 2 * type + (g & 1), 636, 145);
        std::set<unsigned> tags;
        for (const auto &spec : sophistry::generatorLayout(g, type)) {
          if (!tags.insert(spec.tag).second)
            throw std::runtime_error("Duplicate control in original panel");
          if (spec.image) {
            size(spec.image, spec.width, spec.height * spec.frames);
            ++bindings;
          }
        }
        ++layouts;
      }
    std::cout << "{\"passed\":true,\"layouts\":" << layouts
              << ",\"sprite_bindings_measured\":" << bindings
              << ",\"background_dimensions_verified\":true,"
                 "\"native_cocoa_visual_render_tested\":false}\n";
    return 0;
  } catch (const std::exception &e) {
    std::cerr << e.what() << '\n';
    return 1;
  }
}
