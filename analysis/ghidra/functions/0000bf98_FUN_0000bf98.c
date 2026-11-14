/* 0000bf98 FUN_0000bf98 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0000bf98(undefined4 *param_1,undefined1 param_2)

{
  FUN_00013e4c(param_1);
  *param_1 = &PTR_FUN_000e66a8;
  *(undefined1 *)(param_1 + 0x7d) = param_2;
  param_1[0x77] = 0;
  param_1[0x78] = 0;
  param_1[0x7b] = 0;
  param_1[0x7c] = 0;
  *(undefined1 *)(param_1 + 0x75) = 0;
  *(undefined1 *)((int)param_1 + 0x1d5) = 0;
  param_1[0x79] = 0;
  param_1[0x76] = 5;
  return;
}

