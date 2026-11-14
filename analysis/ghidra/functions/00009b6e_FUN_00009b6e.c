/* 00009b6e FUN_00009b6e */

size_t FUN_00009b6e(int param_1,void *param_2,size_t param_3)

{
  size_t sVar1;
  
  if (*(FILE **)(param_1 + 8) != (FILE *)0x0) {
    sVar1 = _fread(param_2,1,param_3,*(FILE **)(param_1 + 8));
    return sVar1;
  }
  return 0xffffffff;
}

