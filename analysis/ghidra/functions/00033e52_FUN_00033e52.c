/* 00033e52 FUN_00033e52 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00033e52(int param_1,char *param_2,undefined4 param_3,char param_4)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_2b4;
  int local_2a0;
  char local_29c [320];
  char local_15c [332];
  
  if (((*(int *)(param_1 + 0x120) != 0) && (param_2 != (char *)0x0)) && (*param_2 != '\0')) {
    _strcpy(local_29c,param_2);
    iVar4 = param_1 + 0x9f20;
    FUN_00009e70(iVar4,local_29c);
    local_2a0 = 0;
    iVar5 = 9;
    local_2b4 = 0;
    do {
      FUN_00012482(*(undefined4 *)(param_1 + 0x120),0,iVar5,local_15c);
      if (local_15c[0] != '\0') {
        if (param_4 == '\0') {
          iVar2 = FUN_0000a748(iVar4,local_15c,local_29c);
        }
        else {
          if (*(char *)(param_1 + 0x1d4) == '\0') {
            pcVar1 = "D4T";
          }
          else {
            pcVar1 = "D4U";
          }
          iVar2 = FUN_0000aa76(iVar4,local_15c,local_29c,pcVar1);
          iVar3 = local_2b4 + 0x1e0 + local_2a0 + param_1;
          if (iVar3 != 0) {
            FUN_000afa8c(iVar3,iVar2);
          }
        }
        if (iVar2 != 0) {
          FUN_00012432(*(undefined4 *)(param_1 + 0x120),0,iVar5,iVar2);
        }
      }
      local_2a0 = local_2a0 + 1;
      local_2b4 = local_2b4 + 0x273;
      iVar5 = iVar5 + 0x14;
    } while (local_2a0 != 0x40);
  }
  return;
}

