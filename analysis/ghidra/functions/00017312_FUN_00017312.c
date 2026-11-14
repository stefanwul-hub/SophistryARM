/* 00017312 FUN_00017312 */

void FUN_00017312(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x3b88);
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = iVar2 + 1;
      if (iVar2 < iVar1) {
        iVar3 = 0;
        do {
          iVar3 = iVar3 + 1;
        } while (iVar3 != iVar1 - iVar2);
      }
    } while (iVar2 < iVar1);
  }
  return;
}

