/* 00014d00 FUN_00014d00 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00014d00(int param_1)

{
  float fVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  longdouble lVar5;
  longdouble lVar6;
  float fVar7;
  float fVar8;
  
  iVar4 = *(int *)(param_1 + 0x1d4);
  fVar1 = *(float *)(iVar4 + 0xf0);
  *(undefined4 *)(param_1 + 0x1d8) = 0xc;
  *(undefined4 *)(param_1 + 0x1dc) = 0x3f800000;
  lVar5 = (longdouble)FUN_000152c0(*(undefined4 *)(iVar4 + 0xac),*(undefined4 *)(iVar4 + 0xa8));
  bVar2 = true;
  iVar4 = 0xb0;
  do {
    puVar3 = (undefined4 *)(iVar4 + *(int *)(param_1 + 0x1d4));
    FUN_000152c0(*puVar3,puVar3[-1]);
    lVar6 = (longdouble)FUN_000152c0();
    if (0.03 < ABS((float)lVar6 - 1.0)) {
      bVar2 = false;
    }
    iVar4 = iVar4 + 4;
  } while (iVar4 != 0x13c);
  if (bVar2) {
    lVar5 = (longdouble)_log((double)(float)lVar5);
    *(float *)(param_1 + 0x1dc) = (float)((double)lVar5 * 17.312339782714844);
  }
  iVar4 = 0x3d;
  fVar8 = fVar1;
  do {
    fVar7 = ABS(*(float *)(*(int *)(param_1 + 0x1d4) + iVar4 * 4) * 0.5 - fVar1);
    if (fVar7 < fVar8) {
      *(int *)(param_1 + 0x1d8) = iVar4 + -0x3c;
      fVar8 = fVar7;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 != 0x7f);
  return;
}

