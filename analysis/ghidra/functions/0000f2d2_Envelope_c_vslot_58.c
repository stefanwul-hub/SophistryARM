/* 0000f2d2 Envelope_c_vslot_58 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Envelope_c_vslot_58(int param_1,float *param_2,int param_3)

{
  float fVar1;
  float fVar2;
  
  fVar2 = *(float *)(param_1 + 0x174 + param_3 * 4) * 0.5;
  if ((-1.0 <= fVar2) || (NAN(fVar2))) {
    if (1.0 < fVar2) {
      fVar2 = -1.0;
    }
    else {
      fVar2 = -fVar2;
    }
  }
  else {
    fVar2 = 1.0;
  }
  fVar2 = fVar2 * fVar2 * fVar2 * 0.05362607 + fVar2 * fVar2 * 0.24807328 + fVar2 * 0.69521874 + 1.0
  ;
  fVar2 = *param_2 * fVar2 * fVar2 * fVar2 * fVar2;
  fVar1 = 0.0;
  if (0.0 <= fVar2) {
    fVar1 = fVar2;
  }
  *param_2 = fVar1;
  return;
}

