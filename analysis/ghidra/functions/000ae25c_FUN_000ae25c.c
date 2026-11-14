/* 000ae25c FUN_000ae25c */

void FUN_000ae25c(undefined4 *param_1,int param_2,int param_3)

{
  void *pvVar1;
  uint uVar2;
  
  if ((*(int *)(param_2 + 8) == 0x6c70636d) && ((*(byte *)(param_2 + 0xc) & 0x20) != 0)) {
    uVar2 = *(uint *)(param_2 + 0x1c);
    if (uVar2 <= (uint)param_1[4]) goto LAB_000ae27d;
  }
  else {
    uVar2 = 1;
    if (param_1[4] != 0) goto LAB_000ae27d;
  }
  pvVar1 = _realloc((void *)param_1[2],uVar2 * 0xc + 4);
  param_1[2] = pvVar1;
  param_1[4] = uVar2;
LAB_000ae27d:
  uVar2 = uVar2 * (param_3 * *(int *)(param_2 + 0x18) + 0xfU & 0xfffffff0);
  if ((uint)param_1[6] <= uVar2 && uVar2 - param_1[6] != 0) {
    if (*(char *)(param_1 + 1) != '\0') {
      *(undefined1 *)(param_1 + 1) = 0;
      param_1[3] = 0;
    }
    pvVar1 = _realloc((void *)param_1[3],uVar2);
    param_1[3] = pvVar1;
    param_1[6] = uVar2;
  }
  param_1[5] = param_3;
  *param_1 = 0;
  return;
}

