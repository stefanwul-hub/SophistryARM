/* 0002fb5c FUN_0002fb5c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int FUN_0002fb5c(int param_1,int param_2,int param_3,int param_4,int param_5,undefined1 *param_6,
                char param_7)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined *local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (*(int *)(param_1 + 0x10) == 0) {
    return -1;
  }
  if (param_3 == 0) {
    return -1;
  }
  iVar5 = 1;
  if (param_4 != 0) {
    iVar5 = param_4;
  }
  *param_6 = 1;
  if (iVar5 < *(int *)(param_3 + 0x14c)) {
    FUN_0002fa40(param_1,param_2,*(int *)(param_3 + 0x14c) - iVar5);
  }
  if ((*(int *)(param_3 + 0x14c) < iVar5) &&
     (iVar5 = *(int *)(param_1 + 0xc), *(int *)(param_1 + 0x14) < iVar5)) {
    if (param_7 != '\0') {
      iVar5 = *(int *)(param_5 + 0x10);
      iVar1 = *(int *)(param_5 + 8);
      if (*(int *)(param_1 + 0x10) == 0) {
        return -1;
      }
      *param_6 = 0;
      iVar3 = *(int *)(param_1 + 0xc);
      if (iVar3 < 1) {
        return -1;
      }
      piVar4 = *(int **)(param_1 + 0x10);
      if (iVar5 == 0x10) {
        iVar6 = 0;
        piVar2 = piVar4;
        do {
          if (((iVar1 == piVar2[3]) && (param_2 == piVar2[1])) && (*piVar2 == 2)) goto LAB_0002fc43;
          iVar6 = iVar6 + 1;
          piVar2 = piVar2 + 9;
        } while (iVar6 != iVar3);
      }
      else {
        iVar6 = 0;
        piVar2 = piVar4;
        do {
          if (((iVar1 == piVar2[3]) && (iVar5 == piVar2[5])) &&
             ((param_2 == piVar2[1] && (*piVar2 == 2)))) goto LAB_0002fc43;
          iVar6 = iVar6 + 1;
          piVar2 = piVar2 + 9;
        } while (iVar6 != iVar3);
      }
      goto LAB_0002fc67;
    }
    piVar4 = *(int **)(param_1 + 0x10);
    if ((piVar4 == (int *)0x0) || (iVar5 < 1)) {
LAB_0002fd4a:
      iVar6 = -1;
    }
    else if (*piVar4 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = 0;
      do {
        piVar4 = piVar4 + 9;
        iVar6 = iVar6 + 1;
        if (iVar6 == iVar5) goto LAB_0002fd4a;
      } while (*piVar4 != 0);
    }
    *param_6 = 0;
  }
  else {
    iVar6 = FUN_0002eede(param_1,param_2,*(undefined4 *)(param_5 + 8),
                         *(undefined4 *)(param_5 + 0x10));
  }
LAB_0002fcb2:
  if (iVar6 < 0) {
    return iVar6;
  }
LAB_0002fcba:
  local_2c = *(undefined1 *)(param_5 + 4);
  local_28 = *(undefined4 *)(param_5 + 8);
  local_24 = *(undefined4 *)(param_5 + 0xc);
  local_30 = PTR_DAT_00103814 + 8;
  local_20 = *(undefined4 *)(param_5 + 0x10);
  FUN_0002f8ce(param_1,param_2,param_3,iVar6,&local_30);
  return iVar6;
LAB_0002fc43:
  *param_6 = 1;
  if (iVar6 == -1) {
    iVar3 = *(int *)(param_1 + 0xc);
    if (iVar3 < 1) {
      return -1;
    }
    piVar4 = *(int **)(param_1 + 0x10);
LAB_0002fc67:
    if (*piVar4 == 0) {
      iVar6 = 0;
      goto LAB_0002fcba;
    }
    iVar6 = 0;
    do {
      piVar4 = piVar4 + 9;
      iVar6 = iVar6 + 1;
      if (iVar3 == iVar6) {
        return -1;
      }
    } while (*piVar4 != 0);
  }
  goto LAB_0002fcb2;
}

