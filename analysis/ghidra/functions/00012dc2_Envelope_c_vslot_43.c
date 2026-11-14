/* 00012dc2 Envelope_c_vslot_43 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Envelope_c_vslot_43(int param_1,float *param_2,float param_3)

{
  longdouble lVar1;
  
  lVar1 = (longdouble)_pow(0,0x40000000,(double)(param_3 * *(float *)(param_1 + 0x160)) * 8.0);
  *param_2 = (float)lVar1 * *param_2;
  return;
}

