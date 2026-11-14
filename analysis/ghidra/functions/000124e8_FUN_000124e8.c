/* 000124e8 FUN_000124e8 */

void FUN_000124e8(int param_1,int param_2)

{
  if (*(int *)(*(int *)(param_1 + 0x1c) + param_2 * 4) != 0) {
    FUN_00010c3c();
    return;
  }
  return;
}

