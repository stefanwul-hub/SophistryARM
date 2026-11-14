/* 00043de6 CrushX_c_vslot_40 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CrushX_c_vslot_40(int param_1,float param_2)

{
  longdouble lVar1;
  float fVar2;
  
  if (0.0 < param_2) {
    fVar2 = 44100.0 / param_2;
    *(float *)(param_1 + 0x204) = fVar2;
    if ((0.1 <= fVar2) || (NAN(fVar2))) {
      fVar2 = (float)(~-(uint)(fVar2 <= 1.0) & (uint)1.0 | (uint)fVar2 & -(uint)(fVar2 <= 1.0));
    }
    else {
      fVar2 = 0.1;
    }
    *(float *)(param_1 + 0x204) = fVar2;
    lVar1 = (longdouble)_pow(0,0x3fe00000,1.0 / ((double)param_2 * 0.2 * 0.125),param_2);
    *(float *)(param_1 + 0x1fc) = (float)lVar1;
    Part_c_vslot_40();
    return;
  }
  return;
}

