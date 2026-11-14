/* 0008b3f4 ECS2_c_vslot_0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void ECS2_c_vslot_0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_28;
  int local_20;
  
  *param_1 = &PTR_ECS2_c_vslot_0_000f2f28;
  puVar3 = param_1 + 0x64e;
  if ((puVar3 != (undefined4 *)0x0) && (puVar2 = param_1 + 0xbce, puVar3 != puVar2)) {
    puVar1 = param_1 + 0xbc3;
    local_28 = 0x80;
    do {
      puVar2 = puVar2 + -0xb;
      (**(code **)*puVar1)(puVar2);
      puVar1 = puVar1 + -0xb;
      local_28 = local_28 + -1;
    } while (local_28 != 0);
  }
  if ((param_1 != (undefined4 *)0xfffffcc8) && (param_1 + 0xce != puVar3)) {
    param_1 = param_1 + 0x643;
    local_20 = 0x80;
    do {
      puVar3 = puVar3 + -0xb;
      (**(code **)*param_1)(puVar3);
      param_1 = param_1 + -0xb;
      local_20 = local_20 + -1;
    } while (local_20 != 0);
  }
  FUN_00013fc0();
  return;
}

