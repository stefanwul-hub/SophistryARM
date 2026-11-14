/* 0000c1dc SamLoop_c_vslot_60 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined1 SamLoop_c_vslot_60(int *param_1,undefined4 param_2,float param_3)

{
  undefined1 uVar1;
  
  param_1[0x7a] = 0x3f800000;
  (**(code **)(*param_1 + 0xf4))(param_1,param_2,0);
  param_1[0x7a] = (int)(param_3 * 0.0011 + 1.0);
  uVar1 = (**(code **)(*param_1 + 0xf4))(param_1,param_2,1);
  param_1[0x7a] = (int)(param_3 * -0.00117 + 1.0);
  (**(code **)(*param_1 + 0xf4))(param_1,param_2,2);
  if (param_1[0x76] != 5) {
    param_1[0x7a] = 0x3f800000;
    return uVar1;
  }
  param_1[0x7a] = (int)(param_3 * -0.00056 + 1.0);
  (**(code **)(*param_1 + 0xf4))(param_1,param_2,3);
  param_1[0x7a] = (int)(param_3 * 0.0006 + 1.0);
  (**(code **)(*param_1 + 0xf4))(param_1,param_2,4);
  param_1[0x7a] = 0x3f800000;
  return uVar1;
}

