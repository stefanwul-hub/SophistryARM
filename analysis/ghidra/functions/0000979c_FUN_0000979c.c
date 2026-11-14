/* 0000979c FUN_0000979c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_0000979c(int param_1,char *param_2)

{
  char cVar1;
  FILE *pFVar2;
  int *piVar3;
  uint uVar4;
  char *pcVar5;
  char local_15c [332];
  
  if (param_2 != (char *)0x0) {
    uVar4 = 0xffffffff;
    pcVar5 = param_2;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (~uVar4 - 1 < 0x13f) {
      _strcpy(local_15c,param_2);
      pFVar2 = _fopen(local_15c,"rb");
      *(FILE **)(param_1 + 8) = pFVar2;
      if (pFVar2 != (FILE *)0x0) {
        return 1;
      }
      piVar3 = ___error();
      _fprintf((FILE *)(PTR_001037f8 + 0xb0),"%s cannot be loaded, errno: %d\n",param_2,*piVar3);
    }
  }
  return 0;
}

