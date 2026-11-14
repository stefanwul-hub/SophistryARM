/* 00094cea FUN_00094cea */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00094cea(undefined4 *param_1)

{
  *param_1 = &PTR_AudioEffect_vslot_0_000f3628;
  if ((int *)param_1[2] != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00094d0f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)param_1[2] + 4))();
    return;
  }
  return;
}

