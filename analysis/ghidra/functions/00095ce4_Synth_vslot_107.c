/* 00095ce4 Synth_vslot_107 */

bool Synth_vslot_107(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,0xf,param_2,param_3,0,0);
    return iVar1 != 0;
  }
  return false;
}

