/* 00014636 FUN_00014636 */

void FUN_00014636(int param_1,int param_2,undefined4 param_3)

{
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (0x3f < param_2) {
    param_2 = 0x3f;
  }
  *(undefined4 *)(param_1 + 0x14 + param_2 * 4) = param_3;
  if (*(int *)(param_1 + 0x114) <= param_2) {
    *(int *)(param_1 + 0x114) = param_2 + 1;
  }
  return;
}

