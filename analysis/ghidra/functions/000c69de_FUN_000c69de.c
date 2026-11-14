/* 000c69de FUN_000c69de */

int FUN_000c69de(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 8);
  param_1 = param_1 + 4;
  if (iVar2 != 0) {
    do {
      if (*(uint *)(iVar2 + 0x10) < *param_2) {
        iVar1 = *(int *)(iVar2 + 0xc);
      }
      else {
        iVar1 = *(int *)(iVar2 + 8);
        param_1 = iVar2;
      }
      iVar2 = iVar1;
    } while (iVar2 != 0);
  }
  return param_1;
}

