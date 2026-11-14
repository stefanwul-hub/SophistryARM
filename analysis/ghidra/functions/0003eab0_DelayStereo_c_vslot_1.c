/* 0003eab0 DelayStereo_c_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void DelayStereo_c_vslot_1(undefined4 *param_1)

{
  *param_1 = &PTR_DelayStereo_c_vslot_0_000e8aa8;
  if ((void *)param_1[0x88] != (void *)0x0) {
    _free((void *)param_1[0x88]);
  }
  param_1[0x88] = 0;
  if ((void *)param_1[0x89] != (void *)0x0) {
    _free((void *)param_1[0x89]);
  }
  param_1[0x89] = 0;
  FUN_00031edc(param_1);
  operator_delete(param_1);
  return;
}

