/* 0006fe00 StepSeq_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void StepSeq_c_vslot_0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  *param_1 = &PTR_StepSeq_c_vslot_0_000f10a8;
  NoteC_c_vslot_0(param_1 + 0x1d9);
  if ((param_1 != (undefined4 *)0xfffffce8) && (param_1 + 0xc6 != param_1 + 0x1a6)) {
    iVar2 = 0x20;
    puVar1 = param_1 + 0x1a6;
    do {
      NoteC_c_vslot_0(puVar1 + -5);
      iVar2 = iVar2 + -1;
      puVar1 = puVar1 + -7;
    } while (iVar2 != 0);
  }
  NoteC_c_vslot_0(param_1 + 0x7d);
  FUN_00013fc0();
  return;
}

