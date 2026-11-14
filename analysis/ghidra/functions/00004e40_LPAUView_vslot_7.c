/* 00004e40 LPAUView_vslot_7 */

undefined1 LPAUView_vslot_7(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  short sVar5;
  short sVar6;
  undefined1 local_44 [8];
  float local_3c;
  float local_38;
  undefined1 local_34 [8];
  short local_2c;
  short local_2a;
  short local_28;
  short local_26;
  short local_24;
  short local_22;
  short local_20;
  short local_1e;
  short local_1c;
  short local_1a;
  short local_18;
  short local_16;
  short local_14;
  short local_12;
  short local_10;
  short local_e;
  
  iVar3 = _GetEventClass(param_2);
  iVar4 = _GetEventKind(param_2);
  if (iVar3 == 0x636e746c) {
    if (iVar4 == 0x9a) {
      _HIViewGetFrame(*(undefined4 *)(param_1 + 0x38),local_44);
      _GetEventParameter(param_2,0x70726374,0x71647274,0,8,0,&local_14);
      _GetEventParameter(param_2,0x63726374,0x71647274,0,8,0,&local_1c);
      iVar4 = ((int)local_16 - (int)local_1a) - ((int)local_e - (int)local_12);
      iVar3 = ((int)local_18 - (int)local_1c) - ((int)local_10 - (int)local_14);
      _GetWindowBounds(*(undefined4 *)(param_1 + 0x34),0x21,&local_24);
      local_3c = (float)iVar4 + local_3c;
      local_38 = (float)iVar3 + local_38;
      _HIViewSetFrame(*(undefined4 *)(param_1 + 0x38),local_44);
      sVar6 = (short)iVar4;
      *(short *)(param_1 + 0x3e) = *(short *)(param_1 + 0x3e) + sVar6;
      sVar5 = (short)iVar3;
      *(short *)(param_1 + 0x3c) = *(short *)(param_1 + 0x3c) + sVar5;
      _GetWindowBounds(*(undefined4 *)(param_1 + 0x34),0x21,&local_2c);
      if (((int)local_1e - (int)local_22 == (int)local_26 - (int)local_2a) &&
         ((int)local_20 - (int)local_24 == (int)local_28 - (int)local_2c)) {
        _SizeWindow(*(undefined4 *)(param_1 + 0x34),(int)(short)(sVar6 + (local_1e - local_22)),
                    (int)(short)(sVar5 + (local_20 - local_24)),1);
      }
      if (*(char *)(param_1 + 0x48) != '\0') {
        return 1;
      }
      _GetControlBounds(*(undefined4 *)(param_1 + 0x38),local_34);
      _InvalWindowRect(*(undefined4 *)(param_1 + 0x34),local_34);
      return 1;
    }
  }
  else if ((iVar3 == 0x77696e64) && (iVar4 == 0x49)) {
    piVar1 = *(int **)(param_1 + 0x58);
    if (piVar1 == (int *)0x0) {
      return 1;
    }
    _OSAtomicAdd32Barrier(0xffffffff,piVar1 + 0x9e72);
    if (piVar1[0x9e72] == 0) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    *(undefined4 *)(param_1 + 0x58) = 0;
    return 1;
  }
  uVar2 = AUCarbonViewBase_vslot_7(param_1,param_2);
  return uVar2;
}

