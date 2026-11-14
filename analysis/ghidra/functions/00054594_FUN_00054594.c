/* 00054594 FUN_00054594 */

void FUN_00054594(int param_1,int *param_2,int param_3,int param_4,int param_5,char param_6,
                 char param_7)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  if (param_2 != (int *)0x0) {
    uVar2 = (**(code **)(*param_2 + 0x24))(param_2);
    if (param_6 == '\0') {
      local_20 = *(undefined4 *)(param_1 + 0x278e4);
      local_14 = 0x13;
      local_24 = 10;
      local_10 = 0x56;
      local_1c = param_4 + -4;
    }
    else {
      local_20 = *(undefined4 *)(param_1 + 0x278e8);
      local_14 = 10;
      local_24 = 8;
      local_10 = 0x49;
      local_1c = param_4;
    }
    local_18 = param_5;
    local_14 = local_14 + local_1c;
    local_10 = local_10 + param_5;
    pvVar3 = operator_new(0xe4);
    iVar1 = param_1 + 0x54 + param_3 * 0x68;
    FUN_000808d4(pvVar3,&local_1c,local_24,iVar1,param_3,local_20,uVar2);
    if (pvVar3 != (void *)0x0) {
      *(undefined1 *)((int)pvVar3 + 0x72) = 1;
      *(undefined1 *)((int)pvVar3 + 0x73) = 1;
      FUN_0000b7e2(iVar1,pvVar3,param_3,param_1,*(undefined4 *)(param_1 + 0x4c),param_2);
      if (param_7 != '\0') {
        FUN_0000b2b0(iVar1,param_4 + 6,param_5 + -0xc,0x22,8,*(undefined4 *)(param_1 + 0x34));
      }
    }
  }
  return;
}

