/* 0001935a Synth_vslot_212 */

void Synth_vslot_212(int param_1)

{
  if (*(int **)(param_1 + 8) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00019370. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 8) + 0x7c))();
    return;
  }
  return;
}

