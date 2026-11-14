/* 000c307a LPAUOutputElement_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void LPAUOutputElement_vslot_1(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = PTR_DAT_0010387c + 8;
  FUN_000ae638(param_1 + 0x1e);
  *param_1 = PTR_DAT_00103874 + 8;
  *param_1 = PTR_DAT_00103870 + 8;
  FUN_000ae4de(param_1 + 0x17);
  *param_1 = PTR_DAT_00103878 + 8;
  if (param_1[0xc] != 0) {
    _CFRelease(param_1[0xc]);
  }
  for (iVar1 = param_1[9]; param_1[10] != iVar1; iVar1 = iVar1 + 0x18) {
  }
  if ((void *)param_1[9] != (void *)0x0) {
    operator_delete((void *)param_1[9]);
  }
  FUN_000c2d68(param_1 + 2,param_1[4]);
  operator_delete(param_1);
  return;
}

