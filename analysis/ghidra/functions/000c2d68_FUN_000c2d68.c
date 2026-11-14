/* 000c2d68 FUN_000c2d68 */

void FUN_000c2d68(undefined4 param_1,void *param_2)

{
  void *pvVar1;
  
  if (param_2 != (void *)0x0) {
    do {
      FUN_000c2d68(param_1,*(undefined4 *)((int)param_2 + 0xc));
      pvVar1 = *(void **)((int)param_2 + 8);
      operator_delete(param_2);
      param_2 = pvVar1;
    } while (pvVar1 != (void *)0x0);
  }
  return;
}

