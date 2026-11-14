/* 0009470c FUN_0009470c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0009470c(undefined4 *param_1,int param_2)

{
  void *pvVar1;
  
  *param_1 = &PTR_Dependency_c_vslot_0_000f34a8;
  param_1[3] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  if (0 < param_2) {
    param_1[3] = param_2;
    pvVar1 = _malloc(param_2 * 4 + 4);
    param_1[1] = pvVar1;
    pvVar1 = _malloc(param_1[3] * 4 + 4);
    param_1[2] = pvVar1;
  }
  return;
}

