/* 00095c34 Synth_vslot_61 */

bool Synth_vslot_61(int param_1)

{
  int iVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,0xd,0,0,0,0);
    return iVar1 != 0;
  }
  return false;
}

