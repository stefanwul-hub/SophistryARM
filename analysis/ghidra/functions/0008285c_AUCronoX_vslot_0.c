/* 0008285c AUCronoX_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void AUCronoX_vslot_0(undefined4 *param_1)

{
  *param_1 = &PTR_AUCronoX_vslot_0_000f2048;
  param_1[2] = &PTR_LAB_000f21a8;
  param_1[0x39] = &PTR_LAB_000f21b4;
  param_1[0x3b] = &PTR_LAB_000f2208;
  if (param_1[0xcad18] != 0) {
    _CFRelease(param_1[0xcad18]);
    param_1[0xcad18] = 0;
  }
  if (param_1[0xcad19] != 0) {
    _CFRelease(param_1[0xcad19]);
    param_1[0xcad19] = 0;
  }
  FUN_00004a5c();
  return;
}

