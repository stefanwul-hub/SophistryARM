/* 0009efc2 CViewContainer_vslot_13 */

undefined1
CViewContainer_vslot_13(int *param_1,int param_2,int *param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 uVar5;
  int *piVar6;
  int local_14;
  int local_10;
  
  piVar6 = (int *)(**(code **)(*param_1 + 0xec))(param_1,param_3,0);
  if (piVar6 != (int *)0x0) {
    local_14 = *param_3 - param_1[2];
    local_10 = param_3[1] - param_1[3];
    iVar1 = *(int *)(param_2 + 8);
    iVar2 = *(int *)(param_2 + 0xc);
    iVar3 = *(int *)(param_2 + 0x10);
    iVar4 = *(int *)(param_2 + 0x14);
    *(int *)(param_2 + 8) = param_1[2] + iVar1;
    *(int *)(param_2 + 0xc) = iVar2 + param_1[3];
    *(int *)(param_2 + 0x10) = iVar3 + param_1[2];
    *(int *)(param_2 + 0x14) = iVar4 + param_1[3];
    uVar5 = (**(code **)(*piVar6 + 0x34))(piVar6,param_2,&local_14,param_4,param_5);
    *(int *)(param_2 + 8) = iVar1;
    *(int *)(param_2 + 0xc) = iVar2;
    *(int *)(param_2 + 0x10) = iVar3;
    *(int *)(param_2 + 0x14) = iVar4;
    return uVar5;
  }
  return 0;
}

