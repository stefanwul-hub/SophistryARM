/* 000b4642 FUN_000b4642 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_000b4642(int *param_1,undefined4 param_2,double param_3,undefined4 param_4,int *param_5)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  longdouble lVar4;
  double dVar5;
  float local_20;
  
  if ((param_3 < *(double *)(param_1 + 0xc4)) ||
     (*(double *)(param_1 + 0xc4) <= *(double *)(param_1 + 0xcc))) {
    return true;
  }
  lVar4 = (longdouble)FUN_00013db8(param_1,param_2,*(double *)(param_1 + 0xcc));
  iVar3 = *param_5;
  if ((0 < iVar3) &&
     (local_20 = (float)lVar4,
     *(double *)(param_1 + 0xc4) <= param_3 && param_3 != *(double *)(param_1 + 0xc4))) {
    do {
      *param_5 = iVar3 + -1;
      uVar2 = param_1[0xed];
      param_1[0xed] = uVar2 + 1;
      if ((uVar2 & 7) == 0) {
        param_1[0x85] = *(int *)param_1[0x81];
        param_1[0x81] = (int)((int *)param_1[0x81] + 1);
        dVar5 = (double)*(float *)param_1[0x82];
        param_1[0x82] = (int)((float *)param_1[0x82] + 1);
        dVar5 = dVar5 * dVar5 * dVar5 * 0.05362607007876781 + dVar5 * dVar5 * 0.2480732860777168 +
                dVar5 * 0.695218770961068 + 1.0;
        *(double *)(param_1 + 0xd2) = dVar5 * dVar5 * dVar5 * dVar5 * *(double *)(param_1 + 0xd0);
        *(double *)(param_1 + 0xd4) =
             (double)((*(float *)param_1[0x83] + 1.0) * (float)param_1[0xef]);
        param_1[0x83] = (int)((float *)param_1[0x83] + 1);
        if (*(double *)(param_1 + 0xd2) <= 0.0) {
          param_1[0xd2] = -0x20000000;
          param_1[0xd3] = 0x3f1a36e2;
        }
      }
      lVar4 = (longdouble)FUN_00013aba(param_1,param_2,*(undefined8 *)(param_1 + 0xc4));
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_4,
                 (float)((double)(((float)lVar4 - local_20) * (float)param_1[0x85]) /
                        (*(double *)(param_1 + 0xc4) - *(double *)(param_1 + 0xcc))));
      *(undefined8 *)(param_1 + 0xcc) = *(undefined8 *)(param_1 + 0xc4);
      fVar1 = *(float *)param_1[0x84];
      param_1[0x84] = (int)((float *)param_1[0x84] + 1);
      if ((0.0001 <= fVar1) || (NAN(fVar1))) {
        if (2.0 < fVar1) {
          dVar5 = 2.0;
        }
        else {
          dVar5 = (double)fVar1;
        }
      }
      else {
        dVar5 = 9.999999747378752e-05;
      }
      dVar5 = dVar5 * *(double *)(param_1 + 0xd2) + *(double *)(param_1 + 0xc4);
      *(double *)(param_1 + 0xc4) = dVar5;
      iVar3 = *param_5;
      if (iVar3 < 1) goto LAB_000b484c;
      local_20 = (float)lVar4;
    } while (dVar5 < param_3);
  }
  dVar5 = *(double *)(param_1 + 0xc4);
LAB_000b484c:
  return param_3 <= dVar5;
}

