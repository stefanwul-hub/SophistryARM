/* 000894d6 FUN_000894d6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000894d6(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float *local_24;
  float *local_20 [4];
  
  if (param_1[0x49] == 0) {
    return;
  }
  (**(code **)(*(int *)param_1[0x46] + 0x28))((int *)param_1[0x46],local_20,0);
  (**(code **)(*(int *)param_1[4] + 0x34))((int *)param_1[4],&local_24,0);
  fVar3 = *(float *)(param_1[0x49] + 0xec) + (float)param_1[0x5d];
  if ((0.0 <= fVar3) || (NAN(fVar3))) {
    fVar1 = 1.0;
    if (fVar3 <= 1.0) {
      fVar1 = fVar3;
    }
  }
  else {
    fVar1 = 0.0;
  }
  if (local_24 == local_20[0]) {
    if (0 < param_2) {
      iVar2 = 0;
      do {
        fVar3 = *local_24;
        *local_24 = (1.0 - fVar1) * fVar3 + fVar3 * ((1.0 - ABS(fVar3)) * 4.0 + 1.0) * fVar1 * 0.5;
        local_24 = local_24 + 1;
        iVar2 = iVar2 + 1;
      } while (param_2 != iVar2);
      (**(code **)(*(int *)param_1[0x46] + 0x40))((int *)param_1[0x46]);
      return;
    }
  }
  else if (0 < param_2) {
    iVar2 = 0;
    do {
      fVar3 = *local_24;
      local_24 = local_24 + 1;
      (**(code **)(*param_1 + 0xcc))
                (param_1,local_20,
                 (1.0 - fVar1) * fVar3 + fVar3 * ((1.0 - ABS(fVar3)) * 4.0 + 1.0) * fVar1 * 0.5);
      iVar2 = iVar2 + 1;
    } while (iVar2 != param_2);
  }
  (**(code **)(*(int *)param_1[0x46] + 0x40))((int *)param_1[0x46]);
  return;
}

