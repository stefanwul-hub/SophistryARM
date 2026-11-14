/* 0002edda FUN_0002edda */

int FUN_0002edda(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x10);
  if ((piVar3 != (int *)0x0) && (iVar1 = *(int *)(param_1 + 0xc), 0 < iVar1)) {
    if (param_4 == 0x10) {
      if (param_3 == 0x80) {
        iVar2 = 0;
        do {
          if (((piVar3[1] == param_2) && (*piVar3 != 0)) && (*piVar3 != 3)) {
            return iVar2;
          }
          iVar2 = iVar2 + 1;
          piVar3 = piVar3 + 9;
        } while (iVar2 != iVar1);
      }
      else {
        iVar2 = 0;
        do {
          if (((piVar3[3] == param_3) && (piVar3[1] == param_2)) &&
             ((*piVar3 != 0 && (*piVar3 != 3)))) {
            return iVar2;
          }
          iVar2 = iVar2 + 1;
          piVar3 = piVar3 + 9;
        } while (iVar1 != iVar2);
      }
    }
    else if (param_3 == 0x80) {
      iVar2 = 0;
      do {
        if (((piVar3[5] == param_4) && (piVar3[1] == param_2)) && ((*piVar3 != 0 && (*piVar3 != 3)))
           ) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 9;
      } while (iVar2 != iVar1);
    }
    else {
      iVar2 = 0;
      do {
        if ((((param_3 == piVar3[3]) && (param_4 == piVar3[5])) && (param_2 == piVar3[1])) &&
           ((*piVar3 != 0 && (*piVar3 != 3)))) {
          return iVar2;
        }
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 9;
      } while (iVar2 != iVar1);
    }
  }
  return -1;
}

