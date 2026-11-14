/* 000086fc FUN_000086fc */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000086fc(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,uint param_6,undefined1 param_7,undefined4 param_8,
                 undefined1 param_9)

{
  FUN_000021e2(param_1,param_2,param_3,param_4);
  *param_1 = &PTR_CRadioButtonPl_vslot_0_000e60c8;
  param_1[0x2c] = param_8;
  param_1[0x2d] = param_5;
  *(byte *)((int)param_1 + 0xbf) = (byte)(param_6 >> 0x1f);
  if (0x7fffffff < param_6) {
    param_6 = -param_6;
  }
  param_1[0x2e] = param_6;
  *(undefined1 *)(param_1 + 0x2f) = param_7;
  param_1[0x30] = (int)(param_1[4] - param_1[2]) / (int)param_1[0x2d];
  param_1[0x31] = (int)(param_1[5] - param_1[3]) / (int)param_1[0x2e];
  *(undefined1 *)((int)param_1 + 0xbd) = param_9;
  *(undefined1 *)((int)param_1 + 0xbe) = 0;
  CControlPl_vslot_77(param_1,7);
  return;
}

