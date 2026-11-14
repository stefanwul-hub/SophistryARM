/* 000c66d8 AUOutputElement_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void AUOutputElement_vslot_0(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &PTR_AUOutputElement_vslot_0_000f45c8;
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
  return;
}

