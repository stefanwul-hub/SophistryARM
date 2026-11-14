/* 00010cca FUN_00010cca */

void FUN_00010cca(int param_1,int param_2)

{
  int iVar1;
  
  param_2 = *(int *)(param_1 + 0x5c) + param_2;
  if (*(int *)(param_1 + 0x48) < param_2) {
    param_2 = *(int *)(param_1 + 0x48);
  }
  iVar1 = *(int *)(param_1 + 0x44);
  if (*(int *)(param_1 + 0x44) <= param_2) {
    iVar1 = param_2;
  }
  *(int *)(param_1 + 0x5c) = iVar1;
  FUN_0000ff7e(param_1);
  FUN_0000ff7e();
  return;
}

