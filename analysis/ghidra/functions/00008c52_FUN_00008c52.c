/* 00008c52 FUN_00008c52 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00008c52(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6,int param_7)

{
  undefined4 uVar1;
  
  FUN_000021e2(param_1,param_3,param_4,param_5);
  *param_1 = &PTR_CSliderPl_vslot_0_000e6228;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  if ((param_6 != 0) && (param_7 != 0)) {
    uVar1 = *param_2;
    param_1[0x30] = uVar1;
    param_1[0x31] = param_2[1];
    param_1[0x32] = param_2[2];
    param_1[0x33] = param_2[3];
    param_1[0x2c] = uVar1;
    param_1[0x2d] = param_1[0x31];
    param_1[0x2e] = param_1[0x32];
    param_1[0x2f] = param_1[0x33];
    param_1[0x34] = param_6;
    param_1[0x37] = *(undefined4 *)(param_6 + 0xc);
    param_1[0x38] = *(undefined4 *)(param_6 + 0x10);
    param_1[0x35] = param_7;
    *(bool *)(param_1 + 0x36) = (int)(param_1[5] - param_1[3]) < (int)(param_1[4] - param_1[2]);
    CControlPl_vslot_77(param_1,4);
  }
  return;
}

