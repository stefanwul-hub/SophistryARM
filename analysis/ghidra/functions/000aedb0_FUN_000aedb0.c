/* 000aedb0 FUN_000aedb0 */

undefined4 FUN_000aedb0(int param_1,FILE *param_2,int param_3,int param_4)

{
  void *pvVar1;
  size_t sVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  undefined4 *puVar6;
  undefined4 local_64 [10];
  uint local_3c [4];
  int local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_14;
  undefined4 local_10;
  
  *(undefined1 *)(param_1 + 0x214) = 0;
  uVar4 = param_3 * param_4;
  pvVar1 = (void *)FUN_00013124(param_1,uVar4 >> 2);
  if (pvVar1 != (void *)0x0) {
    sVar2 = _fread(pvVar1,1,uVar4,param_2);
    if (uVar4 - sVar2 == 0) {
      puVar5 = local_3c;
      for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      puVar6 = local_64;
      for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      local_3c[2] = 0x6c70636d;
      local_3c[3] = (-(uint)(*(char *)(param_1 + 0x230) == '\0') & 0xfffffffe) + 0xe;
      if (*(char *)(param_1 + 0x231) != '\0') {
        local_3c[3] = local_3c[3] | 1;
      }
      local_1c = param_4 << 3;
      local_20 = 1;
      local_28 = 1;
      local_24 = param_4;
      local_2c = param_4;
      local_64[2] = 0x6c70636d;
      local_64[3] = 9;
      local_64[8] = 0x20;
      local_64[7] = 1;
      local_64[5] = 1;
      local_64[6] = 4;
      local_64[4] = 4;
      iVar3 = _AudioConverterNew(local_3c,local_64,&local_10);
      if (iVar3 == 0) {
        local_14 = param_3 << 2;
        _AudioConverterConvertBuffer
                  (local_10,uVar4,pvVar1,&local_14,*(undefined4 *)(param_1 + 0x21c));
        _AudioConverterDispose(local_10);
        operator_delete__(pvVar1);
        return 1;
      }
    }
  }
  return 0;
}

