/* 0009cfdc CControlPl_vslot_36 */

undefined4 CControlPl_vslot_36(int param_1)

{
  undefined4 uVar1;
  
  if (*(int **)(param_1 + 0x28) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0009cff5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(int **)(param_1 + 0x28) + 0x90))();
    return uVar1;
  }
  return 0;
}

