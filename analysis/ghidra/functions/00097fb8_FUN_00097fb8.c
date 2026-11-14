/* 00097fb8 FUN_00097fb8 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_00097fb8(int param_1,int *param_2)

{
  bool bVar1;
  byte bVar2;
  short sVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  byte bVar10;
  char *pcVar11;
  char *pcVar12;
  char *pcVar13;
  char *pcVar14;
  bool bVar15;
  int local_154;
  int local_150;
  int local_12c;
  char local_11c [268];
  
  bVar2 = *(byte *)(param_1 + 0x80) & 1;
  sVar3 = _UniqueID(0x4d454e55);
  *(short *)(param_1 + 0xb0) = sVar3;
  uVar4 = _NewMenu((int)sVar3,"\x05PopUp");
  *param_2 = *param_2 + *(int *)(param_1 + 0xb4);
  if (0 < *(int *)(param_1 + 0xb4)) {
    local_150 = 0;
    local_12c = 0;
    sVar3 = 1;
LAB_0009815b:
    do {
      _strcpy(local_11c,*(char **)(*(int *)(param_1 + 0xa4) + local_12c * 4));
      pcVar5 = _strchr(local_11c,9);
      bVar15 = pcVar5 == (char *)0x0;
      if (bVar15) {
        local_154 = 0;
        bVar10 = 0;
        bVar1 = false;
      }
      else {
        *pcVar5 = '\0';
        pcVar11 = pcVar5 + 1;
        bVar15 = pcVar5[1] == '\0';
        if (bVar15) {
          local_154 = 0;
          bVar10 = 8;
          bVar1 = false;
        }
        else {
          pcVar5 = _strstr(pcVar11,"Ctrl");
          bVar10 = -(pcVar5 == (char *)0x0) & 8;
          pcVar5 = _strstr(pcVar11,"Alt");
          if (pcVar5 != (char *)0x0) {
            bVar10 = bVar10 | 2;
          }
          pcVar5 = _strstr(pcVar11,"Shift");
          if (pcVar5 != (char *)0x0) {
            bVar10 = bVar10 | 1;
          }
          pcVar5 = _strstr(pcVar11,"Apple");
          bVar15 = pcVar5 == (char *)0x0;
          if (!bVar15) {
            bVar10 = bVar10 | 4;
          }
          iVar8 = 3;
          pcVar5 = pcVar11;
          pcVar13 = "Del";
          do {
            pcVar12 = pcVar5;
            pcVar14 = pcVar13;
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            pcVar14 = pcVar13 + 1;
            pcVar12 = pcVar5 + 1;
            bVar15 = *pcVar5 == *pcVar13;
            pcVar5 = pcVar12;
            pcVar13 = pcVar14;
          } while (bVar15);
          iVar8 = 0;
          if (!bVar15) {
            iVar8 = (uint)(byte)pcVar12[-1] - (uint)(byte)pcVar14[-1];
          }
          bVar15 = iVar8 == 0;
          if (bVar15) {
            local_154 = 0x17;
            bVar1 = false;
          }
          else {
            iVar8 = 4;
            pcVar5 = pcVar11;
            pcVar13 = "Left";
            do {
              pcVar12 = pcVar5;
              pcVar14 = pcVar13;
              if (iVar8 == 0) break;
              iVar8 = iVar8 + -1;
              pcVar14 = pcVar13 + 1;
              pcVar12 = pcVar5 + 1;
              bVar15 = *pcVar5 == *pcVar13;
              pcVar5 = pcVar12;
              pcVar13 = pcVar14;
            } while (bVar15);
            iVar8 = 0;
            if (!bVar15) {
              iVar8 = (uint)(byte)pcVar12[-1] - (uint)(byte)pcVar14[-1];
            }
            bVar15 = iVar8 == 0;
            if (bVar15) {
              local_154 = 100;
              bVar1 = true;
            }
            else {
              iVar8 = 5;
              pcVar5 = pcVar11;
              pcVar13 = "Right";
              do {
                pcVar12 = pcVar5;
                pcVar14 = pcVar13;
                if (iVar8 == 0) break;
                iVar8 = iVar8 + -1;
                pcVar14 = pcVar13 + 1;
                pcVar12 = pcVar5 + 1;
                bVar15 = *pcVar5 == *pcVar13;
                pcVar5 = pcVar12;
                pcVar13 = pcVar14;
              } while (bVar15);
              iVar8 = 0;
              if (!bVar15) {
                iVar8 = (uint)(byte)pcVar12[-1] - (uint)(byte)pcVar14[-1];
              }
              bVar15 = iVar8 == 0;
              if (bVar15) {
                local_154 = 0x65;
                bVar1 = true;
              }
              else {
                iVar8 = 2;
                pcVar5 = pcVar11;
                pcVar13 = "Up";
                do {
                  pcVar12 = pcVar5;
                  pcVar14 = pcVar13;
                  if (iVar8 == 0) break;
                  iVar8 = iVar8 + -1;
                  pcVar14 = pcVar13 + 1;
                  pcVar12 = pcVar5 + 1;
                  bVar15 = *pcVar5 == *pcVar13;
                  pcVar5 = pcVar12;
                  pcVar13 = pcVar14;
                } while (bVar15);
                iVar8 = 0;
                if (!bVar15) {
                  iVar8 = (uint)(byte)pcVar12[-1] - (uint)(byte)pcVar14[-1];
                }
                bVar15 = iVar8 == 0;
                if (bVar15) {
                  local_154 = 0x68;
                  bVar1 = true;
                }
                else {
                  iVar8 = 4;
                  pcVar5 = pcVar11;
                  pcVar13 = "Down";
                  do {
                    pcVar12 = pcVar5;
                    pcVar14 = pcVar13;
                    if (iVar8 == 0) break;
                    iVar8 = iVar8 + -1;
                    pcVar14 = pcVar13 + 1;
                    pcVar12 = pcVar5 + 1;
                    bVar15 = *pcVar5 == *pcVar13;
                    pcVar5 = pcVar12;
                    pcVar13 = pcVar14;
                  } while (bVar15);
                  iVar8 = 0;
                  if (!bVar15) {
                    iVar8 = (uint)(byte)pcVar12[-1] - (uint)(byte)pcVar14[-1];
                  }
                  bVar15 = iVar8 == 0;
                  if (bVar15) {
                    local_154 = 0x6a;
                    bVar1 = true;
                  }
                  else {
                    uVar9 = 0xffffffff;
                    bVar15 = true;
                    pcVar5 = pcVar11;
                    do {
                      if (uVar9 == 0) break;
                      uVar9 = uVar9 - 1;
                      bVar15 = *pcVar5 == '\0';
                      pcVar5 = pcVar5 + 1;
                    } while (!bVar15);
                    local_154 = (int)pcVar11[~uVar9 - 2];
                    bVar1 = false;
                  }
                }
              }
            }
          }
        }
      }
      pcVar5 = *(char **)(*(int *)(param_1 + 0xa4) + local_12c * 4);
      iVar8 = 2;
      pcVar11 = pcVar5;
      pcVar13 = "-";
      do {
        pcVar12 = pcVar11;
        pcVar14 = pcVar13;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar14 = pcVar13 + 1;
        pcVar12 = pcVar11 + 1;
        bVar15 = *pcVar11 == *pcVar13;
        pcVar11 = pcVar12;
        pcVar13 = pcVar14;
      } while (bVar15);
      iVar8 = 0;
      if (!bVar15) {
        iVar8 = (uint)(byte)pcVar12[-1] - (uint)(byte)pcVar14[-1];
      }
      bVar15 = iVar8 == 0;
      if (bVar15) {
        _AppendMenuItemTextWithCFString(uVar4,&cf___,0x40,0,0);
LAB_00098105:
        if (local_154 != 0) {
          _SetItemCmd(uVar4,sVar3,(int)(short)local_154);
          if (bVar1) {
            _SetMenuItemKeyGlyph(uVar4,sVar3,(int)(short)local_154);
          }
          _SetMenuItemModifiers(uVar4,sVar3,bVar10);
        }
        if ((bVar2 != 0) && (*(char *)(*(int *)(param_1 + 0xac) + local_12c) != '\0')) {
          _CheckMenuItem(uVar4,sVar3,1);
        }
LAB_0009813b:
        local_12c = local_12c + 1;
        sVar3 = sVar3 + 1;
        if (*(int *)(param_1 + 0xb4) <= local_12c) break;
        goto LAB_0009815b;
      }
      iVar8 = 2;
      pcVar11 = pcVar5;
      pcVar13 = "-M";
      do {
        pcVar12 = pcVar11;
        pcVar14 = pcVar13;
        if (iVar8 == 0) break;
        iVar8 = iVar8 + -1;
        pcVar14 = pcVar13 + 1;
        pcVar12 = pcVar11 + 1;
        bVar15 = *pcVar11 == *pcVar13;
        pcVar11 = pcVar12;
        pcVar13 = pcVar14;
      } while (bVar15);
      iVar8 = 0;
      if (!bVar15) {
        iVar8 = (uint)(byte)pcVar12[-1] - (uint)(byte)pcVar14[-1];
      }
      bVar15 = iVar8 == 0;
      if (!bVar15) {
        iVar8 = 2;
        pcVar11 = pcVar5;
        pcVar13 = "-G";
        do {
          pcVar12 = pcVar11;
          pcVar14 = pcVar13;
          if (iVar8 == 0) break;
          iVar8 = iVar8 + -1;
          pcVar14 = pcVar13 + 1;
          pcVar12 = pcVar11 + 1;
          bVar15 = *pcVar11 == *pcVar13;
          pcVar11 = pcVar12;
          pcVar13 = pcVar14;
        } while (bVar15);
        iVar8 = 0;
        if (!bVar15) {
          iVar8 = (uint)(byte)pcVar12[-1] - (uint)(byte)pcVar14[-1];
        }
        bVar15 = iVar8 == 0;
        if (bVar15) {
          uVar6 = _CFStringCreateWithCString(0,pcVar5 + 2,0x8000100);
          uVar7 = 0x101;
        }
        else {
          iVar8 = 2;
          pcVar11 = pcVar5;
          pcVar13 = "-T";
          do {
            pcVar12 = pcVar11;
            pcVar14 = pcVar13;
            if (iVar8 == 0) break;
            iVar8 = iVar8 + -1;
            pcVar14 = pcVar13 + 1;
            pcVar12 = pcVar11 + 1;
            bVar15 = *pcVar11 == *pcVar13;
            pcVar11 = pcVar12;
            pcVar13 = pcVar14;
          } while (bVar15);
          iVar8 = 0;
          if (!bVar15) {
            iVar8 = (uint)(byte)pcVar12[-1] - (uint)(byte)pcVar14[-1];
          }
          if (iVar8 == 0) {
            uVar6 = _CFStringCreateWithCString(0,pcVar5 + 2,0x8000100);
            uVar7 = 0x180;
          }
          else {
            uVar6 = _CFStringCreateWithCString(0,pcVar5,0x8000100);
            uVar7 = 0x100;
          }
        }
        _InsertMenuItemTextWithCFString(uVar4,uVar6,sVar3,uVar7,0);
        _CFRelease(uVar6);
        goto LAB_00098105;
      }
      if (local_150 < *(int *)(param_1 + 0xb8)) {
        uVar6 = _CFStringCreateWithCString(0,pcVar5 + 2,0x8000100);
        _InsertMenuItemTextWithCFString(uVar4,uVar6,sVar3,0x100,0);
        _CFRelease(uVar6);
        iVar8 = FUN_00097fb8(*(undefined4 *)(*(int *)(param_1 + 0xa8) + local_150 * 4),param_2);
        if (iVar8 != 0) {
          _SetMenuItemHierarchicalID
                    (uVar4,sVar3,
                     (int)*(short *)(*(int *)(local_150 * 4 + *(int *)(param_1 + 0xa8)) + 0xb0));
          local_150 = local_150 + 1;
        }
        goto LAB_0009813b;
      }
      local_12c = local_12c + 1;
      sVar3 = sVar3 + 1;
    } while (local_12c < *(int *)(param_1 + 0xb4));
  }
  if (((*(byte *)(param_1 + 0x81) & 4) != 0) && (bVar2 == 0)) {
    _CheckMenuItem(uVar4,*(short *)(param_1 + 0xbc) + 1,1);
  }
  _InsertMenu(uVar4,0xffffffff);
  *(undefined4 *)(param_1 + 0xa0) = uVar4;
  return uVar4;
}

