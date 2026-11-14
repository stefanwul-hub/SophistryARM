/* 00094d14 AudioEffect_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void AudioEffect_vslot_0(undefined4 *param_1)

{
  *param_1 = &PTR_AudioEffect_vslot_0_000f3628;
  if ((int *)param_1[2] != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00094d39. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)param_1[2] + 4))();
    return;
  }
  return;
}

