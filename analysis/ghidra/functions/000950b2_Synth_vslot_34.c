/* 000950b2 Synth_vslot_34 */

int Synth_vslot_34(int param_1)

{
  int iVar1;
  
  if ((*(code **)(param_1 + 4) != (code *)0x0) &&
     (iVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,1,0,0,0,0), iVar1 != 0)) {
    return iVar1;
  }
  return 1;
}

