/* 0002ddfc FUN_0002ddfc */

bool FUN_0002ddfc(int param_1)

{
  int iVar1;
  
  iVar1 = _pthread_mutex_trylock((pthread_mutex_t *)(param_1 + 8));
  return iVar1 == 0;
}

