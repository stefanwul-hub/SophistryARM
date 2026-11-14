/* 0001a326 Synth_vslot_192 */

void Synth_vslot_192(int *param_1,char param_2)

{
  int iVar1;
  
  if (param_1[0xe3c] == 0) {
    return;
  }
  iVar1 = Envelope_c_vslot_12(param_1 + 0xf3,0,0x1a);
  if (param_2 == '\0') {
    iVar1 = iVar1 + -1;
  }
  else {
    iVar1 = iVar1 + 1;
  }
  if (-1 < iVar1) {
                    /* WARNING: Could not recover jumptable at 0x0001a396. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x2a8))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0001a3c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x2a8))();
  return;
}

