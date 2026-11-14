/* 0000f394 FUN_0000f394 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0000f394(int param_1,float param_2,int param_3,float param_4,undefined4 *param_5,
                 undefined4 *param_6)

{
  float fVar1;
  int iVar2;
  int iVar3;
  longdouble lVar4;
  float fVar5;
  double dVar6;
  float fVar7;
  float local_38;
  float local_2c;
  int local_28;
  
  if (1.0 < param_4) {
    local_38 = 1.0 / (2.0 - param_4);
  }
  else {
    local_38 = 1.0 / param_4;
  }
  iVar2 = (int)(*(float *)(param_1 + 0x140) * 0.0125);
  if (0 < iVar2) {
    lVar4 = (longdouble)FUN_000152c0(**(float **)(param_1 + 0x1d4) + 1.0,param_2 + 1.0);
    if ((1.01 < (float)lVar4) || ((float)lVar4 < 0.99)) {
      iVar2 = (int)((float)param_3 / (float)iVar2 + 0.5);
      *(int *)(param_1 + 0x380) = iVar2;
    }
    else {
      *(undefined4 *)(param_1 + 0x380) = 1;
      iVar2 = *(int *)(param_1 + 0x380);
    }
    if (iVar2 < 1) {
      iVar2 = 1;
    }
    else if (0x20 < iVar2) {
      iVar2 = 0x20;
    }
    *(int *)(param_1 + 0x380) = iVar2;
    iVar2 = *(int *)(param_1 + 0x380);
    fVar1 = **(float **)(param_1 + 0x1d4);
    *(undefined4 *)(param_1 + 0x37c) = 0;
    if (0 < *(int *)(param_1 + 0x380)) {
      local_28 = 0;
      iVar3 = 0;
      local_2c = fVar1;
      do {
        fVar5 = (float)(iVar3 + 1) * (0.999999 / (float)iVar2);
        if (1.0 < param_4) {
          lVar4 = (longdouble)_pow((double)fVar5,(double)local_38);
          dVar6 = 1.0 - (double)lVar4;
        }
        else {
          lVar4 = (longdouble)_pow((double)(1.0 - fVar5),(double)local_38);
          dVar6 = (double)lVar4;
        }
        fVar7 = 1.0;
        fVar5 = (1.0 - (float)dVar6) * (param_2 - fVar1) + fVar1;
        *(float *)(param_1 + 0x1fc + iVar3 * 0xc) = fVar5;
        lVar4 = (longdouble)
                FUN_000152c0((float)(param_3 - local_28),
                             (float)(*(int *)(param_1 + 0x380) - *(int *)(param_1 + 0x37c)));
        iVar3 = (int)lVar4;
        if (iVar3 < 1) {
          iVar3 = 1;
        }
        else {
          fVar7 = (float)iVar3;
        }
        *(int *)(param_1 + 0x204 + *(int *)(param_1 + 0x37c) * 0xc) = iVar3;
        *(float *)(param_1 + 0x200 + *(int *)(param_1 + 0x37c) * 0xc) = (fVar5 - local_2c) / fVar7;
        local_28 = local_28 + iVar3;
        iVar3 = *(int *)(param_1 + 0x37c) + 1;
        *(int *)(param_1 + 0x37c) = iVar3;
        local_2c = fVar5;
      } while (iVar3 < *(int *)(param_1 + 0x380));
    }
    *(undefined4 *)(param_1 + 0x37c) = 0;
    *param_5 = *(undefined4 *)(param_1 + 0x200);
    *param_6 = *(undefined4 *)(param_1 + 0x204 + *(int *)(param_1 + 0x37c) * 0xc);
    return;
  }
  return;
}

