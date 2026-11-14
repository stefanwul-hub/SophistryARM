/* 000c7690 FUN_000c7690 */

void * FUN_000c7690(int param_1,void *param_2)

{
  void *pvVar1;
  void *pvVar2;
  
  pvVar2 = *(void **)(param_1 + 4);
  pvVar1 = (void *)((int)param_2 + 4);
  if (pvVar1 != pvVar2) {
    _memmove(param_2,pvVar1,(int)pvVar2 - (int)pvVar1);
    pvVar2 = *(void **)(param_1 + 4);
  }
  *(int *)(param_1 + 4) = (int)pvVar2 + -4;
  return param_2;
}

