/* 0002debe Lock_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Lock_c_vslot_0(undefined4 *param_1)

{
  *param_1 = &PTR_Lock_c_vslot_0_000e7b48;
  _pthread_mutex_destroy((pthread_mutex_t *)(param_1 + 2));
  *param_1 = PTR_DAT_0010380c + 8;
  OsLib_c_vslot_0();
  return;
}

