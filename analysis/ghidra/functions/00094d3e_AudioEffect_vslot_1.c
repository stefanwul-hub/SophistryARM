/* 00094d3e AudioEffect_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void AudioEffect_vslot_1(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_AudioEffect_vslot_0_000f3628;
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  operator_delete(param_1);
  return;
}

