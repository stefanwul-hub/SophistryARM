/* 0001a280 Synth_vslot_191 */

void Synth_vslot_191(int *param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  
  iVar1 = Envelope_c_vslot_12(param_1 + 0x169,param_2,1);
  if (param_3 == '\0') {
    iVar1 = iVar1 + -1;
  }
  else {
    iVar1 = iVar1 + 1;
  }
  if (-1 < iVar1) {
                    /* WARNING: Could not recover jumptable at 0x0001a300. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x2a4))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001a323. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x2a4))();
  return;
}

