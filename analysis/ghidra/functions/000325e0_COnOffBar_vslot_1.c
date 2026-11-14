/* 000325e0 COnOffBar_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void COnOffBar_vslot_1(undefined4 *param_1)

{
  *param_1 = &PTR_COnOffBar_vslot_0_000e80e8;
  if ((void *)param_1[0x2f] != (void *)0x0) {
    _free((void *)param_1[0x2f]);
  }
  param_1[0x2f] = 0;
  FUN_00001452(param_1);
  operator_delete(param_1);
  return;
}

