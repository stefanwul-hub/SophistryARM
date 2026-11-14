/* 00009ebe FUN_00009ebe */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00009ebe(int param_1,char *param_2,char *param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char local_15c [332];
  
  if ((param_3 != (char *)0x0) && (*param_3 != '\0')) {
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
    if (~uVar3 + (~uVar2 - 2) < 0x13e) {
      cVar1 = param_2[~uVar2 - 2];
      if (((cVar1 == *(char *)(param_1 + 0x10)) || (cVar1 == *(char *)(param_1 + 0x11))) ||
         (cVar1 == *(char *)(param_1 + 0x12))) {
        _sprintf(local_15c,"%s%s",param_2,param_3);
      }
      else {
        _sprintf(local_15c,"%s%c%s",param_2,(int)*(char *)(param_1 + 0x11),param_3);
      }
      _strcpy(param_3,local_15c);
      return;
    }
  }
  return;
}

