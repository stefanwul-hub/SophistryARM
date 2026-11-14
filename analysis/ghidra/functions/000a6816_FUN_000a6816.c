/* 000a6816 FUN_000a6816 */

int FUN_000a6816(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_2 == 0x19) {
    if (param_1[0x36] != 0) {
      _CFRelease(param_1[0x36]);
    }
    param_1[0x36] = 0;
    iVar1 = 0;
  }
  else if (param_2 == 0x1b) {
    if (param_3 == 0) {
      iVar1 = 1;
      do {
        if (*(char *)((int)param_1 + iVar1 + 199) != '\0') {
          param_1[0x32] = 0;
          param_1[0x33] = 0;
          param_1[0x34] = 0;
          param_1[0x35] = 0;
          FUN_000a67ae(param_1,0x1b,0,param_4);
          return 0;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 != 0x11);
      return 0;
    }
    iVar1 = -0x2a72;
  }
  else {
    if (param_2 != 0x13) {
                    /* WARNING: Could not recover jumptable at 0x000a6856. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(*param_1 + 0x2c))();
      return iVar1;
    }
    iVar1 = (**(code **)(*param_1 + 0xd0))(param_1,param_3,param_4);
    if (iVar1 == 0) {
      FUN_000a67ae(param_1,0x13,param_3,param_4);
    }
  }
  return iVar1;
}

