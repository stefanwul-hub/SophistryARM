/* 0009722e Synth_vslot_144 */

undefined4 Synth_vslot_144(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    uVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,0x27,0,0,param_2,0);
    return uVar1;
  }
  return 0;
}

