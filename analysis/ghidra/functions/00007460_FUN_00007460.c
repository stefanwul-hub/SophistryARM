/* 00007460 FUN_00007460 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00007460(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined1 param_10)

{
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_2c = *param_2;
  local_28 = param_2[1];
  local_24 = param_2[2];
  local_20 = param_2[3];
  FUN_00005886(param_1,&local_2c,param_3,param_4,param_5,param_6,param_8,param_9);
  *param_1 = &PTR_CMIKnob_vslot_0_000e5a48;
  *(undefined1 *)(param_1 + 0x37) = param_10;
  param_1[0x38] = param_7;
  return;
}

