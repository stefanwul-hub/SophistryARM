/* 0007310e ChordMem_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void ChordMem_c_vslot_0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int local_20;
  
  *param_1 = &PTR_ChordMem_c_vslot_0_000f1308;
  if ((param_1 != (undefined4 *)0xfffffe1c) && (puVar1 = param_1 + 0x2f9, param_1 + 0x79 != puVar1))
  {
    param_1 = param_1 + 0x2f4;
    local_20 = 0x80;
    do {
      puVar1 = puVar1 + -5;
      (**(code **)*param_1)(puVar1);
      param_1 = param_1 + -5;
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  FUN_00013fc0();
  return;
}

