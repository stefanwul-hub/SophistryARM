/* 000af3fa FUN_000af3fa */

undefined4 FUN_000af3fa(int param_1,FILE *param_2,uint param_3)

{
  void *pvVar1;
  size_t sVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_64 [10];
  undefined4 local_3c [10];
  int local_14;
  undefined4 local_10;
  
  pvVar1 = (void *)FUN_00013124(param_1,param_3 & 0x3fffffff);
  if (pvVar1 != (void *)0x0) {
    puVar4 = local_3c;
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    puVar4 = local_64;
    for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    local_64[2] = 0x6c70636d;
    local_3c[2] = 0x6c70636d;
    local_3c[3] = 9;
    local_64[3] = 9;
    local_64[8] = 0x20;
    local_3c[8] = 0x20;
    local_64[7] = 1;
    local_3c[7] = 1;
    local_64[5] = 1;
    local_3c[5] = 1;
    local_64[6] = 4;
    local_64[4] = 4;
    local_3c[6] = 4;
    local_3c[4] = 4;
    iVar3 = _AudioConverterNew(local_3c,local_64,&local_10);
    if (iVar3 == 0) {
      local_14 = param_3 << 2;
      _AudioConverterConvertBuffer
                (local_10,param_3 << 2,*(undefined4 *)(param_1 + 0x21c),&local_14,pvVar1);
      _AudioConverterDispose(local_10);
      sVar2 = _fwrite(pvVar1,4,param_3,param_2);
      if (param_3 == sVar2) {
        operator_delete__(pvVar1);
        return 1;
      }
    }
    operator_delete__(pvVar1);
  }
  return 0;
}

