/* 00080824 FUN_00080824 */

void FUN_00080824(undefined4 *param_1)

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

