/* 00018638 FUN_00018638 */

void FUN_00018638(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_3 < *(int *)(param_1 + 0xcfb4)) {
    param_3 = param_3 * 2;
    iVar1 = 2;
  }
  else {
    param_3 = *(int *)(param_1 + 0xcfb4) + param_3;
    iVar1 = 1;
  }
  FUN_0000bcdc(&UNK_0000c66c + param_1,param_2,param_3,param_3 + -1 + iVar1,param_4);
  return;
}

