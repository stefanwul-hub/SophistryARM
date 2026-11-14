/* 0000a3be FUN_0000a3be */

bool FUN_0000a3be(undefined4 param_1,char *param_2,char *param_3,int param_4,char param_5,
                 int *param_6)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int local_154;
  char local_14c [320];
  
  if ((((param_4 < 0) || (param_2 == (char *)0x0)) || (*param_2 == '\0')) ||
     (iVar3 = _opendir(param_2), iVar3 == 0)) {
    return false;
  }
  iVar4 = _readdir(iVar3);
  if (iVar4 == 0) {
    local_154 = -1;
  }
  else {
    local_154 = -1;
    do {
      pcVar1 = (char *)(iVar4 + 8);
      if (param_5 == '\0') {
        if (pcVar1 != (char *)0x0) {
          uVar6 = 0xffffffff;
          pcVar5 = pcVar1;
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar2 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar2 != '\0');
          iVar7 = ~uVar6 - 2;
          if (iVar7 < 0) {
LAB_0000a554:
            local_14c[0] = '\0';
          }
          else {
            pcVar5 = pcVar1 + iVar7;
            if (*pcVar5 != '.') {
              iVar8 = 0;
              do {
                pcVar5 = pcVar5 + -1;
                if (iVar8 == iVar7) goto LAB_0000a554;
                iVar8 = iVar8 + 1;
              } while (*pcVar5 != '.');
            }
            _strcpy(local_14c,pcVar5 + 1);
          }
        }
        pcVar5 = (char *)*param_6;
        if (pcVar5 != (char *)0x0) {
          piVar9 = param_6;
          do {
            iVar7 = _strcasecmp(local_14c,pcVar5);
            if (iVar7 == 0) {
              local_154 = local_154 + 1;
              if (param_4 <= local_154) goto LAB_0000a43c;
              break;
            }
            pcVar5 = (char *)piVar9[1];
            piVar9 = piVar9 + 1;
          } while (pcVar5 != (char *)0x0);
        }
LAB_0000a42c:
        iVar4 = _readdir(iVar3);
      }
      else if (((*(char *)(iVar4 + 6) != '\x04') || (pcVar1 == (char *)0x0)) ||
              ((*(char *)(iVar4 + 8) == '.' || (local_154 = local_154 + 1, local_154 < param_4))))
      goto LAB_0000a42c;
LAB_0000a43c:
    } while ((iVar4 != 0) && (local_154 < param_4));
    if (param_4 == local_154) {
      _strncpy(param_3,pcVar1,0x13f);
      param_3[0x13f] = '\0';
      local_154 = param_4;
    }
  }
  _closedir(iVar3);
  return param_4 == local_154;
}

