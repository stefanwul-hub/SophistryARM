/* 0002a3ec FUN_0002a3ec */

void FUN_0002a3ec(int param_1,int param_2,int param_3,undefined1 param_4,undefined1 param_5)

{
  if (((-1 < param_2) && (param_2 < 0x40)) && (param_3 != 0)) {
    *(int *)(param_1 + 0x400 + param_2 * 4) = param_3;
    *(undefined1 *)(param_2 + 0x4c0 + param_1) = param_4;
    *(undefined1 *)(param_2 + 0x4f0 + param_1) = param_5;
  }
  return;
}

