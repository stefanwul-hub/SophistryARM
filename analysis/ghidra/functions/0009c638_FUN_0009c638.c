/* 0009c638 FUN_0009c638 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0009c638(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int *param_6,undefined4 param_7)

{
  FUN_0009c4e8(param_1,param_2,param_5,param_7);
  *param_1 = &PTR_COptionMenu_vslot_0_000f3d48;
  param_1[0x30] = param_6;
  param_1[0x32] = 0xffffffff;
  param_1[0x36] = 0;
  param_1[0x38] = 0;
  param_1[0xf] = param_3;
  param_1[0x10] = param_4;
  param_1[0x2d] = 0;
  param_1[0x2e] = 0;
  param_1[0x2f] = 0xffffffff;
  param_1[0x31] = 4;
  param_1[0x28] = 0;
  param_1[0x35] = 0xffffffff;
  param_1[0x37] = 0;
  *(undefined2 *)(param_1 + 0x2c) = 0;
  if (param_6 != (int *)0x0) {
    (**(code **)(*param_6 + 0xc))(param_6);
  }
  param_1[0x33] = 0;
  param_1[0x34] = 0;
  param_1[0x2b] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  return;
}

