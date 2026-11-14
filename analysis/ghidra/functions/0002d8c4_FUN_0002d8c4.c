/* 0002d8c4 FUN_0002d8c4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_0002d8c4(int param_1,char *param_2,char *param_3,int param_4)

{
  char **ppcVar1;
  char cVar2;
  char *pcVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  char **ppcVar11;
  uint uVar12;
  int *piVar13;
  uint *puVar14;
  int local_680;
  int local_66c;
  int local_668;
  char *local_664;
  int local_660;
  char *local_654;
  char *local_650 [263];
  uint auStack_234 [129];
  char local_30;
  char local_2f [18];
  undefined1 local_1d;
  
  *(undefined4 *)(param_1 + 0x20c) = 1;
  if (param_4 != 0) {
    iVar5 = 0;
    do {
      *(undefined1 *)(param_4 + iVar5) = 0;
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0x11);
    cVar2 = *param_2;
    while (cVar2 == ' ') {
      param_2 = param_2 + 1;
      cVar2 = *param_2;
    }
    local_664 = &local_30;
    _strncpy(local_664,param_2,0x13);
    local_1d = 0;
    ppcVar11 = &local_654;
    _memcpy(ppcVar11,&PTR_s_6gZef8FAXFLSg9rb5GG_000e7700,0x424);
    while (local_654 != (char *)0x0) {
      iVar5 = _strcmp(local_664,local_654);
      if (iVar5 == 0) {
        *(undefined4 *)(param_1 + 0x20c) = 2;
      }
      ppcVar1 = ppcVar11 + 1;
      ppcVar11 = ppcVar11 + 1;
      local_654 = *ppcVar1;
    }
    iVar8 = param_1 + 4;
    iVar9 = 0;
    iVar5 = iVar8;
    do {
      *(undefined4 *)(iVar5 + 4) = 0;
      iVar9 = iVar9 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar9 != 0x80);
    if (local_30 != '\0') {
      local_660 = 5;
      pcVar3 = *(char **)(param_1 + 0x208);
      do {
        cVar2 = *pcVar3;
        if (cVar2 == '\0') {
          return 0;
        }
        if (cVar2 == local_30) {
          iVar5 = 0;
        }
        else {
          iVar5 = 0;
          do {
            iVar5 = iVar5 + 1;
            cVar2 = pcVar3[iVar5];
            if (cVar2 == '\0') {
              return 0;
            }
          } while (cVar2 != local_30);
          if (iVar5 == -1) {
            return 0;
          }
        }
        local_680 = local_660 + -5;
        if ((local_660 < 0x80) && (local_680 < local_660)) {
          puVar14 = (uint *)(param_1 + 8 + local_680 * 4);
          iVar9 = 4;
          do {
            if (local_680 < 0x80) {
              *puVar14 = iVar5 >> ((byte)iVar9 & 0x1f) & 1;
            }
            local_680 = local_680 + 1;
            iVar9 = iVar9 + -1;
            puVar14 = puVar14 + 1;
          } while (iVar9 != -1);
        }
        local_30 = local_664[1];
        local_664 = local_664 + 1;
        local_660 = local_660 + 5;
      } while (local_30 != '\0');
    }
    iVar9 = 1;
    iVar5 = iVar8;
    do {
      auStack_234[iVar9] = (uint)(*(int *)(iVar5 + 4) != 0);
      iVar9 = iVar9 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar9 != 0x81);
    iVar5 = 0;
    do {
      iVar9 = iVar5 * 0x13 + (iVar5 / 5) * -0x5e;
      if (iVar9 < 0x80) {
        *(uint *)(param_1 + 8 + iVar9 * 4) = (uint)(auStack_234[iVar5 + 1] != 0);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0x5f);
    uVar12 = 0;
    iVar5 = iVar8;
    do {
      uVar6 = uVar12 & 0x8000000f;
      if ((int)uVar6 < 0) {
        uVar6 = (uVar6 - 1 | 0xfffffff0) + 1;
      }
      if ((0xbc2a >> (0xfU - (char)uVar6 & 0x1f) & 1U) != 0) {
        *(uint *)(iVar5 + 4) = (uint)(*(int *)(iVar5 + 4) == 0);
      }
      uVar12 = uVar12 + 1;
      iVar5 = iVar5 + 4;
    } while (uVar12 != 0x80);
    bVar10 = false;
    iVar9 = 0x80;
    iVar5 = iVar8;
    do {
      bVar10 = (bool)(bVar10 ^ *(int *)(iVar5 + 4) != 0);
      iVar5 = iVar5 + 4;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    if (bVar10) {
      iVar9 = 0xc;
      iVar5 = 0;
      do {
        iVar5 = (uint)(*(int *)(iVar8 + 0x14c) != 0) + iVar5 * 2;
        iVar8 = iVar8 + 4;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      *(undefined1 *)(param_4 + 0x10) = 0;
      local_66c = 1;
      local_668 = 5;
      do {
        iVar9 = local_668 + -5;
        if ((local_668 < 0x80) && (iVar9 < local_668)) {
          piVar13 = (int *)(param_1 + 8 + iVar9 * 4);
          uVar12 = 0;
          iVar8 = 5;
          do {
            while (uVar12 = uVar12 * 2, iVar9 < 0x80) {
              uVar12 = (*piVar13 != 0) + uVar12;
              iVar9 = iVar9 + 1;
              piVar13 = piVar13 + 1;
              iVar8 = iVar8 + -1;
              if (iVar8 == 0) goto LAB_0002dc0f;
            }
            iVar9 = iVar9 + 1;
            piVar13 = piVar13 + 1;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
LAB_0002dc0f:
          if (uVar12 < 0x1a) goto LAB_0002dca7;
          if (uVar12 == 0x1a) {
            *(undefined1 *)(local_66c + -1 + param_4) = 0x20;
          }
          else {
            uVar4 = 0x2e;
            if (uVar12 != 0x1b) {
              uVar4 = 0x3f;
            }
            *(undefined1 *)(param_4 + -1 + local_66c) = uVar4;
          }
        }
        else {
          uVar12 = 0;
LAB_0002dca7:
          *(char *)(param_4 + -1 + local_66c) = (char)uVar12 + 'A';
        }
        local_668 = local_668 + 5;
        local_66c = local_66c + 1;
        if (local_66c == 0x11) {
          while( true ) {
            lVar7 = _atol(param_3);
            if (lVar7 == iVar5) {
              if (*(int *)(param_1 + 0x20c) == 2) {
                return 0;
              }
              *(undefined4 *)(param_1 + 0x20c) = 0;
              return 1;
            }
            if (param_3[4] == '\0') break;
            param_3 = param_3 + 5;
          }
          return 0;
        }
      } while( true );
    }
  }
  return 0;
}

