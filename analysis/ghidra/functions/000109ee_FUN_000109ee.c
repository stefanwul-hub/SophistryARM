/* 000109ee FUN_000109ee */

void FUN_000109ee(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < *(int *)(param_1 + 0x44)) {
    return;
  }
  *(int *)(param_1 + 0x48) = param_2;
  *(int *)(param_1 + 0x28) = param_2;
  if (param_2 < *(int *)(param_1 + 0x5c)) {
    *(int *)(param_1 + 0x5c) = param_2;
    iVar1 = *(int *)(param_1 + 0x4c);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x4c);
  }
  if (iVar1 <= param_2) {
    FUN_0000ff7e();
    return;
  }
  *(int *)(param_1 + 0x4c) = param_2;
  *(int *)(param_1 + 0x2c) = param_2;
  FUN_0000ff7e();
  return;
}

