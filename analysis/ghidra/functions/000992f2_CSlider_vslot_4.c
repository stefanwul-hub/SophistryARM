/* 000992f2 CSlider_vslot_4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CSlider_vslot_4(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  code *pcVar4;
  uint uVar5;
  float fVar6;
  int local_64;
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
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_64 = param_1[0x20];
  if (local_64 == 0) {
    local_64 = param_2;
  }
  else if (*(char *)((int)param_1 + 0x32) != '\0') {
    FUN_0009cd10(local_64,param_2,param_1 + 2,0,0);
  }
  uVar5 = param_1[0x21];
  if (((uVar5 & 8) == 0) && ((uVar5 & 0x20) == 0)) {
    fVar6 = 1.0 - (float)param_1[0x13];
  }
  else {
    fVar6 = (float)param_1[0x13];
  }
  local_40 = param_1[0x29];
  local_44 = param_1[0x28];
  local_4c = 0;
  local_48 = 0;
  if (param_1[0x20] == 0) {
    local_48 = param_1[3];
    local_4c = param_1[2];
    local_44 = local_4c + local_44;
    local_40 = local_48 + local_40;
  }
  piVar1 = (int *)param_1[0xd];
  if (piVar1 != (int *)0x0) {
    if (*(char *)((int)param_1 + 0x32) == '\0') {
      (**(code **)(*piVar1 + 0x10))(piVar1,local_64,&local_4c,param_1 + 0x1b);
      uVar5 = param_1[0x21];
    }
    else {
      (**(code **)(*piVar1 + 0x14))(piVar1,local_64,&local_4c,param_1 + 0x1b);
      uVar5 = param_1[0x21];
    }
  }
  if ((uVar5 & 1) == 0) {
    local_5c = param_1[0x1d];
    local_54 = local_5c + param_1[0x22];
    local_58 = (int)(fVar6 * (float)param_1[0x24]) + param_1[0x1e];
    if (local_58 < param_1[0x25]) {
      local_58 = param_1[0x25];
    }
    local_50 = local_58 + param_1[0x23];
    if (param_1[0x26] < local_58 + param_1[0x23]) {
      local_50 = param_1[0x26];
    }
    iVar2 = param_1[0x20];
  }
  else {
    local_58 = param_1[0x1e];
    local_50 = local_58 + param_1[0x23];
    local_5c = (int)(fVar6 * (float)param_1[0x24]) + param_1[0x1d];
    if (local_5c < param_1[0x25]) {
      local_5c = param_1[0x25];
    }
    local_54 = local_5c + param_1[0x22];
    if (param_1[0x26] < local_5c + param_1[0x22]) {
      local_54 = param_1[0x26];
    }
    iVar2 = param_1[0x20];
  }
  if (iVar2 == 0) {
    local_5c = local_5c + param_1[2];
    local_54 = local_54 + param_1[2];
    local_58 = local_58 + param_1[3];
    local_50 = local_50 + param_1[3];
  }
  piVar1 = (int *)param_1[0x1f];
  if (piVar1 != (int *)0x0) {
    if ((char)param_1[0x2b] == '\0') {
      pcVar4 = *(code **)(*piVar1 + 0x10);
      local_24 = 0;
      local_20 = 0;
      puVar3 = &local_24;
    }
    else {
      pcVar4 = *(code **)(*piVar1 + 0x14);
      local_2c = 0;
      local_28 = 0;
      puVar3 = &local_2c;
    }
    (*pcVar4)(piVar1,local_64,&local_5c,puVar3);
  }
  if (param_1[0x20] != 0) {
    local_3c = param_1[2];
    local_38 = param_1[3];
    local_34 = param_1[4];
    local_30 = param_1[5];
    FUN_0009ffee(param_1[0x20],param_2,&local_3c,0,0);
  }
  (**(code **)(*param_1 + 0x54))(param_1,0);
  return;
}

