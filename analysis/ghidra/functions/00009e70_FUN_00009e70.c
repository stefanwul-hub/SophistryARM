/* 00009e70 FUN_00009e70 */

bool FUN_00009e70(undefined4 param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
  if (param_2 != (char *)0x0) {
    uVar3 = 0xffffffff;
    pcVar4 = param_2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (~uVar3 - 1 < 0x13f) {
      iVar2 = _mkdir(param_2,0x1ff);
      return iVar2 == 0;
    }
  }
  return false;
}

