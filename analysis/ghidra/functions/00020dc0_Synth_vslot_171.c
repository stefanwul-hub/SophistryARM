/* 00020dc0 Synth_vslot_171 */

void Synth_vslot_171(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if ((((param_1[0xe3b] != 0) && (param_1[0xe3c] != 0)) && (-1 < param_2)) &&
     (param_2 < *(int *)(param_1[0xe3b] + 0x528))) {
    piVar1 = param_1 + 0xf3;
    Envelope_c_vslot_9(piVar1,0,0x1b,param_2);
    Envelope_c_vslot_9(piVar1,0,0x1a,0);
    iVar2 = FUN_0002ca94(param_1[0xe3b],param_2);
    if (iVar2 != 0) {
      FUN_0002d328(param_1[0xe3c],iVar2,0);
      if (*(int *)(param_1[0xe3c] + 0x528) < 1) {
        (**(code **)(*param_1 + 0x350))(param_1);
      }
      else {
        iVar2 = FUN_0002ca94(param_1[0xe3c],0);
        if (iVar2 == 0) {
          return;
        }
        (**(code **)(*param_1 + 0x2e0))(param_1,iVar2);
        Envelope_c_vslot_9(piVar1,0,0x1a,0);
        iVar2 = Envelope_c_vslot_12(piVar1,0,0x1a);
        param_1[7] = iVar2;
      }
      param_1[0x2c] = param_2;
      return;
    }
  }
  return;
}

