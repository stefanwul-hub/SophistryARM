/* 0004dc1a Kaja_c_vslot_67 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 Kaja_c_vslot_67(int param_1,uint param_2,char *param_3)

{
  undefined4 uVar1;
  char *local_24 [6];
  
  local_24[0] = "Soph L";
  local_24[1] = "Soph R";
  local_24[2] = "Soph C";
  local_24[3] = "Soph Lfe";
  local_24[4] = "Soph LS";
  local_24[5] = "Soph RS";
  if (*(int *)(param_1 + 0xcfbc) == 2) {
    param_3[0x40] = '\x03';
    param_3[0x41] = '\0';
    param_3[0x42] = '\0';
    param_3[0x43] = '\0';
    if (1 < param_2) {
      return 1;
    }
    _strcpy(param_3,*(char **)(param_1 + 0x3bac));
    uVar1 = 1;
  }
  else if ((*(int *)(param_1 + 0xcfbc) == 6) && (param_2 < 6)) {
    param_3[0x40] = '\x01';
    param_3[0x41] = '\0';
    param_3[0x42] = '\0';
    param_3[0x43] = '\0';
    if (*(int *)(param_1 + 0xcfe8) == 0) {
      _strcpy(param_3,*(char **)(param_1 + 0x3bac));
      *(uint *)(param_3 + 0x40) = *(uint *)(param_3 + 0x40) | 4;
      param_3[0x44] = '\x0f';
      param_3[0x45] = '\0';
      param_3[0x46] = '\0';
      param_3[0x47] = '\0';
      return 1;
    }
    _strcpy(param_3,local_24[param_2]);
    if (param_2 - 2 < 2) {
      return 1;
    }
    *(uint *)(param_3 + 0x40) = *(uint *)(param_3 + 0x40) | 2;
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

