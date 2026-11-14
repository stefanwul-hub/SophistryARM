/* 00096136 Synth_vslot_118 */

bool Synth_vslot_118(int param_1)

{
  int iVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,0x1c,0,0,0,0);
    return iVar1 != 0;
  }
  return false;
}

