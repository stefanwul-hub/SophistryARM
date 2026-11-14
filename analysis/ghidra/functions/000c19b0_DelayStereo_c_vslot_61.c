/* 000c19b0 DelayStereo_c_vslot_61 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble DelayStereo_c_vslot_61(int param_1)

{
  int iVar1;
  longdouble lVar2;
  longdouble lVar3;
  double dVar4;
  double dVar5;
  float fVar6;
  
  if (*(int *)(param_1 + 0x124) != 0) {
    lVar2 = (longdouble)_log10((double)*(float *)(*(int *)(param_1 + 0x124) + 0x2ac) + 0.0001);
    lVar2 = (longdouble)FUN_00015302(0,0xc0100000,(double)lVar2);
    iVar1 = *(int *)(param_1 + 0x124);
    if ((iVar1 == 0) || (*(int *)(param_1 + 0x228) < 0x11)) {
      dVar4 = 0.0;
    }
    else {
      fVar6 = *(float *)(iVar1 + 0xec) * 0.001;
      if (*(int *)(iVar1 + 0x174) < *(int *)(iVar1 + 0x158)) {
        lVar3 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar1 + 0x158));
        fVar6 = (float)lVar3;
        iVar1 = *(int *)(param_1 + 0x124);
      }
      for (; (float)(*(int *)(param_1 + 0x228) + -0x10) <= fVar6 * *(float *)(param_1 + 0x140);
          fVar6 = fVar6 * 0.5) {
      }
      dVar4 = (double)fVar6;
    }
    dVar4 = dVar4 * (double)lVar2 + 0.1;
    if ((iVar1 == 0) || (*(int *)(param_1 + 0x228) < 0x11)) {
      dVar5 = 0.0;
    }
    else {
      fVar6 = *(float *)(iVar1 + 0x1cc) * 0.001;
      if (*(int *)(iVar1 + 0x254) < *(int *)(iVar1 + 0x238)) {
        lVar3 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar1 + 0x238));
        fVar6 = (float)lVar3;
      }
      for (; (float)(*(int *)(param_1 + 0x228) + -0x10) <= *(float *)(param_1 + 0x140) * fVar6;
          fVar6 = fVar6 * 0.5) {
      }
      dVar5 = (double)fVar6;
    }
    dVar5 = dVar5 * (double)lVar2 + 0.1;
    if (dVar5 <= dVar4) {
      dVar5 = dVar4;
    }
    return (longdouble)(float)dVar5;
  }
  return (longdouble)0.0;
}

