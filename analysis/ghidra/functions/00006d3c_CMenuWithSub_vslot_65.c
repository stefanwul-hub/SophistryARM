/* 00006d3c CMenuWithSub_vslot_65 */

void CMenuWithSub_vslot_65(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  CMenuFileList_vslot_65(param_1,param_2);
  iVar1 = param_1[0x3e];
  iVar2 = param_1[0x3d];
  if (-1 < iVar1 - iVar2) {
    iVar5 = 0;
    piVar4 = param_1;
    do {
      piVar3 = (int *)piVar4[0x65];
      if (piVar3 != param_1) {
        (**(code **)(*piVar3 + 0x104))(piVar3,param_2);
      }
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar5 <= iVar1 - iVar2);
  }
  return;
}

