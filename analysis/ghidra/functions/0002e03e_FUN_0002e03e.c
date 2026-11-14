/* 0002e03e FUN_0002e03e */

undefined4 FUN_0002e03e(int param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  
  if (param_2 != (void *)0x0) {
    if ((int)param_3 < 0) {
      param_3 = 0;
    }
    sVar1 = *(size_t *)(param_1 + 8);
    if ((int)sVar1 < (int)param_3) {
      param_3 = sVar1;
    }
    if (*(void **)(param_1 + 4) != (void *)0x0) {
      _memset(*(void **)(param_1 + 4),0,sVar1);
      if (param_3 != 0) {
        _memcpy(*(void **)(param_1 + 4),param_2,param_3);
      }
      return 1;
    }
  }
  return 0;
}

