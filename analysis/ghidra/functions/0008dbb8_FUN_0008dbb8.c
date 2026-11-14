/* 0008dbb8 FUN_0008dbb8 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0008dbb8(int param_1,char *param_2,char param_3)

{
  int iVar1;
  undefined1 local_3f0 [660];
  char local_15c [332];
  
  FUN_0000a5d4(local_3f0);
  if (((*(int *)(param_1 + 0x120) != 0) && (param_2 != (char *)0x0)) && (*param_2 != '\0')) {
    FUN_00012482(*(int *)(param_1 + 0x120),0,1,local_15c);
    if (local_15c[0] != '\0') {
      if (param_3 == '\0') {
        iVar1 = FUN_0000a748(local_3f0,local_15c,param_2);
      }
      else {
        iVar1 = FUN_0000aa76(local_3f0,local_15c,param_2,"D4T");
        if (param_1 + 0x1d8 != 0) {
          FUN_000afa8c(param_1 + 0x1d8,iVar1);
        }
      }
      if (iVar1 != 0) {
        FUN_00012432(*(undefined4 *)(param_1 + 0x120),0,1,iVar1);
      }
    }
  }
  Disk_c_vslot_0(local_3f0);
  return;
}

