/* 00037a86 FUN_00037a86 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00037a86(int param_1,float *param_2,undefined4 param_3,undefined4 param_4,float param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  uint uVar5;
  float fVar6;
  longdouble lVar7;
  longdouble lVar8;
  longdouble lVar9;
  longdouble lVar10;
  longdouble lVar11;
  longdouble lVar12;
  double dVar13;
  double dVar14;
  float fVar15;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  double local_54;
  double local_44;
  float local_24;
  float local_20;
  
  lVar7 = (longdouble)FUN_0001421a(param_1,param_3,*(undefined8 *)(param_1 + 0x330));
  lVar8 = (longdouble)
          FUN_0001421a(param_1,param_3,*(double *)(param_1 + 0x330) - *(double *)(param_1 + 0x410));
  lVar9 = (longdouble)FUN_0001421a(param_1,param_4,*(undefined8 *)(param_1 + 0x330));
  lVar10 = (longdouble)
           FUN_0001421a(param_1,param_4,*(double *)(param_1 + 0x330) - *(double *)(param_1 + 0x410))
  ;
  if ((*(uint *)(param_1 + 0x430) & 7) == 0) goto LAB_00037c5b;
  uVar5 = *(uint *)(param_1 + 0x430) & 0x80000007;
  if ((int)uVar5 < 0) {
    local_20 = (float)(8 - ((uVar5 - 1 | 0xfffffff8) + 1));
    if ((int)local_20 < (int)*param_2) goto LAB_0003811a;
LAB_00037b5b:
    fVar15 = *param_2;
    local_54 = *(double *)(param_1 + 0x328);
    pfVar4 = *(float **)(param_1 + 0x228);
  }
  else {
    local_20 = (float)(8 - uVar5);
    if ((int)*param_2 <= (int)local_20) goto LAB_00037b5b;
LAB_0003811a:
    local_54 = *(double *)(param_1 + 0x328);
    pfVar4 = *(float **)(param_1 + 0x228);
    fVar15 = local_20;
  }
  if (0 < (int)fVar15) {
    fVar6 = 0.0;
    do {
      local_54 = (double)*pfVar4 * *(double *)(param_1 + 0x420) + local_54;
      pfVar4 = pfVar4 + 1;
      fVar6 = (float)((int)fVar6 + 1);
    } while (fVar6 != fVar15);
  }
  lVar11 = (longdouble)
           FUN_000152c0(1.0,(float)(*(double *)(param_1 + 0x400) - *(double *)(param_1 + 0x408)));
  lVar12 = (longdouble)FUN_000152c0(1.0,(float)(int)fVar15);
  fVar15 = 1.0 - (float)((*(double *)(param_1 + 0x328) - *(double *)(param_1 + 0x408)) *
                        (double)(float)lVar11);
  local_6c = 1.0 - fVar15 * fVar15;
  fVar15 = 1.0 - (float)((double)(float)lVar11 * (local_54 - *(double *)(param_1 + 0x408)));
  local_68 = ((1.0 - fVar15 * fVar15) - local_6c) * (float)lVar12;
LAB_00037c5b:
  if ((int)*param_2 < 1) {
    return;
  }
  uVar5 = *(uint *)(param_1 + 0x430);
  *(uint *)(param_1 + 0x430) = uVar5 + 1;
  local_64 = (float)lVar7;
  local_60 = (float)lVar8;
  local_5c = (float)lVar9;
  local_58 = (float)lVar10;
  if ((uVar5 & 7) != 0) goto LAB_00038083;
  do {
    local_24 = *param_2;
    if ((int)*param_2 < (int)1.26117e-44) {
      pfVar4 = &local_24;
    }
    else {
      pfVar4 = &FLOAT_000c8c38;
    }
    fVar6 = *pfVar4;
    *(float *)(param_1 + 0x218) = param_5 * **(float **)(param_1 + 0x208);
    *(float **)(param_1 + 0x208) = *(float **)(param_1 + 0x208) + 1;
    fVar15 = **(float **)(param_1 + 0x20c);
    *(float **)(param_1 + 0x20c) = *(float **)(param_1 + 0x20c) + 1;
    if ((-1.0 <= fVar15) || (NAN(fVar15))) {
      if (fVar15 <= 1.0) {
        dVar14 = (double)fVar15;
      }
      else {
        dVar14 = 1.0;
      }
    }
    else {
      dVar14 = -1.0;
    }
    dVar14 = dVar14 * dVar14 * dVar14 * 0.05362607007876781 + dVar14 * dVar14 * 0.2480732860777168 +
             dVar14 * 0.695218770961068 + 1.0;
    dVar14 = dVar14 * dVar14 * dVar14 * dVar14 * *(double *)(param_1 + 0x418);
    *(double *)(param_1 + 0x420) = dVar14;
    *(float *)(param_1 + 0x218) = (float)((double)*(float *)(param_1 + 0x218) / dVar14);
    if (((*(char *)(param_1 + 0x458) != '\0') && (*(char *)(param_1 + 0x459) != '\0')) &&
       (uVar5 = *(uint *)(param_1 + 0x454), *(uint *)(param_1 + 0x454) = uVar5 + 1,
       (uVar5 & 0xf) == 0)) {
      *(int *)(param_1 + 0x210) = *(int *)(param_1 + 0x210) + 0x40;
      *(int *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + 0x40;
    }
    local_44 = *(double *)(param_1 + 0x328);
    pfVar4 = *(float **)(param_1 + 0x228);
    if (0 < (int)fVar6) {
      fVar15 = 0.0;
      do {
        local_44 = (double)*pfVar4 * *(double *)(param_1 + 0x420) + local_44;
        pfVar4 = pfVar4 + 1;
        fVar15 = (float)((int)fVar15 + 1);
      } while (fVar6 != fVar15);
    }
    lVar7 = (longdouble)
            FUN_000152c0(0x3f800000,
                         (float)(*(double *)(param_1 + 0x400) - *(double *)(param_1 + 0x408)));
    lVar8 = (longdouble)FUN_000152c0(0x3f800000,(float)(int)fVar6);
    dVar14 = *(double *)(param_1 + 0x328);
    fVar15 = 1.0 - (float)((dVar14 - *(double *)(param_1 + 0x408)) * (double)(float)lVar7);
    local_6c = 1.0 - fVar15 * fVar15;
    fVar15 = 1.0 - (float)((double)(float)lVar7 * (local_44 - *(double *)(param_1 + 0x408)));
    local_68 = ((1.0 - fVar15 * fVar15) - local_6c) * (float)lVar8;
    while( true ) {
      lVar7 = (longdouble)FUN_00013b34(param_1,param_3,dVar14);
      fVar15 = (float)lVar7;
      lVar7 = (longdouble)
              FUN_00013b34(param_1,param_3,
                           *(double *)(param_1 + 0x328) - *(double *)(param_1 + 0x410));
      fVar6 = (float)lVar7;
      pfVar4 = *(float **)(param_1 + 0x230);
      *pfVar4 = *(float *)(param_1 + 0x218) * **(float **)(param_1 + 0x22c) *
                ((fVar15 - local_64) * (1.0 - local_6c) + (fVar6 - local_60) * local_6c) + *pfVar4;
      *(float **)(param_1 + 0x230) = pfVar4 + 1;
      lVar7 = (longdouble)FUN_00013b34(param_1,param_4,*(undefined8 *)(param_1 + 0x328));
      fVar1 = (float)lVar7;
      lVar7 = (longdouble)
              FUN_00013b34(param_1,param_4,
                           *(double *)(param_1 + 0x328) - *(double *)(param_1 + 0x410));
      fVar2 = (float)lVar7;
      pfVar4 = *(float **)(param_1 + 0x234);
      *pfVar4 = *(float *)(param_1 + 0x218) * **(float **)(param_1 + 0x22c) *
                ((1.0 - local_6c) * (fVar1 - local_5c) + (fVar2 - local_58) * local_6c) + *pfVar4;
      *(float **)(param_1 + 0x234) = pfVar4 + 1;
      local_6c = local_6c + local_68;
      *(int *)(param_1 + 0x22c) = *(int *)(param_1 + 0x22c) + 4;
      dVar14 = *(double *)(param_1 + 0x328);
      *(double *)(param_1 + 0x330) = dVar14;
      dVar13 = (double)**(float **)(param_1 + 0x228) * *(double *)(param_1 + 0x420) + dVar14;
      *(double *)(param_1 + 0x328) = dVar13;
      *(float **)(param_1 + 0x228) = *(float **)(param_1 + 0x228) + 1;
      if (*(double *)(param_1 + 0x400) <= dVar13 && dVar13 != *(double *)(param_1 + 0x400)) {
        *(double *)(param_1 + 0x328) = dVar13 - *(double *)(param_1 + 0x410);
        *(double *)(param_1 + 0x330) = dVar14 - *(double *)(param_1 + 0x410);
        *param_2 = (float)((int)*param_2 + -1);
        return;
      }
      fVar3 = *param_2;
      *param_2 = (float)((int)fVar3 + -1);
      if ((int)fVar3 + -1 < 1) {
        return;
      }
      uVar5 = *(uint *)(param_1 + 0x430);
      *(uint *)(param_1 + 0x430) = uVar5 + 1;
      local_64 = fVar15;
      local_60 = fVar6;
      local_5c = fVar1;
      local_58 = fVar2;
      if ((uVar5 & 7) == 0) break;
LAB_00038083:
      dVar14 = *(double *)(param_1 + 0x328);
    }
  } while( true );
}

