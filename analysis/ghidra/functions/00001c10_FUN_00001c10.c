/* 00001c10 FUN_00001c10 */

void FUN_00001c10(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x00001c25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x28) + 0x130))();
  return;
}

