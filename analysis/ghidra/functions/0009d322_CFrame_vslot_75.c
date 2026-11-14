/* 0009d322 CFrame_vslot_75 */

void CFrame_vslot_75(int param_1)

{
  if (*(int **)(param_1 + 0x60) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0009d338. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x60) + 0x48))();
    return;
  }
  return;
}

