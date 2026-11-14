/* 00031bca VariatorTone_c_vslot_63 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void VariatorTone_c_vslot_63
               (int *param_1,uint param_2,float *param_3,float *param_4,float *param_5,
               float *param_6)

{
  uint uVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float *local_38;
  float *local_34;
  float local_30;
  undefined1 local_28 [4];
  undefined1 local_24 [4];
  float *local_20 [4];
  
  (**(code **)(*(int *)param_1[4] + 0x34))((int *)param_1[4],local_20,0);
  (**(code **)(*(int *)param_1[0x46] + 0x2c))((int *)param_1[0x46],local_24,local_28);
  if (0 < (int)param_2) {
    local_38 = param_3;
    local_34 = param_4;
    uVar2 = 0;
    do {
      uVar1 = uVar2 & 7;
      uVar2 = uVar2 + 1;
      if (uVar1 == 0) {
        fVar3 = *local_38;
        local_38 = local_38 + 1;
        local_30 = (fVar3 - *param_5) * 0.125;
        fVar4 = *param_6 * 0.75 + (*local_34 + 1.0) * 0.25;
        *param_6 = fVar4;
        local_34 = local_34 + 1;
        fVar3 = 1e-05;
        if ((1e-05 <= fVar4) && (fVar3 = 1.99999, fVar4 <= 1.99999)) {
          fVar3 = fVar4;
        }
        *param_6 = fVar3;
      }
      fVar3 = *param_5;
      *param_5 = local_30 + fVar3;
      (**(code **)(*param_1 + 0xcc))
                (param_1,local_24,(local_30 + fVar3) * *local_20[0] * (2.0 - *param_6));
      (**(code **)(*param_1 + 0xcc))(param_1,local_28,*local_20[0] * *param_5 * *param_6);
      local_20[0] = local_20[0] + 1;
    } while (uVar2 != param_2);
  }
  (**(code **)(*(int *)param_1[0x46] + 0x44))((int *)param_1[0x46]);
  return;
}

