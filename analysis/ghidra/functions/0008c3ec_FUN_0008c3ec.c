/* 0008c3ec FUN_0008c3ec */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble FUN_0008c3ec(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  float fVar7;
  float fVar8;
  float local_24;
  int local_20;
  
  iVar5 = *(int *)(param_1 + 0x124);
  fVar7 = 0.0;
  if (iVar5 == 0) goto LAB_0008c563;
  if (param_2 < 0) {
    param_2 = 0;
    local_20 = 0;
LAB_0008c430:
    iVar4 = *(int *)(iVar5 + local_20 + 0x698);
    iVar2 = 0x7f - *(int *)(iVar5 + local_20 + 0x708);
    if (iVar2 < iVar4) goto LAB_0008c44f;
LAB_0008c5a1:
    local_24 = 1.0;
    iVar3 = iVar2;
    if (param_3 < iVar4) goto LAB_0008c46b;
LAB_0008c5b7:
    if (iVar3 < param_3) {
      param_3 = iVar3;
    }
    if (iVar4 != iVar3) goto LAB_0008c476;
LAB_0008c5cb:
    local_24 = 0.5;
  }
  else {
    if (0x7f < param_2) {
      param_2 = 0x7f;
      local_20 = 0x26330;
      goto LAB_0008c430;
    }
    local_20 = param_2 * 0x4d0;
    iVar4 = *(int *)(iVar5 + local_20 + 0x698);
    iVar2 = 0x7f - *(int *)(iVar5 + local_20 + 0x708);
    if (iVar4 <= iVar2) goto LAB_0008c5a1;
LAB_0008c44f:
    local_24 = -1.0;
    iVar3 = iVar4;
    iVar4 = iVar2;
    if (iVar2 <= param_3) goto LAB_0008c5b7;
LAB_0008c46b:
    param_3 = iVar4;
    if (iVar4 == iVar3) goto LAB_0008c5cb;
LAB_0008c476:
    uVar1 = (iVar3 - iVar4) + 1;
    if ((uVar1 & 1) == 0) {
      iVar5 = (int)uVar1 / 2;
      if (iVar5 < param_3) {
        lVar6 = (longdouble)FUN_000152c0(0x3f800000,(float)(iVar3 - iVar5));
        fVar7 = (float)lVar6 * (float)(param_3 - iVar5) * 0.5 + 0.5;
        goto LAB_0008c4d5;
      }
      lVar6 = (longdouble)FUN_000152c0(0x3f800000,(float)(iVar5 - iVar4));
      fVar7 = (float)lVar6 * (float)(param_3 - iVar4) * 0.5;
      if (fVar7 < 0.0) goto LAB_0008c61f;
LAB_0008c4e2:
      fVar8 = 1.0;
      if (fVar7 <= 1.0) {
        fVar8 = fVar7;
      }
    }
    else {
      lVar6 = (longdouble)FUN_000152c0(0x3f800000,(float)(iVar3 - iVar4));
      fVar7 = (float)lVar6 * (float)(param_3 - iVar4);
LAB_0008c4d5:
      if (0.0 <= fVar7) goto LAB_0008c4e2;
LAB_0008c61f:
      fVar8 = 0.0;
    }
    local_24 = local_24 * fVar8;
    iVar5 = *(int *)(param_1 + 0x124);
  }
  if (iVar5 == 0) {
    fVar7 = 0.0;
  }
  else {
    if (param_2 < 0) {
      local_20 = 0;
      iVar4 = local_20;
    }
    else {
      iVar4 = 0x26330;
      if (param_2 < 0x80) {
        iVar4 = local_20;
      }
    }
    local_20 = iVar4;
    fVar8 = 0.0;
    if ((0.0 <= local_24) && (fVar8 = 1.0, local_24 <= 1.0)) {
      fVar8 = local_24;
    }
    fVar7 = *(float *)(iVar5 + local_20 + 0x404);
    fVar7 = (*(float *)(iVar5 + local_20 + 0x474) - fVar7) * fVar8 + fVar7;
  }
LAB_0008c563:
  return (longdouble)fVar7;
}

