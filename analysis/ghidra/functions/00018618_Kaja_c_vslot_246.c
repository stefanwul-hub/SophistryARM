/* 00018618 Kaja_c_vslot_246 */

void Kaja_c_vslot_246(int param_1)

{
  if (*(int **)(param_1 + 0x36bc) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00018634. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x36bc) + 0xe8))();
    return;
  }
  return;
}

