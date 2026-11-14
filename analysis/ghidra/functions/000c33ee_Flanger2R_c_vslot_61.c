/* 000c33ee Flanger2R_c_vslot_61 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble Flanger2R_c_vslot_61(int param_1)

{
  longdouble lVar1;
  
  if (*(int *)(param_1 + 0x124) != 0) {
    lVar1 = (longdouble)_log10((double)*(float *)(*(int *)(param_1 + 0x124) + 0x23c) + 0.0001);
    lVar1 = (longdouble)FUN_00015302(0,0xc0140000,(double)lVar1);
    return (longdouble)((float)lVar1 * *(float *)(param_1 + 0x224) + 0.1);
  }
  return (longdouble)0.0;
}

