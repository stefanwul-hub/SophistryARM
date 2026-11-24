#pragma once
#include "GeneratorControls.h"
namespace sophistry {
struct EditorControlState {
  GeneratorControlState value{};
  float normalized = 0;
};
struct EditorPanelState {
  std::uint32_t version = 1, panel = 0, count = 0;
  std::array<std::uint32_t, 2> filterModes{}, envelopeModes{};
  std::array<EditorControlState, 48> controls{};
};
struct EditorLine {
  float x1 = 0, y1 = 0, x2 = 0, y2 = 0;
  std::uint32_t color = 0;
};
struct EditorDrawing {
  std::uint32_t version = 1, width = 0, height = 0, count = 0, sourceFrames = 0,
                sampleRate = 0;
  std::array<EditorLine, 512> lines{};
};
struct EditorXYSpec {
  unsigned xTag, yTag;
  int x, y, size;
};
inline std::vector<EditorXYSpec> editorXY(unsigned panel) {
  if (!panel)
    return {{585, 586, 46, 35, 40},  {587, 588, 266, 35, 40},
            {589, 590, 46, 102, 40}, {591, 592, 266, 102, 40},
            {593, 594, 511, 35, 40}, {595, 596, 511, 102, 40}};
  return {{597, 598, 67, 45, 60}, {599, 600, 67, 183, 60}};
}
inline std::uint32_t editorAUParameter(unsigned tag) {
  if (tag >= 585 && tag <= 592)
    return ((tag - 585) & 1 ? 4 : 8) + (tag - 585) / 2;
  if (tag >= 593 && tag <= 600) {
    unsigned axis = (tag - 593) % 4;
    return axis == 0 ? 114 : axis == 1 ? 116 : axis == 2 ? 115 : 117;
  }
  if ((tag >= 110 && tag <= 152) || tag == 482)
    return tag;
  if (tag >= 488 && tag <= 491)
    return 114 + tag - 488;
  if (tag >= 498 && tag <= 503)
    return 492 + tag - 498;
  if (tag >= 480 && tag <= 487)
    return tag;
  return noAUParameter;
}
inline std::vector<GeneratorControlSpec>
editorLayout(unsigned panel, const std::array<std::uint32_t, 2> &modes) {
  using W = GeneratorWidget;
  std::vector<GeneratorControlSpec> r;
  auto box = [&](unsigned tag, W kind, int x, int y, int w, int h,
                 unsigned image = 0, unsigned frames = 0, int offset = 0) {
    r.push_back({tag, kind, x, y, w, h, image, frames, offset, false});
  };
  auto dial = [&](unsigned tag, int x, int y, unsigned image, int w, int h,
                  unsigned frames, int offset = 0) {
    box(tag, W::Dial, x - w / 2, y - h / 2, w, h, image, frames, offset);
  };
  if (!panel) {
    const struct {
      unsigned tag, image, frames;
      int x, y, w, h;
    } knobs[] = {
        {484, 360, 42, 144, 57, 58, 57},  {485, 361, 42, 206, 57, 58, 57},
        {486, 362, 42, 144, 119, 58, 57}, {487, 363, 42, 206, 119, 58, 57},
        {488, 364, 42, 389, 57, 58, 57},  {489, 366, 42, 389, 119, 58, 57},
        {490, 365, 42, 451, 57, 58, 57},  {491, 367, 42, 451, 119, 58, 57},
        {498, 356, 41, 663, 57, 120, 57}, {499, 355, 41, 663, 119, 120, 57},
        {500, 352, 51, 250, 247, 73, 36}, {501, 352, 51, 336, 247, 73, 36},
        {502, 352, 51, 422, 247, 73, 36}, {503, 352, 51, 508, 247, 73, 36},
        {480, 350, 71, 692, 226, 33, 33}};
    for (auto k : knobs)
      dial(k.tag, k.x, k.y, k.image, k.w, k.h, k.frames);
    box(958, W::Step, 30, 256, 56, 15);
    box(614, W::Step, 109, 256, 56, 15);
    box(482, W::Step, 597, 249, 56, 15);
    box(481, W::Toggle, 612, 216, 48, 22, 371, 4);
    box(483, W::Toggle, 673, 248, 38, 15, 333, 2);
    return r;
  }
  for (unsigned f = 0; f < 2; ++f) {
    const int dy = 138 * f;
    box(112 + f, W::Toggle, 92, f ? 265 : 7, 35, 17, f ? 330 : 329, 2);
    dial(110 + f, 36, 83 + dy, 350, 33, 33, 71);
    dial(114 + f, 205, 44 + dy, 356, 120, 57, 41, 17);
    dial(116 + f, 205, 106 + dy, 355, 120, 57, 41, -16);
    dial(120 + f, 449, 31 + dy, 353, 78, 38, 53, 5);
    dial(124 + f, 449, 73 + dy, 352, 73, 36, 51, -5);
    box(122 + f, W::HorizontalRadio, 409, 102 + dy, 74, 18, 338, 4);
    dial(130 + f, f ? 727 : 725, 63 + dy, 350, 33, 33, 71);
    dial(132 + f, 727, 113 + dy, 350, 33, 33, 71);
    if (modes[f]) {
      dial(126 + f, 339, 74 + dy, 357, 107, 107, 80);
      box(128 + f, W::HorizontalRadio, 321, 60 + dy, 76, 15, 340, 4);
    } else
      box(118 + f, W::Radio, 321, 40 + dy, 37, 68, 322, 2);
  }
  return r;
}
inline bool isEditorControl(unsigned tag) {
  if (tag == 958 || tag == 614 || tag == 482 || tag == 780 || tag == 781)
    return true;
  if (tag >= 110 && tag <= 133)
    return true;
  if (tag >= 480 && tag <= 503)
    return true;
  return tag >= 585 && tag <= 600;
}
static_assert(sizeof(EditorLine) == 20);
static_assert(sizeof(EditorControlState) == 200);
} // namespace sophistry
