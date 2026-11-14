/* 0009bdb8 CMenuFileList_vslot_19 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CMenuFileList_vslot_19(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  short sVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  uint uVar10;
  short sVar11;
  int *piVar12;
  short local_94;
  short local_80;
  undefined4 local_70;
  int *local_64;
  float local_58;
  float local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  undefined1 local_38 [4];
  short local_34;
  undefined4 local_30;
  undefined1 local_2c [2];
  byte local_2a;
  int local_28;
  undefined4 local_24;
  int local_20 [4];
  
  if (param_1[10] == 0) {
    return;
  }
  param_1[0x35] = -1;
  param_1[0x37] = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  if (param_2 == (int *)0x0) {
    uVar5 = *(undefined4 *)(param_1[10] + 0x7c);
    _HIViewGetFrame(uVar5,&local_58);
    uVar6 = *(undefined4 *)(param_1[10] + 100);
    _GetWindowAttributes(uVar6,local_2c);
    if ((local_2a & 8) != 0) {
      uVar2 = *(undefined4 *)PTR_0010389c;
      uVar3 = *(undefined4 *)(PTR_0010389c + 4);
      uVar6 = _HIViewGetRoot(uVar6);
      _HIViewFindByID(uVar6,uVar2,uVar3,&local_28);
      iVar7 = _HIViewGetSuperview(uVar5);
      if (iVar7 != local_28) {
        _HIViewConvertRect(&local_58,uVar5,local_28);
      }
      local_58 = (float)*(int *)(param_1[10] + 0x8c) + local_58;
      local_54 = (float)*(int *)(param_1[10] + 0x90) + local_54;
    }
    local_48 = (int)local_58;
    local_44 = (int)local_54;
  }
  else {
    local_48 = param_2[2];
    local_44 = param_2[3];
  }
  for (piVar12 = (int *)param_1[0xb]; piVar12 != (int *)0x0; piVar12 = (int *)piVar12[0xb]) {
    while (iVar7 = (**(code **)(*piVar12 + 0x94))
                             (piVar12,param_1,
                              *(undefined4 *)PTR_PTR_s_kMsgCheckIfViewContainer_00103894),
          iVar7 != 1) {
      piVar12 = (int *)piVar12[0xb];
      if (piVar12 == (int *)0x0) goto LAB_0009be95;
    }
    local_58 = 0.0;
    local_54 = 0.0;
    local_50 = 0;
    local_4c = 0;
    (**(code **)(*piVar12 + 0x78))(piVar12,&local_58);
    local_48 = local_48 + (int)local_58;
    local_40 = local_40 + (int)local_58;
    local_44 = local_44 + (int)local_54;
    local_3c = local_3c + (int)local_54;
  }
LAB_0009be95:
  if (param_1[0x2d] == 0) {
    (**(code **)(*param_1 + 0xe4))(param_1);
    (**(code **)(*(int *)param_1[10] + 0x13c))((int *)param_1[10],0);
    return;
  }
  if ((*(byte *)((int)param_1 + 0x81) & 2) == 0) {
    local_80 = (short)param_1[5];
  }
  else {
    local_80 = (short)param_1[3];
  }
  local_30 = 0;
  local_24 = 0;
  (**(code **)(*(int *)param_1[10] + 0x114))((int *)param_1[10],&local_30,&local_24);
  sVar11 = (short)local_24 + (short)local_44;
  sVar9 = (short)local_48 + (short)local_30 + (short)param_1[2];
  local_20[0] = 0;
  uVar5 = FUN_00097fb8(param_1,local_20);
  _CalcMenuSize(uVar5);
  uVar6 = _GetGrayRgn();
  _GetRegionBounds(uVar6,local_38);
  sVar4 = _GetMenuHeight(uVar5);
  iVar7 = (sVar4 + -1 + param_1[0x2d]) / param_1[0x2d];
  (**(code **)(*param_1 + 0x54))(param_1,0);
  iVar8 = (int)(short)(sVar11 + local_80);
  if (sVar4 + iVar8 < (int)local_34 - iVar7 / 2) {
    local_70 = _PopUpMenuSelect(uVar5,iVar8,(int)sVar9,1);
  }
  else {
    uVar10 = param_1[0x2d];
    if ((int)(iVar7 * uVar10) < (int)local_34) {
      local_94 = (short)iVar7;
      local_70 = _PopUpMenuSelect(uVar5,(int)(short)((local_34 - sVar4) - local_94),(int)sVar9,1);
    }
    else {
      if ((int)(param_1[0x2f] + 2U) <= (int)uVar10) {
        uVar10 = param_1[0x2f] + 2U;
      }
      local_70 = _PopUpMenuSelect(uVar5,iVar8,(int)sVar9,uVar10 & 0xffff);
    }
  }
  if (param_1[0x2e] < 1) {
    sVar4 = (short)param_1[0x2c];
  }
  else {
    iVar7 = 0;
    do {
      FUN_0009b910(*(undefined4 *)(param_1[0x2a] + iVar7 * 4));
      iVar7 = iVar7 + 1;
    } while (iVar7 < param_1[0x2e]);
    sVar4 = (short)param_1[0x2c];
  }
  if (sVar4 != 0) {
    _DeleteMenu((int)sVar4);
  }
  if (param_1[0x28] != 0) {
    _DisposeMenu(param_1[0x28]);
  }
  param_1[0x28] = 0;
  iVar7 = (int)(short)((short)local_70 + -1);
  param_1[0x35] = iVar7;
  sVar4 = (short)((uint)local_70 >> 0x10);
  if (sVar4 == 0) {
    if (param_1[0x30] == 0) goto LAB_0009c07e;
LAB_0009c04c:
    (**(code **)(*param_1 + 0x54))(param_1,1);
  }
  else if (param_1[0x30] != 0) goto LAB_0009c04c;
  if (param_2 == (int *)0x0) {
    if (sVar4 == 0) goto LAB_0009c07e;
    param_2 = (int *)FUN_000a1db2(param_1[10]);
LAB_0009c0c8:
    local_28 = 0;
    local_20[0] = (int)sVar4;
    if (local_20[0] == (short)param_1[0x2c]) {
      local_64 = param_1;
      local_28 = iVar7;
LAB_0009c148:
      param_1[0x37] = (int)local_64;
      (**(code **)(*local_64 + 0xb0))(local_64,(float)iVar7);
      puVar1 = (undefined4 *)param_1[0xf];
      if (puVar1 != (undefined4 *)0x0) {
        (**(code **)*puVar1)(puVar1,param_2,local_64);
      }
    }
    else if (0 < param_1[0x2e]) {
      iVar8 = 0;
      do {
        local_64 = (int *)FUN_0009b272(*(undefined4 *)(param_1[0x2a] + iVar8 * 4),iVar7,&local_28,
                                       local_20);
        if (local_64 != (int *)0x0) goto LAB_0009c148;
        iVar8 = iVar8 + 1;
      } while (iVar8 < param_1[0x2e]);
    }
    if (param_2 == (int *)0x0) goto LAB_0009c07e;
  }
  else {
    (**(code **)(*param_2 + 0xc))(param_2);
    if (sVar4 != 0) goto LAB_0009c0c8;
  }
  (**(code **)(*param_2 + 8))(param_2);
LAB_0009c07e:
  (**(code **)(*(int *)param_1[10] + 0x13c))((int *)param_1[10],0);
  (**(code **)(*param_1 + 0xe4))(param_1);
  return;
}

