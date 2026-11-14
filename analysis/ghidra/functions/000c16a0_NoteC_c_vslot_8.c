/* 000c16a0 NoteC_c_vslot_8 */

void NoteC_c_vslot_8(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 < 0) {
    *(int *)(param_1 + 8) = 0;
    iVar1 = *(int *)(param_1 + 0xc);
  }
  else {
    if (0x7f < iVar1) {
      iVar1 = 0x7f;
    }
    *(int *)(param_1 + 8) = iVar1;
    iVar1 = *(int *)(param_1 + 0xc);
  }
  if (iVar1 < 0) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    iVar1 = *(int *)(param_1 + 0x10);
  }
  else {
    if (0x7f < iVar1) {
      iVar1 = 0x7f;
    }
    *(int *)(param_1 + 0xc) = iVar1;
    iVar1 = *(int *)(param_1 + 0x10);
  }
  if (-1 < iVar1) {
    if (0xf < iVar1) {
      iVar1 = 0xf;
    }
    *(int *)(param_1 + 0x10) = iVar1;
    return;
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

