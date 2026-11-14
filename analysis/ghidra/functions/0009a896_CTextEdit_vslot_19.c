/* 0009a896 CTextEdit_vslot_19 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CTextEdit_vslot_19(int param_1,int param_2)

{
  char cVar1;
  undefined *puVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int *piVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined1 local_2bc [256];
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_bc;
  undefined4 local_b8;
  int *local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  int local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 *local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined1 local_74;
  int local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  undefined4 local_48;
  short local_44;
  undefined2 local_42;
  short local_40;
  short local_3e;
  short local_3c;
  short local_3a;
  undefined4 local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24 [2];
  byte local_22;
  short local_1e [7];
  
  *(undefined1 *)(param_1 + 0xa8) = 0;
  puVar2 = PTR_PTR_s_kMsgCheckIfViewContainer_00103894;
  local_58 = *(int *)(param_1 + 8);
  local_54 = *(int *)(param_1 + 0xc);
  local_50 = *(int *)(param_1 + 0x10);
  local_4c = *(int *)(param_1 + 0x14);
  piVar7 = *(int **)(param_1 + 0x2c);
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  for (; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[0xb]) {
    while( true ) {
      iVar4 = (**(code **)(*piVar7 + 0x94))(piVar7,param_1,*(undefined4 *)puVar2);
      if (iVar4 != 1) break;
      (**(code **)(*piVar7 + 0x78))(piVar7,&local_68);
      local_58 = local_58 + local_68;
      local_50 = local_50 + local_68;
      local_54 = local_54 + local_64;
      local_4c = local_4c + local_64;
      piVar7 = (int *)piVar7[0xb];
      if (piVar7 == (int *)0x0) goto LAB_0009a948;
    }
  }
LAB_0009a948:
  if (param_2 != 0) {
    local_58 = local_58 + *(int *)(param_2 + 0x10);
    local_50 = local_50 + *(int *)(param_2 + 0x10);
    local_54 = local_54 + *(int *)(param_2 + 0x14);
    local_4c = local_4c + *(int *)(param_2 + 0x14);
  }
  uVar5 = *(undefined4 *)(*(int *)(param_1 + 0x28) + 100);
  _GetWindowAttributes(uVar5,local_24);
  if ((local_22 & 8) == 0) {
    if (param_2 != 0) {
      local_58 = local_58 + *(int *)(param_2 + 8);
      local_50 = local_50 + *(int *)(param_2 + 8);
      local_54 = local_54 + *(int *)(param_2 + 0xc);
      local_4c = local_4c + *(int *)(param_2 + 0xc);
    }
    if (DAT_000fd4e8 == '\0') {
      local_80 = 0;
      local_7c = 0xc0000;
      local_78 = _CreateTextEncoding(0,0,0);
      local_74 = 0;
      _TXNInitTextension(&local_80,1,0);
      DAT_000fd4e8 = '\x01';
    }
    DAT_000fd4e0 = 0;
    local_28 = 0;
    local_3e = (short)local_58;
    local_3a = (short)local_50;
    local_40 = (short)local_54;
    local_3c = (short)local_4c;
    iVar4 = _TXNNewObject(0,uVar5,&local_40,0x2c000,1,0x4d505352,1,&local_2c,&local_28,0);
    if (iVar4 == 0) {
      *(undefined4 *)(param_1 + 0xa4) = local_2c;
      _TXNSetFrameBounds(local_2c,(int)local_40,(int)local_3e,(int)local_3c,(int)local_3a,local_28);
      if (*(char *)(param_1 + 0xb4) != '\0') {
        uVar6 = 0xffffffff;
        pcVar9 = (char *)(param_1 + 0xb4);
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        _TXNSetData(*(undefined4 *)(param_1 + 0xa4),0x54455854,(char *)(param_1 + 0xb4),~uVar6 - 1,0
                    ,0x7fffffff);
      }
      local_48 = 0;
      local_44 = 0;
      FUN_0009c92e(PTR_DAT_00103804,&local_48);
      local_98 = 0x7fff7fff;
      local_94 = CONCAT22(local_94._2_2_,0x7fff);
      FUN_0009c92e(PTR_DAT_00103800,&local_98);
      _RGBBackColor(&local_48);
      _RGBForeColor(&local_98);
      local_80 = 1;
      local_7c = local_48;
      local_78 = CONCAT22(local_78._2_2_,local_44);
      _TXNSetBackground(*(undefined4 *)(param_1 + 0xa4),&local_80);
      if (*(int *)(param_1 + 0x7c) == 0) {
        local_34 = 1;
      }
      else {
        local_34 = (uint)(*(int *)(param_1 + 0x7c) != 2) * 2 + 2;
      }
      local_38 = 0x6a757374;
      _TXNSetTXNObjectControls(*(undefined4 *)(param_1 + 0xa4),0,1,&local_38,&local_34);
      _CopyCStringToPascal
                (*(undefined4 *)(PTR_PTR_s_Helvetica_0010388c + *(int *)(param_1 + 0x84) * 4),
                 local_2bc);
      _GetFNum(local_2bc,local_1e);
      _ATSUFONDtoFontID((int)local_1e[0],0,&local_30);
      local_bc = 0x105;
      local_b8 = 4;
      local_a8 = *(int *)(PTR_DAT_00103884 + *(int *)(param_1 + 0x84) * 4) << 0x10;
      local_b0 = 0x73697a65;
      local_ac = 4;
      local_a4 = 0x6b6c6f72;
      local_a0 = 6;
      local_b4 = &local_30;
      local_9c = &local_98;
      _TXNSetTypeAttributes(*(undefined4 *)(param_1 + 0xa4),3,&local_bc,0,0x7fffffff);
      _SetUserFocusWindow(uVar5);
      _TXNFocus(*(undefined4 *)(param_1 + 0xa4),1);
      _TXNSelectAll(*(undefined4 *)(param_1 + 0xa4));
      local_1bc = 0x6d6f7573;
      local_1b8 = 5;
      local_1b4 = 0x6d6f7573;
      local_1b0 = 1;
      local_1ac = 0x6d6f7573;
      local_1a8 = 2;
      local_1a4 = 0x77696e64;
      local_1a0 = 6;
      local_19c = 0x6b657962;
      local_198 = 1;
      local_194 = 0x6b657962;
      local_190 = 2;
      local_18c = 0x636d6473;
      local_188 = 1;
      uVar5 = _GetWindowEventTarget(uVar5);
      _InstallEventHandler(uVar5,FUN_00099a7e,7,&local_1bc,param_1,&DAT_000fd4e4);
      return;
    }
  }
  else {
    local_42 = (undefined2)local_50;
    sVar3 = (short)local_54;
    local_44 = (short)local_4c;
    iVar4 = *(int *)(PTR_DAT_00103884 + *(int *)(param_1 + 0x84) * 4);
    if (iVar4 < local_4c - local_54) {
      sVar3 = ((sVar3 + (short)((local_4c - local_54) / 2)) - (short)(iVar4 / 2)) + 1;
      local_44 = sVar3 + (short)iVar4;
    }
    local_48 = CONCAT22((short)local_58,sVar3);
    iVar4 = _CreateEditUnicodeTextControl(0,&local_48,0,0,0,param_1 + 0xac);
    if (iVar4 == 0) {
      _HIViewAddSubview(*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x7c),
                        *(undefined4 *)(param_1 + 0xac));
      _HIViewSetFirstSubViewFocus
                (*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x7c),*(undefined4 *)(param_1 + 0xac));
      _HIViewAdvanceFocus(*(undefined4 *)(*(int *)(param_1 + 0x28) + 0x7c),0);
      local_98 = 0x77696e64;
      local_94 = 6;
      local_90 = 0x6b657962;
      local_8c = 1;
      local_88 = 0x6b657962;
      local_84 = 2;
      uVar5 = _GetControlEventTarget(*(undefined4 *)(param_1 + 0xac));
      _InstallEventHandler(uVar5,FUN_00099a7e,3,&local_98,param_1,&DAT_000fd4e4);
      uVar5 = *(undefined4 *)(param_1 + 0xac);
      *(undefined4 *)(param_1 + 0xa4) = uVar5;
      if (*(char *)(param_1 + 0xb4) != '\0') {
        local_30 = _CFStringCreateWithCString(0,(char *)(param_1 + 0xb4),0x8000100);
        if (local_30 != 0) {
          _SetControlData(*(undefined4 *)(param_1 + 0xac),5,0x63667374,4,&local_30);
          _CFRelease(local_30);
        }
        iVar4 = -1;
        pcVar9 = (char *)(param_1 + 0xb4);
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          cVar1 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        local_34 = (uint)(ushort)(~(ushort)iVar4 - 1) << 0x10;
        _SetControlData(*(undefined4 *)(param_1 + 0xac),5,0x73656c65,4,&local_34);
        uVar5 = *(undefined4 *)(param_1 + 0xac);
      }
      local_1e[0] = CONCAT11(local_1e[0]._1_1_,1);
      _SetControlData(uVar5,5,0x73676c63,1,local_1e);
      puVar8 = &local_80;
      for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
      local_80 = CONCAT22(local_80._2_2_,0x45);
      if (*(int *)(param_1 + 0x7c) == 0) {
        local_78 = CONCAT22(0xfffe,(undefined2)local_78);
      }
      else if (*(int *)(param_1 + 0x7c) == 2) {
        local_78 = CONCAT22(0xffff,(undefined2)local_78);
      }
      else {
        local_78 = CONCAT22(1,(undefined2)local_78);
      }
      local_7c = CONCAT22(local_7c._2_2_,
                          (short)*(undefined4 *)(PTR_DAT_00103884 + *(int *)(param_1 + 0x84) * 4));
      _CopyCStringToPascal
                (*(undefined4 *)(PTR_PTR_s_Helvetica_0010388c + *(int *)(param_1 + 0x84) * 4),
                 &local_1bc);
      _GetFNum(&local_1bc,(int)&local_80 + 2);
      _SetControlData(*(undefined4 *)(param_1 + 0xac),5,0x666f6e74,0x18,&local_80);
      _HIViewSetVisible(*(undefined4 *)(param_1 + 0xac),1);
      return;
    }
  }
  return;
}

