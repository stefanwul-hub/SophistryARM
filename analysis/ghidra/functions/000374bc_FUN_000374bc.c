/* 000374bc FUN_000374bc */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000374bc(int param_1,float *param_2,undefined4 param_3,float param_4)

{
  float fVar1;
  float *pfVar2;
  uint uVar3;
  float fVar4;
  longdouble lVar5;
  longdouble lVar6;
  longdouble lVar7;
  longdouble lVar8;
  double dVar9;
  double dVar10;
  float fVar11;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  double local_4c;
  double local_3c;
  float local_24;
  float local_20;
  
  lVar5 = (longdouble)FUN_0001421a(param_1,param_3,*(undefined8 *)(param_1 + 0x330));
  lVar6 = (longdouble)
          FUN_0001421a(param_1,param_3,*(double *)(param_1 + 0x330) - *(double *)(param_1 + 0x410));
  if ((*(uint *)(param_1 + 0x430) & 7) == 0) goto LAB_00037649;
  uVar3 = *(uint *)(param_1 + 0x430) & 0x80000007;
  if ((int)uVar3 < 0) {
    local_20 = (float)(8 - ((uVar3 - 1 | 0xfffffff8) + 1));
    if ((int)local_20 < (int)*param_2) goto LAB_00037a42;
LAB_00037549:
    fVar11 = *param_2;
    local_4c = *(double *)(param_1 + 0x328);
    pfVar2 = *(float **)(param_1 + 0x228);
  }
  else {
    local_20 = (float)(8 - uVar3);
    if ((int)*param_2 <= (int)local_20) goto LAB_00037549;
LAB_00037a42:
    local_4c = *(double *)(param_1 + 0x328);
    pfVar2 = *(float **)(param_1 + 0x228);
    fVar11 = local_20;
  }
  if (0 < (int)fVar11) {
    fVar4 = 0.0;
    do {
      local_4c = (double)*pfVar2 * *(double *)(param_1 + 0x420) + local_4c;
      pfVar2 = pfVar2 + 1;
      fVar4 = (float)((int)fVar4 + 1);
    } while (fVar11 != fVar4);
  }
  lVar7 = (longdouble)
          FUN_000152c0(1.0,(float)(*(double *)(param_1 + 0x400) - *(double *)(param_1 + 0x408)));
  lVar8 = (longdouble)FUN_000152c0(1.0,(float)(int)fVar11);
  fVar11 = 1.0 - (float)((*(double *)(param_1 + 0x328) - *(double *)(param_1 + 0x408)) *
                        (double)(float)lVar7);
  local_5c = 1.0 - fVar11 * fVar11;
  fVar11 = 1.0 - (float)((double)(float)lVar7 * (local_4c - *(double *)(param_1 + 0x408)));
  local_58 = ((1.0 - fVar11 * fVar11) - local_5c) * (float)lVar8;
LAB_00037649:
  if ((int)*param_2 < 1) {
    return;
  }
  uVar3 = *(uint *)(param_1 + 0x430);
  *(uint *)(param_1 + 0x430) = uVar3 + 1;
  local_54 = (float)lVar5;
  local_50 = (float)lVar6;
  if ((uVar3 & 7) != 0) goto LAB_000379ab;
  do {
    local_24 = *param_2;
    if ((int)*param_2 < (int)1.26117e-44) {
      pfVar2 = &local_24;
    }
    else {
      pfVar2 = &FLOAT_000c8c38;
    }
    fVar4 = *pfVar2;
    *(float *)(param_1 + 0x218) = param_4 * **(float **)(param_1 + 0x208);
    *(float **)(param_1 + 0x208) = *(float **)(param_1 + 0x208) + 1;
    fVar11 = **(float **)(param_1 + 0x20c);
    *(float **)(param_1 + 0x20c) = *(float **)(param_1 + 0x20c) + 1;
    if ((-1.0 <= fVar11) || (NAN(fVar11))) {
      if (fVar11 <= 1.0) {
        dVar10 = (double)fVar11;
      }
      else {
        dVar10 = 1.0;
      }
    }
    else {
      dVar10 = -1.0;
    }
    dVar10 = dVar10 * dVar10 * dVar10 * 0.05362607007876781 + dVar10 * dVar10 * 0.2480732860777168 +
             dVar10 * 0.695218770961068 + 1.0;
    dVar10 = dVar10 * dVar10 * dVar10 * dVar10 * *(double *)(param_1 + 0x418);
    *(double *)(param_1 + 0x420) = dVar10;
    *(float *)(param_1 + 0x218) = (float)((double)*(float *)(param_1 + 0x218) / dVar10);
    if (((*(char *)(param_1 + 0x458) != '\0') && (*(char *)(param_1 + 0x459) != '\0')) &&
       (uVar3 = *(uint *)(param_1 + 0x454), *(uint *)(param_1 + 0x454) = uVar3 + 1,
       (uVar3 & 0xf) == 0)) {
      *(int *)(param_1 + 0x210) = *(int *)(param_1 + 0x210) + 0x40;
      *(int *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + 0x40;
    }
    local_3c = *(double *)(param_1 + 0x328);
    pfVar2 = *(float **)(param_1 + 0x228);
    if (0 < (int)fVar4) {
      fVar11 = 0.0;
      do {
        local_3c = (double)*pfVar2 * *(double *)(param_1 + 0x420) + local_3c;
        pfVar2 = pfVar2 + 1;
        fVar11 = (float)((int)fVar11 + 1);
      } while (fVar4 != fVar11);
    }
    lVar5 = (longdouble)
            FUN_000152c0(0x3f800000,
                         (float)(*(double *)(param_1 + 0x400) - *(double *)(param_1 + 0x408)));
    lVar6 = (longdouble)FUN_000152c0(0x3f800000,(float)(int)fVar4);
    dVar10 = *(double *)(param_1 + 0x328);
    fVar11 = 1.0 - (float)((dVar10 - *(double *)(param_1 + 0x408)) * (double)(float)lVar5);
    local_5c = 1.0 - fVar11 * fVar11;
    fVar11 = 1.0 - (float)((double)(float)lVar5 * (local_3c - *(double *)(param_1 + 0x408)));
    local_58 = ((1.0 - fVar11 * fVar11) - local_5c) * (float)lVar6;
    while( true ) {
      lVar5 = (longdouble)FUN_00013b34(param_1,param_3,dVar10);
      fVar11 = (float)lVar5;
      lVar5 = (longdouble)
              FUN_00013b34(param_1,param_3,
                           *(double *)(param_1 + 0x328) - *(double *)(param_1 + 0x410));
      fVar4 = (float)lVar5;
      pfVar2 = *(float **)(param_1 + 0x230);
      *pfVar2 = *(float *)(param_1 + 0x218) * **(float **)(param_1 + 0x22c) *
                ((1.0 - local_5c) * (fVar11 - local_54) + (fVar4 - local_50) * local_5c) + *pfVar2;
      *(float **)(param_1 + 0x230) = pfVar2 + 1;
      local_5c = local_5c + local_58;
      *(int *)(param_1 + 0x22c) = *(int *)(param_1 + 0x22c) + 4;
      dVar10 = *(double *)(param_1 + 0x328);
      *(double *)(param_1 + 0x330) = dVar10;
      dVar9 = (double)**(float **)(param_1 + 0x228) * *(double *)(param_1 + 0x420) + dVar10;
      *(double *)(param_1 + 0x328) = dVar9;
      *(float **)(param_1 + 0x228) = *(float **)(param_1 + 0x228) + 1;
      if (*(double *)(param_1 + 0x400) <= dVar9 && dVar9 != *(double *)(param_1 + 0x400)) {
        *(double *)(param_1 + 0x328) = dVar9 - *(double *)(param_1 + 0x410);
        *(double *)(param_1 + 0x330) = dVar10 - *(double *)(param_1 + 0x410);
        *param_2 = (float)((int)*param_2 + -1);
        return;
      }
      fVar1 = *param_2;
      *param_2 = (float)((int)fVar1 + -1);
      if ((int)fVar1 + -1 < 1) {
        return;
      }
      uVar3 = *(uint *)(param_1 + 0x430);
      *(uint *)(param_1 + 0x430) = uVar3 + 1;
      local_54 = fVar11;
      local_50 = fVar4;
      if ((uVar3 & 7) == 0) break;
LAB_000379ab:
      dVar10 = *(double *)(param_1 + 0x328);
    }
  } while( true );
}

