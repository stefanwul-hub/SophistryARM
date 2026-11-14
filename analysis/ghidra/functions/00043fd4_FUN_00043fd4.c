/* 00043fd4 FUN_00043fd4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00043fd4(int *param_1,int param_2,float *param_3,float *param_4)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  uint uVar4;
  float fVar5;
  double dVar6;
  float fVar7;
  float fVar8;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  float *local_20 [4];
  
  if ((char)param_1[0x7b] == '\0') {
    if (*(char *)((int)param_1 + 0x20d) == '\0') {
      local_20[0] = param_4;
      if (0 < param_2) {
        local_30 = 0;
        do {
          fVar7 = *param_3;
          param_3 = param_3 + 1;
          fVar7 = ((float)(int)((fVar7 + 1.0001) * (float)param_1[0x79] + 0.5) *
                   (float)param_1[0x7a] - 0.998) - (float)param_1[0xa1];
          param_1[0xa1] = (int)((float)param_1[0xa1] + fVar7 * 5e-05);
          (**(code **)(*param_1 + 0xd0))(param_1,local_20,fVar7);
          local_30 = local_30 + 1;
        } while (param_2 != local_30);
      }
    }
    else {
      local_20[0] = param_4;
      if (0 < param_2) {
        local_34 = 0;
        do {
          fVar7 = *param_3;
          param_3 = param_3 + 1;
          fVar8 = (float)param_1[0x7e];
          if (fVar8 < fVar7) {
            param_1[0x7e] = (int)fVar7;
          }
          else {
            fVar5 = -fVar7;
            if (fVar5 <= fVar8) {
              uVar4 = -(uint)(0.01 <= fVar8 * (float)param_1[0x7f]);
              fVar5 = (float)(~uVar4 & (uint)0.01 | (uint)(fVar8 * (float)param_1[0x7f]) & uVar4);
            }
            param_1[0x7e] = (int)fVar5;
          }
          fVar7 = ((float)(int)((fVar7 / (float)param_1[0x7e] + 1.0001) * (float)param_1[0x79] + 0.5
                               ) * (float)param_1[0x7a] - 0.998) - (float)param_1[0xa1];
          param_1[0xa1] = (int)((float)param_1[0xa1] + fVar7 * 5e-05);
          (**(code **)(*param_1 + 0xd0))(param_1,local_20,fVar7 * (float)param_1[0x7e]);
          local_34 = local_34 + 1;
        } while (param_2 != local_34);
      }
    }
  }
  else if (*(char *)((int)param_1 + 0x20d) == '\0') {
    local_20[0] = param_4;
    if (0 < param_2) {
      local_38 = 0;
      do {
        fVar7 = (float)param_1[0x7c] * 0.5 + *param_3;
        param_3 = param_3 + 1;
        fVar8 = (float)(int)((fVar7 + 1.0001) * (float)param_1[0x79] + 0.5) * (float)param_1[0x7a] -
                0.998;
        param_1[0x7c] = (int)(fVar7 - fVar8);
        fVar8 = fVar8 - (float)param_1[0xa1];
        param_1[0xa1] = (int)((float)param_1[0xa1] + fVar8 * 5e-05);
        (**(code **)(*param_1 + 0xd0))(param_1,local_20,fVar8);
        local_38 = local_38 + 1;
      } while (param_2 != local_38);
    }
  }
  else {
    local_20[0] = param_4;
    if (0 < param_2) {
      local_3c = 0;
      do {
        fVar7 = *param_3;
        param_3 = param_3 + 1;
        fVar8 = (float)param_1[0x7e];
        if (fVar8 < fVar7) {
          param_1[0x7e] = (int)fVar7;
        }
        else {
          fVar5 = -fVar7;
          if (fVar5 <= fVar8) {
            uVar4 = -(uint)(0.01 <= fVar8 * (float)param_1[0x7f]);
            fVar5 = (float)(~uVar4 & (uint)0.01 | (uint)(fVar8 * (float)param_1[0x7f]) & uVar4);
          }
          param_1[0x7e] = (int)fVar5;
        }
        fVar8 = (float)(int)((fVar7 / (float)param_1[0x7e] + (float)param_1[0x7c] * 0.5 + 1.0001) *
                             (float)param_1[0x79] + 0.5) * (float)param_1[0x7a] - 0.998;
        param_1[0x7c] = (int)(fVar7 - fVar8);
        fVar8 = fVar8 - (float)param_1[0xa1];
        param_1[0xa1] = (int)((float)param_1[0xa1] + fVar8 * 5e-05);
        (**(code **)(*param_1 + 0xd0))(param_1,local_20,fVar8 * (float)param_1[0x7e]);
        local_3c = local_3c + 1;
      } while (param_2 != local_3c);
    }
  }
  if (((char)param_1[0x83] == '\0') && (*(char *)((int)param_1 + 0x1e1) != '\0')) {
    iVar3 = param_1[0x82];
    if (iVar3 == 2) {
      local_20[0] = param_4;
      if (0 < param_2) {
        local_48 = 0;
        pfVar2 = param_4;
        do {
          dVar6 = ((double)*pfVar2 - *(double *)(param_1 + 0x88)) -
                  (1.0 - (double)(float)param_1[0x85]) * *(double *)(param_1 + 0x8c);
          *(double *)(param_1 + 0x8a) = dVar6;
          pfVar2 = pfVar2 + 1;
          dVar6 = dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x8c);
          *(double *)(param_1 + 0x8c) = dVar6;
          *(double *)(param_1 + 0x88) =
               dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x88);
          (**(code **)(*param_1 + 0xd0))(param_1,local_20,(float)*(double *)(param_1 + 0x8a));
          local_48 = local_48 + 1;
        } while (param_2 != local_48);
      }
    }
    else if (iVar3 < 3) {
      if ((iVar3 == 1) && (local_20[0] = param_4, 0 < param_2)) {
        local_4c = 0;
        pfVar2 = param_4;
        do {
          dVar6 = ((double)*pfVar2 - *(double *)(param_1 + 0x88)) -
                  (1.0 - (double)(float)param_1[0x85]) * *(double *)(param_1 + 0x8c);
          *(double *)(param_1 + 0x8a) = dVar6;
          pfVar2 = pfVar2 + 1;
          dVar6 = dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x8c);
          *(double *)(param_1 + 0x8c) = dVar6;
          dVar6 = dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x88);
          *(double *)(param_1 + 0x88) = dVar6;
          (**(code **)(*param_1 + 0xd0))(param_1,local_20,(float)dVar6);
          local_4c = local_4c + 1;
        } while (local_4c != param_2);
      }
    }
    else if (iVar3 == 3) {
      local_20[0] = param_4;
      if (0 < param_2) {
        local_44 = 0;
        pfVar2 = param_4;
        do {
          dVar6 = ((double)*pfVar2 - *(double *)(param_1 + 0x88)) -
                  (1.0 - (double)(float)param_1[0x85]) * *(double *)(param_1 + 0x8c);
          *(double *)(param_1 + 0x8a) = dVar6;
          pfVar2 = pfVar2 + 1;
          dVar6 = dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x8c);
          *(double *)(param_1 + 0x8c) = dVar6;
          *(double *)(param_1 + 0x88) =
               dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x88);
          (**(code **)(*param_1 + 0xd0))(param_1,local_20,(float)*(double *)(param_1 + 0x8c));
          local_44 = local_44 + 1;
        } while (param_2 != local_44);
      }
    }
    else if ((iVar3 == 4) && (local_20[0] = param_4, 0 < param_2)) {
      local_40 = 0;
      pfVar2 = param_4;
      do {
        dVar6 = ((double)*pfVar2 - *(double *)(param_1 + 0x88)) -
                (1.0 - (double)(float)param_1[0x85]) * *(double *)(param_1 + 0x8c);
        *(double *)(param_1 + 0x8a) = dVar6;
        pfVar2 = pfVar2 + 1;
        dVar6 = dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x8c);
        *(double *)(param_1 + 0x8c) = dVar6;
        dVar6 = dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x88);
        *(double *)(param_1 + 0x88) = dVar6;
        (**(code **)(*param_1 + 0xd0))
                  (param_1,local_20,(float)(dVar6 + *(double *)(param_1 + 0x8a)));
        local_40 = local_40 + 1;
      } while (param_2 != local_40);
    }
  }
  if ((char)param_1[0x8e] != '\0') {
    iVar3 = param_1[0x8f];
    if (iVar3 == 2) {
      local_20[0] = param_4;
      if (0 < param_2) {
        iVar3 = 0;
        do {
          iVar1 = param_1[0x92];
          param_1[0x92] = iVar1 + -1;
          if (iVar1 + -1 < 1) {
            param_1[0x90] = (int)param_4[iVar3];
            param_1[0x92] = param_1[0x93];
          }
          (**(code **)(*param_1 + 0xd0))(param_1,local_20,param_1[0x90]);
          iVar3 = iVar3 + 1;
        } while (param_2 != iVar3);
      }
    }
    else if (iVar3 == 3) {
      local_20[0] = param_4;
      if (0 < param_2) {
        iVar3 = 0;
        do {
          iVar1 = param_1[0x92];
          param_1[0x92] = iVar1 + -1;
          if (iVar1 + -1 < 1) {
            param_1[0x91] = (int)((param_4[iVar3] - (float)param_1[0x90]) * (float)param_1[0x94]);
            param_1[0x92] = param_1[0x93];
          }
          fVar7 = (float)param_1[0x90];
          param_1[0x90] = (int)(fVar7 + (float)param_1[0x91]);
          (**(code **)(*param_1 + 0xd0))(param_1,local_20,fVar7 + (float)param_1[0x91]);
          iVar3 = iVar3 + 1;
        } while (iVar3 != param_2);
      }
    }
    else if ((iVar3 == 1) && (local_20[0] = param_4, 0 < param_2)) {
      local_50 = 0;
      pfVar2 = param_4;
      do {
        fVar7 = (float)param_1[0x90] * (float)param_1[0x95] + *pfVar2 * (float)param_1[0x94];
        param_1[0x90] = (int)fVar7;
        pfVar2 = pfVar2 + 1;
        (**(code **)(*param_1 + 0xd0))(param_1,local_20,fVar7);
        local_50 = local_50 + 1;
      } while (param_2 != local_50);
    }
  }
  if (((char)param_1[0x83] != '\0') && (*(char *)((int)param_1 + 0x1e1) != '\0')) {
    iVar3 = param_1[0x82];
    if (iVar3 == 2) {
      local_20[0] = param_4;
      if (0 < param_2) {
        iVar3 = 0;
        do {
          dVar6 = ((double)*param_4 - *(double *)(param_1 + 0x88)) -
                  (1.0 - (double)(float)param_1[0x85]) * *(double *)(param_1 + 0x8c);
          *(double *)(param_1 + 0x8a) = dVar6;
          param_4 = param_4 + 1;
          dVar6 = dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x8c);
          *(double *)(param_1 + 0x8c) = dVar6;
          *(double *)(param_1 + 0x88) =
               dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x88);
          (**(code **)(*param_1 + 0xd0))(param_1,local_20,(float)*(double *)(param_1 + 0x8a));
          iVar3 = iVar3 + 1;
        } while (param_2 != iVar3);
      }
    }
    else if (iVar3 < 3) {
      if ((iVar3 == 1) && (local_20[0] = param_4, 0 < param_2)) {
        iVar3 = 0;
        do {
          dVar6 = ((double)*param_4 - *(double *)(param_1 + 0x88)) -
                  (1.0 - (double)(float)param_1[0x85]) * *(double *)(param_1 + 0x8c);
          *(double *)(param_1 + 0x8a) = dVar6;
          param_4 = param_4 + 1;
          dVar6 = dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x8c);
          *(double *)(param_1 + 0x8c) = dVar6;
          dVar6 = dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x88);
          *(double *)(param_1 + 0x88) = dVar6;
          (**(code **)(*param_1 + 0xd0))(param_1,local_20,(float)dVar6);
          iVar3 = iVar3 + 1;
        } while (param_2 != iVar3);
      }
    }
    else if (iVar3 == 3) {
      local_20[0] = param_4;
      if (0 < param_2) {
        iVar3 = 0;
        do {
          dVar6 = ((double)*param_4 - *(double *)(param_1 + 0x88)) -
                  (1.0 - (double)(float)param_1[0x85]) * *(double *)(param_1 + 0x8c);
          *(double *)(param_1 + 0x8a) = dVar6;
          param_4 = param_4 + 1;
          dVar6 = dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x8c);
          *(double *)(param_1 + 0x8c) = dVar6;
          *(double *)(param_1 + 0x88) =
               dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x88);
          (**(code **)(*param_1 + 0xd0))(param_1,local_20,(float)*(double *)(param_1 + 0x8c));
          iVar3 = iVar3 + 1;
        } while (param_2 != iVar3);
      }
    }
    else if ((iVar3 == 4) && (local_20[0] = param_4, 0 < param_2)) {
      iVar3 = 0;
      do {
        dVar6 = ((double)*param_4 - *(double *)(param_1 + 0x88)) -
                (1.0 - (double)(float)param_1[0x85]) * *(double *)(param_1 + 0x8c);
        *(double *)(param_1 + 0x8a) = dVar6;
        param_4 = param_4 + 1;
        dVar6 = dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x8c);
        *(double *)(param_1 + 0x8c) = dVar6;
        dVar6 = dVar6 * *(double *)(param_1 + 0x86) + *(double *)(param_1 + 0x88);
        *(double *)(param_1 + 0x88) = dVar6;
        (**(code **)(*param_1 + 0xd0))
                  (param_1,local_20,(float)(dVar6 + *(double *)(param_1 + 0x8a)));
        iVar3 = iVar3 + 1;
      } while (param_2 != iVar3);
    }
  }
  return;
}

