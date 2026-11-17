#pragma once
#include "RecoveredEditorLayout.h"
#include <map>
#include <set>
#include <stdexcept>
namespace sophistry {
struct CompleteEditorState {
  std::uint32_t version = 1, page = 0, count = 0, selectionCount = 0;
  struct Selection {
    std::uint32_t tag = 0;
    std::int32_t value = 0;
  };
  std::array<Selection, 48> selections{};
  struct Viewport {
    float first = 0, span = 0;
    std::uint32_t frames = 0, rate = 0;
  };
  std::array<Viewport, 2> waveforms{};
  std::array<EditorControlState, 256> controls{};
};
struct EditorChoices {
  std::uint32_t version = 1, count = 0;
  std::array<std::array<char, 64>, 256> labels{};
};
struct EditorAction {
  std::uint32_t version = 1, key = 0;
};
struct EditorKeyHit {
  std::uint32_t version = 1, note = 0, velocity = 0;
};
struct EditorFileInfo {
  std::uint32_t version = 1, save = 0, count = 0;
  char title[128]{}, suggestedName[128]{};
  std::array<std::array<char, 16>, 16> extensions{};
};
struct EditorFileRequest {
  std::uint32_t version = 1, tag = 0, operation = 0, pathBytes = 0;
};
inline bool editorFileCommand(unsigned tag, unsigned operation) {
  return (tag >= 643 && tag <= 647 && operation <= 1) ||
         (tag == 610 && (operation == 4 || operation == 5));
}
constexpr unsigned editorStringBytes = 4096;
struct PlacedEditorPanel {
  unsigned id;
  int x, y;
  unsigned image;
};
struct PlacedEditorControl {
  RecoveredControl control;
  int offsetX = 0, offsetY = 0;
};
struct CompleteEditorLayout {
  std::vector<PlacedEditorPanel> panels;
  std::vector<PlacedEditorControl> controls;
};
inline std::set<unsigned> completeSelectionTags() {
  std::set<unsigned> tags{213, 214, 215, 216, 217, 218, 657};
  for (const auto &r : recoveredSelectors())
    tags.insert(r.tag);
  return tags;
}
inline CompleteEditorLayout
completeEditorLayout(unsigned page, const std::function<int(unsigned)> &value) {
  if (page > 8)
    throw std::out_of_range("Unknown original editor page");
  CompleteEditorLayout result;
  auto originalPanel = [](unsigned id) -> const RecoveredPanel * {
    for (const auto &p : recoveredPanels())
      if (p.id == id)
        return &p;
    return nullptr;
  };
  std::function<void(unsigned, int, int)> append = [&](unsigned id, int x,
                                                       int y) {
    const auto *p = originalPanel(id);
    if (!p)
      return;
    result.panels.push_back({id, x, y, p->image});
    for (const auto &c : recoveredControls())
      if (c.panel == id)
        result.controls.push_back({c, x, y});
    for (const auto &r : recoveredSelectors()) {
      if (r.parent != id || r.children.empty())
        continue;
      auto i = std::clamp(value(r.tag), 0, int(r.children.size() - 1));
      auto child = originalPanel(r.children[i]);
      if (child)
        append(child->id, x + child->x, y + child->y);
    }
  };
  append(page + 1, 0, 0);
  if (page == 4) {
    for (unsigned slot = 0; slot < 4; ++slot) {
      int type = std::clamp(value(215 + slot), 0, 11);
      append(30 + 3 * type, 265 + 240 * (slot / 2), 31 + 118 * (slot % 2));
    }
  }
  return result;
}
// Resolve against the controls in the current original panel, rather than
// sending an invisible mode's tag directly to the engine.
inline const PlacedEditorControl *
completeEditorControl(const CompleteEditorLayout &layout, unsigned tag) {
  for (const auto &c : layout.controls)
    if (c.control.tag == tag)
      return &c;
  const unsigned generator = generatorForTypeTag(tag);
  if (generator < 4)
    for (const auto &c : layout.controls)
      if (c.control.kind == RecoveredWidget::Menu &&
          generatorForTypeTag(c.control.tag) == generator)
        return &c;
  return nullptr;
}
inline bool originalPointerKind(RecoveredWidget k) {
  return k == RecoveredWidget::Dial || k == RecoveredWidget::Drawbar ||
         k == RecoveredWidget::ThinSlider || k == RecoveredWidget::Scrollbar;
}
inline bool completeControlEditable(unsigned tag) {
  if (tag == 765)
    return false;
  if (tag >= 643 && tag <= 646)
    return true;
  for (const auto &c : recoveredControls())
    if (c.tag == tag) {
      auto k = c.kind;
      if (k == RecoveredWidget::Dial || k == RecoveredWidget::Step ||
          k == RecoveredWidget::Toggle || k == RecoveredWidget::Radio ||
          k == RecoveredWidget::Menu || k == RecoveredWidget::Drawbar ||
          k == RecoveredWidget::HorizontalSlider ||
          k == RecoveredWidget::ThinSlider || k == RecoveredWidget::Text ||
          k == RecoveredWidget::Scrollbar)
        return true;
      if (k == RecoveredWidget::XY)
        return true;
    }
  // Y axes and original viewport aliases are not standalone widgets.
  return (tag >= 523 && tag <= 578) || (tag >= 585 && tag <= 600) ||
         (tag >= 940 && tag <= 957) || tag == 610;
}
inline bool completeControlStringEditable(unsigned tag) {
  if (tag == 765)
    return false;
  if (tag == 648)
    return true; // Original arpeggiator sequence bytes.
  for (const auto &c : recoveredControls())
    if (c.tag == tag &&
        (c.kind == RecoveredWidget::File || c.kind == RecoveredWidget::Text))
      return true;
  return false;
}
inline bool completeControlReadable(unsigned tag) {
  if (tag == 765)
    return false;
  if (tag == 648 || (tag >= 523 && tag <= 578))
    return true;
  for (const auto &c : recoveredControls())
    if (c.tag == tag && c.kind != RecoveredWidget::Licence &&
        c.kind != RecoveredWidget::Label)
      return true;
  return completeControlEditable(tag);
}
} // namespace sophistry
