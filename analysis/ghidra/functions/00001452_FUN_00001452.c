/* 00001452 FUN_00001452 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00001452(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = &PTR_CControlPl_vslot_0_000e4648;
  if ((void *)param_1[0x24] != (void *)0x0) {
    _free((void *)param_1[0x24]);
  }
  param_1[0x24] = 0;
  puVar1 = (undefined4 *)param_1[0x21];
  if (puVar1 != param_1 + 0x26) {
    if (puVar1 != (undefined4 *)0x0) {
      _free(puVar1);
    }
    param_1[0x21] = 0;
  }
  OsLib_c_vslot_0(param_1 + 0x23);
  FUN_00097280();
  return;
}

