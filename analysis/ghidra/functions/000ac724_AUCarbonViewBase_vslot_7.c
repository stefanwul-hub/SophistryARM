/* 000ac724 AUCarbonViewBase_vslot_7 */

undefined4 AUCarbonViewBase_vslot_7(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_40 [8];
  undefined1 local_38 [8];
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  int local_20 [4];
  
  iVar1 = _GetEventClass(param_2);
  iVar2 = _GetEventKind(param_2);
  if (iVar1 == 0x636e746c) {
    if ((iVar2 == 0xd) &&
       (_GetEventParameter(param_2,0x2d2d2d2d,0x6374726c,0,4,0,local_20),
       *(int *)(param_1 + 0x38) == local_20[0])) {
      _ClearKeyboardFocus(*(undefined4 *)(param_1 + 0x34));
      return 1;
    }
  }
  else if (iVar1 == 0x7363726c) {
    if (iVar2 == 1) {
      local_28 = (float)(int)*(short *)(param_1 + 0x3e);
      local_24 = (float)(int)*(short *)(param_1 + 0x3c);
      _SetEventParameter(param_2,0x696d737a,0x6869737a,8,&local_28);
      uVar3 = _HIViewGetSuperview(*(undefined4 *)(param_1 + 0x38));
      _HIViewGetBounds(uVar3,local_40);
      _SetEventParameter(param_2,0x7677737a,0x6869737a,8,local_38);
      local_30 = 16.0;
      local_2c = 20.0;
      _SetEventParameter(param_2,0x6c6e737a,0x6869737a,8,&local_30);
      _SetEventParameter(param_2,0x6f72676e,0x68697074,8,param_1 + 0x4c);
      return 1;
    }
    if (iVar2 == 10) {
      _GetEventParameter(param_2,0x6f72676e,0x68697074,0,8,0,&local_30);
      _HIViewScrollRect(*(undefined4 *)(param_1 + 0x38),0,*(float *)(param_1 + 0x4c) - local_30,
                        *(float *)(param_1 + 0x50) - local_2c);
      _HIViewSetBoundsOrigin(*(undefined4 *)(param_1 + 0x38),local_30,local_2c);
      *(float *)(param_1 + 0x4c) = local_30;
      *(float *)(param_1 + 0x50) = local_2c;
      return 1;
    }
  }
  return 0;
}

