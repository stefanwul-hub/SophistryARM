/* 0001795c FUN_0001795c */

void FUN_0001795c(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  if (((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x9a48))) &&
     (*(int *)(param_1 + 0x8abc) != 0)) {
    iVar2 = *(int *)(param_2 * 0x20 + 0xc + *(int *)(param_1 + 0x8abc));
    if (iVar2 == -1) {
      iVar2 = *(int *)(param_1 + 0xcfe0);
      cVar1 = *(char *)(param_1 + 0x958);
    }
    else {
      cVar1 = *(char *)(param_1 + 0x958);
    }
    if (((cVar1 != '\0') && (param_2 != *(int *)(param_1 + 0x3b48))) &&
       (param_2 != *(int *)(param_1 + 0x3b4c))) {
      FUN_0008d4a0(param_1 + 0x784,iVar2,param_2);
    }
  }
  return;
}

