/* 00032500 FUN_00032500 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00032500(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int param_6)

{
  void *pvVar1;
  
  FUN_000021e2(param_1,param_2,param_3,param_4);
  *param_1 = &PTR_COnOffBar_vslot_0_000e80e8;
  param_1[0x2c] = param_5;
  param_1[0x2d] = param_6;
  param_1[0x2e] = (param_2[2] - *param_2) / param_6;
  CControlPl_vslot_77(param_1,6);
  *(undefined1 *)((int)param_1 + 0x6e) = 1;
  pvVar1 = _malloc(param_6 + 2);
  param_1[0x2f] = pvVar1;
  return;
}

