/* 000960e2 Synth_vslot_117 */

bool Synth_vslot_117(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,0x19,param_4,param_3,param_2,0);
    return iVar1 != 0;
  }
  return false;
}

