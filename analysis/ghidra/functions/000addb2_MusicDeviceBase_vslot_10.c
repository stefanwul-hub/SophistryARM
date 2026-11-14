/* 000addb2 MusicDeviceBase_vslot_10 */

void MusicDeviceBase_vslot_10
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  
  iVar1 = AUBase_vslot_10(param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 != -0x2a7f) {
    return;
  }
  AUMIDIBase_vslot_4();
  return;
}

