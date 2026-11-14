/* 000ae4de FUN_000ae4de */

void FUN_000ae4de(undefined4 *param_1)

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
  if ((void *)param_1[2] != (void *)0x0) {
    _free((void *)param_1[2]);
    return;
  }
  return;
}

