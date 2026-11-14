/* 000083da FUN_000083da */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000083da(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10)

{
  undefined4 uVar1;
  undefined1 local_34;
  undefined1 local_30;
  
  FUN_000021e2(param_1,param_2,param_3,param_4);
  *param_1 = &PTR_CPlusMinusDisplay_vslot_0_000e5f68;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  param_1[0x36] = 0;
  param_1[0x37] = 0;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  uVar1 = *param_5;
  param_1[0x30] = uVar1;
  param_1[0x31] = param_5[1];
  param_1[0x32] = param_5[2];
  param_1[0x33] = param_5[3];
  param_1[0x2c] = uVar1;
  param_1[0x2d] = param_1[0x31];
  param_1[0x2e] = param_1[0x32];
  param_1[0x2f] = param_1[0x33];
  param_1[0x34] = *param_6;
  param_1[0x35] = param_6[1];
  param_1[0x36] = param_6[2];
  param_1[0x37] = param_6[3];
  param_1[0x38] = *param_7;
  param_1[0x39] = param_7[1];
  param_1[0x3a] = param_7[2];
  param_1[0x3b] = param_7[3];
  param_1[0x3c] = param_8;
  param_1[0x3d] = param_9;
  *(undefined1 *)(param_1 + 0x22) = (undefined1)param_10;
  *(char *)((int)param_1 + 0x89) = (char)((uint)param_10 >> 8);
  local_34 = (undefined1)((uint)param_10 >> 0x10);
  *(undefined1 *)((int)param_1 + 0x8a) = local_34;
  local_30 = (undefined1)((uint)param_10 >> 0x18);
  *(undefined1 *)((int)param_1 + 0x8b) = local_30;
  *(undefined1 *)(param_1 + 0x1c) = 1;
  CControlPl_vslot_77(param_1,0xc);
  return;
}

