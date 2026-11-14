/* 00095d9e Synth_vslot_63 */

int Synth_vslot_63(int param_1)

{
  int iVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,0x11,0,0,0,0);
    if (0 < iVar1) {
      *(int *)(param_1 + 0x10) = iVar1;
      return iVar1;
    }
  }
  return *(int *)(param_1 + 0x10);
}

