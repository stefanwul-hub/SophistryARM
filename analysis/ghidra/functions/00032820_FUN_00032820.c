/* 00032820 FUN_00032820 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00032820(undefined4 *param_1)

{
  *param_1 = &PTR_StereoEnh1_c_vslot_0_000e8248;
  if ((void *)param_1[0x78] != (void *)0x0) {
    _free((void *)param_1[0x78]);
  }
  param_1[0x78] = 0;
  if ((void *)param_1[0x79] != (void *)0x0) {
    _free((void *)param_1[0x79]);
  }
  param_1[0x79] = 0;
  FUN_00031edc();
  return;
}

