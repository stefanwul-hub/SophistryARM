/* 0002d6d6 FUN_0002d6d6 */

void FUN_0002d6d6(int param_1,int param_2)

{
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xffffU - param_2;
  return;
}

