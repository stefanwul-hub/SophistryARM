/* 00009a68 FUN_00009a68 */

int FUN_00009a68(int param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  
  if (*(FILE **)(param_1 + 8) == (FILE *)0x0) {
    iVar2 = -1;
  }
  else {
    pcVar3 = _fgets(param_2,param_3,*(FILE **)(param_1 + 8));
    if (pcVar3 == (char *)0x0) {
      iVar2 = -2;
    }
    else {
      uVar4 = 0xffffffff;
      pcVar3 = param_2;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (param_2[~uVar4 - 2] == '\n') {
        param_2[~uVar4 - 2] = '\0';
      }
      uVar4 = 0xffffffff;
      pcVar3 = param_2;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (param_2[~uVar4 - 2] == '\r') {
        param_2[~uVar4 - 2] = '\0';
      }
      uVar4 = 0xffffffff;
      pcVar3 = param_2;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (param_2[~uVar4 - 2] == '\n') {
        param_2[~uVar4 - 2] = '\0';
      }
      uVar4 = 0xffffffff;
      do {
        if (uVar4 == 0) break;
        uVar4 = uVar4 - 1;
        cVar1 = *param_2;
        param_2 = param_2 + 1;
      } while (cVar1 != '\0');
      iVar2 = ~uVar4 - 1;
    }
  }
  return iVar2;
}

