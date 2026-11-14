/* 0008f37a Phaser1SR_c_vslot_61 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble Phaser1SR_c_vslot_61(int param_1)

{
  longdouble lVar1;
  double dVar2;
  float fVar3;
  
  fVar3 = 0.0;
  if (*(int *)(param_1 + 0x124) != 0) {
    dVar2 = (double)*(float *)(*(int *)(param_1 + 0x124) + 0x2ac);
    if (0.9 < dVar2) {
      lVar1 = (longdouble)_log10(dVar2);
      return (longdouble)
             ((float)(-4.0 / (double)lVar1) * 0.0002 * (float)(-4.0 / (double)lVar1) + 0.1);
    }
    fVar3 = 0.1;
  }
  return (longdouble)fVar3;
}

