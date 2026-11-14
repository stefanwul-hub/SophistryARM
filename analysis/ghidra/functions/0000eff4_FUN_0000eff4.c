/* 0000eff4 FUN_0000eff4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0000eff4(undefined4 *param_1)

{
  int iVar1;
  
  FUN_0000fd04(param_1);
  *param_1 = &PTR_Envelope_c_vslot_0_000e68a8;
  param_1[0xdf] = 0;
  iVar1 = 0;
  do {
    param_1[iVar1 * 3 + 0x7f] = 0;
    param_1[param_1[0xdf] * 3 + 0x81] = 0;
    param_1[param_1[0xdf] * 3 + 0x80] = 0;
    iVar1 = param_1[0xdf] + 1;
    param_1[0xdf] = iVar1;
  } while (iVar1 < 0x20);
  param_1[0xdf] = 0;
  param_1[0xe0] = 0;
  return;
}

