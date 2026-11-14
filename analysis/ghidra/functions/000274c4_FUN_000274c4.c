/* 000274c4 FUN_000274c4 */

void FUN_000274c4(int *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  
  if ((param_1[0x13] != 0) && (*(char *)((int)param_1 + 0x51) != '\0')) {
    iVar6 = 0;
    piVar5 = param_1 + 0x977a;
    do {
      iVar2 = FUN_00080800(piVar5);
      if ((-1 < iVar2) && ((iVar2 == param_2 || (param_2 == -1)))) {
        pcVar1 = *(code **)(*param_1 + 100);
        uVar3 = FUN_0001d28c(param_1[0x13],iVar2);
        uVar4 = FUN_00080816(piVar5);
        iVar2 = FUN_0008080a(piVar5);
        if ((iVar2 < 1) || ((0xbf < iVar2 || (iVar2 = param_1[iVar2 + 0x9616], iVar2 == 0)))) {
          iVar2 = 0;
        }
        (*pcVar1)(param_1,iVar2,uVar4,uVar3);
      }
      iVar6 = iVar6 + 1;
      piVar5 = piVar5 + 0x1a;
    } while (iVar6 != 0x40);
  }
  return;
}

