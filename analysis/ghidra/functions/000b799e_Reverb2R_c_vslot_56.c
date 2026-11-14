/* 000b799e Reverb2R_c_vslot_56 */

void Reverb2R_c_vslot_56(int param_1)

{
  if (*(char *)(param_1 + 0x15c) == '\0') {
    return;
  }
  if ((*(int *)(param_1 + 0x10) != *(int *)(param_1 + 0x118)) &&
     (*(char *)(*(int *)(param_1 + 0x10) + 0x26) != '\0')) {
    FUN_000b6a2c();
    return;
  }
  FUN_000b73a6();
  return;
}

