/* 0001c4e4 FUN_0001c4e4 */

void FUN_0001c4e4(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 != 0) {
    if (0 < *(int *)(param_1 + 0x3b88)) {
      iVar4 = 0;
      iVar3 = param_1;
      do {
        if ((*(int **)(iVar3 + 0x511c) != (int *)0x0) && (param_3 == **(int **)(iVar3 + 0x511c)))
        goto LAB_0001c510;
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 0x1c;
      } while (*(int *)(param_1 + 0x3b88) != iVar4);
    }
    iVar4 = -1;
LAB_0001c510:
    *(int *)(param_1 + 0x9a64) = iVar4;
    *(undefined4 *)(FUN_00009a68 + param_1) = 0;
    while (((iVar3 = *(int *)(param_1 + 0x9a64), -1 < iVar3 &&
            (iVar4 = *(int *)(FUN_00009a68 + param_1),
            iVar4 < *(int *)(iVar3 * 0x1c + 0x512c + param_1))) &&
           (iVar2 = *(int *)(iVar3 * 0x1c + 0x511c + param_1), iVar2 != 0))) {
      while( true ) {
        piVar1 = *(int **)(iVar2 + iVar4 * 4);
        if (piVar1 == (int *)0x0) {
          return;
        }
        iVar2 = piVar1[0x4a];
        iVar4 = iVar4 + 1;
        *(int *)(FUN_00009a68 + param_1) = iVar4;
        if (param_2 == iVar2) break;
        iVar2 = iVar3 * 0x1c + param_1;
        if (*(int *)(iVar2 + 0x512c) <= iVar4) {
          return;
        }
        iVar2 = *(int *)(iVar2 + 0x511c);
        if (iVar2 == 0) {
          return;
        }
      }
      if (param_2 != iVar2) {
        return;
      }
      (**(code **)(*piVar1 + 0x7c))(piVar1,param_4);
    }
  }
  return;
}

