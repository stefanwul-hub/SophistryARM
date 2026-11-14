/* 0003b88a Gator_c_vslot_56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Gator_c_vslot_56(int *param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  longdouble lVar8;
  longdouble lVar9;
  float fVar10;
  double dVar11;
  float fVar12;
  int local_34;
  int local_30;
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  float *local_24;
  float *local_20 [4];
  
  piVar1 = (int *)param_1[0x78];
  if (((piVar1 != (int *)0x0) &&
      (cVar5 = (**(code **)(*piVar1 + 0x30))(piVar1,&local_30,&local_34), cVar5 != '\0')) &&
     (iVar3 = param_1[0x90], 0 < local_30)) {
    lVar8 = (longdouble)FUN_000152c0(param_1[0x92],param_1[0x93]);
    uVar6 = (uint)lVar8;
    fVar12 = (float)param_1[0x93];
    dVar11 = (double)fVar12;
    fVar10 = (float)param_1[0x92];
    lVar8 = (longdouble)_fmod((double)fVar10,dVar11);
    iVar4 = param_1[0x90];
    uVar7 = (int)(((float)local_34 / (float)local_30) * (float)iVar4) & 0x8000000f;
    if ((int)uVar7 < 0) {
      uVar7 = (uVar7 - 1 | 0xfffffff0) + 1;
    }
    lVar9 = (longdouble)_fmod((double)local_34,dVar11);
    if ((1 < (int)(0x10 / (longlong)iVar3)) && (0 < (int)uVar7)) {
      for (; (int)uVar7 < (int)uVar6; uVar7 = uVar7 + iVar4) {
      }
    }
    if (uVar7 != uVar6) {
      fVar10 = (float)(int)(uVar7 - uVar6) * fVar12 + fVar10;
      param_1[0x92] = (int)fVar10;
      if ((fVar10 < 0.0) && (!NAN(fVar10))) {
        param_1[0x92] = (int)(fVar10 + (float)param_1[0x93] * 16.0);
      }
    }
    if ((int)lVar8 != (int)lVar9) {
      param_1[0x92] = (int)((float)((int)lVar9 - (int)lVar8) + (float)param_1[0x92]);
    }
  }
  (**(code **)(*(int *)param_1[0x46] + 0x2c))((int *)param_1[0x46],local_28,local_2c);
  piVar1 = (int *)param_1[4];
  if (*(char *)((int)piVar1 + 0x27) == '\0') {
    (**(code **)(*piVar1 + 0x34))(piVar1,local_20,0);
    local_24 = local_20[0];
  }
  else {
    (**(code **)(*piVar1 + 0x38))(piVar1,local_20,&local_24);
  }
  if (0 < (int)param_2) {
    uVar7 = 0;
    do {
      uVar6 = uVar7 & 7;
      uVar7 = uVar7 + 1;
      if (uVar6 == 0) {
        fVar12 = 0.0;
        if (0.0 < (float)param_1[0x93]) {
          uVar6 = (int)(((float)(int)uVar7 + (float)param_1[0x92]) / (float)param_1[0x93] + 0.1) &
                  0x8000000f;
          if ((int)uVar6 < 0) {
            uVar6 = (uVar6 - 1 | 0xfffffff0) + 1;
          }
          uVar2 = param_1[0x7a];
          if (uVar6 != uVar2) {
            param_1[0x91] = uVar2;
          }
          param_1[0x7a] = uVar6;
          if (uVar6 != uVar2) {
            fVar10 = fVar12;
            if (((param_1 + 0x84 != (int *)0x0) && ((int)uVar6 < 0x10)) &&
               (fVar10 = (1.0 - (float)param_1[0x83]) * (1.0 - (float)param_1[0x83]) + 1e-07,
               *(char *)((int)(param_1 + 0x84) + uVar6) == '1')) {
              fVar10 = 1.0;
            }
            param_1[0x81] = (int)fVar10;
            if ((((int)param_1 + 0x221 != 0) && (param_1[0x7a] < 0x10)) &&
               (fVar12 = (1.0 - (float)param_1[0x83]) * (1.0 - (float)param_1[0x83]) + 1e-07,
               *(char *)((int)param_1 + 0x221 + param_1[0x7a]) == '1')) {
              fVar12 = 1.0;
            }
            param_1[0x82] = (int)fVar12;
          }
        }
        param_1[0x7f] = (int)(((float)param_1[0x81] - (float)param_1[0x7b]) * (float)param_1[0x8f]);
        param_1[0x80] = (int)(((float)param_1[0x82] - (float)param_1[0x7c]) * (float)param_1[0x8f]);
      }
      fVar12 = *local_20[0];
      local_20[0] = local_20[0] + 1;
      (**(code **)(*param_1 + 0xcc))(param_1,local_28,fVar12 * (float)param_1[0x7b]);
      fVar12 = *local_24;
      local_24 = local_24 + 1;
      (**(code **)(*param_1 + 0xcc))(param_1,local_2c,fVar12 * (float)param_1[0x7c]);
      param_1[0x7b] = (int)((float)param_1[0x7b] + (float)param_1[0x7d]);
      param_1[0x7c] = (int)((float)param_1[0x7c] + (float)param_1[0x7e]);
      param_1[0x7d] = (int)((float)param_1[0x7d] * 0.8 + (float)param_1[0x7f] * 0.2);
      param_1[0x7e] = (int)((float)param_1[0x7e] * 0.8 + (float)param_1[0x80] * 0.2);
    } while (uVar7 != param_2);
  }
  param_1[0x92] = (int)((float)(int)param_2 + (float)param_1[0x92]);
  (**(code **)(*(int *)param_1[0x46] + 0x44))((int *)param_1[0x46]);
  return;
}

