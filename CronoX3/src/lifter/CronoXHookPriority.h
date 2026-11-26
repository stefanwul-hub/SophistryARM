#pragma once
#include "LifterRuntime.h"

// Only these independently compared original function entries may take
// the direct C++ path. The generated units and their fallback stay unchanged.
inline bool sl_cronox_preferred_hook(SlCpu& c) {
  if (c.pc != 0xd3d70 && c.pc != 0xd400e && c.pc != 0xd42d8) return false;
  const SlU32 entry = c.pc;
  for (SlU32 h = 0; h < c.hook_count; ++h) {
    if (c.hooks[h].address != entry) continue;
    c.hooks[h].function(c.hooks[h].user, entry, &c);
    if (c.pc == entry && !c.fault) return false; // unsupported: original unit
    if (entry < sizeof(c.seen)) c.seen[entry] = 1;
    if (++c.steps > c.limit) c.fault = 4;
    return true;
  }
  return false;
}
