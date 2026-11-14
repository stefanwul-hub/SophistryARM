/* 00011652 FUN_00011652 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00011652(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                 int param_6,int param_7,int param_8,undefined4 param_9)

{
  longdouble lVar1;
  
  if (param_8 < param_5) {
    param_8 = param_5;
  }
  if (param_6 < param_8) {
    param_8 = param_6;
  }
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  *(undefined4 *)(param_1 + 0x40) = param_3;
  *(undefined4 *)(param_1 + 4) = 1;
  *(undefined4 *)(param_1 + 0x20) = 1;
  *(int *)(param_1 + 0x44) = param_5;
  *(int *)(param_1 + 0x24) = param_5;
  *(int *)(param_1 + 0x48) = param_6;
  *(int *)(param_1 + 0x28) = param_6;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(int *)(param_1 + 0x54) = param_7;
  *(int *)(param_1 + 0x34) = param_7;
  *(undefined4 *)(param_1 + 0x38) = param_4;
  *(undefined4 *)(param_1 + 0x58) = param_9;
  if (param_7 < 0) {
    param_7 = 0;
  }
  else if (8 < param_7) {
    param_7 = 8;
  }
  *(int *)(param_1 + 0x54) = param_7;
  lVar1 = (longdouble)_pow(0,0x40240000,(double)*(int *)(param_1 + 0x54));
  *(int *)(param_1 + 100) = (int)((float)lVar1 + 0.5);
  *(int *)(param_1 + 0x5c) = param_8;
  *(int *)(param_1 + 0x4c) = param_8;
  *(int *)(param_1 + 0x2c) = param_8;
  FUN_0000ff7e();
  return;
}

