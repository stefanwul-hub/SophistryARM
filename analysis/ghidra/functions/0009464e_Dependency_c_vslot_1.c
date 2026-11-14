/* 0009464e Dependency_c_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Dependency_c_vslot_1(undefined4 *param_1)

{
  *param_1 = &PTR_Dependency_c_vslot_0_000f34a8;
  if ((void *)param_1[1] != (void *)0x0) {
    _free((void *)param_1[1]);
  }
  param_1[1] = 0;
  if ((void *)param_1[2] != (void *)0x0) {
    _free((void *)param_1[2]);
  }
  param_1[2] = 0;
  operator_delete(param_1);
  return;
}

