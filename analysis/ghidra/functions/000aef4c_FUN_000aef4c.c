/* 000aef4c FUN_000aef4c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_000aef4c(int param_1,FILE *param_2,int param_3,int param_4)

{
  uint uVar1;
  void *pvVar2;
  size_t sVar3;
  undefined4 *puVar4;
  int iVar5;
  uint *puVar6;
  undefined4 local_84 [10];
  uint local_5c [4];
  uint local_4c;
  undefined4 local_48;
  uint local_44;
  undefined4 local_40;
  int local_3c;
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  uint local_24;
  undefined4 local_20 [4];
  
  *(undefined1 *)(param_1 + 0x214) = 1;
  uVar1 = param_3 * param_4 * 2;
  pvVar2 = (void *)FUN_00013124(param_1,uVar1 >> 2);
  if (pvVar2 != (void *)0x0) {
    sVar3 = _fread(pvVar2,1,uVar1,param_2);
    if (uVar1 == sVar3) {
      puVar6 = local_5c;
      for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      puVar4 = local_84;
      for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      local_5c[2] = 0x6c70636d;
      local_5c[3] = (-(uint)(*(char *)(param_1 + 0x230) == '\0') & 0xfffffffe) + 0xe;
      if (*(char *)(param_1 + 0x231) != '\0') {
        local_5c[3] = local_5c[3] | 1;
      }
      local_3c = param_4 << 3;
      local_40 = 2;
      local_48 = 1;
      local_4c = param_4 * 2;
      local_84[2] = 0x6c70636d;
      local_84[3] = 0x29;
      local_84[8] = 0x20;
      local_84[7] = 2;
      local_84[5] = 1;
      local_84[6] = 4;
      local_84[4] = 4;
      local_44 = local_4c;
      iVar5 = _AudioConverterNew(local_5c,local_84,local_20);
      if (iVar5 == 0) {
        local_24 = uVar1 / local_4c;
        puVar4 = (undefined4 *)_malloc(0x1c);
        if (puVar4 == (undefined4 *)0x0) {
          iVar5 = -1;
        }
        else {
          local_34 = 1;
          local_30 = 1;
          *puVar4 = 2;
          puVar4[3] = *(undefined4 *)(param_1 + 0x21c);
          puVar4[6] = *(undefined4 *)(param_1 + 0x220);
          puVar4[4] = 1;
          puVar4[1] = 1;
          puVar4[5] = param_3 << 2;
          puVar4[2] = param_3 << 2;
          local_2c = uVar1;
          local_28 = pvVar2;
          iVar5 = _AudioConverterFillComplexBuffer
                            (local_20[0],FUN_000aef2c,&local_34,&local_24,puVar4,0);
          _free(puVar4);
        }
        _AudioConverterDispose(local_20[0]);
        operator_delete__(pvVar2);
        return iVar5 == 0;
      }
    }
  }
  return false;
}

