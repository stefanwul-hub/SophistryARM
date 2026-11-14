/* 00017f44 FUN_00017f44 */

void FUN_00017f44(int *param_1,undefined4 param_2,byte *param_3)

{
  byte bVar1;
  int *piVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  
  bVar1 = *param_3;
  bVar3 = bVar1 & 0xf0;
  if (((bVar3 != 0xf0) && ((param_1[0xe3c] == 0 || (bVar3 != 0xc0)))) &&
     ((param_1[0xe3b] == 0 || ((bVar3 != 0xb0 || ((param_3[1] != 0 && (param_3[1] != 0x20)))))))) {
    if (0 < param_1[0x33ec]) {
      iVar5 = 0;
      do {
        cVar4 = (**(code **)(*param_1 + 0x3e4))(param_1,bVar1 & 0xf,iVar5);
        if (cVar4 != '\0') {
          piVar2 = *(int **)(param_1[0x33a9] + iVar5 * 4);
          (**(code **)(*piVar2 + 0x38))(piVar2,param_2,param_3);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_1[0x33ec]);
    }
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00017fd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)param_1[0x33a9] + 0x38))();
  return;
}

