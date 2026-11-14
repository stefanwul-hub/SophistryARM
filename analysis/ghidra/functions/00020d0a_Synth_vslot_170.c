/* 00020d0a Synth_vslot_170 */

void Synth_vslot_170(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[0xe3c];
  if ((((iVar2 != 0) && (-1 < param_2)) && (param_2 < param_1[0x2694])) &&
     (param_2 < *(int *)(iVar2 + 0x528))) {
    iVar1 = 0x140;
    do {
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    iVar2 = FUN_0002ca94(iVar2,param_2);
    if (iVar2 != 0) {
      Envelope_c_vslot_9(param_1 + 0xf3,0,0x1a,param_2);
      iVar1 = Envelope_c_vslot_12(param_1 + 0xf3,0,0x1a);
      param_1[7] = iVar1;
      (**(code **)(*param_1 + 0x2e0))(param_1,iVar2);
    }
  }
  return;
}

