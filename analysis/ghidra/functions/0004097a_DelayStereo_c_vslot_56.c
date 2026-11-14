/* 0004097a DelayStereo_c_vslot_56 */

void DelayStereo_c_vslot_56(int param_1,undefined4 param_2)

{
  if (*(char *)(param_1 + 0x15c) == '\0') {
    return;
  }
  (**(code **)(**(int **)(param_1 + 0x118) + 0x2c))
            (*(int **)(param_1 + 0x118),param_1 + 0x23c,param_1 + 0x240);
  (**(code **)(**(int **)(param_1 + 0x10) + 0x38))
            (*(int **)(param_1 + 0x10),param_1 + 0x244,param_1 + 0x248);
  if (*(char *)(param_1 + 0x270) != '\0') {
    if (*(char *)(param_1 + 0x271) == '\0') {
      FUN_00040484(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x00040a0b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
      return;
    }
    FUN_0003fb02(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x00040a7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
    return;
  }
  if (*(char *)(param_1 + 0x271) != '\0') {
    FUN_0003ffb6(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x00040a36. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
    return;
  }
  FUN_0003f2f6(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x00040a58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
  return;
}

