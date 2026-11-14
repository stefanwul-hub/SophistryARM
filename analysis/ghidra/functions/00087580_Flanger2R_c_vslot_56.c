/* 00087580 Flanger2R_c_vslot_56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Flanger2R_c_vslot_56(int *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint local_38;
  float *local_2c;
  float *local_28;
  undefined1 local_24 [4];
  undefined1 local_20 [16];
  
  (**(code **)(*(int *)param_1[0x46] + 0x2c))((int *)param_1[0x46],local_20,local_24);
  (**(code **)(*(int *)param_1[4] + 0x38))((int *)param_1[4],&local_28,&local_2c);
  if (0 < (int)param_2) {
    local_38 = 0;
    do {
      uVar1 = local_38 & 7;
      local_38 = local_38 + 1;
      if (uVar1 == 0) {
        fVar6 = (float)param_1[0x85];
        fVar7 = (float)param_1[0x8b] * 0.0027777778 + fVar6;
        if (1.0 < fVar7) {
          fVar7 = fVar7 - 1.0;
        }
        if (0.5 <= fVar6) {
          param_1[0x87] = (int)((1.0 - fVar6) * 4.0 - 1.0);
        }
        else {
          param_1[0x87] = (int)(fVar6 * 4.0 - 1.0);
        }
        if (0.5 <= fVar7) {
          fVar7 = 1.0 - fVar7;
        }
        fVar6 = fVar6 + (float)param_1[0x86];
        param_1[0x85] = (int)fVar6;
        if (1.0 < fVar6) {
          param_1[0x85] = (int)(fVar6 - 1.0);
        }
        *(double *)(param_1 + 0x7e) =
             ((double)((float)param_1[0x82] -
                      ((float)param_1[0x8c] * (float)param_1[0x87] + 1.0) * (float)param_1[0x8e]) -
             *(double *)(param_1 + 0x7a)) * 0.125;
        *(double *)(param_1 + 0x80) =
             ((double)((float)param_1[0x82] -
                      (float)param_1[0x8e] * ((fVar7 * 4.0 - 1.0) * (float)param_1[0x8c] + 1.0)) -
             *(double *)(param_1 + 0x7c)) * 0.125;
      }
      fVar6 = *local_28;
      local_28 = local_28 + 1;
      fVar7 = *local_2c;
      local_2c = local_2c + 1;
      uVar2 = (uint)*(double *)(param_1 + 0x7a);
      fVar8 = (float)(*(double *)(param_1 + 0x7a) - (double)(int)uVar2);
      uVar3 = (uint)*(double *)(param_1 + 0x7c);
      fVar4 = (float)(*(double *)(param_1 + 0x7c) - (double)(int)uVar3);
      uVar1 = param_1[0x79];
      fVar8 = fVar8 * *(float *)(param_1[0x83] + (uVar2 + 1 & uVar1) * 4) +
              (1.0 - fVar8) * *(float *)(param_1[0x83] + (uVar2 & uVar1) * 4);
      fVar5 = fVar4 * *(float *)(param_1[0x84] + (uVar1 & uVar3 + 1) * 4) +
              (1.0 - fVar4) * *(float *)(param_1[0x84] + (uVar3 & uVar1) * 4);
      (**(code **)(*param_1 + 0xcc))
                (param_1,local_20,
                 fVar8 * (float)param_1[0x88] * ((float)param_1[0x87] * (float)param_1[0x8d] + 1.0)
                 + fVar6);
      (**(code **)(*param_1 + 0xcc))
                (param_1,local_24,
                 fVar5 * (float)param_1[0x88] * (1.0 - (float)param_1[0x87] * (float)param_1[0x8d])
                 + fVar7);
      fVar6 = fVar8 * (float)param_1[0x8a] + fVar6;
      fVar4 = -1.0;
      fVar8 = fVar4;
      if ((-1.0 <= fVar6) && (fVar8 = 1.0, fVar6 <= 1.0)) {
        fVar8 = fVar6;
      }
      *(float *)(param_1[0x83] + (param_1[0x82] & param_1[0x79]) * 4) = fVar8;
      uVar1 = param_1[0x82];
      fVar7 = fVar5 * (float)param_1[0x8a] + fVar7;
      if ((-1.0 <= fVar7) && (fVar4 = 1.0, fVar7 <= 1.0)) {
        fVar4 = fVar7;
      }
      *(float *)(param_1[0x84] + (uVar1 & param_1[0x79]) * 4) = fVar4;
      param_1[0x82] = uVar1 + 1;
      *(double *)(param_1 + 0x7a) = *(double *)(param_1 + 0x7a) + *(double *)(param_1 + 0x7e);
      *(double *)(param_1 + 0x7c) = *(double *)(param_1 + 0x7c) + *(double *)(param_1 + 0x80);
    } while (local_38 != param_2);
  }
  (**(code **)(*(int *)param_1[0x46] + 0x44))((int *)param_1[0x46]);
  return;
}

