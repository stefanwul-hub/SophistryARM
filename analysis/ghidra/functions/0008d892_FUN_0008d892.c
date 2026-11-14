/* 0008d892 FUN_0008d892 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_0008d892(int *param_1,undefined1 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_540 [660];
  undefined1 local_2ac [320];
  char local_16c [320];
  char *local_2c;
  char *local_28;
  char *local_24;
  undefined4 local_20;
  
  if (param_1[0x48] == 0) {
    return 0;
  }
  FUN_0000a5d4(local_540);
  FUN_00012482(param_1[0x48],param_3,1,local_16c);
  if (local_16c[0] != '\0') {
    local_2c = "aif";
    local_28 = "wav";
    local_24 = "d4t";
    local_20 = 0;
    cVar1 = FUN_0000abd0(local_540,param_2,local_16c,local_2ac,&local_2c);
    if (cVar1 != '\0') {
      FUN_00012432(param_1[0x48],param_3,1,local_2ac);
      (**(code **)(*param_1 + 0x78))(param_1,param_3,1);
      uVar2 = 1;
      goto LAB_0008d904;
    }
  }
  uVar2 = 0;
LAB_0008d904:
  Disk_c_vslot_0(local_540);
  return uVar2;
}

