/* 000061da FUN_000061da */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000061da(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,int param_6,undefined4 param_7,int param_8,char *param_9)

{
  FUN_0009c638(param_1,param_2,param_3,param_4,param_5,0,0x400);
  *param_1 = &PTR_CMenuFileList_vslot_0_000e5268;
  if ((param_6 != 0) && (param_8 != 0)) {
    param_1[0x39] = param_6;
    param_1[0x3a] = param_7;
    param_1[0x3b] = param_8;
    _strcpy((char *)(param_1 + 0x3c),param_9);
    if (param_5 == 0) {
      *(undefined1 *)((int)param_1 + 0x32) = 1;
      return;
    }
  }
  return;
}

