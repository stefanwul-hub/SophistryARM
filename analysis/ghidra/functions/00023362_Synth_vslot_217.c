/* 00023362 Synth_vslot_217 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Removing unreachable block (ram,0x00023599) */
/* WARNING: Removing unreachable block (ram,0x00023d43) */

void Synth_vslot_217(int *param_1,int param_2,int *param_3,int param_4)

{
  undefined *puVar1;
  code *pcVar2;
  undefined1 uVar3;
  undefined2 uVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  longdouble lVar10;
  undefined **local_190;
  undefined *local_170;
  undefined1 local_16c;
  undefined1 local_16b;
  undefined2 local_16a;
  int local_168;
  int local_164;
  undefined4 local_160;
  undefined *local_30;
  undefined1 local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  
  if (((param_4 == -1) || ((param_4 == 7 && (param_3 == param_1 + 0x2d)))) &&
     (((char)param_1[0x33f1] != '\0' && ((int *)param_1[2] != (int *)0x0)))) {
    pcVar2 = *(code **)(*(int *)param_1[2] + 0x6c);
    Envelope_c_vslot_12(param_1 + 0x2d,0,7);
    (*pcVar2)(param_1[2]);
  }
  piVar5 = param_1 + 0xf3;
  if ((piVar5 == param_3) && (param_4 == 1)) {
    uVar3 = Envelope_c_vslot_12(param_3,0,1);
    if ((param_1[0xecc] == 0) && (param_1[0xecd] == 0)) {
      FUN_0002b8e2(&local_170);
      local_16c = 0x4f;
      local_16a = 0;
      local_164 = 0;
      local_160 = 0;
      local_16b = uVar3;
      FUN_0002ba10(param_1 + 0xe2e);
      HoldData_c_vslot_0(&local_170);
    }
    else {
      (**(code **)(*param_1 + 0x318))(param_1);
    }
LAB_000234b7:
    if (((piVar5 == param_3) && (param_4 == 10)) &&
       (iVar8 = (**(code **)(*param_3 + 0x30))(param_3,0,10), iVar8 < 200000)) {
      local_16c = 0;
      local_170 = PTR_DAT_00103814 + 8;
      local_168 = iVar8 / 1000;
      local_164 = iVar8 % 1000;
      if (local_168 < 0) {
        local_168 = 0;
      }
      else if (0x7f < local_168) {
        local_168 = 0x7f;
      }
      if (local_164 < 0) {
        local_164 = 0;
      }
      else if (0x7f < local_164) {
        local_164 = 0x7f;
      }
      local_160 = 0;
      puVar1 = PTR_DAT_00103808 + 8;
      local_2c = 0;
      local_30 = PTR_DAT_00103814 + 8;
      local_28 = local_168;
      local_24 = local_164;
      local_20 = local_160;
      (**(code **)(*param_1 + 0x288))(param_1,param_2,&local_30,1);
      local_170 = puVar1;
      local_30 = puVar1;
    }
  }
  else {
    if (param_4 == -1) {
LAB_00023803:
      iVar8 = Envelope_c_vslot_12(piVar5,0,3);
      lVar10 = (longdouble)_log((double)((float)iVar8 / 4400.0));
      param_1[0xee7] = (int)(float)((double)lVar10 * 0.36067376022224085);
      lVar10 = (longdouble)
               _pow(0,0x40000000,(double)(float)((double)lVar10 * 0.36067376022224085) * 4.0);
      param_1[0xee8] = (int)(float)lVar10;
      if (param_4 != -1) {
LAB_000233b4:
        if (param_4 != 0x21) goto LAB_000234b7;
        if (piVar5 != param_3) goto LAB_000233cd;
      }
      iVar8 = param_1[0x2696];
      iVar7 = Envelope_c_vslot_12(piVar5,0,0x21);
      param_1[0x2696] = iVar7;
      if ((iVar7 - iVar8 == 1) && (param_1[0xed0] != 0)) {
        FUN_0002b8e2(&local_170);
        local_16c = 0x59;
        local_16b = 0xff;
        local_16a = 0xffff;
        local_164 = 0;
        local_160 = 0;
        FUN_0002ba10(param_1 + 0xe29);
        HoldData_c_vslot_0(&local_170);
      }
      goto LAB_000234b7;
    }
    if (param_4 != 3) goto LAB_000233b4;
    if (piVar5 == param_3) goto LAB_00023803;
  }
LAB_000233cd:
  uVar3 = (**(code **)(*param_1 + 0x380))(param_1);
  *(undefined1 *)((int)param_1 + 0xcfcd) = uVar3;
  piVar9 = param_1 + 0x169;
  if (param_3 == piVar9) {
    if (param_4 == 5) {
      (**(code **)(*param_1 + 0x33c))(param_1,param_2,1);
    }
    else if (param_4 == 4) {
      (**(code **)(*param_1 + 0x33c))(param_1,param_2,0);
    }
  }
  if (((*(char *)((int)param_1 + 0xcfcd) == '\0') && (param_3 == param_1 + 0x2d)) && (param_4 == 1))
  {
    Envelope_c_vslot_18(param_3,0,1,&local_170);
    if ((char)local_170 != '\0') {
      _strcpy((char *)(param_1 + 0x26a1),(char *)&local_170);
    }
  }
  if (param_3 == piVar9) {
    if (param_4 == 0x12) {
      uVar4 = Envelope_c_vslot_12(piVar9,param_2,0x12);
      FUN_0002b8e2(&local_170);
      local_16c = 0x4b;
      local_16b = (undefined1)param_2;
      local_164 = 0;
      local_160 = 0;
      local_16a = uVar4;
      FUN_0002ba10(param_1 + 0xe2e,&local_170);
    }
    else {
      if (param_4 != 1) goto LAB_00023418;
      uVar4 = Envelope_c_vslot_12(piVar9,param_2,1);
      iVar8 = Envelope_c_vslot_12(piVar9,param_1[0x33f8],1);
      param_1[7] = iVar8;
      FUN_0002b8e2(&local_170);
      local_16c = 0x4a;
      local_16b = (undefined1)param_2;
      local_164 = 0;
      local_160 = 0;
      local_16a = uVar4;
      FUN_0002ba10(param_1 + 0xe2e,&local_170);
    }
    local_190 = &local_170;
    HoldData_c_vslot_0(local_190);
  }
LAB_00023418:
  if (piVar5 == param_3) {
    if (param_4 == 0x1b) {
      uVar4 = Envelope_c_vslot_12(piVar5,0,0x1b);
      FUN_0002b8e2(&local_170);
      local_16c = 0x46;
      local_16b = 0;
      local_164 = 0;
      local_160 = 0;
      local_16a = uVar4;
      FUN_0002ba10(param_1 + 0xe2e,&local_170);
    }
    else {
      if (param_4 != 0x1a) goto LAB_00023427;
      iVar8 = Envelope_c_vslot_12(piVar5,0,0x1a);
      param_1[7] = iVar8;
      FUN_0002b8e2(&local_170);
      local_16c = 0x45;
      local_16b = 0;
      local_16a = (undefined2)iVar8;
      local_164 = 0;
      local_160 = 0;
      FUN_0002ba10(param_1 + 0xe2e,&local_170);
    }
    local_190 = &local_170;
    HoldData_c_vslot_0(local_190);
  }
LAB_00023427:
  if (param_3 == piVar9) {
    if (param_4 == 0xf) {
      Envelope_c_vslot_18(param_3,param_2,0xf,&local_170);
      (**(code **)(*param_1 + 0x2d8))(param_1,param_2,&local_170);
      return;
    }
    if (param_4 == 0xe) {
      Envelope_c_vslot_18(param_3,param_2,0xe,&local_170);
      if ((char)local_170 == '\0') {
        return;
      }
      iVar8 = (**(code **)(*param_1 + 0x2dc))(param_1,param_2,&local_170);
      if (iVar8 != 0) {
        return;
      }
      FUN_0002e53a(param_1 + 0xe28,"Load Error","This preset could not be loaded!");
      return;
    }
  }
  if (param_4 == -1) {
LAB_00023679:
    uVar3 = Envelope_c_vslot_13(piVar9,param_2,0x1a);
    iVar8 = param_2 * 4;
    FUN_0000cc4e(*(undefined4 *)(param_1[0x33a9] + iVar8),uVar3);
    if (param_4 != -1) goto LAB_00023444;
LAB_000236bb:
    uVar3 = Envelope_c_vslot_13(piVar9,param_2,0x1c);
    FUN_0000cc70(*(undefined4 *)(iVar8 + param_1[0x33a9]),uVar3);
    if (param_4 != -1) goto LAB_000236f3;
LAB_00023708:
    uVar3 = Envelope_c_vslot_13(piVar9,param_2,0x1d);
    FUN_0000ccb6(*(undefined4 *)(param_1[0x33a9] + iVar8),uVar3);
    if (param_4 == -1) goto LAB_00023753;
  }
  else {
    if (param_4 == 0x1a) {
      if (param_3 != piVar9) {
        return;
      }
      goto LAB_00023679;
    }
LAB_00023444:
    if (param_4 == 0x1c) {
      if (param_3 != piVar9) {
        return;
      }
      iVar8 = param_2 << 2;
      goto LAB_000236bb;
    }
LAB_000236f3:
    if (param_4 == 0x1d) {
      if (param_3 != piVar9) {
        return;
      }
      iVar8 = param_2 << 2;
      goto LAB_00023708;
    }
  }
  if (param_4 != 0x17) {
    return;
  }
  if (param_3 != piVar9) {
    return;
  }
LAB_00023753:
  FUN_0002b8e2(&local_170);
  local_16c = 0x53;
  local_16b = (undefined1)param_2;
  local_16a = 0;
  local_164 = 0;
  local_160 = 0;
  FUN_0002ba10(param_1 + 0xe29,&local_170);
  HoldData_c_vslot_0(&local_170);
  uVar6 = Envelope_c_vslot_12(piVar9,param_2,0x17);
  FUN_0000cd14(*(undefined4 *)(param_1[0x33a9] + param_2 * 4),uVar6);
  return;
}

