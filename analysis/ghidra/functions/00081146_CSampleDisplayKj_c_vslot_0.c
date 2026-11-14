/* 00081146 CSampleDisplayKj_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CSampleDisplayKj_c_vslot_0(undefined4 *param_1)

{
  *param_1 = &PTR_CSampleDisplayKj_c_vslot_0_000f1ee8;
  if ((void *)param_1[0x35] != (void *)0x0) {
    _free((void *)param_1[0x35]);
  }
  param_1[0x35] = 0;
  if ((void *)param_1[0x34] != (void *)0x0) {
    _free((void *)param_1[0x34]);
  }
  param_1[0x34] = 0;
  FUN_00001452();
  return;
}

