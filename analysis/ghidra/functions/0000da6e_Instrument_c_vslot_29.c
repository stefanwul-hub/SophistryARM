/* 0000da6e Instrument_c_vslot_29 */

void Instrument_c_vslot_29(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_2;
  if ((int)param_2 < 0) {
    uVar1 = param_2 + 0x3f;
  }
  iVar2 = (int)uVar1 >> 6;
  if ((param_2 & 0x3f) != 0) {
    iVar2 = ((int)uVar1 >> 6) + 1;
  }
  iVar2 = iVar2 + -1;
  *(undefined4 *)(param_1 + 0x11c) = *(undefined4 *)(param_1 + 0x1aec + iVar2 * 4);
  *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(param_1 + 0x1b00 + iVar2 * 4);
  *(undefined4 *)(param_1 + 0x124) = *(undefined4 *)(param_1 + 0x1b14 + iVar2 * 4);
  *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x1b28 + iVar2 * 4);
  *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x1b3c + iVar2 * 4);
  return;
}

