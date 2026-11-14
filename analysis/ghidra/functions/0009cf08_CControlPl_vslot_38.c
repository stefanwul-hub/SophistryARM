/* 0009cf08 CControlPl_vslot_38 */

void CControlPl_vslot_38(int param_1)

{
  if (*(int **)(param_1 + 0x2c) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0009cf29. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x2c) + 0x98))();
    return;
  }
  if (*(int **)(param_1 + 0x28) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0009cf42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x28) + 0x14))();
    return;
  }
  return;
}

