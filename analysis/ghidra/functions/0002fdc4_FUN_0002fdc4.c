/* 0002fdc4 FUN_0002fdc4 */

int FUN_0002fdc4(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  piVar1 = *(int **)(param_1 + 0x10);
  if ((piVar1 != (int *)0x0) && (iVar4 = *(int *)(param_1 + 0xc), 0 < iVar4)) {
    iVar6 = 0;
    piVar5 = piVar1;
    do {
      if ((((piVar5[1] == param_2) && (piVar5[3] == *(int *)(param_3 + 8))) &&
          ((piVar5[5] == *(int *)(param_3 + 0x10) || (*(int *)(param_3 + 0x10) == 0x10)))) &&
         (*piVar5 == 1)) {
        uVar2 = *(undefined4 *)(param_3 + 0xc);
        iVar3 = 0;
        if (-1 < iVar6) {
          iVar3 = iVar6;
        }
        if (iVar4 + -1 < iVar3) {
          iVar3 = iVar4 + -1;
        }
        iVar4 = FUN_0002e1c0(param_1 + 4);
        piVar1[iVar3 * 9 + 8] = iVar4;
        *(undefined4 *)(iVar3 * 0x24 + 0x10 + *(int *)(param_1 + 0x10)) = uVar2;
        FUN_0002f468(param_1,iVar3,2,0);
        return iVar6;
      }
      iVar6 = iVar6 + 1;
      piVar5 = piVar5 + 9;
    } while (iVar6 != iVar4);
  }
  return -1;
}

