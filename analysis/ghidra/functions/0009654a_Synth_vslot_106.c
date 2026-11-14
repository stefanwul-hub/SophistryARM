/* 0009654a Synth_vslot_106 */

bool Synth_vslot_106(int param_1)

{
  int iVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,0x2a,0,0,0,0);
    return iVar1 != 0;
  }
  return false;
}

