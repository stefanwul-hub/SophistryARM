/* 00002ac2 LPAUSynth_vslot_8 */

undefined4
LPAUSynth_vslot_8(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5,undefined1 *param_6)

{
  undefined4 uVar1;
  
  if (param_2 != 4000) {
    if (param_2 < 0xfa1) {
      if ((param_2 == 0x21) || (param_2 == 0x23)) {
        *param_5 = 0xc;
        *param_6 = 0;
        return 0;
      }
    }
    else {
      if (param_2 == 0xfa1) {
        *param_5 = 0x20;
        *param_6 = 0;
        return 0;
      }
      if (param_2 == 0x267134) goto LAB_00002b32;
    }
    uVar1 = MusicDeviceBase_vslot_8();
    return uVar1;
  }
LAB_00002b32:
  *param_5 = 4;
  *param_6 = 0;
  return 0;
}

