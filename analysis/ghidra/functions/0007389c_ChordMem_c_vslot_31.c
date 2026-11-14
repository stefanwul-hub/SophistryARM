/* 0007389c ChordMem_c_vslot_31 */

void ChordMem_c_vslot_31(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x124) != 0) {
    *(undefined4 *)(param_1 + 0x1dc) = *(undefined4 *)(param_1 + 0x1d8);
    iVar1 = *(int *)(*(int *)(param_1 + 0x124) + 0xe8);
    *(int *)(param_1 + 0x1d8) = iVar1;
    if ((*(int *)(param_1 + 0x1dc) != 1) && (iVar1 == 1)) {
      FUN_000109c8(*(int *)(param_1 + 0x124) + 0x150,0);
    }
    *(bool *)(param_1 + 8) = *(int *)(param_1 + 0x1d8) != 0;
  }
  return;
}

