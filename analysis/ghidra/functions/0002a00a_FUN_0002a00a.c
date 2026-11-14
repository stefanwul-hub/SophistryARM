/* 0002a00a FUN_0002a00a */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0002a00a(int param_1)

{
  undefined4 *puVar1;
  float *pfVar2;
  undefined4 *puVar3;
  float *pfVar4;
  undefined4 *local_24;
  undefined4 *local_20;
  
  *(int *)(param_1 + 0xc28) = param_1 + 0x64c;
  *(int *)(param_1 + 0xc2c) = param_1 + 0x6b0;
  *(int *)(param_1 + 0xc30) = param_1 + 0x714;
  pfVar4 = *(float **)(param_1 + 0x64c);
  if (pfVar4 != (float *)0x0) {
    local_24 = (undefined4 *)(param_1 + 0x650);
    do {
      puVar1 = *(undefined4 **)(param_1 + 0xc30);
      pfVar2 = (float *)*puVar1;
      puVar3 = *(undefined4 **)(param_1 + 0xc2c);
      *pfVar2 = *pfVar4 * *(float *)*puVar3 + *pfVar2;
      *(undefined4 **)(param_1 + 0xc30) = puVar1 + 1;
      *(undefined4 **)(param_1 + 0xc28) = local_24;
      *(undefined4 **)(param_1 + 0xc2c) = puVar3 + 1;
      pfVar4 = (float *)*local_24;
      local_24 = local_24 + 1;
    } while (pfVar4 != (float *)0x0);
  }
  *(int *)(param_1 + 0xc28) = param_1 + 0x520;
  *(int *)(param_1 + 0xc2c) = param_1 + 0x584;
  *(int *)(param_1 + 0xc30) = param_1 + 0x5e8;
  pfVar4 = *(float **)(param_1 + 0x520);
  if (pfVar4 != (float *)0x0) {
    local_20 = (undefined4 *)(param_1 + 0x524);
    do {
      puVar1 = *(undefined4 **)(param_1 + 0xc30);
      pfVar2 = (float *)*puVar1;
      puVar3 = *(undefined4 **)(param_1 + 0xc2c);
      *pfVar2 = (*pfVar4 * *(float *)*puVar3 + 1.0) * *pfVar2;
      *(undefined4 **)(param_1 + 0xc30) = puVar1 + 1;
      *(undefined4 **)(param_1 + 0xc28) = local_20;
      *(undefined4 **)(param_1 + 0xc2c) = puVar3 + 1;
      pfVar4 = (float *)*local_20;
      local_20 = local_20 + 1;
    } while (pfVar4 != (float *)0x0);
  }
  if (*(size_t *)(param_1 + 0xc48) != 0) {
    _memcpy(*(void **)(param_1 + 0xc3c),*(void **)(param_1 + 0xc40),*(size_t *)(param_1 + 0xc48));
    _memcpy((void *)(param_1 + 0x178),(void *)(param_1 + 0x1d8),*(size_t *)(param_1 + 0xc4c));
  }
  return;
}

