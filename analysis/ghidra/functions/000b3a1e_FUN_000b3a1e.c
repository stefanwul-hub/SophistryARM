/* 000b3a1e FUN_000b3a1e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_000b3a1e(int *param_1,undefined4 param_2,double param_3,undefined4 param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  longdouble lVar3;
  double dVar4;
  float local_20;
  
  if ((param_3 < *(double *)(param_1 + 0xc4)) ||
     (*(double *)(param_1 + 0xc4) <= *(double *)(param_1 + 0xcc))) {
    return true;
  }
  lVar3 = (longdouble)FUN_00013db8(param_1,param_2,*(double *)(param_1 + 0xcc));
  iVar2 = *param_5;
  if ((0 < iVar2) &&
     (local_20 = (float)lVar3,
     *(double *)(param_1 + 0xc4) <= param_3 && param_3 != *(double *)(param_1 + 0xc4))) {
    do {
      *param_5 = iVar2 + -1;
      uVar1 = param_1[0xed];
      param_1[0xed] = uVar1 + 1;
      if ((uVar1 & 7) == 0) {
        param_1[0x85] = *(int *)param_1[0x81];
        param_1[0x81] = (int)((int *)param_1[0x81] + 1);
        dVar4 = (double)*(float *)param_1[0x82];
        param_1[0x82] = (int)((float *)param_1[0x82] + 1);
        dVar4 = dVar4 * dVar4 * dVar4 * 0.05362607007876781 + dVar4 * dVar4 * 0.2480732860777168 +
                dVar4 * 0.695218770961068 + 1.0;
        *(double *)(param_1 + 0xd2) = dVar4 * dVar4 * dVar4 * dVar4 * *(double *)(param_1 + 0xd0);
        *(double *)(param_1 + 0xd4) =
             (double)((*(float *)param_1[0x83] + 1.0) * (float)param_1[0xef]);
        param_1[0x83] = (int)((float *)param_1[0x83] + 1);
        if (*(double *)(param_1 + 0xd2) <= 0.0) {
          param_1[0xd2] = -0x20000000;
          param_1[0xd3] = 0x3f1a36e2;
        }
      }
      lVar3 = (longdouble)FUN_00013aba(param_1,param_2,*(undefined8 *)(param_1 + 0xc4));
      (**(code **)(*param_1 + 0xcc))
                (param_1,param_4,
                 (float)((double)(((float)lVar3 - local_20) * (float)param_1[0x85]) /
                        (*(double *)(param_1 + 0xc4) - *(double *)(param_1 + 0xcc))));
      *(double *)(param_1 + 0xcc) = *(double *)(param_1 + 0xc4);
      dVar4 = *(double *)(param_1 + 0xc4) + *(double *)(param_1 + 0xd2);
      *(double *)(param_1 + 0xc4) = dVar4;
      iVar2 = *param_5;
      if (iVar2 < 1) goto LAB_000b3aa3;
      local_20 = (float)lVar3;
    } while (dVar4 < param_3);
  }
  dVar4 = *(double *)(param_1 + 0xc4);
LAB_000b3aa3:
  return param_3 <= dVar4;
}

