/* 000946a0 FUN_000946a0 */

undefined4 FUN_000946a0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((((iVar1 != 0) && (*(int *)(param_1 + 8) != 0)) &&
      (*(int *)(param_1 + 0x10) + 1 <= *(int *)(param_1 + 0xc))) &&
     (iVar3 = *(int *)(param_1 + 0x14), iVar3 < *(int *)(param_1 + 0x10))) {
    if (*(int *)(iVar1 + iVar3 * 4) != *(int *)(param_1 + 0x18)) {
      iVar2 = iVar3 * 4;
      do {
        iVar2 = iVar2 + 4;
        iVar3 = iVar3 + 1;
        *(int *)(param_1 + 0x14) = iVar3;
        if (*(int *)(param_1 + 0x10) <= iVar3) {
          return 0xffffffff;
        }
      } while (*(int *)(iVar2 + iVar1) != *(int *)(param_1 + 0x18));
    }
    *(int *)(param_1 + 0x14) = iVar3 + 1;
    return *(undefined4 *)(*(int *)(param_1 + 8) + -4 + (iVar3 + 1) * 4);
  }
  return 0xffffffff;
}

