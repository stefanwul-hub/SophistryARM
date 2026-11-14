/* 0009df12 FUN_0009df12 */

void FUN_0009df12(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = param_2[1];
  *(int *)(param_1 + 0x34) = *param_2 + *(int *)(param_1 + 0x10);
  *(int *)(param_1 + 0x38) = iVar1 + *(int *)(param_1 + 0x14);
  return;
}

