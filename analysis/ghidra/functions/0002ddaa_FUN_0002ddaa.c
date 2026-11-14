/* 0002ddaa FUN_0002ddaa */

bool FUN_0002ddaa(int param_1)

{
  int iVar1;
  
  iVar1 = _pthread_mutex_lock((pthread_mutex_t *)(param_1 + 8));
  return iVar1 == 0;
}

