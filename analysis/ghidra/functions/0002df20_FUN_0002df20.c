/* 0002df20 FUN_0002df20 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0002df20(undefined4 *param_1,int param_2,int param_3)

{
  void *pvVar1;
  
  *param_1 = &PTR_MemC_c_vslot_0_000e7b68;
  param_1[2] = param_2;
  if (param_3 == 0) {
    *(undefined1 *)(param_1 + 3) = 1;
    pvVar1 = _malloc(param_2 + 1);
    param_1[1] = pvVar1;
  }
  else {
    *(undefined1 *)(param_1 + 3) = 0;
    param_1[1] = param_3;
  }
  return;
}

