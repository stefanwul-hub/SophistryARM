/* 000071aa FUN_000071aa */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000071aa(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6,undefined1 param_7,int param_8,undefined4 param_9,
                 undefined4 param_10,char param_11)

{
  FUN_0009c638(param_1,param_2,param_3,param_4,param_8,param_9,param_10);
  *param_1 = &PTR_CMenuBase_vslot_0_000e53e8;
  param_1[0x39] = 0;
  if (param_8 == 0) {
    *(undefined1 *)((int)param_1 + 0x32) = 1;
  }
  *param_1 = &PTR_CMenuSimple_vslot_0_000e56e8;
  *(undefined1 *)(param_1 + 0x3b) = param_7;
  if (param_5 != 0) {
    param_1[0x3a] = param_5;
    CMenuFileList_vslot_64(param_1,4);
    CMenuFileList_vslot_65(param_1,param_6);
    if (param_11 != '\0') {
      CMenuSimple_vslot_96(param_1);
      return;
    }
  }
  return;
}

