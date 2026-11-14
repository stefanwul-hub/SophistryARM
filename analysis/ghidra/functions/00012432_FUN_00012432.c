/* 00012432 FUN_00012432 */

void FUN_00012432(int param_1,int param_2)

{
  if (*(int *)(*(int *)(param_1 + 0x1c) + param_2 * 4) != 0) {
    FUN_00010e34();
    return;
  }
  return;
}

