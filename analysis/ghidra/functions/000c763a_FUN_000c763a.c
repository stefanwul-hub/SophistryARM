/* 000c763a FUN_000c763a */

void * FUN_000c763a(int param_1,void *param_2,void *param_3)

{
  int iVar1;
  size_t sVar2;
  
  sVar2 = *(int *)(param_1 + 4) - (int)param_3;
  _memmove(param_2,param_3,sVar2);
  for (iVar1 = (int)param_2 + sVar2; *(int *)(param_1 + 4) != iVar1; iVar1 = iVar1 + 4) {
  }
  *(uint *)(param_1 + 4) = *(int *)(param_1 + 4) - ((int)param_3 - (int)param_2 & 0xfffffffcU);
  return param_2;
}

