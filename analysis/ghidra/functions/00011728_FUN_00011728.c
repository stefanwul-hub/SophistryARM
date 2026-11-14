/* 00011728 FUN_00011728 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00011728(int param_1,undefined4 param_2,int param_3,int param_4,int param_5)

{
  longdouble lVar1;
  
  if (param_5 < param_3) {
    param_5 = param_3;
  }
  if (param_4 < param_5) {
    param_5 = param_4;
  }
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  *(char **)(param_1 + 0x40) = "";
  *(undefined4 *)(param_1 + 4) = 3;
  *(undefined4 *)(param_1 + 0x20) = 3;
  *(int *)(param_1 + 0x44) = param_3;
  *(int *)(param_1 + 0x24) = param_3;
  *(int *)(param_1 + 0x48) = param_4;
  *(int *)(param_1 + 0x28) = param_4;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x54) = 0;
  lVar1 = (longdouble)_pow(0,0x40240000,0,0);
  *(int *)(param_1 + 100) = (int)((float)lVar1 + 0.5);
  *(int *)(param_1 + 0x5c) = param_5;
  *(int *)(param_1 + 0x4c) = param_5;
  *(int *)(param_1 + 0x2c) = param_5;
  FUN_0000ff7e();
  return;
}

