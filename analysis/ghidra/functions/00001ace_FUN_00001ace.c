/* 00001ace FUN_00001ace */

longdouble FUN_00001ace(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  iVar1 = *(int *)(param_1 + 0xa4) + -1;
  if (param_2 <= iVar1) {
    iVar1 = param_2;
  }
  return (longdouble)*(float *)(*(int *)(param_1 + 0x90) + 0xc + iVar1 * 0x18);
}

