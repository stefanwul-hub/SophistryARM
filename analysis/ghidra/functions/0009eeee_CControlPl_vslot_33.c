/* 0009eeee CControlPl_vslot_33 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CControlPl_vslot_33(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (param_2 == 0) {
    return;
  }
  piVar1 = *(int **)(param_1 + 0x2c);
  if ((piVar1 != (int *)0x0) &&
     (iVar6 = (**(code **)(*piVar1 + 0x94))(piVar1,param_1,PTR_s_kMsgCheckIfViewContainer_000e20a4),
     iVar6 == 1)) {
    iVar6 = *(int *)(param_1 + 0x2c);
    iVar2 = *(int *)(param_2 + 8);
    iVar3 = *(int *)(param_2 + 0xc);
    iVar4 = *(int *)(param_2 + 0x10);
    iVar5 = *(int *)(param_2 + 0x14);
    *(int *)(param_2 + 8) = iVar2 + *(int *)(iVar6 + 8);
    *(int *)(param_2 + 0xc) = iVar3 + *(int *)(iVar6 + 0xc);
    *(int *)(param_2 + 0x10) = iVar4 + *(int *)(iVar6 + 8);
    *(int *)(param_2 + 0x14) = iVar5 + *(int *)(iVar6 + 0xc);
    (**(code **)(**(int **)(param_1 + 0x2c) + 0x84))(*(int **)(param_1 + 0x2c),param_2,param_3);
    *(int *)(param_2 + 8) = iVar2;
    *(int *)(param_2 + 0xc) = iVar3;
    *(int *)(param_2 + 0x10) = iVar4;
    *(int *)(param_2 + 0x14) = iVar5;
    return;
  }
  FUN_0009ea10();
  return;
}

