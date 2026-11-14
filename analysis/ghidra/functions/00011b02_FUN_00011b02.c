/* 00011b02 FUN_00011b02 */

void FUN_00011b02(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (param_2 < 0) {
      param_2 = 0;
    }
    iVar1 = *(int *)(param_1 + 0xc);
    if (param_2 <= *(int *)(param_1 + 0xc)) {
      iVar1 = param_2;
    }
    if ((*(char *)(param_1 + 0x12) == '\0') &&
       (iVar1 = *(int *)(param_1 + 4) + iVar1 * *(int *)(param_1 + 0x18) * 0x70,
       0 < *(int *)(param_1 + 0x18))) {
      iVar2 = 0;
      do {
        FUN_00010eee(iVar1);
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x70;
      } while (iVar2 < *(int *)(param_1 + 0x18));
      return;
    }
  }
  return;
}

