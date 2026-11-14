/* 000b1530 WaveSample_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void WaveSample_c_vslot_0(undefined4 *param_1)

{
  *param_1 = &PTR_WaveSample_c_vslot_0_000f4988;
  param_1[0x8b] = 0;
  if (param_1[0x87] != 0) {
    _free((void *)param_1[0x87]);
    param_1[0x87] = 0;
  }
  if (param_1[0x88] != 0) {
    param_1[0x8b] = 0;
    _free((void *)param_1[0x88]);
    param_1[0x88] = 0;
  }
  param_1[0x8b] = 0;
  *(undefined1 *)(param_1 + 0x85) = 0;
  *(undefined1 *)(param_1 + 0x8c) = 0;
  *(undefined1 *)((int)param_1 + 0x231) = 0;
  *(undefined1 *)((int)param_1 + 0x232) = 0;
  *(undefined1 *)(param_1 + 0x96) = 0;
  *(undefined1 *)(param_1 + 0x98) = 0;
  *(undefined1 *)((int)param_1 + 0x233) = 0;
  *(undefined1 *)(param_1 + 0x8d) = 0;
  Lock_c_vslot_0(param_1 + 0x75);
  FUN_00032014();
  return;
}

