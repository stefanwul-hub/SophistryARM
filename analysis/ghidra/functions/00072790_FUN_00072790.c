/* 00072790 FUN_00072790 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00072790(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  longdouble lVar1;
  float fVar2;
  undefined1 local_34;
  undefined1 local_30;
  
  FUN_000023ba(param_1,param_2,param_3,param_4,2);
  *param_1 = &PTR_CXYPl_vslot_0_000f11a8;
  param_1[0x2c] = param_5;
  param_1[0x2d] = (float)(param_2[3] - param_2[1]) * 0.9999;
  fVar2 = (float)(param_2[2] - *param_2) * 0.9999;
  param_1[0x2e] = fVar2;
  lVar1 = (longdouble)FUN_000152c0(0x3f800000,fVar2);
  param_1[0x2f] = (float)lVar1;
  lVar1 = (longdouble)FUN_000152c0(0x3f800000,param_1[0x2d]);
  param_1[0x30] = (float)lVar1;
  *(undefined1 *)(param_1 + 0x31) = (undefined1)param_6;
  *(char *)((int)param_1 + 0xc5) = (char)((uint)param_6 >> 8);
  local_34 = (undefined1)((uint)param_6 >> 0x10);
  *(undefined1 *)((int)param_1 + 0xc6) = local_34;
  local_30 = (undefined1)((uint)param_6 >> 0x18);
  *(undefined1 *)((int)param_1 + 199) = local_30;
  CControlPl_vslot_77(param_1,0xe);
  return;
}

