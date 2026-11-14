/* 0009f2c0 CModulFramePl_vslot_16 */

void CModulFramePl_vslot_16(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_14;
  int local_10;
  
  if (*(int *)(param_1 + 0x28) != 0) {
    iVar1 = *(int *)(param_2 + 8);
    iVar2 = *(int *)(param_2 + 0xc);
    iVar3 = *(int *)(param_2 + 0x10);
    iVar4 = *(int *)(param_2 + 0x14);
    *(int *)(param_2 + 8) = iVar1 + *(int *)(param_1 + 8);
    *(int *)(param_2 + 0xc) = iVar2 + *(int *)(param_1 + 0xc);
    *(int *)(param_2 + 0x10) = iVar3 + *(int *)(param_1 + 8);
    *(int *)(param_2 + 0x14) = iVar4 + *(int *)(param_1 + 0xc);
    local_14 = *param_4 - *(int *)(param_1 + 8);
    local_10 = param_4[1] - *(int *)(param_1 + 0xc);
    piVar5 = *(int **)(param_1 + 0x5c);
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 0x40))(piVar5,param_2,param_3,&local_14);
    }
    *(undefined4 *)(param_1 + 0x5c) = 0;
    *(int *)(param_2 + 8) = iVar1;
    *(int *)(param_2 + 0xc) = iVar2;
    *(int *)(param_2 + 0x10) = iVar3;
    *(int *)(param_2 + 0x14) = iVar4;
  }
  return;
}

