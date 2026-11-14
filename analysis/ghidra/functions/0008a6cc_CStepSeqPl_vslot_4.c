/* 0008a6cc CStepSeqPl_vslot_4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CStepSeqPl_vslot_4(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  char *pcVar13;
  int iVar14;
  int iVar15;
  char *local_80;
  int *local_7c;
  int local_5c;
  int local_58;
  int local_54;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  char local_20 [16];
  
  if (*(char *)(param_1 + 0x71) == '\0') {
    return;
  }
  iVar12 = -1;
  pcVar13 = (char *)(param_1 + 0xd0);
  do {
    if (iVar12 == 0) break;
    iVar12 = iVar12 + -1;
    cVar1 = *pcVar13;
    pcVar13 = pcVar13 + 1;
  } while (cVar1 != '\0');
  if (iVar12 == -0x104) {
    uVar4 = (int)*(char *)(param_1 + 0xd0) + 0x100U & 0x800000ff;
    if ((int)uVar4 < 0) {
      uVar4 = (uVar4 - 1 | 0xffffff00) + 1;
    }
    uVar5 = (int)*(char *)(param_1 + 0xd1) + 0x100U & 0x800000ff;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xffffff00) + 1;
    }
    iVar12 = *(int *)(param_1 + 8);
    iVar6 = (*(int *)(param_1 + 0x10) - iVar12) / *(int *)(param_1 + 0xbc) -
            *(int *)(param_1 + 0xc4);
    iVar7 = (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0xc)) / *(int *)(param_1 + 0xc0);
    iVar2 = *(int *)(param_1 + 0xc);
    if (*(char *)(param_1 + 0xcf) != '\0') {
      if (*(char *)(param_1 + 0xce) == '\0') {
        local_5c = 0;
      }
      else {
        local_5c = *(int *)(*(int *)(param_1 + 0x35c) + 0xc);
      }
      if ((*(char *)(param_1 + 0xcc) == '\0') || (*(char *)(param_1 + 0xcd) == '\0')) {
        iVar14 = 1;
      }
      else {
        iVar14 = 2;
      }
      iVar14 = ((iVar6 - local_5c) + -5) / iVar14;
      if (0 < *(int *)(param_1 + 0xbc)) {
        local_58 = 0;
        iVar9 = *(int *)(param_1 + 0xc0);
        do {
          if (0 < iVar9) {
            local_54 = 0;
            do {
              iVar15 = iVar12 + *(int *)(param_1 + 0xc4) +
                       (*(int *)(param_1 + 0xc4) + iVar6) * local_58;
              iVar8 = local_54 * iVar7 + iVar2;
              iVar9 = local_58 * iVar9 + local_54;
              if (*(char *)(param_1 + 0xce) != '\0') {
                if (*(int *)(param_1 + 0x35c) != 0) {
                  piVar3 = *(int **)(param_1 + 0x35c);
                  local_2c = iVar8 + piVar3[4] / 2;
                  iVar10 = iVar15 + piVar3[3];
                  local_38 = iVar10;
                  local_30 = iVar15;
                  if (iVar15 < iVar10) {
                    local_38 = iVar15;
                    local_30 = iVar10;
                  }
                  if (iVar8 < local_2c) {
                    local_34 = iVar8;
                    if (uVar4 - 1 == iVar9) goto LAB_0008ad7b;
LAB_0008a8da:
                    local_24 = piVar3[4] / 2;
                  }
                  else {
                    local_34 = local_2c;
                    local_2c = iVar8;
                    if (uVar4 - 1 != iVar9) goto LAB_0008a8da;
LAB_0008ad7b:
                    local_24 = 0;
                  }
                  local_28 = 0;
                  (**(code **)(*piVar3 + 0x10))(piVar3,param_2,&local_38,&local_28);
                }
                iVar15 = iVar15 + local_5c;
              }
              iVar10 = iVar15;
              if (*(char *)(param_1 + 0xcc) != '\0') {
                if (*(char *)(iVar9 + 0x2d6 + param_1) == '\0') {
                  if ((*(char *)(param_1 + 0x357) != '\0') && (*(char *)(param_1 + 0x356) != '\0'))
                  goto LAB_0008a93c;
                  cVar1 = *(char *)(param_1 + 0xd2 + iVar9 * 2);
                }
                else {
                  cVar1 = *(char *)(param_1 + 0xd2 + iVar9 * 2);
                }
                uVar11 = (int)cVar1 + 0x100U & 0x800000ff;
                if ((int)uVar11 < 0) {
                  uVar11 = (uVar11 - 1 | 0xffffff00) + 1;
                }
                _sprintf(local_20,"%03ld",uVar11 - 1);
                local_34 = iVar7 + iVar8;
                iVar10 = iVar14 + iVar15;
                local_38 = iVar10;
                local_30 = iVar15;
                if (iVar15 < iVar10) {
                  local_38 = iVar15;
                  local_30 = iVar10;
                }
                if (iVar8 < local_34) {
                  local_24 = (iVar8 + *(int *)(param_1 + 0x364)) - *(int *)(param_1 + 0xc);
                  local_28 = (iVar15 + *(int *)(param_1 + 0x360)) - *(int *)(param_1 + 8);
                  piVar3 = *(int **)(param_1 + 0x358);
                  local_2c = local_34;
                  local_34 = iVar8;
                }
                else {
                  local_24 = (iVar8 + *(int *)(param_1 + 0x364)) - *(int *)(param_1 + 0xc);
                  local_28 = (iVar15 + *(int *)(param_1 + 0x360)) - *(int *)(param_1 + 8);
                  piVar3 = *(int **)(param_1 + 0x358);
                  local_2c = iVar8;
                }
                if (piVar3 != (int *)0x0) {
                  (**(code **)(*piVar3 + 0x10))(piVar3,param_2,&local_38,&local_28);
                }
                local_7c = &local_38;
                if (iVar9 < (int)(uVar5 - 1)) {
                  FUN_0009e6ac(param_2,*(undefined4 *)(param_1 + 0xb4));
                }
                else {
                  FUN_0009e6ac(param_2,CONCAT21(CONCAT11(*(byte *)(param_1 + 0xb6) >> 1,
                                                         *(byte *)(param_1 + 0xb5) >> 1),
                                                *(byte *)(param_1 + 0xb4) >> 1) | 0xff000000);
                }
                FUN_0009ca22(param_2,*(undefined4 *)(param_1 + 0xb0),0,0);
                FUN_0009fe14(param_2,local_20,local_7c,0,1);
              }
LAB_0008a93c:
              if (*(char *)(param_1 + 0xcd) != '\0') {
                if (*(char *)(iVar9 + 0x2d6 + param_1) == '\0') {
                  if ((*(char *)(param_1 + 0x357) != '\0') && (*(char *)(param_1 + 0x356) != '\0'))
                  goto LAB_0008a970;
                  cVar1 = *(char *)(param_1 + 0xd3 + iVar9 * 2);
                }
                else {
                  cVar1 = *(char *)(param_1 + 0xd3 + iVar9 * 2);
                }
                uVar11 = (int)cVar1 + 0x100U & 0x800000ff;
                if ((int)uVar11 < 0) {
                  uVar11 = (uVar11 - 1 | 0xffffff00) + 1;
                }
                iVar15 = uVar11 - 1;
                if (iVar15 == 0) {
                  builtin_strncpy(local_20,"Off",4);
                }
                else if (iVar15 == 0x80) {
                  builtin_strncpy(local_20,"Tie",4);
                }
                else {
                  _sprintf(local_20,"%03ld",iVar15);
                }
                local_80 = local_20;
                iVar15 = iVar7 + iVar8;
                local_30 = iVar10 + iVar14;
                local_38 = iVar10;
                if (local_30 <= iVar10) {
                  local_38 = local_30;
                  local_30 = iVar10;
                }
                local_34 = iVar15;
                local_2c = iVar8;
                if (iVar8 < iVar15) {
                  local_34 = iVar8;
                  local_2c = iVar15;
                }
                local_24 = (iVar8 + *(int *)(param_1 + 0x364)) - *(int *)(param_1 + 0xc);
                local_28 = (iVar10 + *(int *)(param_1 + 0x360)) - *(int *)(param_1 + 8);
                piVar3 = *(int **)(param_1 + 0x358);
                if (piVar3 != (int *)0x0) {
                  (**(code **)(*piVar3 + 0x10))(piVar3,param_2,&local_38,&local_28);
                }
                local_7c = &local_38;
                if (iVar9 < (int)(uVar5 - 1)) {
                  FUN_0009e6ac(param_2,*(undefined4 *)(param_1 + 0xb4));
                }
                else {
                  FUN_0009e6ac(param_2,CONCAT21(CONCAT11(*(byte *)(param_1 + 0xb6) >> 1,
                                                         *(byte *)(param_1 + 0xb5) >> 1),
                                                *(byte *)(param_1 + 0xb4) >> 1) | 0xff000000);
                }
                FUN_0009ca22(param_2,*(undefined4 *)(param_1 + 0xb0),0,0);
                FUN_0009fe14(param_2,local_80,local_7c,0,1);
              }
LAB_0008a970:
              local_54 = local_54 + 1;
              iVar9 = *(int *)(param_1 + 0xc0);
            } while (local_54 < iVar9);
          }
          local_58 = local_58 + 1;
        } while (local_58 < *(int *)(param_1 + 0xbc));
      }
    }
  }
  *(undefined1 *)(param_1 + 0x74) = 0;
  *(undefined1 *)(param_1 + 0x357) = 0;
  return;
}

