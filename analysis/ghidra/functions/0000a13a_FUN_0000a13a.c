/* 0000a13a FUN_0000a13a */

void FUN_0000a13a(undefined4 param_1,char *param_2,int param_3,int *param_4,int *param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  char local_14c [320];
  
  *param_4 = 0;
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    uVar6 = 0xffffffff;
    pcVar4 = param_2;
    do {
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if ((~uVar6 - 1 < 0x13f) && (iVar2 = _opendir(param_2), iVar2 != 0)) {
      iVar3 = *param_4;
      do {
        if ((0x3ff < iVar3) || (iVar3 = _readdir(iVar2), iVar3 == 0)) {
          _closedir(iVar2);
          return;
        }
        pcVar4 = (char *)(iVar3 + 8);
        if (pcVar4 != (char *)0x0) {
          uVar6 = 0xffffffff;
          pcVar5 = pcVar4;
          do {
            if (uVar6 == 0) break;
            uVar6 = uVar6 - 1;
            cVar1 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          } while (cVar1 != '\0');
          iVar3 = ~uVar6 - 2;
          if (iVar3 < 0) {
LAB_0000a29a:
            local_14c[0] = '\0';
          }
          else {
            pcVar5 = pcVar4 + iVar3;
            if (*pcVar5 != '.') {
              iVar7 = 0;
              do {
                pcVar5 = pcVar5 + -1;
                if (iVar7 == iVar3) goto LAB_0000a29a;
                iVar7 = iVar7 + 1;
              } while (*pcVar5 != '.');
            }
            _strcpy(local_14c,pcVar5 + 1);
          }
        }
        pcVar5 = (char *)*param_5;
        if (pcVar5 != (char *)0x0) {
          piVar8 = param_5;
          do {
            iVar3 = _strcasecmp(local_14c,pcVar5);
            if (iVar3 == 0) {
              _strncpy((char *)(*param_4 * 0x140 + param_3),pcVar4,0x13f);
              *(undefined1 *)(*param_4 * 0x140 + 0x13f + param_3) = 0;
              *param_4 = *param_4 + 1;
              break;
            }
            pcVar5 = (char *)piVar8[1];
            piVar8 = piVar8 + 1;
          } while (pcVar5 != (char *)0x0);
        }
        iVar3 = *param_4;
      } while( true );
    }
  }
  return;
}

