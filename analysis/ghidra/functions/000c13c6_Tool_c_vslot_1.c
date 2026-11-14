/* 000c13c6 Tool_c_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Tool_c_vslot_1(undefined4 *param_1)

{
  *param_1 = PTR_DAT_0010380c + 8;
  OsLib_c_vslot_0(param_1 + 1);
  operator_delete(param_1);
  return;
}

