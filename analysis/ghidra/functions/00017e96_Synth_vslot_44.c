/* 00017e96 Synth_vslot_44 */

void Synth_vslot_44(int *param_1,int *param_2)

{
  if ((char)param_1[0x33f5] == '\0') {
    return;
  }
  if (0 < param_1[0x33f0]) {
    if (param_2 == (int *)0x0) {
      return;
    }
    if (*param_2 == 0) {
      return;
    }
    if (param_2[1] == 0) {
      return;
    }
    if (param_1[0x33fa] != 0x11) {
      param_1[0x1e6d] = *param_2;
      param_1[0x1e6e] = param_2[1];
      param_1[0xeea] = (int)(param_1 + 0x1e6d);
                    /* WARNING: Could not recover jumptable at 0x00017f02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x394))();
      return;
    }
  }
  param_1[0x1e6d] = param_1[0x1e6b];
  param_1[0x1e6e] = param_1[0x1e6c];
  param_1[0xeea] = (int)(param_1 + 0x1e6d);
                    /* WARNING: Could not recover jumptable at 0x00017f40. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + 0x394))();
  return;
}

