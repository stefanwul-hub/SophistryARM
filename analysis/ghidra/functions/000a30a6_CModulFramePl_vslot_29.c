/* 000a30a6 CModulFramePl_vslot_29 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CModulFramePl_vslot_29(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  
  param_1[2] = *param_2;
  param_1[3] = param_2[1];
  param_1[4] = param_2[2];
  param_1[5] = param_2[3];
  (**(code **)(*param_1 + 0x54))(param_1,1);
  piVar1 = (int *)param_1[0x12];
  if ((piVar1 != (int *)0x0) && ((char)param_1[0x16] != '\0')) {
    (**(code **)(*piVar1 + 8))(piVar1);
    uVar6 = _DAT_000e20c8;
    iVar2 = param_1[4];
    iVar3 = param_1[2];
    iVar4 = param_1[5];
    iVar5 = param_1[3];
    pvVar7 = operator_new(0x84);
    FUN_000a2030(pvVar7,param_1[10],iVar2 - iVar3,iVar4 - iVar5,uVar6);
    param_1[0x12] = (int)pvVar7;
    return;
  }
  return;
}

