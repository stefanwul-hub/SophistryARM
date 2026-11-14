/* 00009542 FUN_00009542 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00009542(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  undefined *puVar1;
  
  FUN_000021e2(param_1,param_2,param_3,param_4);
  *param_1 = &PTR_CVarDisplay_vslot_0_000e64e8;
  param_1[0x2c] = param_5;
  param_1[0x37] = param_12;
  param_1[0x36] = param_11;
  param_1[0x35] = param_10;
  param_1[0x34] = param_9;
  param_1[0x33] = param_8;
  param_1[0x32] = param_7;
  param_1[0x31] = param_6;
  *(undefined1 *)((int)param_1 + 0x6d) = 0;
  *(undefined1 *)(param_1 + 0x1b) = 0;
  puVar1 = PTR_DAT_00103804;
  *(undefined *)(param_1 + 0x2f) = *PTR_DAT_00103804;
  *(undefined *)((int)param_1 + 0xbd) = puVar1[1];
  *(undefined *)((int)param_1 + 0xbe) = puVar1[2];
  *(undefined *)((int)param_1 + 0xbf) = puVar1[3];
  puVar1 = PTR_DAT_00103800;
  *(undefined *)(param_1 + 0x22) = *PTR_DAT_00103800;
  *(undefined *)((int)param_1 + 0x89) = puVar1[1];
  *(undefined *)((int)param_1 + 0x8a) = puVar1[2];
  *(undefined *)((int)param_1 + 0x8b) = puVar1[3];
  param_1[0x38] = *param_2;
  param_1[0x39] = param_2[1];
  *(undefined1 *)(param_1 + 0x1c) = 1;
  CControlPl_vslot_77(param_1,0xb);
  return;
}

