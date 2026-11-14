/* 000ac698 FUN_000ac698 */

void FUN_000ac698(undefined4 param_1,int *param_2)

{
  param_1 = param_2;
                    /* WARNING: Could not recover jumptable at 0x000ac6ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_2 + 0x18))();
  return;
}

