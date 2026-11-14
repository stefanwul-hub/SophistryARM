/* 000c1478 Envelope_c_vslot_26 */

void Envelope_c_vslot_26(int param_1)

{
  if (*(int **)(param_1 + 0x120) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000c149b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x120) + 0x14))();
    return;
  }
  return;
}

