/* 00004df4 FUN_00004df4 */

void FUN_00004df4(int *param_1)

{
  if (param_1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00004e19. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*param_1 + 0x2c))();
    return;
  }
  return;
}

