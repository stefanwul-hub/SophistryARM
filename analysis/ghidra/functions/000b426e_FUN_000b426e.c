/* 000b426e FUN_000b426e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_000b426e(int *param_1,undefined4 param_2,double param_3,undefined4 param_4,int *param_5,
                 double param_6)

{
  float fVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  longdouble lVar5;
  longdouble lVar6;
  double dVar7;
  double dVar8;
  float local_14;
  float local_10;
  
  if (((param_3 < *(double *)(param_1 + 0xc4)) ||
      (*(double *)(param_1 + 0xc4) <= *(double *)(param_1 + 0xcc))) ||
     (*(double *)(param_1 + 0xc6) < *(double *)(param_1 + 0xce) ||
      *(double *)(param_1 + 0xc6) == *(double *)(param_1 + 0xce))) {
    return false;
  }
  lVar5 = (longdouble)FUN_00013db8(param_1,param_2,*(double *)(param_1 + 0xcc));
  lVar6 = (longdouble)FUN_00013db8(param_1,param_2,*(undefined8 *)(param_1 + 0xce));
  iVar4 = *param_5;
  if ((((0 < iVar4) &&
       (*(double *)(param_1 + 0xc4) <= param_3 && param_3 != *(double *)(param_1 + 0xc4))) &&
      ((*(double *)(param_1 + 0xc6) <= param_3 && param_3 != *(double *)(param_1 + 0xc6) &&
       ((dVar8 = *(double *)(param_1 + 0xca), 0.0 <= dVar8 && (dVar8 <= 1.0)))))) &&
     (local_14 = (float)lVar5, local_10 = (float)lVar6, !NAN(dVar8))) {
    do {
      *param_5 = iVar4 + -1;
      uVar3 = param_1[0xed];
      param_1[0xed] = uVar3 + 1;
      if ((uVar3 & 7) == 0) {
        param_1[0x85] = *(int *)param_1[0x81];
        param_1[0x81] = (int)((int *)param_1[0x81] + 1);
        dVar8 = (double)*(float *)param_1[0x82];
        dVar8 = dVar8 * dVar8 * dVar8 * 0.05362607007876781 + dVar8 * dVar8 * 0.2480732860777168 +
                dVar8 * 0.695218770961068 + 1.0;
        dVar7 = dVar8 * dVar8 * dVar8 * dVar8 * *(double *)(param_1 + 0xd0);
        *(double *)(param_1 + 0xd2) = dVar7;
        dVar8 = (double)((*(float *)param_1[0x83] + 1.0) * (float)param_1[0xef]);
        *(double *)(param_1 + 0xd4) = dVar8;
        param_1[0x83] = (int)((float *)param_1[0x83] + 1);
        param_1[0x87] = (int)(float)((dVar7 - dVar8) / param_6);
        if (*(double *)(param_1 + 0xd2) <= 0.0) {
          param_1[0xd2] = -0x20000000;
          param_1[0xd3] = 0x3f1a36e2;
        }
      }
      lVar5 = (longdouble)FUN_00013aba(param_1,param_2,*(undefined8 *)(param_1 + 0xc4));
      lVar6 = (longdouble)FUN_00013aba(param_1,param_2,*(undefined8 *)(param_1 + 0xc6));
      pcVar2 = *(code **)(*param_1 + 0xcc);
      fVar1 = *(float *)param_1[0x84];
      param_1[0x84] = (int)((float *)param_1[0x84] + 1);
      (*pcVar2)(param_1,param_4,
                (float)((double)fVar1 *
                       (((double)(float)param_1[0x85] * *(double *)(param_1 + 0xca) *
                        (double)((float)lVar5 - local_14)) /
                        (*(double *)(param_1 + 0xc4) - *(double *)(param_1 + 0xcc)) +
                       ((double)(float)param_1[0x85] * (1.0 - *(double *)(param_1 + 0xca)) *
                       (double)((float)lVar6 - local_10)) /
                       (*(double *)(param_1 + 0xc6) - *(double *)(param_1 + 0xce)))));
      *(double *)(param_1 + 0xcc) = *(double *)(param_1 + 0xc4);
      *(double *)(param_1 + 0xce) = *(double *)(param_1 + 0xc6);
      *(double *)(param_1 + 0xc6) = *(double *)(param_1 + 0xc6) + *(double *)(param_1 + 0xd2);
      dVar8 = *(double *)(param_1 + 0xc4) + *(double *)(param_1 + 0xd2);
      *(double *)(param_1 + 0xc4) = dVar8;
      dVar7 = (double)(float)param_1[0x87] + *(double *)(param_1 + 0xca);
      *(double *)(param_1 + 0xca) = dVar7;
      iVar4 = *param_5;
      if (iVar4 < 1) goto LAB_000b462b;
    } while ((((*(double *)(param_1 + 0xc4) <= param_3 && param_3 != *(double *)(param_1 + 0xc4)) &&
              (*(double *)(param_1 + 0xc6) <= param_3 && param_3 != *(double *)(param_1 + 0xc6))) &&
             (0.0 <= dVar7)) && (local_14 = (float)lVar5, local_10 = (float)lVar6, dVar7 <= 1.0));
  }
  dVar8 = *(double *)(param_1 + 0xc4);
LAB_000b462b:
  return param_3 <= dVar8;
}

