/* 000af546 FUN_000af546 */

undefined4 FUN_000af546(int param_1,FILE *param_2,uint param_3)

{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 local_64 [10];
  undefined4 local_3c [10];
  int local_14;
  undefined4 local_10;
  
  iVar1 = param_3 << 2;
  pvVar2 = (void *)FUN_00013124(param_1,param_3 & 0x3fffffff);
  if (pvVar2 != (void *)0x0) {
    puVar5 = local_3c;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    puVar5 = local_64;
    for (iVar4 = 10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
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
    iVar4 = _AudioConverterNew(local_3c,local_64,&local_10);
    if (iVar4 == 0) {
      local_14 = iVar1;
      _AudioConverterConvertBuffer(local_10,iVar1,*(undefined4 *)(param_1 + 0x21c),&local_14,pvVar2)
      ;
      sVar3 = _fwrite(pvVar2,4,param_3,param_2);
      if (param_3 == sVar3) {
        local_14 = iVar1;
        _AudioConverterConvertBuffer
                  (local_10,iVar1,*(undefined4 *)(param_1 + 0x220),&local_14,pvVar2);
        sVar3 = _fwrite(pvVar2,4,param_3,param_2);
        if (param_3 == sVar3) {
          _AudioConverterDispose(local_10);
          operator_delete__(pvVar2);
          return 1;
        }
      }
      operator_delete__(pvVar2);
      return 0;
    }
    operator_delete__(pvVar2);
  }
  return 0;
}

