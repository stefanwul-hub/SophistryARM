/* 0008c1dc FUN_0008c1dc */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int FUN_0008c1dc(int param_1,int param_2,float param_3)

{
  uint uVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  longdouble lVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  iVar6 = *(int *)(param_1 + 0x124);
  if (iVar6 == 0) {
    return 0;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  else if (param_2 < 0x80) {
    param_2 = param_2 * 0x4d0;
  }
  else {
    param_2 = 0x26330;
  }
  fVar9 = *(float *)(iVar6 + param_2 + 0x404);
  fVar2 = *(float *)(iVar6 + param_2 + 0x474);
  fVar12 = (fVar9 + fVar2) * 0.5;
  fVar10 = fVar2;
  fVar11 = fVar9;
  if (fVar9 < fVar2) {
    fVar10 = fVar9;
    fVar11 = fVar2;
  }
  if (fVar10 <= param_3) {
    fVar10 = fVar11;
    if (param_3 <= fVar11) {
      fVar10 = param_3;
    }
    bVar7 = NAN(fVar9) || NAN(fVar2);
    if (fVar9 == fVar2) goto LAB_0008c25f;
LAB_0008c330:
    lVar8 = (longdouble)FUN_000152c0(0x3f800000,fVar2 - fVar9);
    fVar9 = (fVar10 - fVar9) * (float)lVar8;
    if ((0.0 <= fVar9) || (NAN(fVar9))) {
      if (fVar9 <= 1.0) {
        iVar6 = *(int *)(param_1 + 0x124);
      }
      else {
        fVar9 = 1.0;
        iVar6 = *(int *)(param_1 + 0x124);
      }
    }
    else {
      fVar9 = 0.0;
      iVar6 = *(int *)(param_1 + 0x124);
    }
  }
  else {
    bVar7 = NAN(fVar9) || NAN(fVar2);
    if (fVar9 != fVar2) goto LAB_0008c330;
LAB_0008c25f:
    if (bVar7) goto LAB_0008c330;
    fVar9 = 1.0;
  }
  iVar3 = *(int *)(param_2 + iVar6 + 0x698);
  iVar6 = 0x7f - *(int *)(param_2 + iVar6 + 0x708);
  uVar1 = (iVar6 - iVar3) + 1;
  if ((uVar1 & 1) == 0) {
    if (fVar9 <= fVar12) {
      iVar5 = iVar3 + (int)(fVar9 * (float)(int)uVar1 + 0.25);
    }
    else {
      fVar9 = fVar9 - fVar12;
      iVar5 = (int)uVar1 / 2 + (int)((float)(iVar6 - (int)uVar1 / 2) * (fVar9 + fVar9));
    }
  }
  else {
    iVar5 = iVar3 + (int)((float)(int)uVar1 * fVar9 * 0.9961);
  }
  iVar4 = iVar3;
  if (iVar6 <= iVar3) {
    iVar4 = iVar6;
  }
  if (iVar5 < iVar4) {
    iVar5 = iVar3;
    if (iVar6 <= iVar3) {
      return iVar6;
    }
  }
  else {
    iVar4 = iVar3;
    if (iVar6 <= iVar3) goto LAB_0008c2ce;
  }
  iVar4 = iVar6;
LAB_0008c2ce:
  if ((iVar4 < iVar5) && (iVar5 = iVar6, iVar6 <= iVar3)) {
    return iVar3;
  }
  return iVar5;
}

