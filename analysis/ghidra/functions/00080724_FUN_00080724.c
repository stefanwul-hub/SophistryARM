/* 00080724 FUN_00080724 */

void FUN_00080724(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  iVar1 = 0x18;
  do {
    param_1[2] = 0xffffffff;
    param_1 = param_1 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

