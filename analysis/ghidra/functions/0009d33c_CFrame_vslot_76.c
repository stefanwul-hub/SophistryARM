/* 0009d33c CFrame_vslot_76 */

void CFrame_vslot_76(int param_1)

{
  if (*(int **)(param_1 + 0x60) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0009d352. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x60) + 0x4c))();
    return;
  }
  return;
}

