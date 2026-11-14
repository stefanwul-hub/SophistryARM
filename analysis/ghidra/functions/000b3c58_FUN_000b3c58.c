/* 000b3c58 FUN_000b3c58 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_000b3c58(int *param_1,undefined4 param_2,double param_3,undefined4 param_4,int *param_5,
                 double param_6)

{
  uint uVar1;
  int iVar2;
  longdouble lVar3;
  longdouble lVar4;
  double dVar5;
  double dVar6;
  float local_14;
  float local_10;
  
  if (((param_3 < *(double *)(param_1 + 0xc4)) ||
      (*(double *)(param_1 + 0xc4) <= *(double *)(param_1 + 0xcc))) ||
     (*(double *)(param_1 + 0xc6) < *(double *)(param_1 + 0xce) ||
      *(double *)(param_1 + 0xc6) == *(double *)(param_1 + 0xce))) {
    return false;
  }
  lVar3 = (longdouble)FUN_00013db8(param_1,param_2,*(double *)(param_1 + 0xcc));
  lVar4 = (longdouble)FUN_00013db8(param_1,param_2,*(undefined8 *)(param_1 + 0xce));
  iVar2 = *param_5;
  if ((((0 < iVar2) &&
       (*(double *)(param_1 + 0xc4) <= param_3 && param_3 != *(double *)(param_1 + 0xc4))) &&
      ((*(double *)(param_1 + 0xc6) <= param_3 && param_3 != *(double *)(param_1 + 0xc6) &&
       ((dVar6 = *(double *)(param_1 + 0xca), 0.0 <= dVar6 && (dVar6 <= 1.0)))))) &&
     (local_14 = (float)lVar3, local_10 = (float)lVar4, !NAN(dVar6))) {
    do {
      *param_5 = iVar2 + -1;
      uVar1 = param_1[0xed];
      param_1[0xed] = uVar1 + 1;
      if ((uVar1 & 7) == 0) {
        param_1[0x85] = *(int *)param_1[0x81];
        param_1[0x81] = (int)((int *)param_1[0x81] + 1);
        dVar6 = (double)*(float *)param_1[0x82];
        param_1[0x82] = (int)((float *)param_1[0x82] + 1);
        dVar6 = dVar6 * dVar6 * dVar6 * 0.05362607007876781 + dVar6 * dVar6 * 0.2480732860777168 +
                dVar6 * 0.695218770961068 + 1.0;
        dVar5 = dVar6 * dVar6 * dVar6 * dVar6 * *(double *)(param_1 + 0xd0);
        *(double *)(param_1 + 0xd2) = dVar5;
        dVar6 = (double)((*(float *)param_1[0x83] + 1.0) * (float)param_1[0xef]);
        *(double *)(param_1 + 0xd4) = dVar6;
        param_1[0x83] = (int)((float *)param_1[0x83] + 1);
        param_1[0x87] = (int)(float)((dVar5 - dVar6) / param_6);
        if (*(double *)(param_1 + 0xd2) <= 0.0) {
          param_1[0xd2] = -0x20000000;
          param_1[0xd3] = 0x3f1a36e2;
        }
      }
      lVar3 = (longdouble)FUN_00013aba(param_1,param_2,*(undefined8 *)(param_1 + 0xc4));
      lVar4 = (longdouble)FUN_00013aba(param_1,param_2,*(undefined8 *)(param_1 + 0xc6));
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_4,
                 (float)(((double)(float)param_1[0x85] * *(double *)(param_1 + 0xca) *
                         (double)((float)lVar3 - local_14)) /
                         (*(double *)(param_1 + 0xc4) - *(double *)(param_1 + 0xcc)) +
                        ((double)(float)param_1[0x85] * (1.0 - *(double *)(param_1 + 0xca)) *
                        (double)((float)lVar4 - local_10)) /
                        (*(double *)(param_1 + 0xc6) - *(double *)(param_1 + 0xce))));
      *(double *)(param_1 + 0xcc) = *(double *)(param_1 + 0xc4);
      *(double *)(param_1 + 0xce) = *(double *)(param_1 + 0xc6);
      *(double *)(param_1 + 0xc6) = *(double *)(param_1 + 0xc6) + *(double *)(param_1 + 0xd2);
      dVar6 = *(double *)(param_1 + 0xc4) + *(double *)(param_1 + 0xd2);
      *(double *)(param_1 + 0xc4) = dVar6;
      dVar5 = (double)(float)param_1[0x87] + *(double *)(param_1 + 0xca);
      *(double *)(param_1 + 0xca) = dVar5;
      iVar2 = *param_5;
      if (iVar2 < 1) goto LAB_000b4005;
    } while ((((*(double *)(param_1 + 0xc4) <= param_3 && param_3 != *(double *)(param_1 + 0xc4)) &&
              (*(double *)(param_1 + 0xc6) <= param_3 && param_3 != *(double *)(param_1 + 0xc6))) &&
             (0.0 <= dVar5)) && (local_14 = (float)lVar3, local_10 = (float)lVar4, dVar5 <= 1.0));
  }
  dVar6 = *(double *)(param_1 + 0xc4);
LAB_000b4005:
  return param_3 <= dVar6;
}

