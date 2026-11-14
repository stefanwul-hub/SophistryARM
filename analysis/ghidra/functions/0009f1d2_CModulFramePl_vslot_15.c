/* 0009f1d2 CModulFramePl_vslot_15 */

void CModulFramePl_vslot_15(int *param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_14;
  int local_10;
  
  if (param_1[10] != 0) {
    iVar1 = *(int *)(param_2 + 8);
    iVar2 = *(int *)(param_2 + 0xc);
    iVar3 = *(int *)(param_2 + 0x10);
    iVar4 = *(int *)(param_2 + 0x14);
    *(int *)(param_2 + 8) = iVar1 + param_1[2];
    *(int *)(param_2 + 0xc) = iVar2 + param_1[3];
    *(int *)(param_2 + 0x10) = iVar3 + param_1[2];
    *(int *)(param_2 + 0x14) = iVar4 + param_1[3];
    local_14 = *param_4 - param_1[2];
    local_10 = param_4[1] - param_1[3];
    piVar5 = (int *)param_1[0x17];
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x40))(piVar5,param_2,param_3,&local_14);
    }
    piVar5 = (int *)(**(code **)(*param_1 + 0xec))(param_1,param_4,0);
    param_1[0x17] = (int)piVar5;
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x3c))(piVar5,param_2,param_3,&local_14);
    }
    *(int *)(param_2 + 8) = iVar1;
    *(int *)(param_2 + 0xc) = iVar2;
    *(int *)(param_2 + 0x10) = iVar3;
    *(int *)(param_2 + 0x14) = iVar4;
  }
  return;
}

