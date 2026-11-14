/* 0002a18e FUN_0002a18e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0002a18e(int param_1)

{
  size_t sVar1;
  undefined4 *puVar2;
  float *pfVar3;
  undefined4 *puVar4;
  uint uVar5;
  float *pfVar6;
  undefined4 *local_24;
  undefined4 *local_20;
  
  uVar5 = *(int *)(param_1 + 0x15c) + 8;
  *(uint *)(param_1 + 0x15c) = uVar5;
  if ((uVar5 & 0x3f) == 0) {
    (**(code **)(**(int **)(param_1 + 0x144) + 0x70))
              (*(int **)(param_1 + 0x144),*(undefined4 *)(param_1 + 0x13c));
    *(float *)(param_1 + 0x138) =
         (1.0 - *(float *)(param_1 + 0xc44)) * *(float *)(param_1 + 0x138) +
         *(float *)(param_1 + 0xc44) * *(float *)(param_1 + 0x134);
    sVar1 = *(size_t *)(param_1 + 0xc48);
  }
  else {
    sVar1 = *(size_t *)(param_1 + 0xc48);
  }
  if (sVar1 != 0) {
    _memcpy(*(void **)(param_1 + 0xc40),*(void **)(param_1 + 0xc3c),sVar1);
    _memcpy((void *)(param_1 + 0x1d8),(void *)(param_1 + 0x178),*(size_t *)(param_1 + 0xc4c));
  }
  *(int *)(param_1 + 0xc28) = param_1 + 0x8a4;
  *(int *)(param_1 + 0xc2c) = param_1 + 0x908;
  *(int *)(param_1 + 0xc30) = param_1 + 0x96c;
  pfVar6 = *(float **)(param_1 + 0x8a4);
  if (pfVar6 != (float *)0x0) {
    local_24 = (undefined4 *)(param_1 + 0x8a8);
    do {
      puVar2 = *(undefined4 **)(param_1 + 0xc30);
      pfVar3 = (float *)*puVar2;
      puVar4 = *(undefined4 **)(param_1 + 0xc2c);
      *pfVar3 = *pfVar6 * *(float *)*puVar4 + *pfVar3;
      *(undefined4 **)(param_1 + 0xc30) = puVar2 + 1;
      *(undefined4 **)(param_1 + 0xc28) = local_24;
      *(undefined4 **)(param_1 + 0xc2c) = puVar4 + 1;
      pfVar6 = (float *)*local_24;
      local_24 = local_24 + 1;
    } while (pfVar6 != (float *)0x0);
  }
  *(int *)(param_1 + 0xc28) = param_1 + 0x778;
  *(int *)(param_1 + 0xc2c) = param_1 + 0x7dc;
  *(int *)(param_1 + 0xc30) = param_1 + 0x840;
  pfVar6 = *(float **)(param_1 + 0x778);
  if (pfVar6 != (float *)0x0) {
    local_20 = (undefined4 *)(param_1 + 0x77c);
    do {
      puVar2 = *(undefined4 **)(param_1 + 0xc30);
      pfVar3 = (float *)*puVar2;
      puVar4 = *(undefined4 **)(param_1 + 0xc2c);
      *pfVar3 = (*pfVar6 * *(float *)*puVar4 + 1.0) * *pfVar3;
      *(undefined4 **)(param_1 + 0xc30) = puVar2 + 1;
      *(undefined4 **)(param_1 + 0xc28) = local_20;
      *(undefined4 **)(param_1 + 0xc2c) = puVar4 + 1;
      pfVar6 = (float *)*local_20;
      local_20 = local_20 + 1;
    } while (pfVar6 != (float *)0x0);
  }
  return;
}

