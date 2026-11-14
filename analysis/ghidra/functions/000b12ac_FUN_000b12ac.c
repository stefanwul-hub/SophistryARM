/* 000b12ac FUN_000b12ac */

void FUN_000b12ac(int param_1,char param_2,char param_3,int *param_4)

{
  float fVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  float *pfVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int local_20;
  int local_14;
  
  iVar2 = *(int *)(param_1 + 0x22c);
  if ((7 < iVar2) && (*(int *)(param_1 + 0x21c) != 0)) {
    iVar8 = *param_4;
    pfVar5 = (float *)(*(int *)(param_1 + 0x21c) + iVar8 * 4);
    local_20 = 0;
    pfVar7 = pfVar5;
    local_14 = iVar8;
    do {
      if (iVar8 < 1) {
        if (iVar8 == 0) goto LAB_000b134c;
        bVar3 = false;
      }
      else if (iVar8 < iVar2 + -1) {
        if (param_2 == '\0') {
          if ((*pfVar5 < 0.0) || (0.0 < pfVar5[-1])) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          if ((0.0 < *pfVar5) || (pfVar5[-1] < 0.0)) {
            bVar4 = false;
          }
          else {
            bVar4 = true;
          }
          if (!bVar3) {
            if (param_3 == '\0') goto LAB_000b13d8;
            if (!bVar4) {
              bVar3 = false;
              goto LAB_000b1351;
            }
          }
        }
        else {
          fVar1 = *pfVar5;
          if ((pfVar5[-1] < fVar1) || (pfVar5[1] < fVar1)) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          if ((fVar1 < pfVar5[-1]) || (fVar1 < pfVar5[1])) {
            bVar4 = false;
          }
          else {
            bVar4 = true;
          }
          if (!bVar3) {
            if (param_3 == '\0') goto LAB_000b13d8;
            if (!bVar4) {
              bVar3 = false;
              goto LAB_000b1351;
            }
          }
        }
LAB_000b134c:
        bVar3 = true;
      }
      else {
LAB_000b13d8:
        bVar3 = false;
      }
LAB_000b1351:
      iVar6 = iVar8;
      if (bVar3) {
LAB_000b13a5:
        if (bVar3) {
          *param_4 = iVar6;
          return;
        }
      }
      else {
        iVar6 = local_14;
        if (local_14 < 1) {
          if (local_14 == 0) {
            bVar3 = true;
            goto LAB_000b13a5;
          }
        }
        else if (local_14 < iVar2 + -1) {
          if (param_2 == '\0') {
            if ((*pfVar7 < 0.0) || (0.0 < pfVar7[-1])) {
              bVar3 = false;
            }
            else {
              bVar3 = true;
            }
            if ((0.0 < *pfVar7) || (pfVar7[-1] < 0.0)) {
              bVar4 = false;
            }
            else {
              bVar4 = true;
            }
            if ((bVar3) || ((param_3 != '\0' && (bVar4)))) {
LAB_000b13a0:
              bVar3 = true;
              goto LAB_000b13a5;
            }
          }
          else {
            fVar1 = *pfVar7;
            if ((pfVar7[-1] < fVar1) || (pfVar7[1] < fVar1)) {
              bVar3 = false;
            }
            else {
              bVar3 = true;
            }
            if ((fVar1 < pfVar7[-1]) || (fVar1 < pfVar7[1])) {
              bVar4 = false;
            }
            else {
              bVar4 = true;
            }
            if ((bVar3) || ((param_3 != '\0' && (bVar4)))) goto LAB_000b13a0;
          }
        }
      }
      local_20 = local_20 + 1;
      iVar8 = iVar8 + -1;
      local_14 = local_14 + 1;
      pfVar7 = pfVar7 + 1;
      pfVar5 = pfVar5 + -1;
    } while (iVar2 != local_20);
  }
  return;
}

