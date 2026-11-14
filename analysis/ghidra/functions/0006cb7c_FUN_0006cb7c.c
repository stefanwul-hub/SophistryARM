/* 0006cb7c FUN_0006cb7c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0006cb7c(undefined4 *param_1)

{
  *param_1 = &PTR_Delay2_c_vslot_0_000f0fa8;
  if ((void *)param_1[0x291] != (void *)0x0) {
    _free((void *)param_1[0x291]);
  }
  param_1[0x291] = 0;
  Crossfader_c_vslot_0(param_1 + 0x29d);
  Crossfader_c_vslot_0(param_1 + 0x294);
  FUN_00031edc();
  return;
}

