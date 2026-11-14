/* 000103f8 FUN_000103f8 */

void FUN_000103f8(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  iVar1 = *(int *)(param_1 + 0x54) + -1;
  if (iVar1 < param_2) {
    param_2 = iVar1;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x60) + param_2 * 4) = param_3;
  return;
}

