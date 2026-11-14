/* 0009d94c CBitmap_vslot_8 */

void CBitmap_vslot_8(int param_1)

{
  if (*(int *)(param_1 + 0x24) != 0) {
    _CGImageRelease(*(int *)(param_1 + 0x24));
  }
  *(undefined4 *)(param_1 + 0x24) = 0;
  if (*(int *)(param_1 + 0x1c) != 0) {
    _DisposeGWorld(*(int *)(param_1 + 0x1c));
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    _DisposeGWorld(*(int *)(param_1 + 0x20));
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

