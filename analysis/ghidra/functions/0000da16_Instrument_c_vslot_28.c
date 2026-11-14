/* 0000da16 Instrument_c_vslot_28 */

void Instrument_c_vslot_28(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x1b50);
  *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0x1aec + iVar1 * 4);
  *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(param_1 + 0x1b00 + iVar1 * 4);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x1b14 + iVar1 * 4);
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x1b28 + iVar1 * 4);
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x1b3c + iVar1 * 4);
  *(int *)(param_1 + 0x1b50) = iVar1 + 1;
  return;
}

