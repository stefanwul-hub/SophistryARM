/* 00095152 Synth_vslot_36 */

void Synth_vslot_36(int param_1)

{
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    (**(code **)(param_1 + 4))(param_1 + 0x20,3,0,0,0,0);
  }
  return;
}

