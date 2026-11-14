/* 0009e384 COffscreenContext_vslot_5 */

undefined4 COffscreenContext_vslot_5(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x6c) != 0) {
    uVar1 = _GetPortBitMapForCopyBits();
    return uVar1;
  }
  return 0;
}

