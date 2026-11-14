/* 0002ec4e FUN_0002ec4e */

void FUN_0002ec4e(int param_1,int param_2,int param_3)

{
  if (param_3 != 0) {
    param_2 = param_2 * 0x24;
    *(undefined4 *)(param_3 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc + param_2);
    *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)(param_2 + 0x10 + *(int *)(param_1 + 0x10));
    *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(param_2 + 0x14 + *(int *)(param_1 + 0x10));
  }
  return;
}

