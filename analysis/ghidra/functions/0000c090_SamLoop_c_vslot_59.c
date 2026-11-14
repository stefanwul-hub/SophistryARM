/* 0000c090 SamLoop_c_vslot_59 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool SamLoop_c_vslot_59(int *param_1,undefined4 param_2)

{
  byte bVar1;
  
  if (0.001 < (float)param_1[0x79]) {
    bVar1 = (**(code **)(*param_1 + 0xf0))(param_1,param_2,param_1[0x79]);
    return (bVar1 & *(byte *)(param_1 + 0x7d)) != 0;
  }
  param_1[0x7a] = 0x3f800000;
  bVar1 = (**(code **)(*param_1 + 0xf4))(param_1,param_2,0);
  return (bVar1 & *(byte *)(param_1 + 0x7d)) != 0;
}

