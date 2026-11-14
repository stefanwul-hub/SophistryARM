/* 000c6836 FUN_000c6836 */

int FUN_000c6836(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  param_1 = param_1 + 4;
  iVar2 = param_1;
  if (iVar3 != 0) {
    do {
      if (*(uint *)(iVar3 + 0x10) < *param_2) {
        iVar1 = *(int *)(iVar3 + 0xc);
      }
      else {
        iVar1 = *(int *)(iVar3 + 8);
        iVar2 = iVar3;
      }
      iVar3 = iVar1;
    } while (iVar3 != 0);
  }
  if ((iVar2 != param_1) && (*(uint *)(iVar2 + 0x10) <= *param_2)) {
    return iVar2;
  }
  return param_1;
}

