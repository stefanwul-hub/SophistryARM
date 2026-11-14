/* 000a08c2 FUN_000a08c2 */

void FUN_000a08c2(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 0x10) + *param_2;
  iVar2 = *(int *)(param_1 + 0x10) + param_2[2];
  iVar3 = param_2[1] + *(int *)(param_1 + 0x14);
  iVar4 = *(int *)(param_1 + 0x14) + param_2[3];
  if ((((*(int *)(param_1 + 0x50) != iVar1) || (*(int *)(param_1 + 0x58) != iVar2)) ||
      (*(int *)(param_1 + 0x54) != iVar3)) || (iVar4 != *(int *)(param_1 + 0x5c))) {
    *(int *)(param_1 + 0x50) = iVar1;
    *(int *)(param_1 + 0x54) = iVar3;
    *(int *)(param_1 + 0x58) = iVar2;
    *(int *)(param_1 + 0x5c) = iVar4;
  }
  return;
}

