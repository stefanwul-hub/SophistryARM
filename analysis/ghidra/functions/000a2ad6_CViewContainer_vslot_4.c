/* 000a2ad6 CViewContainer_vslot_4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CViewContainer_vslot_4(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  int iVar9;
  int *piVar10;
  int *local_c8;
  int local_c4;
  int local_a4;
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
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  uVar5 = _DAT_000e20c8;
  pvVar8 = (void *)param_1[0x12];
  if (pvVar8 == (void *)0x0) {
    if ((char)param_1[0x16] == '\0') goto LAB_000a2b35;
    iVar9 = param_1[4];
    iVar2 = param_1[2];
    iVar3 = param_1[5];
    iVar4 = param_1[3];
    pvVar8 = operator_new(0x84);
    FUN_000a2030(pvVar8,param_1[10],iVar9 - iVar2,iVar3 - iVar4,uVar5);
    param_1[0x12] = (int)pvVar8;
    if (pvVar8 == (void *)0x0) goto LAB_000a2b35;
  }
  local_c8 = param_1 + 2;
  if (*(char *)((int)param_1 + 0x32) != '\0') {
    FUN_0009cd10(pvVar8,param_2,local_c8,0,0);
  }
LAB_000a2b35:
  local_c8 = param_1 + 2;
  if ((char)param_1[0x16] == '\0') {
    local_80 = *(int *)(param_2 + 8);
    local_84 = *(int *)(param_2 + 0xc);
    local_88 = *(int *)(param_2 + 0x10);
    local_8c = *(int *)(param_2 + 0x14);
    *(int *)(param_2 + 8) = local_80 + param_1[2];
    *(int *)(param_2 + 0xc) = local_84 + param_1[3];
    local_c4 = local_88 + param_1[2];
    *(int *)(param_2 + 0x10) = local_c4;
    iVar9 = local_8c + param_1[3];
    *(int *)(param_2 + 0x14) = iVar9;
    local_a4 = param_2;
  }
  else {
    local_a4 = param_1[0x12];
    local_c4 = *(int *)(param_2 + 0x10);
    iVar9 = *(int *)(param_2 + 0x14);
  }
  local_30 = param_1[5] - param_1[3];
  local_34 = param_1[4] - param_1[2];
  local_3c = 0;
  local_38 = 0;
  local_5c = *(int *)(param_2 + 0x50) + -local_c4;
  local_54 = -local_c4 + *(int *)(param_2 + 0x58);
  local_58 = -iVar9 + *(int *)(param_2 + 0x54);
  local_50 = -iVar9 + *(int *)(param_2 + 0x5c);
  local_4c = local_5c;
  local_48 = local_58;
  local_44 = local_54;
  local_40 = local_50;
  if (((char)param_1[0x16] != '\0') && (param_1 != (int *)param_1[10])) {
    local_4c = 0;
    local_44 = local_54 - local_5c;
    local_48 = 0;
    local_40 = local_50 - local_58;
  }
  iVar4 = local_40;
  iVar3 = local_44;
  iVar2 = local_48;
  iVar9 = local_4c;
  local_6c = local_4c;
  if (local_4c < 1) {
    local_6c = 0;
  }
  local_68 = local_48;
  if (local_48 < 1) {
    local_68 = 0;
  }
  iVar6 = local_44;
  if (local_34 <= local_44) {
    iVar6 = local_34;
  }
  iVar7 = local_40;
  if (local_30 <= local_40) {
    iVar7 = local_30;
  }
  local_60 = local_68;
  if (local_68 <= iVar7) {
    local_60 = iVar7;
  }
  local_64 = local_6c;
  if (local_6c <= iVar6) {
    local_64 = iVar6;
  }
  FUN_000a08c2(local_a4,&local_6c);
  piVar10 = (int *)param_1[0xd];
  if (piVar10 == (int *)0x0) {
    if (*(char *)((int)param_1 + 0x32) == '\0') {
      FUN_0009e6ec(local_a4,param_1[0x13]);
      FUN_0009fcae(local_a4,&local_3c);
    }
  }
  else if (*(char *)((int)param_1 + 0x32) == '\0') {
    (**(code **)(*piVar10 + 0x10))(piVar10,local_a4,&local_3c,param_1 + 0x14);
  }
  else {
    (**(code **)(*piVar10 + 0x14))(piVar10,local_a4,&local_3c,param_1 + 0x14);
  }
  piVar10 = (int *)param_1[0xf];
  if (piVar10 != (int *)0x0) {
    do {
      piVar1 = (int *)*piVar10;
      local_7c = iVar9;
      if (iVar9 <= piVar1[2]) {
        local_7c = piVar1[2];
      }
      local_78 = iVar2;
      if (iVar2 <= piVar1[3]) {
        local_78 = piVar1[3];
      }
      iVar6 = iVar3;
      if (piVar1[4] <= iVar3) {
        iVar6 = piVar1[4];
      }
      iVar7 = iVar4;
      if (piVar1[5] <= iVar4) {
        iVar7 = piVar1[5];
      }
      local_70 = local_78;
      if (local_78 <= iVar7) {
        local_70 = iVar7;
      }
      local_74 = local_7c;
      if (local_7c <= iVar6) {
        local_74 = iVar6;
      }
      FUN_000a08c2(local_a4,&local_7c);
      (**(code **)(*piVar1 + 0x10))(piVar1,local_a4);
      piVar10 = (int *)piVar10[1];
    } while (piVar10 != (int *)0x0);
  }
  FUN_000a08c2(local_a4,&local_5c);
  if ((char)param_1[0x16] != '\0') {
    local_2c = *local_c8;
    local_28 = param_1[3];
    local_24 = param_1[4];
    local_20 = param_1[5];
    FUN_0009ffee(local_a4,param_2,&local_2c,0,0);
    (**(code **)(*param_1 + 0x54))(param_1,0);
    return;
  }
  *(int *)(param_2 + 8) = local_80;
  *(int *)(param_2 + 0xc) = local_84;
  *(int *)(param_2 + 0x10) = local_88;
  *(int *)(param_2 + 0x14) = local_8c;
  (**(code **)(*param_1 + 0x54))(param_1,0);
  return;
}

