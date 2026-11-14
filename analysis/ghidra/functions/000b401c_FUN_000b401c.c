/* 000b401c FUN_000b401c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_000b401c(int *param_1,undefined4 param_2,double param_3,undefined4 param_4,int *param_5)

{
  float fVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  longdouble lVar5;
  double dVar6;
  float local_20;
  
  if ((param_3 < *(double *)(param_1 + 0xc4)) ||
     (*(double *)(param_1 + 0xc4) <= *(double *)(param_1 + 0xcc))) {
    return true;
  }
  lVar5 = (longdouble)FUN_00013db8(param_1,param_2,*(double *)(param_1 + 0xcc));
  iVar4 = *param_5;
  if ((0 < iVar4) &&
     (local_20 = (float)lVar5,
     *(double *)(param_1 + 0xc4) <= param_3 && param_3 != *(double *)(param_1 + 0xc4))) {
    do {
      *param_5 = iVar4 + -1;
      uVar3 = param_1[0xed];
      param_1[0xed] = uVar3 + 1;
      if ((uVar3 & 7) == 0) {
        param_1[0x85] = *(int *)param_1[0x81];
        param_1[0x81] = (int)((int *)param_1[0x81] + 1);
        dVar6 = (double)*(float *)param_1[0x82];
        param_1[0x82] = (int)((float *)param_1[0x82] + 1);
        dVar6 = dVar6 * dVar6 * dVar6 * 0.05362607007876781 + dVar6 * dVar6 * 0.2480732860777168 +
                dVar6 * 0.695218770961068 + 1.0;
        *(double *)(param_1 + 0xd2) = dVar6 * dVar6 * dVar6 * dVar6 * *(double *)(param_1 + 0xd0);
        *(double *)(param_1 + 0xd4) =
             (double)((*(float *)param_1[0x83] + 1.0) * (float)param_1[0xef]);
        param_1[0x83] = (int)((float *)param_1[0x83] + 1);
        if (*(double *)(param_1 + 0xd2) <= 0.0) {
          param_1[0xd2] = -0x20000000;
          param_1[0xd3] = 0x3f1a36e2;
        }
      }
      lVar5 = (longdouble)FUN_00013aba(param_1,param_2,*(undefined8 *)(param_1 + 0xc4));
      pcVar2 = *(code **)(*param_1 + 0xcc);
      fVar1 = *(float *)param_1[0x84];
      param_1[0x84] = (int)((float *)param_1[0x84] + 1);
      (*pcVar2)(param_1,param_4,
                (float)((double)(fVar1 * (float)param_1[0x85] * ((float)lVar5 - local_20)) /
                       (*(double *)(param_1 + 0xc4) - *(double *)(param_1 + 0xcc))));
      *(double *)(param_1 + 0xcc) = *(double *)(param_1 + 0xc4);
      dVar6 = *(double *)(param_1 + 0xc4) + *(double *)(param_1 + 0xd2);
      *(double *)(param_1 + 0xc4) = dVar6;
      iVar4 = *param_5;
      if (iVar4 < 1) goto LAB_000b40a1;
      local_20 = (float)lVar5;
    } while (dVar6 < param_3);
  }
  dVar6 = *(double *)(param_1 + 0xc4);
LAB_000b40a1:
  return param_3 <= dVar6;
}

