/* 000951f8 Synth_vslot_38 */

bool Synth_vslot_38(int param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,4,param_2,1,0,0);
    return iVar1 == 0;
  }
  return true;
}

