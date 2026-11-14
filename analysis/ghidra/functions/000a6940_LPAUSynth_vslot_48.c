/* 000a6940 LPAUSynth_vslot_48 */

void LPAUSynth_vslot_48(int *param_1,int param_2)

{
  param_1[0x28] = param_2;
  if ((char)param_1[0x37] != '\0') {
    (**(code **)(*param_1 + 0xbc))(param_1);
  }
  FUN_000a67ae(param_1,0xe,0,0);
  return;
}

