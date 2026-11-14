/* 00095be4 Synth_vslot_128 */

undefined4 Synth_vslot_128(int param_1)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,0xc,0,0,0,0);
    return uVar1;
  }
  return 0;
}

