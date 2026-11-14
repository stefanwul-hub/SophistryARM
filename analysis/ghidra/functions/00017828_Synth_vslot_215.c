/* 00017828 Synth_vslot_215 */

void Synth_vslot_215(int *param_1)

{
  int iVar1;
  
  if (param_1[0x33ec] < 1) {
    return;
  }
  iVar1 = 0;
  do {
    (**(code **)(*param_1 + 0x360))(param_1,iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < param_1[0x33ec]);
  return;
}

