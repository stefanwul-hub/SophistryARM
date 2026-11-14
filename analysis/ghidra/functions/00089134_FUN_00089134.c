/* 00089134 FUN_00089134 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00089134(int *param_1,uint param_2)

{
  float fVar1;
  uint uVar2;
  uint uVar3;
  longdouble lVar4;
  double dVar5;
  double dVar6;
  double local_3c;
  float *local_34;
  float *local_30;
  float *local_24;
  undefined1 local_20 [16];
  
  (**(code **)(*(int *)param_1[0x46] + 0x28))((int *)param_1[0x46],local_20,0);
  (**(code **)(*(int *)param_1[4] + 0x34))((int *)param_1[4],&local_24,0);
  local_34 = (float *)param_1[0x79];
  local_30 = (float *)param_1[0x78];
  if (0 < (int)param_2) {
    uVar3 = 0;
    do {
      uVar2 = uVar3 & 7;
      uVar3 = uVar3 + 1;
      if (uVar2 == 0) {
        fVar1 = *local_30;
        param_1[0x7a] = (int)fVar1;
        local_30 = local_30 + 1;
        param_1[0x7b] = (int)((fVar1 - (float)param_1[0x7c]) * 0.125);
        dVar5 = (double)*local_34;
        local_34 = local_34 + 1;
        dVar6 = 1e-05;
        if ((1e-05 <= dVar5) && (dVar6 = 0.99, dVar5 <= 0.99)) {
          dVar6 = dVar5;
        }
        lVar4 = (longdouble)_pow(dVar6,0,0x3fe00000);
        local_3c = (double)lVar4;
      }
      param_1[0x7c] = (int)((float)param_1[0x7c] + (float)param_1[0x7b]);
      fVar1 = *local_24;
      local_24 = local_24 + 1;
      (**(code **)(*param_1 + 0xcc))
                (param_1,local_20,
                 (float)((double)(fVar1 * (float)param_1[0x7c]) *
                        ((1.0 - local_3c) + local_3c / ((double)ABS(fVar1) + (1.001 - local_3c)))));
    } while (uVar3 != param_2);
  }
  (**(code **)(*(int *)param_1[0x46] + 0x40))((int *)param_1[0x46]);
  return;
}

