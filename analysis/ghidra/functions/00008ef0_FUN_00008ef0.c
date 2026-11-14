/* 00008ef0 FUN_00008ef0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00008ef0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined1 param_9)

{
  FUN_000021e2(param_1,param_2,param_3,param_4);
  *param_1 = &PTR_CTouchAreaPl_vslot_0_000e6388;
  param_1[0x2c] = param_5;
  param_1[0x2d] = param_6;
  param_1[0x2e] = param_7;
  param_1[0x2f] = param_8;
  param_1[0x30] = 0xffffffff;
  param_1[0x31] = 0xffffffff;
  param_1[0x32] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x33) = param_9;
  return;
}

