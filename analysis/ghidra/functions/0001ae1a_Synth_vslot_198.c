/* 0001ae1a Synth_vslot_198 */

void Synth_vslot_198(int *param_1,int param_2)

{
  int iVar1;
  
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (param_1[0x33ec] + -1 < param_2) {
    param_2 = param_1[0x33ec] + -1;
  }
  if (param_2 != param_1[0x33f8]) {
    param_1[0x33f8] = param_2;
    Envelope_c_vslot_9(param_1 + 0xf3,0,1,param_2);
    if (param_1[0xe3c] == 0) {
      iVar1 = Envelope_c_vslot_12(param_1 + 0x169,param_1[0x33f8],1);
      param_1[7] = iVar1;
    }
    if (param_1[0x33ec] < 1) {
      (**(code **)(*param_1 + 0x350))(param_1);
      iVar1 = param_1[0xecd];
    }
    else {
      iVar1 = 0;
      do {
        Envelope_c_vslot_9(param_1 + 0x169,iVar1,10,param_2 == iVar1);
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1[0x33ec]);
      (**(code **)(*param_1 + 0x350))(param_1);
      iVar1 = param_1[0xecd];
    }
    if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x0001aeb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 700))();
      return;
    }
  }
  return;
}

