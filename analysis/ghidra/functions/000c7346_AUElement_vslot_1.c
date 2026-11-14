/* 000c7346 AUElement_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void AUElement_vslot_1(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &PTR_AUElement_vslot_0_000f4628;
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

