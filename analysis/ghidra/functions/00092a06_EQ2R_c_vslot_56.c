/* 00092a06 EQ2R_c_vslot_56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void EQ2R_c_vslot_56(int *param_1,int param_2)

{
  float fVar1;
  int *piVar2;
  float *pfVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double local_74;
  double local_6c;
  float *local_60;
  double local_54;
  int local_48;
  int local_44;
  int local_40;
  float *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  float *local_20 [4];
  
  if ((char)param_1[0x57] != '\0') {
    piVar2 = (int *)param_1[4];
    if (*(char *)((int)param_1 + 0x1e1) == '\0') {
      if (*(char *)((int)piVar2 + 0x26) != '\0') {
        (**(code **)(*piVar2 + 0x34))(piVar2,&local_34,0);
        (**(code **)(*(int *)param_1[0x46] + 0x28))((int *)param_1[0x46],&local_24,0);
        local_2c = local_24;
        if (0 < param_2) {
          local_6c = 1e-07;
          local_44 = 0;
          pfVar3 = local_34;
          do {
            local_6c = -local_6c;
            fVar1 = *pfVar3;
            pfVar3 = pfVar3 + 1;
            dVar4 = (((((double)fVar1 + local_6c) * *(double *)(param_1 + 0x7f) +
                       *(double *)(param_1 + 0x91) * *(double *)(param_1 + 0x81) +
                      *(double *)(param_1 + 0x83) * *(double *)(param_1 + 0x93)) -
                     *(double *)(param_1 + 0x7b) * *(double *)(param_1 + 0x99)) -
                    *(double *)(param_1 + 0x7d) * *(double *)(param_1 + 0x9b)) *
                    *(double *)(param_1 + 0x85);
            *(double *)(param_1 + 0x93) = *(double *)(param_1 + 0x91);
            *(double *)(param_1 + 0x91) = (double)fVar1 + local_6c;
            *(undefined8 *)(param_1 + 0x9b) = *(undefined8 *)(param_1 + 0x99);
            *(double *)(param_1 + 0x99) = dVar4;
            (**(code **)(*param_1 + 0xcc))(param_1,&local_2c,(float)dVar4);
            local_44 = local_44 + 1;
          } while (param_2 != local_44);
        }
LAB_00092e26:
        (**(code **)(*(int *)param_1[0x46] + 0x40))((int *)param_1[0x46]);
        return;
      }
      if (*(char *)((int)piVar2 + 0x27) != '\0') {
        (**(code **)(*piVar2 + 0x38))(piVar2,&local_34,local_20);
        (**(code **)(*(int *)param_1[0x46] + 0x2c))((int *)param_1[0x46],&local_24,&local_28);
        local_60 = local_20[0];
        local_2c = local_24;
        local_30 = local_28;
        if (0 < param_2) {
          local_54 = 1e-07;
          local_40 = 0;
          pfVar3 = local_34;
          do {
            dVar6 = (double)*pfVar3 - local_54;
            pfVar3 = pfVar3 + 1;
            local_54 = -local_54;
            fVar1 = *local_60;
            local_60 = local_60 + 1;
            dVar5 = (((dVar6 * *(double *)(param_1 + 0x7f) +
                       *(double *)(param_1 + 0x91) * *(double *)(param_1 + 0x81) +
                      *(double *)(param_1 + 0x83) * *(double *)(param_1 + 0x93)) -
                     *(double *)(param_1 + 0x7b) * *(double *)(param_1 + 0x99)) -
                    *(double *)(param_1 + 0x7d) * *(double *)(param_1 + 0x9b)) *
                    *(double *)(param_1 + 0x85);
            dVar4 = (((*(double *)(param_1 + 0x7f) * ((double)fVar1 + local_54) +
                       *(double *)(param_1 + 0x81) * *(double *)(param_1 + 0x95) +
                      *(double *)(param_1 + 0x83) * *(double *)(param_1 + 0x97)) -
                     *(double *)(param_1 + 0x7b) * *(double *)(param_1 + 0x9d)) -
                    *(double *)(param_1 + 0x7d) * *(double *)(param_1 + 0x9f)) *
                    *(double *)(param_1 + 0x85);
            *(undefined8 *)(param_1 + 0x93) = *(undefined8 *)(param_1 + 0x91);
            *(double *)(param_1 + 0x91) = dVar6;
            *(undefined8 *)(param_1 + 0x9b) = *(undefined8 *)(param_1 + 0x99);
            *(double *)(param_1 + 0x99) = dVar5;
            *(undefined8 *)(param_1 + 0x97) = *(undefined8 *)(param_1 + 0x95);
            *(double *)(param_1 + 0x95) = (double)fVar1 + local_54;
            *(undefined8 *)(param_1 + 0x9f) = *(undefined8 *)(param_1 + 0x9d);
            *(double *)(param_1 + 0x9d) = dVar4;
            (**(code **)(*param_1 + 0xcc))(param_1,&local_2c,(float)dVar5);
            (**(code **)(*param_1 + 0xcc))(param_1,&local_30,(float)dVar4);
            local_40 = local_40 + 1;
          } while (param_2 != local_40);
        }
        (**(code **)(*(int *)param_1[0x46] + 0x44))((int *)param_1[0x46]);
        return;
      }
    }
    else {
      if (*(char *)((int)piVar2 + 0x26) != '\0') {
        (**(code **)(*piVar2 + 0x34))(piVar2,&local_34,0);
        (**(code **)(*(int *)param_1[0x46] + 0x28))((int *)param_1[0x46],&local_24,0);
        local_2c = local_24;
        if (0 < param_2) {
          local_74 = 1e-07;
          local_48 = 0;
          pfVar3 = local_34;
          do {
            local_74 = -local_74;
            fVar1 = *pfVar3;
            pfVar3 = pfVar3 + 1;
            dVar5 = (((((double)fVar1 + local_74) * *(double *)(param_1 + 0x7f) +
                       *(double *)(param_1 + 0x91) * *(double *)(param_1 + 0x81) +
                      *(double *)(param_1 + 0x83) * *(double *)(param_1 + 0x93)) -
                     *(double *)(param_1 + 0x7b) * *(double *)(param_1 + 0x99)) -
                    *(double *)(param_1 + 0x7d) * *(double *)(param_1 + 0x9b)) *
                    *(double *)(param_1 + 0x85);
            dVar4 = (((dVar5 * *(double *)(param_1 + 0xa7) +
                       *(double *)(param_1 + 0xa9) * *(double *)(param_1 + 0xb9) +
                      *(double *)(param_1 + 0xab) * *(double *)(param_1 + 0xbb)) -
                     *(double *)(param_1 + 0xa3) * *(double *)(param_1 + 0xc1)) -
                    *(double *)(param_1 + 0xa5) * *(double *)(param_1 + 0xc3)) *
                    *(double *)(param_1 + 0xad);
            *(double *)(param_1 + 0x93) = *(double *)(param_1 + 0x91);
            *(double *)(param_1 + 0x91) = (double)fVar1 + local_74;
            *(undefined8 *)(param_1 + 0x9b) = *(undefined8 *)(param_1 + 0x99);
            *(double *)(param_1 + 0x99) = dVar5;
            *(undefined8 *)(param_1 + 0xbb) = *(undefined8 *)(param_1 + 0xb9);
            *(double *)(param_1 + 0xb9) = dVar5;
            *(undefined8 *)(param_1 + 0xc3) = *(undefined8 *)(param_1 + 0xc1);
            *(double *)(param_1 + 0xc1) = dVar4;
            (**(code **)(*param_1 + 0xcc))(param_1,&local_2c,(float)dVar4);
            local_48 = local_48 + 1;
          } while (param_2 != local_48);
        }
        goto LAB_00092e26;
      }
      if (*(char *)((int)piVar2 + 0x27) != '\0') {
        (**(code **)(*piVar2 + 0x38))(piVar2,&local_34,local_20);
        (**(code **)(*(int *)param_1[0x46] + 0x2c))((int *)param_1[0x46],&local_24,&local_28);
        FUN_00091ec2(param_1,param_2,local_34,local_20[0],local_24,local_28);
        (**(code **)(*(int *)param_1[0x46] + 0x44))((int *)param_1[0x46]);
        return;
      }
    }
  }
  return;
}

