/* 0002de30 FUN_0002de30 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0002de30(undefined4 *param_1)

{
  pthread_mutexattr_t local_28 [2];
  
  *param_1 = PTR_DAT_0010380c + 8;
  FUN_0002e178(param_1 + 1);
  *param_1 = &PTR_Lock_c_vslot_0_000e7b48;
  _pthread_mutexattr_init(local_28);
  _pthread_mutexattr_settype(local_28,2);
  _pthread_mutex_init((pthread_mutex_t *)(param_1 + 2),local_28);
  _pthread_mutexattr_destroy(local_28);
  return;
}

