/* 00094d74 FUN_00094d74 */

void FUN_00094d74(int param_1,int param_2)

{
  *(int *)(param_1 + 8) = param_2;
  if (param_2 != 0) {
    *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) | 1;
    return;
  }
  *(uint *)(param_1 + 0x44) = *(uint *)(param_1 + 0x44) & 0xfffffffe;
  return;
}

