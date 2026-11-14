/* 000109c8 FUN_000109c8 */

void FUN_000109c8(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x48);
  if (param_2 <= *(int *)(param_1 + 0x48)) {
    iVar2 = param_2;
  }
  iVar1 = *(int *)(param_1 + 0x44);
  if (*(int *)(param_1 + 0x44) <= iVar2) {
    iVar1 = iVar2;
  }
  *(int *)(param_1 + 0x5c) = iVar1;
  FUN_0000ff7e();
  return;
}

