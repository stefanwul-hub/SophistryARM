/* 00010f72 FUN_00010f72 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00010f72(int param_1,undefined4 param_2,char param_3,char param_4,int param_5)

{
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  *(char **)(param_1 + 0x40) = "";
  *(undefined4 *)(param_1 + 4) = 7;
  *(undefined4 *)(param_1 + 0x20) = 7;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(int *)(param_1 + 0x30) = param_5;
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  FUN_0000ff7e(param_1);
  if (param_3 == '\0') {
    FUN_0002d6d6(param_1 + 0x68,8);
  }
  else {
    FUN_0002d6c8(param_1 + 0x68,8);
  }
  if (param_4 == '\0') {
    FUN_0002d6d6(param_1 + 0x68,0x10);
  }
  else {
    FUN_0002d6c8(param_1 + 0x68,0x10);
  }
  if (param_5 != 0) {
    FUN_00010e34();
    return;
  }
  return;
}

