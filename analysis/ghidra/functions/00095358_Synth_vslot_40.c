/* 00095358 Synth_vslot_40 */

void Synth_vslot_40(int *param_1,float param_2)

{
  (**(code **)(*param_1 + 0x80))(param_1);
  if ((param_2 == 0.0) && (!NAN(param_2))) {
                    /* WARNING: Could not recover jumptable at 0x000953b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0xa8))();
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x000953e1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0xa8))();
  return;
}

