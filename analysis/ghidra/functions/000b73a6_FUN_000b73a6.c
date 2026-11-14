/* 000b73a6 FUN_000b73a6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000b73a6(int *param_1,int param_2)

{
  float *pfVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  int local_4c;
  int local_34;
  int local_30;
  undefined1 local_2c [4];
  undefined1 local_28 [4];
  float *local_24;
  float *local_20 [4];
  
  (**(code **)(*(int *)param_1[0x46] + 0x2c))((int *)param_1[0x46],local_28,local_2c);
  (**(code **)(*(int *)param_1[4] + 0x38))((int *)param_1[4],local_20,&local_24);
  if (0 < param_2) {
    local_34 = 0;
    do {
      pfVar1 = (float *)(param_1[0x1d2] + param_1[0x1d5] * 4);
      fVar10 = *pfVar1;
      *pfVar1 = (*local_20[0] + *local_24) * 0.5;
      iVar5 = param_1[0x1d5];
      param_1[0x1d5] = iVar5 + 1;
      if (param_1[0x1d7] <= iVar5 + 1) {
        param_1[0x1d5] = 0;
      }
      fVar10 = fVar10 * (float)param_1[0x21a];
      fVar9 = 0.0;
      fVar7 = 0.0;
      local_30 = 0;
      piVar2 = param_1 + 0x100;
      while( true ) {
        if ((char)param_1[0x218] == '\0') {
          fVar8 = *(float *)(piVar2[-0x86] + piVar2[-0x83] * 4);
          fVar6 = (1.0 - (float)piVar2[-0x80]) * fVar8 + (float)piVar2[-0x80] * (float)piVar2[-0x81]
          ;
          piVar2[-0x81] = (int)fVar6;
          *(float *)(piVar2[-0x86] + piVar2[-0x83] * 4) = fVar6 * (float)piVar2[-0x87] + fVar10;
        }
        else {
          iVar5 = piVar2[-0x7b];
          iVar3 = (piVar2[-0x83] + iVar5) % piVar2[-0x85];
          fVar6 = (float)piVar2[-0x7a];
          iVar4 = piVar2[-0x86];
          fVar8 = (1.0 - fVar6) * *(float *)(iVar4 + iVar3 * 4) +
                  fVar6 * *(float *)(iVar4 + ((iVar3 + 1) % piVar2[-0x85]) * 4);
          fVar6 = fVar6 + (float)piVar2[-0x78];
          piVar2[-0x7a] = (int)fVar6;
          if (1.0 <= fVar6) {
            fVar6 = fVar6 - 1.0;
            piVar2[-0x7a] = (int)fVar6;
            iVar5 = iVar5 + 1;
            piVar2[-0x7b] = iVar5;
          }
          if (fVar6 < 0.0) {
            piVar2[-0x7a] = (int)(fVar6 + 1.0);
            iVar5 = iVar5 + -1;
            piVar2[-0x7b] = iVar5;
          }
          if ((piVar2[-0x77] < iVar5) || (iVar5 < 0)) {
            fVar6 = (float)piVar2[-0x78];
            piVar2[-0x78] = (int)-fVar6;
            fVar6 = -fVar6 + (float)piVar2[-0x7a];
            piVar2[-0x7a] = (int)fVar6;
            if (1.0 <= fVar6) {
              fVar6 = fVar6 - 1.0;
              piVar2[-0x7a] = (int)fVar6;
              piVar2[-0x7b] = iVar5 + 1;
            }
            if (fVar6 < 0.0) {
              piVar2[-0x7a] = (int)(fVar6 + 1.0);
              piVar2[-0x7b] = piVar2[-0x7b] + -1;
            }
          }
          fVar6 = (1.0 - (float)piVar2[-0x80]) * fVar8 + (float)piVar2[-0x80] * (float)piVar2[-0x81]
          ;
          piVar2[-0x81] = (int)fVar6;
          *(float *)(iVar4 + piVar2[-0x83] * 4) = fVar6 * (float)piVar2[-0x87] + fVar10;
        }
        iVar5 = piVar2[-0x83];
        piVar2[-0x83] = iVar5 + 1;
        if (piVar2[-0x85] <= iVar5 + 1) {
          piVar2[-0x83] = 0;
        }
        fVar9 = fVar9 + fVar8;
        if ((char)param_1[0x218] == '\0') {
          fVar8 = *(float *)(piVar2[2] + piVar2[5] * 4);
          fVar6 = (1.0 - (float)piVar2[8]) * fVar8 + (float)piVar2[8] * (float)piVar2[7];
          piVar2[7] = (int)fVar6;
          *(float *)(piVar2[2] + piVar2[5] * 4) = fVar6 * (float)piVar2[1] + fVar10;
          iVar5 = piVar2[5];
          piVar2[5] = iVar5 + 1;
          if (piVar2[3] <= iVar5 + 1) {
            piVar2[5] = 0;
          }
        }
        else {
          local_4c = piVar2[0xd];
          iVar4 = (piVar2[5] + local_4c) % piVar2[3];
          fVar6 = (float)piVar2[0xe];
          iVar5 = piVar2[2];
          fVar8 = (1.0 - fVar6) * *(float *)(iVar5 + iVar4 * 4) +
                  fVar6 * *(float *)(iVar5 + ((iVar4 + 1) % piVar2[3]) * 4);
          fVar6 = fVar6 + (float)piVar2[0x10];
          piVar2[0xe] = (int)fVar6;
          if (1.0 <= fVar6) {
            piVar2[0xe] = (int)(fVar6 - 1.0);
            local_4c = local_4c + 1;
            piVar2[0xd] = local_4c;
            fVar6 = (float)piVar2[0xe];
          }
          if (fVar6 < 0.0) {
            piVar2[0xe] = (int)(fVar6 + 1.0);
            local_4c = local_4c + -1;
            piVar2[0xd] = local_4c;
          }
          if ((piVar2[0x11] < local_4c) || (local_4c < 0)) {
            fVar6 = (float)piVar2[0x10];
            piVar2[0x10] = (int)-fVar6;
            fVar6 = -fVar6 + (float)piVar2[0xe];
            piVar2[0xe] = (int)fVar6;
            if (1.0 <= fVar6) {
              piVar2[0xe] = (int)(fVar6 - 1.0);
              piVar2[0xd] = local_4c + 1;
              fVar6 = (float)piVar2[0xe];
            }
            if (fVar6 < 0.0) {
              piVar2[0xe] = (int)(fVar6 + 1.0);
              piVar2[0xd] = piVar2[0xd] + -1;
            }
          }
          fVar6 = (1.0 - (float)piVar2[8]) * fVar8 + (float)piVar2[8] * (float)piVar2[7];
          piVar2[7] = (int)fVar6;
          *(float *)(iVar5 + piVar2[5] * 4) = fVar6 * (float)piVar2[1] + fVar10;
          iVar5 = piVar2[5];
          piVar2[5] = iVar5 + 1;
          if (piVar2[3] <= iVar5 + 1) {
            piVar2[5] = 0;
          }
        }
        fVar7 = fVar7 + fVar8;
        if (local_30 == 7) break;
        local_30 = local_30 + 1;
        piVar2 = piVar2 + 0x11;
      }
      if (0 < param_1[0x219]) {
        iVar5 = 0;
        piVar2 = param_1 + 0x1b1;
        do {
          pfVar1 = (float *)(piVar2[-0x27] + piVar2[-0x24] * 4);
          fVar10 = *pfVar1;
          *pfVar1 = fVar10 * (float)piVar2[-0x28] + fVar9;
          iVar4 = piVar2[-0x24];
          piVar2[-0x24] = iVar4 + 1;
          if (piVar2[-0x26] <= iVar4 + 1) {
            piVar2[-0x24] = 0;
          }
          fVar9 = fVar10 - fVar9;
          pfVar1 = (float *)(piVar2[-3] + *piVar2 * 4);
          fVar10 = *pfVar1;
          *pfVar1 = fVar10 * (float)piVar2[-4] + fVar7;
          iVar4 = *piVar2;
          *piVar2 = iVar4 + 1;
          if (piVar2[-2] <= iVar4 + 1) {
            *piVar2 = 0;
          }
          fVar7 = fVar10 - fVar7;
          iVar5 = iVar5 + 1;
          piVar2 = piVar2 + 6;
        } while (iVar5 < param_1[0x219]);
      }
      fVar10 = *local_20[0];
      local_20[0] = local_20[0] + 1;
      (**(code **)(*param_1 + 0xcc))(param_1,local_28,fVar9 * (float)param_1[0x78] + fVar10);
      fVar10 = *local_24;
      local_24 = local_24 + 1;
      (**(code **)(*param_1 + 0xcc))(param_1,local_2c,fVar7 * (float)param_1[0x78] + fVar10);
      local_34 = local_34 + 1;
    } while (param_2 != local_34);
  }
  (**(code **)(*(int *)param_1[0x46] + 0x44))((int *)param_1[0x46]);
  return;
}

