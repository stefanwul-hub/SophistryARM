/* 00098ac0 FUN_00098ac0 */

void FUN_00098ac0(int *param_1,int param_2,int param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  (**(code **)(*param_1 + 0x54))(param_1,0);
  uVar5 = param_1[0x20];
  if ((uVar5 & 0x1000) == 0) {
    if (param_4 == (int *)0x0) {
      piVar1 = (int *)param_1[0xd];
      if (piVar1 == (int *)0x0) {
        if (*(char *)((int)param_1 + 0x32) == '\0') {
          FUN_0009e6ec(param_2,param_1[0x24]);
          FUN_0009fcae(param_2,param_1 + 2);
          uVar5 = param_1[0x20];
          if ((uVar5 & 0x4180) == 0) {
            FUN_0009f51a(param_2,param_1[0x25]);
            FUN_000a0ebc(param_2,param_1 + 2,0);
            uVar5 = param_1[0x20];
          }
        }
      }
      else if (*(char *)((int)param_1 + 0x32) == '\0') {
        (**(code **)(*piVar1 + 0x10))(piVar1,param_2,param_1 + 2,param_1 + 0x19);
        uVar5 = param_1[0x20];
      }
      else {
        (**(code **)(*piVar1 + 0x14))(piVar1,param_2,param_1 + 2,param_1 + 0x19);
        uVar5 = param_1[0x20];
      }
    }
    else if (*(char *)((int)param_1 + 0x32) == '\0') {
      (**(code **)(*param_4 + 0x10))(param_4,param_2,param_1 + 2,param_1 + 0x19);
      uVar5 = param_1[0x20];
    }
    else {
      (**(code **)(*param_4 + 0x14))(param_4,param_2,param_1 + 2,param_1 + 0x19);
      uVar5 = param_1[0x20];
    }
    if ((uVar5 & 0x180) != 0) {
      local_1c = param_1[2];
      local_14 = param_1[4] + -1;
      local_18 = param_1[3] + 1;
      iVar6 = param_1[5] + -1;
      local_10 = iVar6;
      FUN_0009c9f4(param_2,1);
      if ((char)param_1[0x20] < '\0') {
        FUN_0009f51a(param_2,param_1[0x24]);
      }
      else {
        FUN_0009f51a(param_2,param_1[0x25]);
      }
      iVar2 = local_1c;
      local_2c = local_1c;
      local_28 = iVar6;
      FUN_0009df12(param_2,&local_2c);
      iVar3 = local_18;
      local_2c = iVar2;
      local_28 = local_18;
      FUN_000a0cea(param_2,&local_2c);
      iVar4 = local_14;
      local_2c = local_14;
      local_28 = iVar3;
      FUN_000a0cea(param_2,&local_2c);
      if ((char)param_1[0x20] < '\0') {
        FUN_0009f51a(param_2,param_1[0x25]);
      }
      else {
        FUN_0009f51a(param_2,param_1[0x24]);
      }
      local_2c = iVar4;
      local_28 = iVar3;
      FUN_0009df12(param_2,&local_2c);
      local_2c = iVar4;
      local_28 = iVar6;
      FUN_000a0cea(param_2,&local_2c);
      local_2c = iVar2;
      local_28 = iVar6;
      FUN_000a0cea(param_2,&local_2c);
      uVar5 = param_1[0x20];
    }
    if (((uVar5 & 0x800) == 0) && (param_3 != 0)) {
      local_1c = *(int *)(param_2 + 0x50) + -*(int *)(param_2 + 0x10);
      local_14 = -*(int *)(param_2 + 0x10) + *(int *)(param_2 + 0x58);
      local_18 = -*(int *)(param_2 + 0x14) + *(int *)(param_2 + 0x54);
      local_10 = -*(int *)(param_2 + 0x14) + *(int *)(param_2 + 0x5c);
      local_2c = param_1[2];
      local_28 = param_1[3];
      local_24 = param_1[4];
      local_20 = param_1[5];
      FUN_0009c994(&local_2c,&local_1c);
      FUN_000a08c2(param_2,&local_2c);
      FUN_0009ca22(param_2,param_1[0x21],0,param_1[0x22]);
      if ((*(byte *)(param_1 + 0x20) & 4) != 0) {
        local_3c = param_1[2] + 1;
        local_34 = param_1[4] + 1;
        local_38 = param_1[3] + 1;
        local_30 = param_1[5] + 1;
        FUN_0009e6ac(param_2,param_1[0x26]);
        FUN_0009fe14(param_2,param_3,&local_3c,*(byte *)(param_1 + 0x27) ^ 1,param_1[0x1f]);
      }
      FUN_0009e6ac(param_2,param_1[0x23]);
      FUN_0009fe14(param_2,param_3,param_1 + 2,*(byte *)(param_1 + 0x27) ^ 1,param_1[0x1f]);
      FUN_000a08c2(param_2,&local_1c);
    }
  }
  return;
}

