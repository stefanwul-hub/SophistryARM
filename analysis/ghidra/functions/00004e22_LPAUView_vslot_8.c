/* 00004e22 LPAUView_vslot_8 */

void LPAUView_vslot_8(int param_1)

{
  if (*(int **)(param_1 + 0x58) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00004e3b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x58) + 0xbc))();
    return;
  }
  return;
}

