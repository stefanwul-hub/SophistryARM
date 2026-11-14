/* 0002fe96 PolyNoteTable_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void PolyNoteTable_c_vslot_0(undefined4 *param_1)

{
  *param_1 = &PTR_PolyNoteTable_c_vslot_0_000e7ba8;
  if ((void *)param_1[4] != (void *)0x0) {
    _free((void *)param_1[4]);
  }
  param_1[4] = 0;
  *param_1 = PTR_DAT_0010380c + 8;
  OsLib_c_vslot_0();
  return;
}

