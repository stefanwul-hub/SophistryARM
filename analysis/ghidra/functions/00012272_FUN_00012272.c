/* 00012272 FUN_00012272 */

void FUN_00012272(int param_1,int param_2)

{
  if (*(int *)(*(int *)(param_1 + 0x1c) + param_2 * 4) != 0) {
    FUN_000109ee();
    return;
  }
  return;
}

