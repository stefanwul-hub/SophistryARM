/* 0007318c ChordMem_c_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void ChordMem_c_vslot_1(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int local_20;
  
  *param_1 = &PTR_ChordMem_c_vslot_0_000f1308;
  if ((param_1 != (undefined4 *)0xfffffe1c) && (puVar2 = param_1 + 0x2f9, param_1 + 0x79 != puVar2))
  {
    puVar1 = param_1 + 0x2f4;
    local_20 = 0x80;
    do {
      puVar2 = puVar2 + -5;
      (**(code **)*puVar1)(puVar2);
      puVar1 = puVar1 + -5;
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  FUN_00013fc0(param_1);
  operator_delete(param_1);
  return;
}

