/* 0008298c AUCronoX_vslot_8 */

undefined4
AUCronoX_vslot_8(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 *param_5,
                undefined1 *param_6)

{
  undefined4 uVar1;
  
  if (param_2 != 0x2d) {
    uVar1 = LPAUSynth_vslot_8();
    return uVar1;
  }
  if (param_3 == 0) {
    if (param_4 - 0xd5U < 6) {
      *param_5 = 0x30;
      *param_6 = 0;
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffd583;
    }
  }
  else {
    uVar1 = 0xffffd58e;
  }
  return uVar1;
}

