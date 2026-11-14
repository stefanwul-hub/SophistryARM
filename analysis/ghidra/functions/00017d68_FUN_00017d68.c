/* 00017d68 FUN_00017d68 */

undefined4 FUN_00017d68(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  iVar1 = *(int *)(param_1 + 0xcfb0);
  if (param_2 <= *(int *)(param_1 + 0xcfb0)) {
    iVar1 = param_2;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0xcea4) + iVar1 * 4);
}

