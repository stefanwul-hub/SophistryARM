/* 000aca18 LPAUView_vslot_5 */

int LPAUView_vslot_5(int *param_1,int param_2,int param_3,undefined4 param_4,float *param_5,
                    float *param_6,int *param_7)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  short local_38;
  short local_36;
  short local_34;
  short local_32;
  undefined4 local_30;
  undefined4 local_2c;
  short local_28;
  short local_26;
  undefined2 local_24;
  undefined2 local_22;
  uint local_20 [4];
  
  param_1[4] = param_2;
  param_1[0xd] = param_3;
  _GetWindowAttributes(param_3,local_20);
  *(byte *)(param_1 + 0x12) = (byte)(local_20[0] >> 0x13) & 1;
  local_26 = (short)(int)*param_5;
  local_28 = (short)(int)param_5[1];
  local_22 = (undefined2)(int)((float)(int)local_26 + *param_6);
  local_24 = (undefined2)(int)((float)(int)local_28 + param_6[1]);
  iVar2 = _CreateUserPaneControl(param_3,&local_28,2,param_1 + 0xe);
  if (iVar2 == 0) {
    *param_7 = param_1[0xe];
    local_30 = 0x636e746c;
    local_2c = 0xd;
    pcVar1 = *(code **)(param_1[2] + 8);
    uVar3 = _GetControlEventTarget(param_1[0xe]);
    (*pcVar1)(param_1 + 2,uVar3,1,&local_30);
    if ((char)param_1[0x12] == '\0') {
      _EmbedControl(param_1[0xe],param_4);
      param_1[0x10] = (int)*param_5;
      param_1[0x11] = (int)param_5[1];
    }
    else {
      _HIViewAddSubview(param_4,param_1[0xe]);
      param_1[0x10] = 0;
      param_1[0x11] = 0;
    }
    *(undefined2 *)(param_1 + 0xf) = 0;
    *(undefined2 *)((int)param_1 + 0x3e) = 0;
    _SizeControl(param_1[0xe],0,0);
    iVar2 = (**(code **)(*param_1 + 0x18))(param_1,param_1[0x10],param_1[0x11]);
    if (iVar2 == 0) {
      _GetControlBounds(param_1[0xe],&local_38);
      if ((((local_38 == local_34) && (local_36 == local_32)) &&
          (*(short *)((int)param_1 + 0x3e) != 0)) && ((short)param_1[0xf] != 0)) {
        _SizeControl(param_1[0xe],
                     (int)(short)(int)((float)(int)*(short *)((int)param_1 + 0x3e) -
                                      (float)param_1[0x10]),
                     (int)(short)(int)((float)(int)(short)param_1[0xf] - (float)param_1[0x11]));
      }
      if ((char)param_1[0x12] != '\0') {
        local_48 = 0x7363726c;
        local_44 = 1;
        local_40 = 0x7363726c;
        local_3c = 10;
        pcVar1 = *(code **)(param_1[2] + 8);
        uVar3 = _GetControlEventTarget(param_1[0xe]);
        (*pcVar1)(param_1 + 2,uVar3,2,&local_48);
        param_1[0x14] = 0;
        param_1[0x13] = 0;
      }
      return 0;
    }
  }
  return iVar2;
}

