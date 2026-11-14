/* 0000ec54 FUN_0000ec54 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0000ec54(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_90;
  undefined *local_6c;
  undefined1 local_68;
  int local_64;
  int local_60;
  int local_5c;
  undefined *local_58;
  undefined1 local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined *local_44;
  undefined1 local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined *local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_3c = *(int *)(param_2 + 8);
  iVar3 = 0;
  local_90 = -1;
  iVar1 = 0;
  piVar2 = param_1;
  do {
    if ((local_3c != iVar1) && (iVar3 < piVar2[0x3b5])) {
      iVar3 = piVar2[0x3b5];
      local_90 = iVar1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 != 0x80);
  if ((-1 < local_90) && (iVar3 < param_1[local_3c + 0x3b5])) {
    local_68 = (undefined1)param_1[local_90 * 5 + 0x436];
    local_60 = param_1[local_90 * 5 + 0x438];
    local_5c = param_1[local_90 * 5 + 0x439];
    local_64 = local_90;
    local_6c = PTR_DAT_00103814 + 8;
    local_50 = local_90;
    local_58 = PTR_DAT_00103814 + 8;
    local_54 = local_68;
    local_4c = local_60;
    local_48 = local_5c;
    (**(code **)(*(int *)param_1[1] + 0x388))((int *)param_1[1],param_1[0x69],&local_58,&local_6c);
    local_58 = PTR_DAT_00103808 + 8;
    local_6c = PTR_DAT_00103808 + 8;
    local_3c = *(int *)(param_2 + 8);
  }
  local_40 = *(undefined1 *)(param_2 + 4);
  local_38 = *(undefined4 *)(param_2 + 0xc);
  local_44 = PTR_DAT_00103814 + 8;
  local_34 = *(undefined4 *)(param_2 + 0x10);
  (**(code **)(*(int *)param_1[1] + 0x38c))((int *)param_1[1],param_1[0x69],&local_44);
  local_44 = PTR_DAT_00103808 + 8;
  local_2c = *(undefined1 *)(param_2 + 4);
  local_28 = *(undefined4 *)(param_2 + 8);
  local_24 = *(undefined4 *)(param_2 + 0xc);
  local_30 = PTR_DAT_00103814 + 8;
  local_20 = *(undefined4 *)(param_2 + 0x10);
  (**(code **)(*param_1 + 0x60))(param_1,&local_30);
  return;
}

