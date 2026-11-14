/* 0003c484 FUN_0003c484 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0003c484(int *param_1,int param_2)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  longdouble lVar9;
  float fVar10;
  float fVar11;
  float local_28;
  float local_24;
  int local_20 [4];
  
  if ((char)param_1[0x7e] == '\0') {
    return;
  }
  fVar1 = *(float *)param_1[0x75];
  param_1[0x7c] = param_2;
  iVar6 = param_1[0x49];
  cVar2 = *(char *)(iVar6 + 0x40c);
  if ((param_2 == 3) && ((char)param_1[0xe1] != '\0')) {
    *(float *)param_1[0x75] = 1.0;
    bVar5 = true;
    iVar6 = param_1[0x49];
  }
  else {
    bVar5 = false;
  }
  iVar3 = param_1[0x7c];
  if (((iVar6 == 0) || (iVar3 < 0)) || (3 < iVar3)) {
LAB_0003c52d:
    iVar8 = 0;
  }
  else {
    iVar8 = *(int *)(iVar6 + 0x15c);
    iVar4 = *(int *)((-(uint)(*(char *)(iVar6 + 0x63c) == '\0') & 0xfffffa50) + 0x778 + iVar6);
    if (iVar3 != 1) {
      if (iVar3 == 2) {
        if (iVar4 == 0) goto LAB_0003c539;
        if (iVar4 < 0) goto LAB_0003c52d;
      }
      else if (iVar3 != 0) goto LAB_0003c52d;
      iVar8 = 0x3f800000;
    }
  }
LAB_0003c539:
  fVar10 = 0.0;
  param_1[0x7d] = iVar8;
  if (((iVar6 == 0) || (iVar3 < 0)) || (fVar11 = (float)param_1[0x50], fVar11 <= 0.0)) {
    local_20[0] = 0;
  }
  else if (iVar3 < 4) {
    if (*(char *)(iVar6 + 0x63c) == '\0') {
      if (iVar3 == 1) {
        if (*(char *)(iVar6 + 0x39c) != '\0') {
          param_1[0x7b] = 0x3f800000;
        }
        local_28 = *(float *)(iVar6 + 0xec) * (float)param_1[0x7a] * (float)param_1[0x7b];
        iVar6 = *param_1;
        uVar7 = 1;
LAB_0003c7e8:
        (**(code **)(iVar6 + 0xe8))(param_1,&local_28,uVar7);
        fVar11 = (float)param_1[0x50];
      }
      else {
        if (iVar3 < 2) {
          if (iVar3 == 0) {
            local_28 = (*(float *)(iVar6 + 0x7c) * (float)param_1[0x7a]) / (float)param_1[0x7b];
            iVar6 = *param_1;
            uVar7 = 0;
            goto LAB_0003c7e8;
          }
        }
        else {
          if (iVar3 == 2) {
            if (*(int *)(iVar6 + 0x1c8) == 0) {
              local_28 = 99999.0;
            }
            else {
              local_28 = (10.01 - ABS(*(float *)(iVar6 + 0x1cc))) * (float)param_1[0x7a] *
                         (float)param_1[0x7b];
            }
            goto LAB_0003c67e;
          }
          if (iVar3 == 3) {
            local_28 = *(float *)(iVar6 + 0x23c) * (float)param_1[0x7a] * (float)param_1[0x7b];
            iVar6 = *param_1;
            uVar7 = 2;
            goto LAB_0003c7e8;
          }
        }
        local_28 = 1.0;
      }
LAB_0003c67e:
      fVar11 = fVar11 * local_28;
    }
    else {
      lVar9 = (longdouble)FUN_00012ed2(param_1,*(uint *)(iVar3 * 0x70 + 0x69c + iVar6) & 0x7fffffff)
      ;
      local_28 = (float)lVar9;
      fVar11 = local_28 * (float)param_1[0x50];
    }
    local_20[0] = (int)fVar11;
    if (local_20[0] == 0) {
      local_20[0] = 1;
      fVar10 = 1.0;
    }
    else {
      fVar10 = (float)local_20[0];
    }
  }
  else {
    local_20[0] = 0x7ffffbff;
    fVar10 = 2.1474826e+09;
  }
  lVar9 = (longdouble)FUN_000152c0((float)param_1[0x7d] - *(float *)param_1[0x75],fVar10);
  local_24 = (float)lVar9;
  iVar6 = param_1[0x7c];
  if (iVar6 == 2) {
    fVar10 = ABS(*(float *)param_1[0x75]);
    if (((fVar10 < 0.0001) && (!NAN(fVar10))) && (*(int *)(param_1[0x49] + 0x1c8) == 0)) {
      if ((char)param_1[0x7e] == '\0') {
        return;
      }
      param_1[0x7c] = 4;
      *(float *)param_1[0x75] = 0.0;
      *(undefined4 *)param_1[0x76] = 0;
      *(undefined4 *)param_1[0x77] = 0x7ffffbff;
      *(undefined1 *)(param_1 + 0x78) = 1;
      return;
    }
  }
  if (cVar2 == '\0') goto LAB_0003c5e8;
  if (iVar6 == 1) {
    uVar7 = *(undefined4 *)(param_1[0x49] + 0x4dc);
  }
  else if (iVar6 < 2) {
    if (iVar6 == 0) {
      uVar7 = *(undefined4 *)(param_1[0x49] + 0x46c);
    }
    else {
LAB_0003c5b8:
      uVar7 = 0x3f800000;
    }
  }
  else if (iVar6 == 2) {
    uVar7 = *(undefined4 *)(param_1[0x49] + 0x54c);
  }
  else {
    if (iVar6 != 3) goto LAB_0003c5b8;
    uVar7 = *(undefined4 *)(param_1[0x49] + 0x5bc);
  }
  FUN_0000f394(param_1,param_1[0x7d],local_20[0],uVar7,&local_24,local_20);
LAB_0003c5e8:
  *(float *)param_1[0x76] = local_24;
  *(int *)param_1[0x77] = local_20[0];
  if (bVar5) {
    if (cVar2 != '\0') {
      FUN_0000f14c(param_1,0x3f800000,fVar1);
      return;
    }
    *(float *)param_1[0x75] = fVar1;
    iVar6 = (int)((float)local_20[0] * fVar1);
    if (iVar6 < 1) {
      iVar6 = 1;
    }
    *(int *)param_1[0x77] = iVar6;
  }
  return;
}

