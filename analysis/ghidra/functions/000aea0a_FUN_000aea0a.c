/* 000aea0a FUN_000aea0a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000aea0a(undefined4 *param_1)

{
  *param_1 = PTR_DAT_0010380c + 8;
  FUN_0002e178(param_1 + 1);
  *param_1 = &PTR_Timer_c_vslot_0_000f4968;
  param_1[2] = 0x32;
  param_1[3] = 0;
  param_1[4] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  return;
}

