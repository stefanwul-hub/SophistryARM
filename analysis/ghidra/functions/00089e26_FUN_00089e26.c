/* 00089e26 FUN_00089e26 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00089e26(undefined4 *param_1)

{
  int iVar1;
  
  *param_1 = &PTR_NRPN_c_vslot_0_000f2d88;
  FUN_0002e178(param_1 + 0x41);
  iVar1 = 0x10;
  do {
    param_1[1] = 0xffffffff;
    param_1[0x11] = 0xffffffff;
    param_1[0x21] = 0xffffffff;
    param_1[0x31] = 0;
    param_1 = param_1 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

