/* 0006b964 FUN_0006b964 */

void FUN_0006b964(int param_1,int param_2)

{
  int iVar1;
  undefined1 local_14 [4];
  uint local_10;
  
  if (0 < param_2) {
    do {
      iVar1 = FUN_00009b22(param_1 + 4,local_14);
      FUN_00009b22(param_1 + 4,&local_10);
      if ((local_10 & 1) != 0) {
        local_10 = local_10 + 1;
      }
      _fseek(*(FILE **)(param_1 + 0xc),local_10,1);
      param_2 = (param_2 - iVar1) - (local_10 + 4);
    } while (0 < param_2);
  }
  return;
}

