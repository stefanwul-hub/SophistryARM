/* 00056e50 FUN_00056e50 */

void FUN_00056e50(int param_1,int *param_2,undefined4 param_3,int param_4,int param_5,char param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
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
  
  if (param_6 == '\0') {
    local_7c = 0x1a;
    local_54 = 0x38;
  }
  else {
    local_7c = 0x29;
    local_54 = 0x47;
  }
  iVar1 = param_5 + 0xf;
  local_54 = param_4 + local_54;
  local_5c = param_4;
  local_58 = param_5;
  local_7c = local_7c + param_4;
  local_6c = param_4;
  local_68 = param_5;
  local_74 = local_7c + 0xf;
  local_78 = param_5;
  local_18 = param_5;
  local_70 = iVar1;
  local_64 = local_7c;
  local_60 = iVar1;
  local_50 = iVar1;
  local_1c = local_74;
  local_14 = local_54;
  local_10 = iVar1;
  uVar3 = (**(code **)(*param_2 + 0x24))(param_2);
  local_4c = local_5c;
  local_48 = local_58;
  local_44 = local_54;
  local_3c = local_6c;
  local_38 = local_68;
  local_34 = local_64;
  local_2c = local_1c;
  local_28 = local_18;
  local_24 = local_14;
  local_8c = local_7c;
  local_88 = local_78;
  local_84 = local_74;
  uVar2 = *(undefined4 *)(param_1 + 0x34);
  local_80 = iVar1;
  local_40 = iVar1;
  local_30 = iVar1;
  local_20 = iVar1;
  pvVar4 = operator_new(0xf8);
  FUN_000083da(pvVar4,&local_4c,param_1 + 0x20,param_3,&local_3c,&local_2c,&local_8c,uVar3,4,uVar2);
  FUN_000266ca(param_1,pvVar4,param_3,param_2);
  return;
}

