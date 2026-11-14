/* 000813ba FUN_000813ba */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000813ba(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int iVar1;
  
  FUN_000023ba(param_1,param_2,param_3,param_4,6);
  *param_1 = &PTR_CSampleDisplayKj_c_vslot_0_000f1ee8;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x33] = param_5;
  param_1[0x32] = 0;
  param_1[0x35] = 0;
  param_1[0x34] = 0;
  param_1[0x2c] = param_2[2] - *param_2;
  iVar1 = param_2[1];
  param_1[0x2d] = *param_2;
  param_1[0x2e] = iVar1;
  *(undefined1 *)(param_1 + 0x36) = 0;
  param_1[0x37] = 0x472c4400;
  param_1[0x38] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  return;
}

