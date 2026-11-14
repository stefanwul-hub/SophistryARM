/* 0000b7e2 FUN_0000b7e2 */

void FUN_0000b7e2(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  if ((((param_2 != 0) && (param_4 != 0)) && (param_5 != 0)) && (param_6 != 0)) {
    *(undefined4 *)(param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    *(undefined4 *)(param_1 + 8) = param_3;
    *(int *)(param_1 + 0x48) = param_4;
    *(int *)(param_1 + 0x4c) = param_5;
    *(int *)(param_1 + 0x44) = param_6;
    *(undefined1 *)(param_1 + 4) = 1;
    FUN_0001ce0e(param_5,param_3,param_1 + 0x10);
    *(undefined4 *)(param_1 + 0xc) = 0xd;
    FUN_0000b6b6();
    return;
  }
  return;
}

