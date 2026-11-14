/* 000c12f8 Note_c_vslot_7 */

void Note_c_vslot_7(int param_1)

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
  if (0 < iVar1) {
    if (0x7f < iVar1) {
      iVar1 = 0x7f;
    }
    *(int *)(param_1 + 0xc) = iVar1;
    return;
  }
  *(undefined4 *)(param_1 + 0xc) = 1;
  return;
}

