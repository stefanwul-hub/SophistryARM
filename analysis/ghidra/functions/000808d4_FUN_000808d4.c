/* 000808d4 FUN_000808d4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000808d4(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7)

{
  int iVar1;
  
  FUN_000021e2(param_1,param_2,param_4,param_5);
  *param_1 = &PTR_CDrawbarPl_vslot_0_000f1c28;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  if ((param_6 != 0) && (param_7 != 0)) {
    param_1[0x2c] = *param_2;
    param_1[0x2d] = param_2[1];
    param_1[0x2e] = param_2[2];
    param_1[0x2f] = param_2[3];
    param_1[0x30] = *param_2;
    iVar1 = param_2[1];
    param_1[0x31] = iVar1;
    param_1[0x32] = param_2[2];
    param_1[0x33] = param_2[3] - param_3 / 2;
    param_1[0x31] = param_3 / 2 + iVar1;
    param_1[0x36] = param_3;
    param_1[0x34] = param_6;
    param_1[0x35] = param_7;
    CControlPl_vslot_77(param_1,4);
  }
  return;
}

