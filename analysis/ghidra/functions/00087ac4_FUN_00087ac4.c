/* 00087ac4 FUN_00087ac4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00087ac4(undefined4 *param_1)

{
  *param_1 = &PTR_DelayPingPong_c_vslot_0_000f2a68;
  if ((void *)param_1[0x7b] != (void *)0x0) {
    _free((void *)param_1[0x7b]);
  }
  param_1[0x7b] = 0;
  if ((void *)param_1[0x7c] != (void *)0x0) {
    _free((void *)param_1[0x7c]);
  }
  param_1[0x7c] = 0;
  if ((void *)param_1[0x7d] != (void *)0x0) {
    _free((void *)param_1[0x7d]);
  }
  param_1[0x7d] = 0;
  if ((void *)param_1[0x7e] != (void *)0x0) {
    _free((void *)param_1[0x7e]);
  }
  param_1[0x7e] = 0;
  if ((void *)param_1[0x7f] != (void *)0x0) {
    _free((void *)param_1[0x7f]);
  }
  param_1[0x7f] = 0;
  if ((void *)param_1[0x80] != (void *)0x0) {
    _free((void *)param_1[0x80]);
  }
  param_1[0x80] = 0;
  FUN_00031edc();
  return;
}

