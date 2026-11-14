/* 000ad518 CarbonEventHandler_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CarbonEventHandler_vslot_0(undefined4 *param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  *param_1 = &PTR_CarbonEventHandler_vslot_0_000f4768;
  if (param_1[1] == 0) {
    return;
  }
  iVar1 = _CFDictionaryGetCount(param_1[1]);
  pvVar2 = _malloc(iVar1 * 4);
  _CFDictionaryGetKeysAndValues(param_1[1],0,pvVar2);
  if (0 < iVar1) {
    iVar3 = 0;
    do {
      _RemoveEventHandler(*(undefined4 *)((int)pvVar2 + iVar3 * 4));
      iVar3 = iVar3 + 1;
    } while (iVar3 != iVar1);
  }
  _CFDictionaryRemoveAllValues(param_1[1]);
  _CFRelease(param_1[1]);
  _free(pvVar2);
  return;
}

