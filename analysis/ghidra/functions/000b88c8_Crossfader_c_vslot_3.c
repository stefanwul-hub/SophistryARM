/* 000b88c8 Crossfader_c_vslot_3 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Crossfader_c_vslot_3(int param_1,undefined4 param_2)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)FUN_000152c0(0x3f800000,param_2);
  *(float *)(param_1 + 4) = (float)lVar1;
  *(float *)(param_1 + 0x1c) = (float)lVar1 * -1000.0;
  return;
}

