/* 0000ff2c Parameter_c_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Parameter_c_vslot_1(undefined4 *param_1)

{
  undefined *puVar1;
  
  *param_1 = &PTR_Parameter_c_vslot_0_000e6ba8;
  puVar1 = (undefined *)param_1[0x18];
  if (puVar1 != &DAT_000e2000) {
    if (puVar1 != (undefined *)0x0) {
      _free(puVar1);
    }
    param_1[0x18] = 0;
  }
  Flags_c_vslot_0(param_1 + 0x1a);
  operator_delete(param_1);
  return;
}

