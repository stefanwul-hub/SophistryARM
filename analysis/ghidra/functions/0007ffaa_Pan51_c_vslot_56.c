/* 0007ffaa Pan51_c_vslot_56 */

void Pan51_c_vslot_56(int param_1)

{
  if (*(char *)(param_1 + 0x1e1) != '\0') {
    if (*(char *)(*(int *)(param_1 + 0x10) + 0x27) == '\0') {
      FUN_0007f6ae();
      return;
    }
    FUN_0007f81e();
    return;
  }
  if (*(char *)(param_1 + 0x1e0) != '\0') {
    if (*(char *)(*(int *)(param_1 + 0x10) + 0x27) == '\0') {
      FUN_0007f9c0();
      return;
    }
    FUN_0007fb5a();
    return;
  }
  if (*(char *)(*(int *)(param_1 + 0x10) + 0x27) == '\0') {
    FUN_0007f3c8();
    return;
  }
  FUN_0007f51a();
  return;
}

