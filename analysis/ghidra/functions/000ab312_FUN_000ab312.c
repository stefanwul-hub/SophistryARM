/* 000ab312 FUN_000ab312 */

void FUN_000ab312(int param_1,int param_2,undefined4 param_3)

{
  if (param_2 != 0) {
    *(undefined1 *)(param_1 + 0x7c) = 1;
    *(undefined4 *)(param_1 + 0x78) = 2;
    *(int *)(param_1 + 0x80) = param_2;
    *(undefined4 *)(param_1 + 0x84) = param_3;
    FUN_000ab9ac(param_1,0);
    *(undefined1 *)(param_1 + 0x7c) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x78) = 0;
  FUN_000ae198();
  return;
}

