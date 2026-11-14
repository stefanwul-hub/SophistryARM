/* 00040cbc FUN_00040cbc */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00040cbc(undefined4 *param_1)

{
  FUN_00031e98(param_1);
  *param_1 = &PTR_Chorus1_c_vslot_0_000e8ba8;
  FUN_0003d2d6(param_1 + 0x78);
  FUN_0003d2d6(param_1 + 0x261);
  FUN_0003d2d6(param_1 + 0x44a);
  FUN_0003d2d6(param_1 + 0x633);
  Envelope_c_vslot_56(param_1 + 0x78,param_1 + 0x81c,param_1 + 0x81d,param_1 + 0x822);
  Envelope_c_vslot_56(param_1 + 0x261,param_1 + 0x81e,param_1 + 0x81f,param_1 + 0x823);
  Envelope_c_vslot_56(param_1 + 0x44a,param_1 + 0x820,param_1 + 0x821,param_1 + 0x824);
  param_1[0x83f] = 0;
  param_1[0x840] = 0;
  param_1[0x841] = 0;
  param_1[0x842] = 0;
  param_1[0x83e] = 0;
  param_1[0x83b] = 0;
  param_1[0x83c] = 0;
  return;
}

