/* 0001a686 FUN_0001a686 */

void FUN_0001a686(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (((-1 < param_2) && (param_2 < *(int *)(param_1 + 0x3b88))) &&
     (iVar2 = param_2 * 0x1c + param_1, *(int *)(iVar2 + 0x511c) != 0)) {
    if (0 < *(int *)(iVar2 + 0x512c)) {
      iVar2 = 0;
      do {
        while( true ) {
          piVar1 = *(int **)(*(int *)(param_2 * 0x1c + 0x511c + param_1) + iVar2 * 4);
          if (piVar1 != (int *)0x0) break;
LAB_0001a6f9:
          iVar2 = iVar2 + 1;
          if (*(int *)(param_2 * 0x1c + 0x512c + param_1) <= iVar2) goto LAB_0001a6c7;
        }
        piVar1[3] = param_1;
        (**(code **)(*piVar1 + 0x18))
                  (piVar1,param_2 * 0x1c + 0x5130 + param_1,*(undefined4 *)(param_1 + 0xcfb0));
        FUN_00012848(piVar1,param_1,param_1 + 0x36c0);
        if (*(char *)(param_1 + 0xcfc7) == '\0') goto LAB_0001a6f9;
        (**(code **)(*piVar1 + 0xa0))(piVar1,*(undefined4 *)(param_1 + 0x3b94));
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_2 * 0x1c + 0x512c + param_1));
    }
LAB_0001a6c7:
    iVar2 = *(int *)(param_1 + 0x3b88);
    iVar4 = 0;
    while (iVar4 < iVar2) {
      while (iVar4 = iVar4 + 1, iVar4 < iVar2) {
        iVar3 = 0;
        do {
          iVar3 = iVar3 + 1;
        } while (iVar2 - iVar4 != iVar3);
        if (iVar2 <= iVar4) {
          return;
        }
      }
    }
  }
  return;
}

