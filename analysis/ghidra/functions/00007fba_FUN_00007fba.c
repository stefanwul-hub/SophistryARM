/* 00007fba FUN_00007fba */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00007fba(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_000021e2(param_1,param_2,param_3,param_4);
  *param_1 = &PTR_COnOffButtonPl_vslot_0_000e5e08;
  param_1[0x2c] = param_5;
  param_1[0x2d] = param_6;
  CControlPl_vslot_77(param_1,5);
  return;
}

