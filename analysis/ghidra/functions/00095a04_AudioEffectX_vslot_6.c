/* 00095a04 AudioEffectX_vslot_6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void AudioEffectX_vslot_6(int *param_1)

{
  int iVar1;
  
  if ((*(byte *)((int)param_1 + 0x45) & 1) == 0) {
    iVar1 = (**(code **)(*param_1 + 0x188))(param_1,"receiveVstMidiEvent");
    if (iVar1 != 1) {
      return;
    }
  }
  (**(code **)(*param_1 + 500))(param_1,1);
  return;
}

