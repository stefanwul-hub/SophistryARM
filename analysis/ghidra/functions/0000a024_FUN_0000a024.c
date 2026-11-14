/* 0000a024 FUN_0000a024 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0000a024(int param_1,char *param_2,char *param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  
  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) && (param_3 != (char *)0x0)) {
    uVar2 = 0xffffffff;
    pcVar4 = param_2;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar3 = 0xffffffff;
    pcVar4 = param_3;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if ((int)(~uVar3 + (~uVar2 - 2)) < 0x13e) {
      cVar1 = param_2[~uVar2 - 2];
      if (((cVar1 == *(char *)(param_1 + 0x10)) || (cVar1 == *(char *)(param_1 + 0x11))) ||
         (cVar1 == *(char *)(param_1 + 0x12))) {
        _sprintf(param_2,"%s%s",param_2,param_3);
        return;
      }
      _sprintf(param_2,"%s%c%s",param_2,(int)*(char *)(param_1 + 0x11),param_3);
    }
  }
  return;
}

