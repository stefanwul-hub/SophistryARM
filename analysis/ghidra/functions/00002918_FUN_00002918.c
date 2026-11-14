/* 00002918 FUN_00002918 */

void FUN_00002918(int param_1)

{
  if (*(char *)(param_1 + 0x32b430) == '\0') {
    (**(code **)(*(int *)(param_1 + 0xec) + 0xc))(param_1 + 0xec);
    *(undefined1 *)(param_1 + 0x32b430) = 1;
  }
  return;
}

