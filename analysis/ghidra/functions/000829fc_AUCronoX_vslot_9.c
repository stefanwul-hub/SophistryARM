/* 000829fc AUCronoX_vslot_9 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int AUCronoX_vslot_9(int *param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  undefined1 local_78 [60];
  undefined4 local_3c;
  int local_38;
  float local_34;
  float local_30;
  byte local_28;
  undefined4 local_24;
  float local_20 [4];
  
  FUN_00002918(param_1);
  if (param_2 == 0x27) {
    iVar1 = _CFBundleGetBundleWithIdentifier(&cf_com_linplug_au_Sophistry);
    if (iVar1 == 0) {
      iVar2 = 0;
    }
    else {
      _CFRetain(iVar1);
      iVar2 = _CFBundleCopyResourceURL(iVar1,&cf_Icon,&cf_icns,0);
      _CFRelease(iVar1);
    }
    *param_5 = iVar2;
    if (iVar2 != 0) {
      return 0;
    }
  }
  else {
    if (param_2 == 0x2d) {
      if (param_3 != 0) {
        return -0x2a72;
      }
      if (5 < param_4 - 0xd5U) {
        return -0x2a7d;
      }
      *param_5 = (int)&DAT_000e1d40;
      return 0;
    }
    if (param_2 != 0x21) {
      iVar1 = LPAUSynth_vslot_9(param_1,param_2,param_3,param_4,param_5);
      return iVar1;
    }
    if (param_5 != (int *)0x0) {
      param_5[2] = 0;
      iVar1 = *param_5;
      iVar2 = (**(code **)(*param_1 + 0x70))(param_1,param_3,iVar1,local_78);
      if (iVar2 != 0) {
        return iVar2;
      }
      if ((local_28 & 0x10) != 0) {
        _CFRelease(local_3c);
      }
      local_20[0] = 0.0;
      if ((float *)param_5[1] == (float *)0x0) {
        iVar2 = (**(code **)(*param_1 + 0x40))(param_1,iVar1,0,0,local_20);
        if (iVar2 != 0) {
          return iVar2;
        }
      }
      else {
        fVar4 = *(float *)param_5[1];
        uVar3 = -(uint)(local_34 <= fVar4);
        fVar4 = (float)(~uVar3 & (uint)local_34 | (uint)fVar4 & uVar3);
        uVar3 = -(uint)(fVar4 <= local_30);
        local_20[0] = (float)(~uVar3 & (uint)local_30 | (uint)fVar4 & uVar3);
      }
      if (local_38 != 0xd) {
        iVar2 = (**(code **)(*param_1 + 0x7c))(param_1,param_3,iVar1,0);
        if (iVar2 != 0) {
          return -0x2a62;
        }
        iVar1 = (**(code **)(*param_1 + 0x7c))(param_1,param_3,iVar1,&local_24);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar1 = (int)(local_20[0] - local_34);
        if ((-1 < iVar1) && (iVar2 = _CFArrayGetCount(local_24), iVar1 < iVar2)) {
          iVar1 = _CFArrayGetValueAtIndex(local_24,iVar1);
          param_5[2] = iVar1;
          _CFRetain(iVar1);
        }
        _CFRelease(local_24);
        return 0;
      }
      if (local_34 != local_20[0]) {
        return 0;
      }
      if (!NAN(local_34) && !NAN(local_20[0])) {
        param_5[2] = (int)&cf__inf;
        return 0;
      }
      return 0;
    }
  }
  return -0x2a63;
}

