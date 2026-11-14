/* 000a2390 CViewContainer_vslot_5 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CViewContainer_vslot_5(int *param_1,int param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_10c;
  int local_108;
  int *local_100;
  int local_d0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  int local_90;
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
  
  uVar3 = _DAT_000e20c8;
  pvVar8 = (void *)param_1[0x12];
  if (pvVar8 == (void *)0x0) {
    if ((char)param_1[0x16] == '\0') goto LAB_000a23ed;
    iVar7 = param_1[4];
    iVar11 = param_1[2];
    iVar9 = param_1[5];
    iVar6 = param_1[3];
    pvVar8 = operator_new(0x84);
    FUN_000a2030(pvVar8,param_1[10],iVar7 - iVar11,iVar9 - iVar6,uVar3);
    param_1[0x12] = (int)pvVar8;
    if (pvVar8 == (void *)0x0) goto LAB_000a23ed;
  }
  local_100 = param_1 + 2;
  if (*(char *)((int)param_1 + 0x32) != '\0') {
    FUN_0009cd10(pvVar8,param_2,local_100,0,0);
  }
LAB_000a23ed:
  local_100 = param_1 + 2;
  if ((char)param_1[0x16] == '\0') {
    local_b0 = *(int *)(param_2 + 8);
    local_b4 = *(int *)(param_2 + 0xc);
    local_b8 = *(int *)(param_2 + 0x10);
    local_bc = *(int *)(param_2 + 0x14);
    *(int *)(param_2 + 8) = local_b0 + param_1[2];
    *(int *)(param_2 + 0xc) = local_b4 + param_1[3];
    local_108 = local_b8 + param_1[2];
    *(int *)(param_2 + 0x10) = local_108;
    local_10c = local_bc + param_1[3];
    *(int *)(param_2 + 0x14) = local_10c;
    local_d0 = param_2;
  }
  else {
    local_d0 = param_1[0x12];
    local_108 = *(int *)(param_2 + 0x10);
    local_10c = *(int *)(param_2 + 0x14);
  }
  iVar7 = param_1[2];
  iVar11 = *param_3;
  if (*param_3 < iVar7) {
    iVar11 = iVar7;
  }
  iVar9 = param_1[3];
  if (param_1[3] <= param_3[1]) {
    iVar9 = param_3[1];
  }
  iVar6 = param_1[4];
  if (param_3[2] <= param_1[4]) {
    iVar6 = param_3[2];
  }
  iVar5 = param_1[5];
  if (param_3[3] <= param_1[5]) {
    iVar5 = param_3[3];
  }
  iVar10 = iVar9;
  if (iVar9 <= iVar5) {
    iVar10 = iVar5;
  }
  iVar5 = iVar11;
  if (iVar11 <= iVar6) {
    iVar5 = iVar6;
  }
  local_4c = -iVar7 + iVar11;
  local_44 = -iVar7 + iVar5;
  local_48 = -param_1[3] + iVar9;
  local_40 = -param_1[3] + iVar10;
  local_6c = *(int *)(param_2 + 0x50) + -local_108;
  local_64 = -local_108 + *(int *)(param_2 + 0x58);
  local_68 = -local_10c + *(int *)(param_2 + 0x54);
  local_60 = -local_10c + *(int *)(param_2 + 0x5c);
  local_5c = local_6c;
  local_58 = local_68;
  local_54 = local_64;
  local_50 = local_60;
  if (((char)param_1[0x16] != '\0') && (param_1 != (int *)param_1[10])) {
    local_5c = 0;
    local_54 = local_64 - local_6c;
    local_58 = 0;
    local_50 = local_60 - local_68;
  }
  local_7c = local_5c;
  if (local_5c <= local_4c) {
    local_7c = local_4c;
  }
  local_78 = local_58;
  if (local_58 <= local_48) {
    local_78 = local_48;
  }
  iVar7 = local_54;
  if (local_44 <= local_54) {
    iVar7 = local_44;
  }
  iVar6 = local_50;
  if (local_40 <= local_50) {
    iVar6 = local_40;
  }
  local_70 = local_78;
  if (local_78 <= iVar6) {
    local_70 = iVar6;
  }
  local_74 = local_7c;
  if (local_7c <= iVar7) {
    local_74 = iVar7;
  }
  local_3c = iVar11;
  local_38 = iVar9;
  local_34 = iVar5;
  local_30 = iVar10;
  FUN_000a08c2(local_d0,&local_7c);
  (**(code **)(*param_1 + 0xd8))(param_1,local_d0,&local_4c);
  for (piVar1 = (int *)param_1[0xf]; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    piVar2 = (int *)*piVar1;
    cVar4 = (**(code **)(*piVar2 + 0x18))(piVar2,&local_4c);
    if (cVar4 != '\0') {
      local_8c = local_7c;
      if (local_7c <= piVar2[2]) {
        local_8c = piVar2[2];
      }
      local_88 = local_78;
      if (local_78 <= piVar2[3]) {
        local_88 = piVar2[3];
      }
      iVar7 = local_74;
      if (piVar2[4] <= local_74) {
        iVar7 = piVar2[4];
      }
      local_80 = local_70;
      if (piVar2[5] <= local_70) {
        local_80 = piVar2[5];
      }
      if (local_80 < local_88) {
        local_80 = local_88;
      }
      local_84 = local_8c;
      if (local_8c <= iVar7) {
        local_84 = iVar7;
      }
      if ((local_84 != local_8c) && (local_80 != local_88)) {
        FUN_000a08c2(local_d0,&local_8c);
        cVar4 = (**(code **)(*piVar2 + 0x50))(piVar2);
        (**(code **)(*piVar2 + 0x14))(piVar2,local_d0,&local_4c);
        local_2c = -param_1[2] + *local_100;
        local_24 = -param_1[2] + param_1[4];
        local_28 = -param_1[3] + param_1[3];
        local_20 = -param_1[3] + param_1[5];
        local_9c = local_2c;
        if (local_2c <= piVar2[2]) {
          local_9c = piVar2[2];
        }
        local_98 = local_28;
        if (local_28 <= piVar2[3]) {
          local_98 = piVar2[3];
        }
        local_94 = local_24;
        if (piVar2[4] <= local_24) {
          local_94 = piVar2[4];
        }
        local_90 = local_20;
        if (piVar2[5] <= local_20) {
          local_90 = piVar2[5];
        }
        if (local_90 < local_98) {
          local_90 = local_98;
        }
        if (local_94 < local_9c) {
          local_94 = local_9c;
        }
        if (((cVar4 != '\0') &&
            ((((local_9c != local_8c || (local_94 != local_84)) || (local_98 != local_88)) ||
             (local_90 != local_80)))) &&
           (cVar4 = (**(code **)(*param_1 + 0xa4))(param_1,"CScrollContainer"), cVar4 == '\0')) {
          (**(code **)(*piVar2 + 0x54))(piVar2,1);
        }
      }
    }
  }
  FUN_000a08c2(local_d0,&local_6c);
  if ((char)param_1[0x16] == '\0') {
    *(int *)(param_2 + 8) = local_b0;
    *(int *)(param_2 + 0xc) = local_b4;
    *(int *)(param_2 + 0x10) = local_b8;
    *(int *)(param_2 + 0x14) = local_bc;
    (**(code **)(*param_1 + 0x54))(param_1,0);
    return;
  }
  local_ac = iVar11;
  local_a8 = iVar9;
  local_a4 = iVar5;
  local_a0 = iVar10;
  FUN_0009ffee(local_d0,param_2,&local_ac,local_4c,local_48);
  (**(code **)(*param_1 + 0x54))(param_1,0);
  return;
}

