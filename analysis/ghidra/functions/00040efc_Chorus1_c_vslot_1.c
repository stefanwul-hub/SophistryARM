/* 00040efc Chorus1_c_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Chorus1_c_vslot_1(undefined4 *param_1)

{
  *param_1 = &PTR_Chorus1_c_vslot_0_000e8ba8;
  if ((void *)param_1[0x83e] != (void *)0x0) {
    _free((void *)param_1[0x83e]);
  }
  param_1[0x83e] = 0;
  LFOSimp_c_vslot_0(param_1 + 0x633);
  LFOSimp_c_vslot_0(param_1 + 0x44a);
  LFOSimp_c_vslot_0(param_1 + 0x261);
  LFOSimp_c_vslot_0(param_1 + 0x78);
  FUN_00031edc(param_1);
  operator_delete(param_1);
  return;
}

