/* 000125a6 FUN_000125a6 */

void FUN_000125a6(int param_1,int param_2)

{
  if (*(int *)(*(int *)(param_1 + 0x1c) + param_2 * 4) != 0) {
    FUN_00010c80();
    return;
  }
  return;
}

