/* 00006082 FUN_00006082 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00006082(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if ((param_1[0x39] != 0) && (piVar1 = (int *)param_1[0x3b], piVar1 != (int *)0x0)) {
    if (param_1[0x3a] == -1) {
      iVar4 = (**(code **)(*piVar1 + 0x31c))(piVar1);
    }
    else {
      iVar4 = 0;
    }
    iVar2 = *(int *)(param_1[0x39] + 0x528 + iVar4 * 0x574);
    (**(code **)(*param_1 + 0x14c))(param_1);
    if (iVar2 < 1) {
      (**(code **)(*param_1 + 0x134))(param_1,param_1 + 0x3c,0);
    }
    else {
      if (iVar2 <= param_2) {
        return;
      }
      iVar5 = 0;
      do {
        while (iVar3 = FUN_0002cbbe(iVar4 * 0x574 + param_1[0x39],iVar5), iVar3 == 0) {
          (**(code **)(*param_1 + 0x134))(param_1,"unknown",iVar5);
          iVar5 = iVar5 + 1;
          if (iVar2 == iVar5) goto LAB_0000616a;
        }
        (**(code **)(*param_1 + 0x134))(param_1,iVar3,iVar5);
        iVar5 = iVar5 + 1;
      } while (iVar2 != iVar5);
    }
LAB_0000616a:
    (**(code **)(*param_1 + 0x13c))(param_1,param_2,1);
    (**(code **)(*param_1 + 0x15c))(param_1,param_2);
  }
  return;
}

