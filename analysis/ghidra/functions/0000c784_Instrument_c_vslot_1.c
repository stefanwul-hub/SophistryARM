/* 0000c784 Instrument_c_vslot_1 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Instrument_c_vslot_1(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int local_20;
  
  *param_1 = &PTR_Instrument_c_vslot_0_000e67c8;
  if ((void *)param_1[0x6b] != (void *)0x0) {
    _free((void *)param_1[0x6b]);
  }
  param_1[0x6b] = 0;
  if ((param_1 != (undefined4 *)0xffffef2c) && (puVar2 = param_1 + 0x6b5, param_1 + 0x435 != puVar2)
     ) {
    puVar1 = param_1 + 0x6b0;
    local_20 = 0x80;
    do {
      puVar2 = puVar2 + -5;
      (**(code **)*puVar1)(puVar2);
      puVar1 = puVar1 + -5;
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  Lock_c_vslot_0(param_1 + 0x3a1);
  Lock_c_vslot_0(param_1 + 0x394);
  Lock_c_vslot_0(param_1 + 0x387);
  FUN_000143c8(param_1);
  operator_delete(param_1);
  return;
}

