#pragma once
#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <vector>

namespace sophistry {
constexpr std::uint32_t noAUParameter = 0xffffffffu;
enum class GeneratorWidget {
  Dial,
  Step,
  Toggle,
  Type,
  Routing,
  Sample,
  Radio,
  HorizontalRadio
};
struct GeneratorControlSpec {
  std::uint32_t tag = 0;
  GeneratorWidget widget = GeneratorWidget::Dial;
  int x = 0, y = 0, width = 0, height = 0;
  std::uint32_t image = 0, frames = 0;
  int valueOffset = 0;
  bool darkValue = false;
};
struct GeneratorControlState {
  std::uint32_t tag = 0, kind = 0;
  std::int32_t minimum = 0, maximum = 0, defaultValue = 0, value = 0;
  std::uint32_t decimals = 0;
  float curve = 0;
  std::uint32_t auParameter = noAUParameter;
  char name[32]{}, text[128]{};
};
struct GeneratorPanelState {
  std::uint32_t version = 1, pair = 0, count = 0;
  std::array<std::uint32_t, 4> types{};
  std::array<GeneratorControlState, 48> controls{};
};
struct GeneratorControlEdit {
  std::uint32_t version = 1, tag = 0;
  float normalized = 0;
};
static_assert(sizeof(GeneratorControlState) == 196);
static_assert(sizeof(GeneratorPanelState) == 9436);
static_assert(sizeof(GeneratorControlEdit) == 12);

inline std::uint32_t generatorTypeTag(unsigned generator) {
  return generator < 2 ? 766 + generator : 772 + generator;
}
inline std::uint32_t generatorAUParameter(std::uint32_t tag) {
  if ((tag >= 28 && tag < 32) || (tag >= 64 && tag < 68) ||
      (tag >= 88 && tag < 92))
    return 484 + tag % 4;
  return tag < 110 ? tag : noAUParameter;
}
inline double generatorNormalized(const GeneratorControlState &s, double raw) {
  if (s.minimum >= s.maximum)
    return 0;
  double linear = std::max(
      0.0, std::min(1.0, (raw - s.minimum) / double(s.maximum - s.minimum)));
  return std::abs(s.curve) > 0.01f
             ? std::log1p(linear * std::expm1(double(s.curve))) / s.curve
             : linear;
}

// Coordinates and sprite styles: original KajaEditor constructors 0x56cc6,
// 0x57cce, 0x5772a, 0x571fc and 0x58ece; style table at0xf0ac0.
// Mode overlays are at(126,0)/(126,145), inside the panel at(0,37).
inline std::vector<GeneratorControlSpec> generatorLayout(unsigned g,
                                                         unsigned type) {
  if (g > 3 || type > (g < 2 ? 3u : 2u))
    return {};
  using W = GeneratorWidget;
  std::vector<GeneratorControlSpec> r;
  const bool bottom = g & 1;
  const int row = bottom ? 145 : 0;
  auto box = [&](unsigned tag, W widget, int x, int y, int w, int h,
                 unsigned image = 0, unsigned frames = 0) {
    r.push_back({tag, widget, x, y, w, h, image, frames, 0, false});
  };
  auto dial = [&](unsigned tag, int x, int y, unsigned image, int w, int h,
                  unsigned frames, int offset = 0, bool dark = false) {
    r.push_back({tag, W::Dial, x - w / 2, y - h / 2, w, h, image, frames,
                 offset, dark});
  };
  box(g, W::Toggle, 90, bottom ? 265 : 7, 35, 17, bottom ? 330 : 329, 2);
  dial(4 + g, bottom ? 72 : 50, bottom ? 223 : 108, 350, 33, 33, 71);
  dial(8 + g, 70, bottom ? 171 : 56, 353, 78, 38, 53);
  if (!bottom)
    // 0x5efe2: x=0x52, y=0x56, three rows; bitmap380 has
    // three inactive rows followed by the three active rows.
    box(108 + g / 2, W::Routing, 82, 86, 30, 54, 380, 2);
  box(generatorTypeTag(g), W::Type, 135, row + (bottom ? 116 : 10), 120, 19);
  auto modeDial = [&](unsigned tag, int x, int y, unsigned image, int w, int h,
                      unsigned frames, int offset = 0, bool dark = false) {
    dial(tag, 126 + x, row + y, image, w, h, frames, offset, dark);
  };
  auto step = [&](unsigned tag, int x, int y) {
    box(tag, W::Step, 126 + x, row + y, 56, 15);
  };
  auto toggle = [&](unsigned tag, int x, int y, unsigned image, int w, int h) {
    box(tag, W::Toggle, 126 + x, row + y, w, h, image, 2);
  };
  if (type == 0) {
    const int dy = bottom ? -7 : 0;
    modeDial(12 + g, 206, 76 + dy, 354, 114, 114, 83);
    modeDial(16 + g, 344, 76 + dy, 354, 114, 114, 83);
    modeDial(36 + g, 464, 44 + dy, 358, 78, 38, 53, 12, true);
    toggle(32 + g, 437, 109 + dy, 349, 55, 20);
    toggle(40 + g, 429, 84 + dy, 300, 71, 20);
    step(20 + g, 533, 41 + dy);
    step(24 + g, 533, 68 + dy);
    step(28 + g, 533, 95 + dy);
  } else if (type == 1 || type == 2) {
    const int dy = bottom ? -7 : 0;
    const bool time = type == 1;
    modeDial((time ? 44 : 96) + g, 438, 77 + dy, 354, 114, 114, 83,
             time ? 15 : 14);
    modeDial((time ? 76 : 104) + g, 341, 49 + dy, 351, 33, 33, 71, -25);
    modeDial((time ? 72 : 100) + g, 341, 109 + dy, 351, 33, 33, 71, -25);
    toggle((time ? 68 : 92) + g, 264, 86 + dy, 348, 43, 15);
    if (time)
      toggle(48 + g, 224, 86 + dy, 339, 16, 15);
    step((time ? 56 : 80) + g, 516, 30 + dy);
    step((time ? 60 : 84) + g, 516, 57 + dy);
    step((time ? 64 : 88) + g, 516, 84 + dy);
    step((time ? 705 : 733) + g, 516, 111 + dy);
    // The loaded sample is observable. File browsing, trim and mapping are
    // separate original editor commands and are not simulated by these fields.
    box((time ? 701 : 737) + g, W::Sample, 126 + 57, row + 64 + dy, 250, 19);
    box((time ? 725 : 757) + g, W::Step, 126 + (time ? 104 : 132),
        row + 87 + dy, 55, 12);
    box((time ? 729 : 761) + g, W::Step, 126 + (time ? 165 : 193),
        row + 87 + dy, 55, 12);
  } else {
    const int dy = bottom ? -28 : 0;
    step(824 + g, 5, 42 + dy);
    step(826 + g, 5, 69 + dy);
    step(828 + g, 5, 96 + dy);
    step(834 + g, 5, 123 + dy);
    toggle(830 + g, 134, bottom ? 115 : 10, 326, 48, 19);
    toggle(836 + g, 186, bottom ? 115 : 10, 325, 81, 19);
    box(800 + g, W::Sample, 126 + 342, row + (bottom ? 3 : 11), 98, 10);
  }
  return r;
}
inline bool isGeneratorControl(std::uint32_t tag, bool writable = false) {
  for (unsigned g = 0; g < 4; ++g)
    for (unsigned type = 0; type < (g < 2 ? 4u : 3u); ++type)
      for (const auto &c : generatorLayout(g, type))
        if (c.tag == tag)
          return !writable || c.widget != GeneratorWidget::Sample;
  return false;
}
} // namespace sophistry
