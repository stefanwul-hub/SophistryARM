/* 00001ca6 FUN_00001ca6 */

void FUN_00001ca6(int param_1)

{
  (**(code **)(**(int **)(param_1 + 0x28) + 0x13c))(*(int **)(param_1 + 0x28),param_1);
                    /* WARNING: Could not recover jumptable at 0x00001cdd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x28) + 300))();
  return;
}

