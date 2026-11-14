/* 000a3b48 CBitmap_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CBitmap_vslot_0(undefined4 *param_1)

{
  *param_1 = &PTR_CBitmap_vslot_0_000f43c8;
  if (param_1[9] != 0) {
    _CGImageRelease(param_1[9]);
  }
  param_1[9] = 0;
  if (param_1[7] != 0) {
    _DisposeGWorld(param_1[7]);
  }
  if (param_1[8] != 0) {
    _DisposeGWorld(param_1[8]);
  }
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  *param_1 = PTR_DAT_00103888 + 8;
  return;
}

