/* 000966a8 Synth_vslot_109 */

bool Synth_vslot_109(int param_1,int param_2)

{
  int iVar1;
  
  if ((*(code **)(param_1 + 4) != (code *)0x0) && (param_2 != 0)) {
    iVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,0x2e,0,0,param_2,0);
    return iVar1 != 0;
  }
  return false;
}

