/* 0003b674 Gator_c_vslot_30 */

void Gator_c_vslot_30(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int local_154;
  int local_150;
  undefined1 local_14c [320];
  
  Envelope_c_vslot_30(param_1,param_2,param_3);
  iVar1 = FUN_00012888(param_1,param_2);
  if (param_1[0x8d] == 1) {
    if ((param_3 == -1) || (param_3 == 1)) {
      FUN_00010aee(iVar1 + 0x70,local_14c);
      FUN_00010e34(iVar1 + 0xe0,local_14c);
      if (param_3 != -1) goto LAB_0003b764;
    }
    else {
LAB_0003b764:
      if (param_3 != 2) goto LAB_0003b6b7;
    }
    local_150 = iVar1 + 0x70;
    FUN_00010aee(iVar1 + 0xe0,local_14c);
    FUN_00010e34(local_150,local_14c);
  }
LAB_0003b6b7:
  if (param_1[0x8d] == 2) {
    if ((param_3 == -1) || (param_3 == 1)) {
      FUN_00010aee(iVar1 + 0x70,local_14c);
      (**(code **)(*param_1 + 0xf8))(param_1,local_14c);
      FUN_00010e34(iVar1 + 0xe0,local_14c);
      if (param_3 == -1) goto LAB_0003b70d;
    }
    if (param_3 == 2) {
LAB_0003b70d:
      local_154 = iVar1 + 0x70;
      FUN_00010aee(iVar1 + 0xe0,local_14c);
      (**(code **)(*param_1 + 0xf8))(param_1,local_14c);
      FUN_00010e34(local_154,local_14c);
      return;
    }
  }
  return;
}

