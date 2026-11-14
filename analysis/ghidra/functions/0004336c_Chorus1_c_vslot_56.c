/* 0004336c Chorus1_c_vslot_56 */

void Chorus1_c_vslot_56(int param_1,undefined4 param_2)

{
  int *piVar1;
  
  if ((*(char *)(param_1 + 0x15c) == '\0') || (*(int *)(param_1 + 0x124) == 0)) {
    return;
  }
  piVar1 = *(int **)(param_1 + 0x10);
  if (*(char *)((int)piVar1 + 0x27) != '\0') {
    (**(code **)(*piVar1 + 0x38))(piVar1,param_1 + 0x20fc,param_1 + 0x2100);
    (**(code **)(**(int **)(param_1 + 0x118) + 0x2c))
              (*(int **)(param_1 + 0x118),param_1 + 0x2104,param_1 + 0x2108);
    if (*(int *)(*(int *)(param_1 + 0x124) + 0x318) != 0) {
      FUN_00042b6e(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x0004347e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
      return;
    }
    FUN_000419fa(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x000434c9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
    return;
  }
  (**(code **)(*piVar1 + 0x34))(piVar1,param_1 + 0x20fc,0);
  (**(code **)(**(int **)(param_1 + 0x118) + 0x2c))
            (*(int **)(param_1 + 0x118),param_1 + 0x2104,param_1 + 0x2108);
  if (*(int *)(*(int *)(param_1 + 0x124) + 0x318) == 0) {
    FUN_000426a4(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x0004340e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
    return;
  }
  FUN_00041f38(param_1,param_2);
                    /* WARNING: Could not recover jumptable at 0x000434a7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(param_1 + 0x118) + 0x44))();
  return;
}

