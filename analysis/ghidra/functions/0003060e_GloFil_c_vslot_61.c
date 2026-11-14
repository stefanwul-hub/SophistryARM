/* 0003060e GloFil_c_vslot_61 */

/* WARNING: Function: __i686.get_pc_thunk.cx replaced with injection: get_pc_thunk_cx */

longdouble GloFil_c_vslot_61(int param_1)

{
  float fVar1;
  float fVar2;
  
  fVar2 = 0.0;
  if (*(int *)(param_1 + 0x124) != 0) {
    fVar1 = *(float *)(*(int *)(param_1 + 0x124) + 0x2ac);
    if (0.955 < fVar1) {
      fVar2 = (fVar1 - 0.94) * 100.0 * 100.0 * (fVar1 - 0.94) + 0.1;
    }
    else {
      fVar2 = 0.1;
    }
    if (0.995 < fVar1) {
      fVar2 = 3600.0;
    }
  }
  return (longdouble)fVar2;
}

