/* 0009f854 CModulFramePl_vslot_20 */

undefined4 CModulFramePl_vslot_20(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_38;
  
  if (*(char *)(param_1 + 0x30) != '\0') {
    return 1;
  }
  local_38 = 0;
  iVar8 = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 8);
  iVar1 = -*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0xc);
  iVar5 = -*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x14);
  piVar2 = *(int **)(param_1 + 0x3c);
  do {
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    piVar3 = (int *)*piVar2;
    cVar4 = (**(code **)(*piVar3 + 0x50))(piVar3);
    if (cVar4 != '\0') {
      iVar9 = local_38;
      if (-1 < piVar3[2]) {
        iVar9 = piVar3[2];
      }
      iVar10 = iVar1;
      if (iVar1 <= piVar3[3]) {
        iVar10 = piVar3[3];
      }
      iVar7 = iVar8;
      if (piVar3[4] <= iVar8) {
        iVar7 = piVar3[4];
      }
      iVar6 = iVar5;
      if (piVar3[5] <= iVar5) {
        iVar6 = piVar3[5];
      }
      if (iVar6 < iVar10) {
        iVar6 = iVar10;
      }
      if (iVar7 < iVar9) {
        iVar7 = iVar9;
      }
      if ((0 < iVar7 - iVar9) && (iVar6 != iVar10 && -1 < iVar6 - iVar10)) {
        return 1;
      }
    }
    piVar2 = (int *)piVar2[1];
  } while( true );
}

