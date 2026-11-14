/* 00039de2 FUN_00039de2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00039de2(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  char local_15c [332];
  
  if (*(int *)(param_1 + 0x120) != 0) {
    FUN_00012482(*(int *)(param_1 + 0x120),0,3,local_15c);
    if (local_15c[0] != '\0') {
      if (param_3 == '\0') {
        iVar1 = FUN_0000a748(param_1 + 0x458,local_15c,param_2);
      }
      else {
        iVar1 = FUN_0000aa76(param_1 + 0x458,local_15c,param_2,"D4U");
        if (param_1 + 0x1e4 != 0) {
          FUN_000afa8c(param_1 + 0x1e4,iVar1);
        }
      }
      if (iVar1 != 0) {
        FUN_00012432(*(undefined4 *)(param_1 + 0x120),0,3,iVar1);
        return;
      }
    }
  }
  return;
}

