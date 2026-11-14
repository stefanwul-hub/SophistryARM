/* 00009492 CVarDisplay_vslot_73 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble CVarDisplay_vslot_73(int param_1,int param_2,char param_3)

{
  float fVar1;
  float fVar2;
  
  if (param_3 == '\0') {
    fVar1 = 1.0;
  }
  else {
    fVar1 = 0.2;
  }
  fVar1 = ((((float)((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0xc)) / 2 +
                    *(int *)(param_1 + 0xc)) - (float)*(int *)(param_2 + 4)) * fVar1) / 120.0 + 1.0)
          * 0.5 + (*(float *)(param_1 + 0x78) - 0.5);
  if ((fVar1 < 0.0) && (!NAN(fVar1))) {
    return (longdouble)0.0;
  }
  fVar2 = 1.0;
  if (fVar1 <= 1.0) {
    fVar2 = fVar1;
  }
  return (longdouble)fVar2;
}

