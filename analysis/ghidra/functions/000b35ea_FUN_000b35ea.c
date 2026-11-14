/* 000b35ea FUN_000b35ea */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_000b35ea(int *param_1,undefined4 param_2,double param_3,undefined4 param_4,int *param_5,
                 double param_6)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  float fVar4;
  longdouble lVar5;
  longdouble lVar6;
  double dVar7;
  double dVar8;
  
  if (((param_3 < *(double *)(param_1 + 0xc4)) ||
      (*(double *)(param_1 + 0xc4) <= *(double *)(param_1 + 0xcc))) ||
     (*(double *)(param_1 + 0xc6) < *(double *)(param_1 + 0xce) ||
      *(double *)(param_1 + 0xc6) == *(double *)(param_1 + 0xce))) {
    return false;
  }
  lVar5 = (longdouble)FUN_00013db8(param_1,param_2,*(double *)(param_1 + 0xcc));
  lVar6 = (longdouble)FUN_00013db8(param_1,param_2,*(undefined8 *)(param_1 + 0xce));
  iVar2 = *param_5;
  if (((0 < iVar2) &&
      (*(double *)(param_1 + 0xc4) <= param_3 && param_3 != *(double *)(param_1 + 0xc4))) &&
     ((*(double *)(param_1 + 0xc6) <= param_3 && param_3 != *(double *)(param_1 + 0xc6) &&
      (dVar8 = *(double *)(param_1 + 0xca), fVar1 = (float)lVar5, fVar4 = (float)lVar6, 0.0 <= dVar8
      )))) {
    while (dVar8 <= 1.0) {
      *param_5 = iVar2 + -1;
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
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_4,
                 (float)(((double)(float)param_1[0x85] * *(double *)(param_1 + 0xca) *
                         (double)((float)lVar5 - fVar1)) /
                         (*(double *)(param_1 + 0xc4) - *(double *)(param_1 + 0xcc)) +
                        ((double)(float)param_1[0x85] * (1.0 - *(double *)(param_1 + 0xca)) *
                        (double)((float)lVar6 - fVar4)) /
                        (*(double *)(param_1 + 0xc6) - *(double *)(param_1 + 0xce))));
      *(undefined8 *)(param_1 + 0xcc) = *(undefined8 *)(param_1 + 0xc4);
      *(undefined8 *)(param_1 + 0xce) = *(undefined8 *)(param_1 + 0xc6);
      fVar1 = *(float *)param_1[0x84];
      param_1[0x84] = (int)((float *)param_1[0x84] + 1);
      if ((0.001 <= fVar1) || (NAN(fVar1))) {
        if (fVar1 <= 2.0) {
          dVar8 = (double)fVar1;
        }
        else {
          dVar8 = 2.0;
        }
      }
      else {
        dVar8 = 0.0010000000474974513;
      }
      *(double *)(param_1 + 0xc6) =
           dVar8 * *(double *)(param_1 + 0xd2) + *(double *)(param_1 + 0xc6);
      *(double *)(param_1 + 0xc4) =
           dVar8 * *(double *)(param_1 + 0xd2) + *(double *)(param_1 + 0xc4);
      dVar8 = (double)(float)param_1[0x87] + *(double *)(param_1 + 0xca);
      *(double *)(param_1 + 0xca) = dVar8;
      iVar2 = *param_5;
      if ((((iVar2 < 1) ||
           (param_3 < *(double *)(param_1 + 0xc4) || param_3 == *(double *)(param_1 + 0xc4))) ||
          (param_3 < *(double *)(param_1 + 0xc6) || param_3 == *(double *)(param_1 + 0xc6))) ||
         (fVar1 = (float)lVar5, fVar4 = (float)lVar6, dVar8 < 0.0)) break;
    }
  }
  return param_3 <= *(double *)(param_1 + 0xc4);
}

