/* 0009ccf6 CDrawContext_vslot_7 */

undefined4 CDrawContext_vslot_7(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    uVar1 = _GetWindowPort();
    return uVar1;
  }
  return 0;
}

