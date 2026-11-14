/* 000c5b4c FUN_000c5b4c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000c5b4c(undefined4 *param_1,undefined4 param_2)

{
  *param_1 = PTR_DAT_00103878 + 8;
  param_1[1] = param_2;
  param_1[7] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = param_1 + 3;
  param_1[6] = param_1 + 3;
  *(undefined1 *)(param_1 + 8) = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  return;
}

