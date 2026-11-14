/* 0003e784 FUN_0003e784 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0003e784(undefined4 *param_1)

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
  FUN_00031edc();
  return;
}

