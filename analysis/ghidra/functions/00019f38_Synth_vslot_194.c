/* 00019f38 Synth_vslot_194 */

void Synth_vslot_194(int *param_1)

{
  if ((-1 < param_1[0xeda]) && (-1 < param_1[0xee0])) {
    if (0 < param_1[0xedb]) {
                    /* WARNING: Could not recover jumptable at 0x00019f68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*param_1 + 0x310))();
      return;
    }
                    /* WARNING: Could not recover jumptable at 0x00019f7b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x30c))();
    return;
  }
  return;
}

