/* 00007d88 FUN_00007d88 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00007d88(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  local_1c = param_2;
  local_18 = param_3;
  local_14 = param_2 + param_4;
  local_10 = param_3 + param_5;
  FUN_000a37c0(param_1,&local_1c,param_6,param_7);
  *param_1 = &PTR_CModulFramePl_vslot_0_000e5d08;
  param_1[0x18] = 0;
  return;
}

