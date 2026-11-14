/* 000845f6 FUN_000845f6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000845f6(undefined4 *param_1)

{
  int iVar1;
  
  FUN_0000fd04(param_1);
  *param_1 = &PTR_AdvLFO_c_vslot_0_000f26e8;
  FUN_0003d2d6(param_1 + 0x7f);
  FUN_00084e24(param_1 + 0x268);
  Envelope_c_vslot_56(param_1 + 0x7f,param_1 + 0x34a,param_1 + 0x34b,param_1 + 0x349);
  Envelope_c_vslot_56(param_1 + 0x268,param_1 + 0x34d,param_1 + 0x34e,param_1 + 0x34c);
  iVar1 = param_1[0x34c];
  if ((int)param_1[0x349] < (int)param_1[0x34c]) {
    iVar1 = param_1[0x349];
  }
  param_1[0x34f] = iVar1;
  return;
}

