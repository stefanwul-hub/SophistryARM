/* 00013fc0 FUN_00013fc0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00013fc0(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = &PTR_Part_c_vslot_0_000e6be8;
  if ((*(char *)(param_1 + 0x5c) != '\0') && (piVar1 = (int *)param_1[0x48], piVar1 != (int *)0x0))
  {
    (**(code **)(*piVar1 + 4))(piVar1);
    param_1[0x48] = 0;
  }
  if ((void *)param_1[1] != (void *)0x0) {
    _free((void *)param_1[1]);
  }
  param_1[1] = 0;
  OsLib_c_vslot_0(param_1 + 0x5a);
  param_1[0x4b] = PTR_DAT_00103808 + 8;
  return;
}

