/* 000ae198 FUN_000ae198 */

void FUN_000ae198(undefined4 *param_1)

{
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  if ((void *)param_1[3] != (void *)0x0) {
    if (*(char *)(param_1 + 1) == '\0') {
      _free((void *)param_1[3]);
    }
    else {
      *(undefined1 *)(param_1 + 1) = 0;
    }
    param_1[3] = 0;
  }
  *param_1 = 0;
  return;
}

