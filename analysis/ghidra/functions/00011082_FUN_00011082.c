/* 00011082 FUN_00011082 */

void FUN_00011082(int param_1,char *param_2)

{
  char cVar1;
  undefined1 local_3e0 [660];
  char local_14c [320];
  
  if (**(char **)(param_1 + 0x60) == '\0') {
    *param_2 = '\0';
  }
  else {
    _strcpy(param_2,*(char **)(param_1 + 0x60));
    cVar1 = FUN_0002d6ea(param_1 + 0x68,8);
    if (cVar1 != '\0') {
      FUN_0000a5d4(local_3e0);
      FUN_000098ea(local_3e0,param_2,local_14c);
      _strcpy(param_2,local_14c);
      Disk_c_vslot_0(local_3e0);
    }
    cVar1 = FUN_0002d6ea(param_1 + 0x68,0x10);
    if (cVar1 != '\0') {
      FUN_0000a5d4(local_3e0);
      FUN_00009a24(local_3e0,param_2);
      Disk_c_vslot_0(local_3e0);
      return;
    }
  }
  return;
}

