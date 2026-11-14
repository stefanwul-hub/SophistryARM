/* 00007532 CMIKnob_vslot_4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CMIKnob_vslot_4(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longdouble lVar7;
  float fVar8;
  int local_24;
  int local_20;
  
  if (*(int *)(param_1 + 0xbc) != 0) {
    iVar2 = *(int *)(param_1 + 0x14);
    iVar3 = *(int *)(param_1 + 0xc);
    iVar4 = *(int *)(param_1 + 0x10);
    iVar5 = *(int *)(param_1 + 8);
    CControlPl_vslot_4(param_1,param_2);
    lVar7 = (longdouble)FUN_000019e8(param_1);
    fVar8 = (float)lVar7;
    if (*(char *)(param_1 + 0xb4) != '\0') {
      fVar8 = fVar8 * 0.9 + 0.05;
    }
    iVar6 = *(int *)(param_1 + 0xe0);
    local_20 = (int)(((float)iVar6 - 1.0) * fVar8 + 0.001);
    if (*(char *)(param_1 + 0xdc) == '\0') {
      iVar6 = (iVar6 / 5 + 1) - (uint)(iVar6 == (iVar6 / 5) * 5);
      local_24 = local_20 / iVar6;
      local_20 = local_20 % iVar6;
      local_24 = (iVar4 - iVar5) * local_24;
      cVar1 = *(char *)(param_1 + 0x72);
    }
    else {
      local_24 = 0;
      cVar1 = *(char *)(param_1 + 0x72);
    }
    local_20 = local_20 * (iVar2 - iVar3);
    if (cVar1 == '\0') {
      (**(code **)(**(int **)(param_1 + 0xbc) + 0x10))
                (*(int **)(param_1 + 0xbc),param_2,param_1 + 8,&local_24);
      return;
    }
    (**(code **)(**(int **)(param_1 + 0xbc) + 0x14))
              (*(int **)(param_1 + 0xbc),param_2,param_1 + 8,&local_24);
  }
  return;
}

