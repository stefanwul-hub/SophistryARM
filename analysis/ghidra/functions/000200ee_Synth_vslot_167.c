/* 000200ee Synth_vslot_167 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Synth_vslot_167(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_0002e1c0(param_1 + 0xe28);
  if ((uint)(iVar1 - param_1[0x269b]) < 1000) {
    if (DAT_000fc0c0 == '\0') {
      DAT_000fc0c0 = 1;
      (**(code **)(*param_1 + 700))(param_1);
      DAT_000fc0c0 = 0;
      return;
    }
  }
  else if ((char)param_1[0x33f1] != '\0') {
    if (param_1[0xe3c] == 0) {
      iVar1 = Envelope_c_vslot_12(param_1 + 0x169,param_1[0x33f8],1);
    }
    else {
      iVar1 = Envelope_c_vslot_12(param_1 + 0xf3,0,0x1a);
    }
    if (iVar1 != param_2) {
      if (param_1[0xe3c] != 0) {
                    /* WARNING: Could not recover jumptable at 0x00020182. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*param_1 + 0x2a8))();
        return;
      }
      (**(code **)(*param_1 + 0x2a4))(param_1,param_1[0x33f8],param_2);
    }
  }
  return;
}

