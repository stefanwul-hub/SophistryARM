/* 000121dc FUN_000121dc */

longdouble FUN_000121dc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_3 < 0) {
    param_3 = 0;
  }
  iVar2 = *(int *)(param_1 + 0x18) + -1;
  if (param_3 <= iVar2) {
    iVar2 = param_3;
  }
  iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + param_2 * 4);
  if (iVar1 != 0) {
    return (longdouble)*(float *)(iVar2 * 0x70 + 0x14 + iVar1);
  }
  return (longdouble)0;
}

