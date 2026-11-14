/* 00009688 Disk_c_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Disk_c_vslot_1(undefined4 *param_1)

{
  *param_1 = &PTR_Disk_c_vslot_0_000e6648;
  *param_1 = PTR_DAT_0010380c + 8;
  OsLib_c_vslot_0(param_1 + 1);
  operator_delete(param_1);
  return;
}

