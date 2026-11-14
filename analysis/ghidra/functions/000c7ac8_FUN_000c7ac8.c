/* 000c7ac8 FUN_000c7ac8 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000c7ac8(undefined4 *param_1)

{
  *param_1 = PTR_DAT_001038d4 + 8;
  if ((void *)param_1[2] != (void *)0x0) {
    _free((void *)param_1[2]);
    param_1[2] = 0;
  }
  *param_1 = PTR_DAT_001038d8 + 8;
  operator_delete(param_1);
  return;
}

