/* 000b6cd6 Reverb2R_c_vslot_61 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble Reverb2R_c_vslot_61(int param_1)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  float fVar4;
  double dVar5;
  undefined1 auVar6 [16];
  
  iVar2 = *(int *)(param_1 + 0x124);
  if (iVar2 != 0) {
    fVar1 = *(float *)(iVar2 + 0x15c);
    dVar5 = (double)*(float *)(iVar2 + 0x23c) * 0.001;
    auVar6._0_4_ = (float)dVar5;
    auVar6._4_8_ = (ulonglong)dVar5 >> 0x20;
    auVar6._12_4_ = 0;
    if (*(int *)(iVar2 + 0x334) < *(int *)(iVar2 + 0x318)) {
      lVar3 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar2 + 0x318));
      auVar6 = ZEXT416((uint)(float)lVar3);
    }
    fVar4 = auVar6._0_4_;
    while (0.125 < fVar4) {
      auVar6._0_4_ = auVar6._0_4_ * 0.5;
      fVar4 = auVar6._0_4_;
    }
    return (longdouble)((auVar6._0_4_ + fVar1) * 1.4);
  }
  return (longdouble)0.0;
}

