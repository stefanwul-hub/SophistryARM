/* 00073810 ChordMem_c_vslot_56 */

void ChordMem_c_vslot_56(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x124) + 0x158);
  if (7 < iVar1) {
    return;
  }
  iVar1 = iVar1 * 0xe0;
  FUN_000109c8(*(int *)(param_1 + 0x124) + 0x1c0 + iVar1,*(undefined4 *)(param_2 + 8));
  FUN_000109c8(iVar1 + *(int *)(param_1 + 0x124) + 0x230,*(undefined4 *)(param_2 + 0xc));
  FUN_00010cca();
  return;
}

