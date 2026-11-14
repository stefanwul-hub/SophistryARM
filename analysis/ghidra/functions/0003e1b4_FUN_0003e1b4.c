/* 0003e1b4 FUN_0003e1b4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0003e1b4(int param_1,double param_2,int param_3)

{
  float fVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  longdouble lVar8;
  longdouble lVar9;
  float fVar10;
  double dVar11;
  float fVar12;
  double dVar13;
  float local_34;
  float local_30;
  double local_24;
  
  dVar11 = 0.0;
  dVar13 = 0.0;
  if ((0.0 <= param_2) && (dVar13 = 1.0, param_2 <= 1.0)) {
    dVar13 = param_2;
  }
  iVar5 = *(int *)(param_1 + 0x124);
  if ((iVar5 == 0) || (iVar6 = *(int *)(param_1 + 0x67c + param_3 * 4), iVar6 < 1)) {
    return;
  }
  iVar7 = 0;
LAB_0003e2ae:
  if (0.0 < *(float *)(param_1 + 0x140)) {
    fVar10 = *(float *)(iVar5 + 0x46c);
    iVar4 = *(int *)(iVar5 + 0xe8) * 0xc0 + iVar7 * 0xc + param_1;
    fVar12 = (float)*(int *)(iVar4 + 0x1fc) * 0.01;
    if ((0.499 <= fVar10) && (fVar10 <= 0.501)) goto LAB_0003e27b;
    if (*(int *)(iVar4 + 0x204) == 0) {
      fVar12 = fVar12 * (fVar10 + fVar10);
      goto LAB_0003e27b;
    }
    fVar12 = fVar12 * ((1.0 - fVar10) + (1.0 - fVar10));
    goto LAB_0003e27b;
  }
  dVar3 = dVar11 + 0.0;
  dVar2 = dVar11;
  do {
    dVar11 = dVar3;
    if (iVar7 == iVar6 + -1) {
      dVar11 = 1.0;
    }
    if ((dVar2 < dVar11) && (dVar13 <= dVar11)) {
      lVar8 = (longdouble)FUN_00015302(dVar13 - dVar2,dVar11 - dVar2);
      local_34 = (float)lVar8;
      if (local_34 < 0.0) {
        local_34 = 0.0;
        local_24 = 0.0;
      }
      else if (local_34 <= 1.0) {
        local_24 = (double)local_34;
      }
      else {
        local_24 = 1.0;
        local_34 = 1.0;
      }
      *(int *)(param_1 + 0x1f0) = iVar7;
      iVar5 = *(int *)(param_1 + 0x124);
      local_30 = *(float *)(iVar5 + 0x15c);
      if ((*(int *)(iVar5 + 0x254) < *(int *)(iVar5 + 0x238)) &&
         (6.0 <= *(float *)(param_1 + 0x150))) {
        lVar8 = (longdouble)FUN_0001329c(param_1,*(int *)(iVar5 + 0x238));
        local_30 = (float)lVar8;
        iVar5 = *(int *)(param_1 + 0x124);
      }
      if (iVar5 == 0) {
        fVar12 = 0.0;
        fVar10 = *(float *)(param_1 + 0x140);
      }
      else if (iVar7 < 0) {
        fVar12 = 0.0;
        fVar10 = *(float *)(param_1 + 0x140);
      }
      else {
        fVar10 = *(float *)(param_1 + 0x140);
        if (0.0 < fVar10) {
          fVar1 = *(float *)(iVar5 + 0x46c);
          iVar5 = *(int *)(iVar5 + 0xe8) * 0xc0 + iVar7 * 0xc + param_1;
          fVar12 = (float)*(int *)(iVar5 + 0x1fc) * 0.01;
          if ((fVar1 < 0.499) || (0.501 < fVar1)) {
            if (*(int *)(iVar5 + 0x204) == 0) {
              fVar12 = fVar12 * (fVar1 + fVar1);
            }
            else {
              fVar12 = fVar12 * ((1.0 - fVar1) + (1.0 - fVar1));
            }
          }
        }
        else {
          fVar12 = 0.0;
        }
      }
      lVar8 = (longdouble)_pow(0,0x40000000,(double)*(float *)(param_1 + 0x1e4) * -2.0);
      lVar9 = (longdouble)FUN_000152c0(fVar10,local_30);
      fVar10 = (float)lVar9 * fVar12 * *(float *)(param_1 + 0x1e8) * *(float *)(param_1 + 0x1ec) *
               (float)lVar8 + *(float *)(param_1 + 0x7a0);
      iVar5 = (int)fVar10;
      *(float *)(param_1 + 0x7a0) = fVar10 - (float)iVar5;
      iVar6 = (int)((double)iVar5 * (1.0 - local_24));
      iVar5 = 1;
      if (0 < iVar6) {
        iVar5 = iVar6;
      }
      *(int *)(param_1 + 0x794) = iVar5;
      if (iVar7 < 1) {
        fVar10 = 0.0;
        iVar5 = *(int *)(param_1 + 0x124);
      }
      else {
        iVar5 = *(int *)(param_1 + 0x124);
        if (iVar5 == 0) {
          fVar10 = 0.0;
          fVar12 = 0.0;
          goto LAB_0003e4fe;
        }
        fVar10 = 0.0;
        if (-1 < iVar7 + -1) {
          fVar10 = (float)*(int *)(*(int *)(iVar5 + 0xe8) * 0xc0 + (iVar7 + -1) * 0xc + 0x200 +
                                  param_1) * 0.02;
        }
      }
      if ((iVar5 == 0) || (iVar7 < 0)) {
        fVar12 = 0.0;
      }
      else {
        fVar12 = (float)*(int *)(*(int *)(iVar5 + 0xe8) * 0xc0 + iVar7 * 0xc + 0x200 + param_1) *
                 0.02;
      }
LAB_0003e4fe:
      fVar10 = (fVar12 - fVar10) * local_34 + fVar10;
      *(float *)(param_1 + 0x798) = fVar10;
      lVar8 = (longdouble)FUN_000152c0(fVar12 - fVar10,(float)*(int *)(param_1 + 0x794));
      fVar10 = (float)lVar8;
      *(float *)(param_1 + 0x79c) = fVar10;
      if ((fVar10 < -1.0) && (!NAN(fVar10))) {
        *(undefined4 *)(param_1 + 0x79c) = 0xbf800000;
      }
      if (*(float *)(param_1 + 0x79c) <= 1.0) {
        return;
      }
      *(float *)(param_1 + 0x79c) = 1.0;
      return;
    }
    iVar7 = iVar7 + 1;
    if (iVar6 <= iVar7) {
      return;
    }
    fVar12 = 0.0;
    if (-1 < iVar7) goto LAB_0003e2ae;
LAB_0003e27b:
    dVar3 = (double)fVar12 + dVar11;
    dVar2 = dVar11;
  } while( true );
}

