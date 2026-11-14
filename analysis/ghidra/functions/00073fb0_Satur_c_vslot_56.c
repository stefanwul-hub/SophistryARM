/* 00073fb0 Satur_c_vslot_56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Satur_c_vslot_56(int *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  float *local_2c;
  float *local_28;
  float *local_24;
  float *local_20 [4];
  
  if (*(char *)(param_1[4] + 0x26) == '\0') {
    if ((*(char *)(param_1[4] + 0x27) != '\0') && (param_1[0x49] != 0)) {
      (**(code **)(*(int *)param_1[0x46] + 0x2c))((int *)param_1[0x46],local_20,&local_24);
      (**(code **)(*(int *)param_1[4] + 0x38))((int *)param_1[4],&local_28,&local_2c);
      if ((local_28 == local_20[0]) && (local_2c == local_24)) {
        if (0 < param_2) {
          iVar2 = 0;
          do {
            *local_20[0] = *local_20[0] *
                           ((float)param_1[0x79] +
                           (float)param_1[0x78] / (ABS(*local_20[0]) + (float)param_1[0x79]));
            local_20[0] = local_20[0] + 1;
            *local_24 = *local_24 *
                        ((float)param_1[0x79] +
                        (float)param_1[0x78] / (ABS(*local_24) + (float)param_1[0x79]));
            local_24 = local_24 + 1;
            iVar2 = iVar2 + 1;
          } while (param_2 != iVar2);
        }
      }
      else if (0 < param_2) {
        iVar2 = 0;
        do {
          fVar1 = *local_2c;
          (**(code **)(*param_1 + 0xcc))
                    (param_1,local_20,
                     *local_28 *
                     ((float)param_1[0x79] +
                     (float)param_1[0x78] / (ABS(*local_28) + (float)param_1[0x79])));
          (**(code **)(*param_1 + 0xcc))
                    (param_1,&local_24,
                     fVar1 * ((float)param_1[0x79] +
                             (float)param_1[0x78] / (ABS(fVar1) + (float)param_1[0x79])));
          iVar2 = iVar2 + 1;
        } while (param_2 != iVar2);
      }
      (**(code **)(*(int *)param_1[0x46] + 0x44))((int *)param_1[0x46]);
      return;
    }
  }
  else if (param_1[0x49] != 0) {
    (**(code **)(*(int *)param_1[0x46] + 0x28))((int *)param_1[0x46],&local_24,0);
    (**(code **)(*(int *)param_1[4] + 0x34))((int *)param_1[4],local_20,0);
    if (local_20[0] == local_24) {
      if (0 < param_2) {
        iVar2 = 0;
        do {
          *local_24 = *local_24 *
                      ((float)param_1[0x79] +
                      (float)param_1[0x78] / (ABS(*local_24) + (float)param_1[0x79]));
          local_24 = local_24 + 1;
          iVar2 = iVar2 + 1;
        } while (param_2 != iVar2);
      }
    }
    else if (0 < param_2) {
      iVar2 = 0;
      do {
        fVar1 = *local_20[0];
        local_20[0] = local_20[0] + 1;
        (**(code **)(*param_1 + 0xcc))
                  (param_1,&local_24,
                   fVar1 * ((float)param_1[0x79] +
                           (float)param_1[0x78] / (ABS(fVar1) + (float)param_1[0x79])));
        iVar2 = iVar2 + 1;
      } while (param_2 != iVar2);
    }
    (**(code **)(*(int *)param_1[0x46] + 0x40))((int *)param_1[0x46]);
  }
  return;
}

