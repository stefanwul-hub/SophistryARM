/* 00095a56 Synth_vslot_125 */

void Synth_vslot_125(int param_1,undefined4 param_2)

{
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    (**(code **)(param_1 + 4))(param_1 + 0x20,6,0,param_2,0,0);
  }
  return;
}

