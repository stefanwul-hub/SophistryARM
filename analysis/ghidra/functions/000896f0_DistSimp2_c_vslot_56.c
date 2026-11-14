/* 000896f0 DistSimp2_c_vslot_56 */

void DistSimp2_c_vslot_56(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x124) != 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x124) + 0x158);
    if (iVar1 == 1) {
      FUN_000894d6();
      return;
    }
    if (iVar1 == 2) {
      FUN_00089134();
      return;
    }
    if (iVar1 == 0) {
      FUN_000892c8();
      return;
    }
  }
  return;
}

