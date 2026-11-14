/* 0008d4a0 FUN_0008d4a0 */

void FUN_0008d4a0(int param_1,int param_2,int param_3)

{
  if (((*(char *)(param_1 + 0x1d4) != '\0') && (-1 < param_2)) && (-1 < param_3)) {
    if (*(char *)(param_1 + 0x316) != '\0') {
      FUN_0008cea6();
      return;
    }
    *(int *)(param_1 + 0x31c) = param_2;
    *(int *)(param_1 + 800) = param_3;
  }
  return;
}

