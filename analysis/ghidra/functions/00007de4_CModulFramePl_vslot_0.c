/* 00007de4 CModulFramePl_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CModulFramePl_vslot_0(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_CModulFramePl_vslot_0_000e5d08;
  piVar1 = (int *)param_1[0x12];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  param_1[0x12] = 0;
  FUN_000a3c6a();
  return;
}

