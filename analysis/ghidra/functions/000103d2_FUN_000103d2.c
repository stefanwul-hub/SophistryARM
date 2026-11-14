/* 000103d2 FUN_000103d2 */

longdouble FUN_000103d2(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  iVar1 = *(int *)(param_1 + 0x54) + -1;
  if (iVar1 < param_2) {
    param_2 = iVar1;
  }
  return (longdouble)*(float *)(*(int *)(param_1 + 0x60) + param_2 * 4);
}

