/* 000c09f4 CControlPl_vslot_43 */

void CControlPl_vslot_43(int param_1)

{
  if (*(int **)(param_1 + 0x28) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x000c0a0d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x28) + 0x104))();
    return;
  }
  return;
}

