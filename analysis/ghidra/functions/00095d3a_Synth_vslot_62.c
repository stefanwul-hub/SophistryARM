/* 00095d3a Synth_vslot_62 */

longdouble Synth_vslot_62(int param_1)

{
  int iVar1;
  
  if (*(code **)(param_1 + 4) != (code *)0x0) {
    iVar1 = (**(code **)(param_1 + 4))(param_1 + 0x20,0x10,0,0,0,0);
    if (0 < iVar1) {
      *(float *)(param_1 + 0xc) = (float)iVar1;
    }
  }
  return (longdouble)*(float *)(param_1 + 0xc);
}

