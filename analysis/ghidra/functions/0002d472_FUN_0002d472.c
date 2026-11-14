/* 0002d472 FUN_0002d472 */

int FUN_0002d472(int param_1,char *param_2,char param_3)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *local_3e0;
  int local_3d0;
  char local_3cc [320];
  undefined1 local_28c [320];
  undefined1 local_14c [320];
  
  if (param_2 == (char *)0x0) {
    iVar3 = -1;
  }
  else {
    if (*(int *)(param_1 + 0x2a4) == 0) {
      return -2;
    }
    if (0 < *(int *)(param_1 + 0x298)) {
      local_3d0 = 0;
      do {
        iVar4 = local_3d0 * 4;
        iVar3 = *(int *)(param_1 + 0x2a4);
        pvVar1 = *(void **)(iVar3 + iVar4);
        if (pvVar1 != *(void **)(param_1 + 0x2a0)) {
          if (pvVar1 != (void *)0x0) {
            _free(pvVar1);
            iVar3 = *(int *)(param_1 + 0x2a4);
          }
          *(undefined4 *)(iVar3 + iVar4) = 0;
          *(undefined4 *)(*(int *)(param_1 + 0x2a4) + iVar4) = *(undefined4 *)(param_1 + 0x2a0);
        }
        local_3d0 = local_3d0 + 1;
      } while (local_3d0 < *(int *)(param_1 + 0x298));
    }
    *(undefined4 *)(param_1 + 0x528) = 0;
    if (*param_2 == '\0') {
      iVar3 = -4;
    }
    else {
      iVar3 = param_1 + 4;
      FUN_00009996(iVar3,param_2,local_14c);
      FUN_00009996(iVar3,local_14c,local_28c);
      if (param_3 == '\0') {
        FUN_0000a65c(iVar3,param_2,local_3cc);
        FUN_0002d328(param_1,local_14c,0);
      }
      else {
        FUN_000098ea(iVar3,local_14c,local_3cc);
        FUN_0002d328(param_1,local_28c,1);
      }
      local_3e0 = local_3cc;
      if (*(int *)(param_1 + 0x528) < 1) {
        iVar3 = -3;
      }
      else {
        iVar3 = -3;
        iVar4 = 0;
        do {
          iVar2 = _strcasecmp(local_3e0,*(char **)(*(int *)(param_1 + 0x2a4) + iVar4 * 4));
          if (iVar2 == 0) {
            iVar3 = iVar4;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < *(int *)(param_1 + 0x528));
      }
    }
  }
  return iVar3;
}

