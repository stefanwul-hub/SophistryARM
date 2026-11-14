/* 00005f56 FUN_00005f56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00005f56(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined1 local_34;
  undefined1 local_30;
  
  FUN_000021e2(param_1,param_2,param_3,param_4);
  *param_1 = &PTR_CLabelPl_vslot_0_000e5108;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x2d] = param_5;
  param_1[0x32] = param_6;
  *(char *)(param_1 + 0x22) = (char)param_7;
  *(char *)((int)param_1 + 0x89) = (char)((uint)param_7 >> 8);
  local_34 = (undefined1)((uint)param_7 >> 0x10);
  *(undefined1 *)((int)param_1 + 0x8a) = local_34;
  local_30 = (undefined1)((uint)param_7 >> 0x18);
  *(undefined1 *)((int)param_1 + 0x8b) = local_30;
  param_1[0x33] = param_8;
  *(undefined1 *)((int)param_1 + 0x31) = 0;
  param_1[0x34] = param_1[2];
  param_1[0x35] = param_1[3];
  *(undefined1 *)(param_1 + 0x1c) = 1;
  param_1[0x2c] = 0;
  return;
}

