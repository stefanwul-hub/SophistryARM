/* 0001f704 Synth_vslot_179 */

void Synth_vslot_179(int *param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  
  FUN_0001f38e(param_1,param_3,param_3);
  (**(code **)(*param_1 + 0x314))(param_1,param_3);
  (**(code **)(*param_1 + 0x354))(param_1,1);
  (**(code **)(*param_1 + 0x360))(param_1,param_2);
  if (*(char *)((int)param_1 + 0xcfda) != '\0') {
    (**(code **)(*param_1 + 0x350))(param_1);
    if (param_1[0x33fa] != 0) {
      (**(code **)(*param_1 + 700))(param_1);
    }
  }
  piVar1 = *(int **)(param_1[0x33a9] + param_2 * 4);
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001f78a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0x4c))();
    return;
  }
  return;
}

