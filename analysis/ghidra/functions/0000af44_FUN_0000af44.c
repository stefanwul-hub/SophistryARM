/* 0000af44 FUN_0000af44 */

void FUN_0000af44(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  if (param_5 != 0) {
    *(undefined4 *)(param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 8) = param_2;
    *(undefined4 *)(param_1 + 0x48) = param_3;
    *(int *)(param_1 + 0x4c) = param_4;
    *(int *)(param_1 + 0x44) = param_5;
    *(undefined1 *)(param_1 + 4) = 1;
    if (param_4 != 0) {
      FUN_0001ce0e();
      return;
    }
  }
  return;
}

