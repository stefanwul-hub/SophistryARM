/* 00083ab2 AUCronoX_vslot_46 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 * AUCronoX_vslot_46(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 != 2) {
    puVar1 = (undefined4 *)LPAUSynth_vslot_46();
    return puVar1;
  }
  puVar1 = (undefined4 *)operator_new(0x7c);
  FUN_000ab3e6(puVar1,param_1);
  *puVar1 = PTR_DAT_0010387c + 8;
  FUN_000ae670(puVar1 + 0x1e);
  iVar2 = AUOutputElement_vslot_3(puVar1,puVar1 + 0xd);
  if (iVar2 != 0) {
    return puVar1;
  }
  uVar3 = 0x790006;
  if (puVar1[0x14] != 6) {
    uVar3 = 0x650002;
  }
  FUN_000ae5a0(puVar1 + 0x1e,uVar3);
  return puVar1;
}

