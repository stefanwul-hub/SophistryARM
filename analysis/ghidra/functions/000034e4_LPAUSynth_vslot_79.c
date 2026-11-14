/* 000034e4 LPAUSynth_vslot_79 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 LPAUSynth_vslot_79(int param_1)

{
  undefined4 *puVar1;
  
  if (*(int *)(param_1 + 0x32b428) != 0) {
    return *(undefined4 *)(param_1 + 0x32b428);
  }
  puVar1 = (undefined4 *)operator_new(0x279cc);
  FUN_00055064(puVar1,param_1 + 0xec);
  *puVar1 = PTR_DAT_001037f0 + 8;
  puVar1[8] = PTR_DAT_001037f0 + 0xd0;
  puVar1[0x9e71] = 0;
  puVar1[0x9e72] = 0;
  *(undefined4 **)(param_1 + 0x32b428) = puVar1;
  _OSAtomicAdd32Barrier(1,puVar1 + 0x9e72);
  *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(param_1 + 0x32b428);
  return *(undefined4 *)(param_1 + 0x32b428);
}

