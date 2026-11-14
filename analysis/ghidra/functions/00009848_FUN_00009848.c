/* 00009848 FUN_00009848 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_00009848(int param_1,char *param_2)

{
  char cVar1;
  FILE *pFVar2;
  uint uVar3;
  char *pcVar4;
  char local_15c [332];
  
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
      _strcpy(local_15c,param_2);
      pFVar2 = _fopen(local_15c,"wb");
      *(FILE **)(param_1 + 8) = pFVar2;
      return pFVar2 != (FILE *)0x0;
    }
  }
  return false;
}

