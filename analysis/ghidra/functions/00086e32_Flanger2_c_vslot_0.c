/* 00086e32 Flanger2_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Flanger2_c_vslot_0(undefined4 *param_1)

{
  *param_1 = &PTR_Flanger2_c_vslot_0_000f2968;
  if ((void *)param_1[0x83] != (void *)0x0) {
    _free((void *)param_1[0x83]);
  }
  param_1[0x83] = 0;
  if ((void *)param_1[0x84] != (void *)0x0) {
    _free((void *)param_1[0x84]);
  }
  param_1[0x84] = 0;
  FUN_00031edc();
  return;
}

