/* 0002a394 FUN_0002a394 */

void FUN_0002a394(int param_1,int param_2,int param_3,undefined1 param_4,undefined1 param_5,
                 undefined1 param_6)

{
  if (((-1 < param_2) && (param_2 < 0x40)) && (param_3 != 0)) {
    *(int *)(param_1 + 0x240 + param_2 * 4) = param_3;
    *(undefined1 *)(param_2 + 0x340 + param_1) = param_4;
    *(undefined1 *)(param_2 + 0x380 + param_1) = param_5;
    *(undefined1 *)(param_2 + 0x3c0 + param_1) = param_6;
  }
  return;
}

