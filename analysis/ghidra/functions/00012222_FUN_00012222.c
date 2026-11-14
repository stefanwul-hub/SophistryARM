/* 00012222 FUN_00012222 */

void FUN_00012222(int param_1,int param_2)

{
  if (*(int *)(*(int *)(param_1 + 0x1c) + param_2 * 4) != 0) {
    FUN_000109c8();
    return;
  }
  return;
}

