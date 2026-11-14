/* 000adc1c MusicDeviceBase_vslot_8 */

int MusicDeviceBase_vslot_8
              (undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 *param_5,
              undefined1 *param_6)

{
  int iVar1;
  
  if (param_2 == 1000) {
    if (param_3 == 0) {
      *param_5 = 4;
      *param_6 = 0;
      return 0;
    }
    iVar1 = -0x2a72;
  }
  else {
    iVar1 = AUBase_vslot_8(param_1,param_2,param_3,param_4,param_5,param_6);
    if (iVar1 == -0x2a7f) {
      iVar1 = AUMIDIBase_vslot_2();
      return iVar1;
    }
  }
  return iVar1;
}

