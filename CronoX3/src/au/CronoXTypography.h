#pragma once
#include "../engine/RecoveredEditorLayout.h"
namespace cronox::typography {
// VSTGUI font globals initialized by original function 0x1f80:
// gNormalFont=Helvetica 12, Small=11, Smaller=10, VerySmall=9, Big=14.
inline constexpr const char *family = "Helvetica";
inline bool sampleFilename(unsigned tag) {
  return (tag >= 841 && tag <= 848) || (tag >= 889 && tag <= 896);
}
inline unsigned textSize(const sophistry::RecoveredControl &c) {
  using K=sophistry::RecoveredWidget;
  if(sampleFilename(c.tag))return 10; // createGenSamTable 0x77ae4
  if(c.kind==K::Text) { // createCharDisp 0x2abc0
    return c.height>=8&&c.height<=10?9:c.height<=13?11:c.height<=15?12:14;
  }
  if(c.kind==K::Display) { // createVarDisplay 0x2bcb2
    return c.height==10?9:c.height>=11&&c.height<=13?11:12;
  }
  return 11; // CMenuSimple, CLabelPl/addDisplay, createDepth, PMDisplay
}
inline bool hiddenMenuValue(unsigned tag) { return tag==610 || tag==612; }
}
