/* 000742fa Satur_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Satur_c_vslot_31(int param_1)

{
  longdouble lVar1;
  
  if (*(int *)(param_1 + 0x124) != 0) {
    lVar1 = (longdouble)_pow((double)*(float *)(*(int *)(param_1 + 0x124) + 0xec),0,0x3fe00000);
    *(float *)(param_1 + 0x1e0) = (float)lVar1;
    *(float *)(param_1 + 0x1e4) = 1.001 - (float)lVar1;
  }
  return;
}

