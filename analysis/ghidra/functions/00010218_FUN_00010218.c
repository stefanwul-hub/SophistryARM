/* 00010218 FUN_00010218 */

void FUN_00010218(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 undefined4 param_6,int param_7,int param_8,undefined4 param_9)

{
  if (param_8 != 0) {
    if (param_7 < param_4) {
      param_7 = param_4;
    }
    if (param_5 < param_7) {
      param_7 = param_5;
    }
    *(undefined4 *)(param_1 + 0x3c) = param_2;
    *(undefined4 *)(param_1 + 0x40) = param_3;
    *(undefined4 *)(param_1 + 4) = 2;
    *(undefined4 *)(param_1 + 0x20) = 2;
    *(int *)(param_1 + 0x44) = param_4;
    *(int *)(param_1 + 0x24) = param_4;
    *(int *)(param_1 + 0x48) = param_5;
    *(int *)(param_1 + 0x28) = param_5;
    *(int *)(param_1 + 0x30) = param_8;
    *(undefined4 *)(param_1 + 0x54) = param_6;
    *(undefined4 *)(param_1 + 0x34) = param_6;
    *(int *)(param_1 + 0x5c) = param_7;
    *(int *)(param_1 + 0x4c) = param_7;
    *(int *)(param_1 + 0x2c) = param_7;
    FUN_0000ff7e(param_1);
    *(undefined4 *)(param_1 + 0x50) = param_9;
  }
  return;
}

