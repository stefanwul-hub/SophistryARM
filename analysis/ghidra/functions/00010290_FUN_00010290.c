/* 00010290 FUN_00010290 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00010290(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 < 0) {
    param_3 = 0;
  }
  else if (1 < param_3) {
    param_3 = 1;
  }
  *(undefined4 *)(param_1 + 0x3c) = param_2;
  *(char **)(param_1 + 0x40) = "";
  *(undefined4 *)(param_1 + 4) = 6;
  *(undefined4 *)(param_1 + 0x20) = 6;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x48) = 1;
  *(undefined4 *)(param_1 + 0x28) = 1;
  *(undefined4 *)(param_1 + 0x54) = 3;
  *(undefined4 *)(param_1 + 0x34) = 3;
  *(int *)(param_1 + 0x5c) = param_3;
  *(int *)(param_1 + 0x4c) = param_3;
  *(int *)(param_1 + 0x2c) = param_3;
  *(char **)(param_1 + 0x30) = "OffOn ";
  FUN_0000ff7e();
  return;
}

