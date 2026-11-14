/* 0009dcc0 CDragContainer_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CDragContainer_vslot_1(undefined4 *param_1)

{
  *param_1 = &PTR_CDragContainer_vslot_0_000f4400;
  if ((void *)param_1[5] != (void *)0x0) {
    _free((void *)param_1[5]);
    param_1[5] = 0;
  }
  *param_1 = PTR_DAT_00103888 + 8;
  operator_delete(param_1);
  return;
}

