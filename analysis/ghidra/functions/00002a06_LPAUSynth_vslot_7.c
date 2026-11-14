/* 00002a06 LPAUSynth_vslot_7 */

void LPAUSynth_vslot_7(int param_1)

{
  *(undefined1 *)(param_1 + 0x32b431) = 0;
  *(undefined4 *)(param_1 + 0x32b438) = 0;
  *(undefined4 *)(param_1 + 0x32b43c) = 0;
  (**(code **)(*(int *)(param_1 + 0xec) + 8))(param_1 + 0xec,0xc,0,0,0,0);
  (**(code **)(*(int *)(param_1 + 0xec) + 8))(param_1 + 0xec,0xc,0,1,0,0);
  AUBase_vslot_7();
  return;
}

