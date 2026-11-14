/* 0002645a FUN_0002645a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void * FUN_0002645a(undefined4 param_1,int param_2)

{
  char cVar1;
  void *pvVar2;
  
  if (param_2 < 0x259) {
    do {
      cVar1 = FUN_0002ddaa(DAT_00101ea0);
    } while (cVar1 == '\0');
    pvVar2 = (void *)(&DAT_00101ec0)[param_2];
    if (pvVar2 == (void *)0x0) {
      pvVar2 = operator_new(0x28);
      FUN_000a36e0(pvVar2,param_2);
      (&DAT_00101ec0)[param_2] = pvVar2;
    }
    FUN_0002ddc8(DAT_00101ea0);
    if (pvVar2 != (void *)0x0) {
      return pvVar2;
    }
  }
  return (void *)0x0;
}

