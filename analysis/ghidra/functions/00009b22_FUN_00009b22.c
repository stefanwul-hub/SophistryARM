/* 00009b22 FUN_00009b22 */

undefined4 FUN_00009b22(int param_1,void *param_2)

{
  size_t sVar1;
  undefined4 uVar2;
  
  if (*(FILE **)(param_1 + 8) != (FILE *)0x0) {
    sVar1 = _fread(param_2,4,1,*(FILE **)(param_1 + 8));
    uVar2 = 4;
    if (sVar1 != 1) {
      uVar2 = 0xfffffffe;
    }
    return uVar2;
  }
  return 0xffffffff;
}

