/* 0006d9aa Delay2R_c_vslot_31 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Delay2R_c_vslot_31(int param_1)

{
  float fVar1;
  int iVar2;
  longdouble lVar3;
  float fVar4;
  float fVar5;
  
  iVar2 = *(int *)(param_1 + 0x124);
  if ((iVar2 != 0) && (*(char *)(param_1 + 0x15c) != '\0')) {
    *(bool *)(param_1 + 0xa40) = *(int *)(iVar2 + 0x468) == 0;
    fVar4 = -*(float *)(iVar2 + 0x46c);
    *(float *)(param_1 + 0xa24) = fVar4;
    *(bool *)(param_1 + 0xa41) = 0.0 < fVar4;
    if (fVar4 <= 0.0) {
      fVar4 = (fVar4 * 0.996 * fVar4 + 0.004) * 0.125;
      *(float *)(param_1 + 0xa24) = fVar4;
      *(float *)(param_1 + 0xa24) = fVar4 * *(float *)(param_1 + 0x144) * 44100.0;
    }
    else {
      fVar4 = (1.0 - fVar4) * 0.996 + 0.04;
      *(float *)(param_1 + 0xa24) = fVar4;
      *(float *)(param_1 + 0xa24) = fVar4 * *(float *)(param_1 + 0x144) * 44100.0;
    }
    fVar4 = 1.0;
    if (*(float *)(param_1 + 0xa24) <= 1.0) {
      fVar4 = *(float *)(param_1 + 0xa24);
    }
    *(float *)(param_1 + 0xa24) = fVar4;
    fVar4 = *(float *)(param_1 + 0xa28);
    fVar5 = *(float *)(iVar2 + 0xec) * 0.001;
    if (*(int *)(iVar2 + 0x414) < *(int *)(iVar2 + 0x3f8)) {
      lVar3 = (longdouble)FUN_0001354c(param_1,*(int *)(iVar2 + 0x3f8));
      fVar5 = (float)lVar3;
    }
    for (; fVar1 = *(float *)(param_1 + 0x140) * fVar5, (float)*(int *)(param_1 + 0xa48) <= fVar1;
        fVar5 = fVar5 * 0.5) {
    }
    *(float *)(param_1 + 0xa28) = fVar1;
    if (100.0 < ABS(fVar4 - fVar1)) {
      Crossfader_c_vslot_2
                (param_1 + 0xa50,*(undefined8 *)(param_1 + 0x1e0),*(undefined8 *)(param_1 + 0x1f0));
      Crossfader_c_vslot_2
                (param_1 + 0xa74,*(undefined8 *)(param_1 + 0x1e8),*(undefined8 *)(param_1 + 0x1f8));
    }
    iVar2 = *(int *)(param_1 + 0x124);
    *(undefined4 *)(param_1 + 0xa2c) = *(undefined4 *)(iVar2 + 0x2ac);
    if (*(int *)(iVar2 + 0x4f4) < *(int *)(iVar2 + 0x4d8)) {
      lVar3 = (longdouble)FUN_0001329c(param_1,*(int *)(iVar2 + 0x4d8));
      *(float *)(param_1 + 0xa2c) = (float)lVar3;
      iVar2 = *(int *)(param_1 + 0x124);
    }
    *(float *)(param_1 + 0xa30) =
         *(float *)(param_1 + 0xa2c) * 512.0 * *(float *)(param_1 + 0x144) * 8.0;
    *(undefined4 *)(param_1 + 0xa34) = *(undefined4 *)(iVar2 + 0x31c);
    *(undefined4 *)(param_1 + 0xa38) = *(undefined4 *)(iVar2 + 0x23c);
    *(float *)(param_1 + 0xa3c) = *(float *)(iVar2 + 0x15c) * 0.5;
  }
  return;
}

