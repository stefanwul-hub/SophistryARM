/* 00019210 FUN_00019210 */

void FUN_00019210(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x8ac0) != 0) {
    piVar1 = (int *)(*(int *)(param_1 + 0x8ac0) + param_2 * 0x10);
    iVar3 = 0;
    piVar2 = piVar1;
    do {
      if (*piVar2 < 0) {
        piVar1[iVar3] = param_3;
        return;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 1;
    } while (iVar3 != 4);
  }
  return;
}

