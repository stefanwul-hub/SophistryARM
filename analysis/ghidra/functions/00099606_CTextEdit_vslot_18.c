/* 00099606 CTextEdit_vslot_18 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CTextEdit_vslot_18(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  short sVar5;
  int *piVar6;
  int iVar7;
  size_t sVar8;
  int local_14c;
  int local_148;
  char local_138 [256];
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  undefined4 *local_20 [4];
  
  (**(code **)(*param_1 + 0xe4))(param_1);
  piVar6 = (int *)(**(code **)(*(int *)param_1[10] + 0x140))((int *)param_1[10]);
  if (param_1 == piVar6) {
    (**(code **)(*(int *)param_1[10] + 0x13c))((int *)param_1[10],0);
  }
  if (param_1[0x29] == 0) {
    return;
  }
  piVar6 = param_1 + 0x2d;
  _strcpy(local_138,(char *)piVar6);
  if (param_1[0x29] == 0) {
    return;
  }
  if (DAT_000fd4e4 != 0) {
    _RemoveEventHandler(DAT_000fd4e4);
  }
  DAT_000fd4e4 = 0;
  iVar7 = param_1[0x2b];
  if (iVar7 == 0) {
    if (DAT_000fd4e0 == '\0') {
      _TXNGetDataEncoded(param_1[0x29],0,0x7fffffff,local_20,0x54455854);
      if ((local_20[0] == (undefined4 *)0x0) || (iVar7 = _GetHandleSize(local_20[0]), iVar7 < 1)) {
        *(undefined1 *)(param_1 + 0x2d) = 0;
      }
      else {
        sVar8 = _GetHandleSize(local_20[0]);
        if (0xff < (int)sVar8) {
          sVar8 = 0xff;
        }
        _strncpy((char *)piVar6,(char *)*local_20[0],sVar8);
        *(undefined1 *)(sVar8 + 0xb4 + (int)param_1) = 0;
        _DisposeHandle(local_20[0]);
      }
    }
    _TXNFocus(param_1[0x29],0);
    _TXNDeleteObject(param_1[0x29]);
  }
  else {
    if (DAT_000fd4e0 == '\0') {
      sVar5 = _GetControlData(iVar7,5,0x63667374,4,local_20,0);
      if (sVar5 == 0) {
        _CFStringGetCString(local_20[0],piVar6,0xff,0x8000100);
        _CFRelease(local_20[0]);
        iVar7 = param_1[0x2b];
      }
      else {
        iVar7 = param_1[0x2b];
      }
    }
    _HIViewSetVisible(iVar7,0);
    _HIViewRemoveFromSuperview(param_1[0x2b]);
    param_1[0x2b] = 0;
    (**(code **)(*(int *)param_1[10] + 0x138))((int *)param_1[10],0);
  }
  param_1[0x29] = 0;
  (**(code **)(*param_1 + 0x54))(param_1,1);
  local_14c = 0;
  local_148 = 0;
  if (param_2 == (int *)0x0) {
    param_2 = (int *)FUN_000a1db2(param_1[10]);
    if (param_1[0xb] != 0) {
      local_14c = param_2[4];
      local_148 = param_2[5];
      piVar2 = (int *)param_1[0xb];
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      (**(code **)(*piVar2 + 0x78))(piVar2,&local_38);
      local_28 = 0;
      local_24 = 0;
      (**(code **)(*piVar2 + 0x8c))(piVar2,&local_28);
      local_38 = local_28 + local_38;
      local_30 = local_30 + local_28;
      local_34 = local_34 + local_24;
      local_2c = local_2c + local_24;
      param_2[4] = local_38;
      param_2[5] = local_34;
      bVar4 = true;
      goto LAB_0009974f;
    }
  }
  else {
    (**(code **)(*param_2 + 0xc))(param_2);
  }
  bVar4 = false;
LAB_0009974f:
  iVar7 = _strcmp(local_138,(char *)piVar6);
  if (iVar7 == 0) {
    bVar3 = false;
  }
  else {
    puVar1 = (undefined4 *)param_1[0xf];
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(puVar1,param_2,param_1);
    }
    bVar3 = true;
  }
  param_1[0x29] = 0;
  if (bVar4) {
    param_2[4] = local_14c;
    param_2[5] = local_148;
  }
  (**(code **)(*param_2 + 8))(param_2);
  if (bVar3) {
    (**(code **)(*param_1 + 0xac))(param_1);
  }
  piVar6 = (int *)param_1[0xb];
  if ((piVar6 != (int *)0x0) || (piVar6 = (int *)param_1[10], piVar6 != (int *)0x0)) {
    (**(code **)(*piVar6 + 0x94))(piVar6,param_1,"LooseFocus");
  }
  return;
}

