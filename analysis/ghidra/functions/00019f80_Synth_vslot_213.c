/* 00019f80 Synth_vslot_213 */

void Synth_vslot_213(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 0xf3;
  iVar2 = Envelope_c_vslot_12(piVar1,0,0x15);
  if (iVar2 != param_2) {
    Envelope_c_vslot_9(piVar1,0,0x15,param_2);
    (**(code **)(*param_1 + 0x348))(param_1,piVar1,0x15,0,0 < param_1[0xecc]);
  }
  return;
}

