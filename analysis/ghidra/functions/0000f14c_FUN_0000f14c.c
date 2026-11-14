/* 0000f14c FUN_0000f14c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0000f14c(int param_1,float param_2,float param_3)

{
  int iVar1;
  int iVar2;
  longdouble lVar3;
  float fVar4;
  float fVar5;
  int local_20;
  
  if (0 < *(int *)(param_1 + 0x380)) {
    local_20 = 0;
    iVar2 = param_1;
    do {
      fVar4 = *(float *)(iVar2 + 0x1fc);
      fVar5 = fVar4;
      if (fVar4 <= param_2) {
        fVar5 = param_2;
      }
      if (((float)(~-(uint)(param_2 < fVar4) & (uint)fVar4 |
                  (uint)param_2 & -(uint)(param_2 < fVar4)) <= param_3) && (param_3 <= fVar5)) {
        if (param_2 == fVar4) {
          fVar4 = 0.0;
          if (1e-10 < ABS(*(float *)(iVar2 + 0x200))) {
            fVar4 = 1.0;
          }
        }
        else {
          lVar3 = (longdouble)FUN_000152c0(param_3 - param_2,fVar4 - param_2);
          fVar4 = (float)lVar3;
          if (1.0 < fVar4) {
            fVar4 = 1.0;
          }
        }
        *(int *)(param_1 + 0x37c) = local_20;
        *(int *)(iVar2 + 0x204) =
             *(int *)(iVar2 + 0x204) - (int)((float)*(int *)(iVar2 + 0x204) * fVar4);
        iVar2 = param_1 + 0x1f0 + *(int *)(param_1 + 0x37c) * 0xc;
        iVar1 = *(int *)(iVar2 + 0x14);
        if (iVar1 < 1) {
          iVar1 = 1;
        }
        *(int *)(iVar2 + 0x14) = iVar1;
        **(float **)(param_1 + 0x1d4) = param_3;
        **(undefined4 **)(param_1 + 0x1d8) =
             *(undefined4 *)(param_1 + 0x200 + *(int *)(param_1 + 0x37c) * 0xc);
        **(undefined4 **)(param_1 + 0x1dc) =
             *(undefined4 *)(param_1 + 0x204 + *(int *)(param_1 + 0x37c) * 0xc);
        return;
      }
      local_20 = local_20 + 1;
      iVar2 = iVar2 + 0xc;
      param_2 = fVar4;
    } while (local_20 < *(int *)(param_1 + 0x380));
  }
  return;
}

