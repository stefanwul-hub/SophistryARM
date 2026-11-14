/* 0003a05c FUN_0003a05c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_0003a05c(int *param_1,undefined1 param_2,int param_3)

{
  char cVar1;
  undefined1 local_2b0 [320];
  char local_170 [320];
  char *local_30;
  char *local_2c;
  char *local_28;
  char *local_24;
  undefined4 local_20;
  
  if (((-1 < param_3) && (param_3 < 1)) && (param_1[0x48] != 0)) {
    FUN_00012482(param_1[0x48],param_3,3,local_170);
    if (local_170[0] != '\0') {
      local_30 = "aif";
      local_2c = "wav";
      local_28 = "d4t";
      local_24 = "d4u";
      local_20 = 0;
      cVar1 = FUN_0000abd0(param_1 + 0x116,param_2,local_170,local_2b0,&local_30);
      if (cVar1 != '\0') {
        FUN_00012432(param_1[0x48],param_3,3,local_2b0);
        (**(code **)(*param_1 + 0x78))(param_1,param_3,3);
        (**(code **)(*param_1 + 0x78))(param_1,param_3,0xb);
        return 1;
      }
    }
  }
  return 0;
}

