/* 00012e20 Envelope_c_vslot_44 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Envelope_c_vslot_44(int param_1,float *param_2,float param_3)

{
  float fVar1;
  longdouble lVar2;
  float fVar3;
  
  if (param_3 <= 0.0) {
    lVar2 = (longdouble)FUN_000152c0(*param_2,1.0 - param_3 * (*(float *)(param_1 + 0x164) - 1.0));
    *param_2 = (float)lVar2;
    fVar3 = *param_2;
  }
  else {
    fVar3 = (param_3 * (*(float *)(param_1 + 0x164) - 1.0) + 1.0) * *param_2;
    *param_2 = fVar3;
  }
  if (0.0 <= fVar3) {
    fVar1 = 1e+09;
    if (fVar3 <= 1e+09) {
      fVar1 = fVar3;
    }
    *param_2 = fVar1;
    return;
  }
  *param_2 = 0.0;
  return;
}

