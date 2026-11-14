/* 00005b42 CKnobPl_vslot_4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CKnobPl_vslot_4(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  longdouble lVar11;
  float fVar12;
  double dVar13;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  CControlPl_vslot_4(param_1,param_2);
  iVar8 = *(int *)(*(int *)(param_1 + 0xbc) + 0xc);
  iVar9 = *(int *)(*(int *)(param_1 + 0xbc) + 0x10);
  iVar10 = *(int *)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 0x14);
  iVar3 = *(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0xb8) != 0) {
    local_30 = *(undefined4 *)(param_1 + 0xcc);
    local_34 = *(int *)(param_1 + 200);
    (**(code **)(**(int **)(param_1 + 0xb8) + 0x10))
              (*(int **)(param_1 + 0xb8),param_2,param_1 + 8,&local_34);
  }
  if (*(int *)(param_1 + 0xbc) != 0) {
    iVar4 = *(int *)(param_1 + 8);
    iVar5 = *(int *)(param_1 + 0x10);
    iVar6 = *(int *)(param_1 + 0xc);
    iVar7 = *(int *)(param_1 + 0x14);
    lVar11 = (longdouble)FUN_000019e8(param_1);
    fVar12 = (float)lVar11;
    if (*(char *)(param_1 + 0xb4) != '\0') {
      fVar12 = fVar12 * 0.9 + 0.05;
    }
    dVar13 = ((double)fVar12 - 0.2) * 5.235987755983;
    lVar11 = (longdouble)_cos(dVar13);
    iVar10 = (iVar4 + (iVar5 - iVar4) / 2) -
             (int)((double)((iVar10 - iVar1) - iVar8) * 0.5 * (double)lVar11 + 0.5);
    lVar11 = (longdouble)_sin(dVar13);
    local_28 = (iVar6 + (iVar7 - iVar6) / 2) -
               (int)((double)((iVar2 - iVar3) - iVar9) * 0.5 * (double)lVar11 + 0.5);
    iVar9 = iVar9 / 2;
    iVar8 = iVar8 / 2;
    local_34 = iVar10 - iVar8;
    local_30 = local_28 - iVar9;
    local_2c = iVar10 + iVar8;
    local_28 = local_28 + iVar9;
    local_24 = 0;
    local_20 = 0;
    (**(code **)(**(int **)(param_1 + 0xbc) + 0x14))
              (*(int **)(param_1 + 0xbc),param_2,&local_34,&local_24);
  }
  return;
}

