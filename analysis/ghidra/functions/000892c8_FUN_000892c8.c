/* 000892c8 FUN_000892c8 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000892c8(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  float fVar4;
  double dVar5;
  float *local_24;
  float *local_20 [4];
  
  if (param_1[0x49] != 0) {
    (**(code **)(*(int *)param_1[0x46] + 0x28))((int *)param_1[0x46],local_20,0);
    (**(code **)(*(int *)param_1[4] + 0x34))((int *)param_1[4],&local_24,0);
    fVar4 = *(float *)(param_1[0x49] + 0xec) + (float)param_1[0x5d];
    if ((0.0 <= fVar4) || (NAN(fVar4))) {
      if (1.0 < fVar4) {
        dVar5 = 1.0;
      }
      else {
        dVar5 = (double)fVar4;
      }
    }
    else {
      dVar5 = 0.0;
    }
    lVar3 = (longdouble)_pow(dVar5,0,0x3fe00000);
    fVar4 = (float)lVar3;
    if (local_24 == local_20[0]) {
      if (0 < param_2) {
        iVar2 = 0;
        do {
          fVar1 = *local_24;
          local_24 = local_24 + 1;
          *local_20[0] = fVar1 * (fVar4 / (ABS(fVar1) + (1.001 - fVar4)) + (1.0 - fVar4));
          local_20[0] = local_20[0] + 1;
          iVar2 = iVar2 + 1;
        } while (param_2 != iVar2);
        (**(code **)(*(int *)param_1[0x46] + 0x40))((int *)param_1[0x46]);
        return;
      }
    }
    else if (0 < param_2) {
      iVar2 = 0;
      do {
        fVar1 = *local_24;
        local_24 = local_24 + 1;
        (**(code **)(*param_1 + 0xcc))
                  (param_1,local_20,fVar1 * (fVar4 / (ABS(fVar1) + (1.001 - fVar4)) + (1.0 - fVar4))
                  );
        iVar2 = iVar2 + 1;
      } while (param_2 != iVar2);
    }
    (**(code **)(*(int *)param_1[0x46] + 0x40))((int *)param_1[0x46]);
  }
  return;
}

