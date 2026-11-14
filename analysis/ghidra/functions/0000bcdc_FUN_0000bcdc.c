/* 0000bcdc FUN_0000bcdc */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

void FUN_0000bcdc(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  longdouble lVar5;
  double dVar6;
  double dVar7;
  int local_84;
  int local_48;
  double local_44;
  int local_3c;
  undefined4 *local_34;
  uint local_24;
  
  if (param_3 <= param_4) {
    local_34 = (undefined4 *)(param_2 + param_3 * 4);
    local_3c = param_3;
    dVar7 = 1.0;
    do {
      pfVar4 = (float *)*local_34;
      iVar3 = *(int *)(param_1 + 0x1c);
      local_44 = *(double *)(param_1 + 4);
      lVar5 = (longdouble)FUN_0002e314();
      dVar6 = (double)((float)lVar5 * 0.99) * 512.0;
      lVar5 = (longdouble)FUN_0002e314();
      dVar7 = (((dVar7 + (double)(float)lVar5 * 0.1 + (double)(float)lVar5 * 0.1) - 0.1) + 1.0) *
              0.5;
      local_84 = param_5 + 1;
      local_48 = iVar3;
      if (iVar3 != 0) {
        if (param_5 < 1) {
          local_84 = param_5;
        }
        else {
          local_84 = param_5;
          iVar2 = 0;
          pfVar1 = pfVar4;
          do {
            pfVar4 = pfVar1 + 1;
            if (0.0 < dVar6) {
              local_24 = SUB84(dVar6 + -0.499999999999 + *(double *)PTR_DAT_00103810,0);
            }
            else {
              local_24 = SUB84(dVar6 + 0.499999999999 + *(double *)PTR_DAT_00103810,0);
            }
            local_24 = local_24 & 0x800001ff;
            if ((int)local_24 < 0) {
              local_24 = (local_24 - 1 | 0xfffffe00) + 1;
            }
            *pfVar1 = *pfVar1 + (float)((double)*(float *)(param_1 + 0x20 + local_24 * 4) * local_44
                                       );
            local_44 = local_44 + *(double *)(param_1 + 0xc);
            dVar6 = dVar6 + dVar7;
            local_48 = (iVar3 - iVar2) + -1;
            if (iVar3 + -1 == iVar2) break;
            local_84 = local_84 + -1;
            iVar2 = iVar2 + 1;
            pfVar1 = pfVar4;
          } while (param_5 != iVar2);
        }
      }
      if (0 < local_84 + -1) {
        iVar3 = 0;
        do {
          local_24 = SUB84((double)(~-(ulonglong)(dVar6 <= 0.0) & (ulonglong)-0.499999999999 |
                                   -(ulonglong)(dVar6 <= 0.0) & (ulonglong)0.499999999999) + dVar6 +
                           *(double *)PTR_DAT_00103810,0);
          local_24 = local_24 & 0x800001ff;
          if ((int)local_24 < 0) {
            local_24 = (local_24 - 1 | 0xfffffe00) + 1;
          }
          *pfVar4 = *pfVar4 + (float)((double)*(float *)(param_1 + 0x20 + local_24 * 4) * local_44);
          pfVar4 = pfVar4 + 1;
          local_44 = local_44 * *(double *)(param_1 + 0x14);
          dVar6 = dVar6 + dVar7;
          iVar3 = iVar3 + 1;
        } while (local_84 + -1 != iVar3);
      }
      local_3c = local_3c + 1;
      local_34 = local_34 + 1;
    } while (local_3c <= param_4);
    *(int *)(param_1 + 0x1c) = local_48;
    *(double *)(param_1 + 4) = local_44;
  }
  return;
}

