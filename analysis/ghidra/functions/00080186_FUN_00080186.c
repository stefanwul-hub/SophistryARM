/* 00080186 FUN_00080186 */

void FUN_00080186(int param_1,int param_2)

{
  if (param_2 != 0) {
    *(int *)(param_1 + 0x1e0) = param_2;
  }
  return;
}

