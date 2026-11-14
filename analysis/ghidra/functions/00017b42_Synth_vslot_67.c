/* 00017b42 Synth_vslot_67 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 Synth_vslot_67(int param_1,int param_2,char *param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0xcfb4);
  if ((iVar1 == 1) && (*(int *)(param_1 + 0xcfb8) == 0)) {
    _strncpy(param_3,*(char **)(param_1 + 0x3bac),6);
    param_3[6] = '\0';
    param_3[0x40] = '\x03';
    param_3[0x41] = '\0';
    param_3[0x42] = '\0';
    param_3[0x43] = '\0';
    param_3[0x44] = '\x01';
    param_3[0x45] = '\0';
    param_3[0x46] = '\0';
    param_3[0x47] = '\0';
  }
  else {
    if (iVar1 * 2 <= param_2) {
      _sprintf(param_3,"%c%c M%02d",(int)**(char **)(param_1 + 0x3bac),
               (int)(*(char **)(param_1 + 0x3bac))[1],param_2 + iVar1 * -2 + 1);
      param_3[0x40] = '\x01';
      param_3[0x41] = '\0';
      param_3[0x42] = '\0';
      param_3[0x43] = '\0';
      param_3[0x44] = '\0';
      param_3[0x45] = '\0';
      param_3[0x46] = '\0';
      param_3[0x47] = '\0';
      return 1;
    }
    _sprintf(param_3,"%c%c S%02d",(int)**(char **)(param_1 + 0x3bac),
             (int)(*(char **)(param_1 + 0x3bac))[1],param_2 / 2);
    param_3[0x40] = '\x03';
    param_3[0x41] = '\0';
    param_3[0x42] = '\0';
    param_3[0x43] = '\0';
    param_3[0x44] = '\x01';
    param_3[0x45] = '\0';
    param_3[0x46] = '\0';
    param_3[0x47] = '\0';
  }
  return 1;
}

