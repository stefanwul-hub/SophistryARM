/* 0009ce34 COffscreenContext_vslot_4 */

undefined4 COffscreenContext_vslot_4(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x60) != 0) {
    uVar1 = _CGBitmapContextCreateImage();
    return uVar1;
  }
  return 0;
}

