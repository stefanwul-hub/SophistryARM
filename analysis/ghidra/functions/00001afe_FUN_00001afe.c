/* 00001afe FUN_00001afe */

undefined4 FUN_00001afe(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  iVar1 = *(int *)(param_1 + 0xa4) + -1;
  if (param_2 <= iVar1) {
    iVar1 = param_2;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x90) + iVar1 * 0x18);
}

