/* 000096d0 FUN_000096d0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_000096d0(int param_1,char *param_2)

{
  FILE *pFVar1;
  
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    pFVar1 = _fopen(param_2,"rb");
    *(FILE **)(param_1 + 8) = pFVar1;
    if (pFVar1 != (FILE *)0x0) {
      _fclose(pFVar1);
      return 1;
    }
  }
  return 0;
}

