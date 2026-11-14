/* 00003b10 LPAUSynth_vslot_9 */

undefined4
LPAUSynth_vslot_9(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  undefined4 uVar1;
  
  if (*(char *)(param_1 + 0x32b430) == '\0') {
    (**(code **)(*(int *)(param_1 + 0xec) + 0xc))(param_1 + 0xec);
    *(undefined1 *)(param_1 + 0x32b430) = 1;
  }
  if (param_2 != 0x267134) {
    uVar1 = MusicDeviceBase_vslot_9();
    return uVar1;
  }
  *param_5 = param_1;
  return 0;
}

