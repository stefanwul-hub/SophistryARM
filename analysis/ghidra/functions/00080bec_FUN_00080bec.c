/* 00080bec FUN_00080bec */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00080bec(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5
                 ,undefined4 param_6)

{
  int iVar1;
  
  FUN_000023ba(param_1,param_2,param_3,param_4,2);
  *param_1 = &PTR_CScrollbarPl_vslot_0_000f1d88;
  param_1[0x2c] = 0;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  param_1[0x32] = 0;
  param_1[0x33] = 0;
  if (param_5 != 0) {
    iVar1 = *param_2;
    param_1[0x30] = iVar1;
    param_1[0x31] = param_2[1];
    param_1[0x32] = param_2[2];
    param_1[0x33] = param_2[3];
    param_1[0x2c] = iVar1;
    param_1[0x2d] = param_1[0x31];
    param_1[0x2e] = param_1[0x32];
    param_1[0x2f] = param_1[0x33];
    param_1[0x34] = param_5;
    *(bool *)(param_1 + 0x35) = (int)(param_1[0x33] - param_1[0x31]) < param_1[0x32] - iVar1;
    param_1[0x36] = param_6;
  }
  return;
}

