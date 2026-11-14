/* 000088a6 CRadioButtonPl_vslot_4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void CRadioButtonPl_vslot_4(int param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  longdouble lVar6;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  CControlPl_vslot_4(param_1,param_2);
  piVar2 = *(int **)(param_1 + 0xb0);
  if (piVar2 != (int *)0x0) {
    local_24 = 0;
    local_20 = 0;
    (**(code **)(*piVar2 + 0x10))(piVar2,param_2,param_1 + 8,&local_24);
    if (*(char *)(param_1 + 0xbd) == '\0') {
      cVar1 = *(char *)(param_1 + 0xbf);
    }
    else {
      if (*(char *)(param_1 + 0xbe) == '\0') {
        return;
      }
      cVar1 = *(char *)(param_1 + 0xbf);
    }
    if (cVar1 != '\0') {
      lVar6 = (longdouble)FUN_000019e8(param_1);
      local_28 = (int)(((float)(*(int *)(param_1 + 0xb4) * *(int *)(param_1 + 0xb8)) - 1.0) *
                       (float)lVar6 + 0.001) * (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0xc));
      local_2c = 0;
      (**(code **)(**(int **)(param_1 + 0xb0) + 0x10))
                (*(int **)(param_1 + 0xb0),param_2,param_1 + 8,&local_2c);
      return;
    }
    lVar6 = (longdouble)FUN_000019e8(param_1);
    iVar4 = *(int *)(param_1 + 0xb4);
    iVar3 = *(int *)(param_1 + 0xb8);
    iVar5 = (int)((float)lVar6 * (float)iVar4 * (float)iVar3 * 0.99);
    if (*(char *)(param_1 + 0xbc) == '\0') {
      iVar4 = iVar5 / iVar3;
      iVar3 = iVar5 % iVar3;
    }
    else {
      iVar3 = iVar5 / iVar4;
      iVar4 = iVar5 % iVar4;
    }
    local_3c = iVar4 * *(int *)(param_1 + 0xc0) + *(int *)(param_1 + 8);
    local_38 = iVar3 * *(int *)(param_1 + 0xc4) + *(int *)(param_1 + 0xc);
    local_34 = *(int *)(param_1 + 0xc0) + local_3c;
    local_30 = *(int *)(param_1 + 0xc4) + local_38;
    local_28 = (local_38 - *(int *)(param_1 + 0xc)) +
               (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0xc));
    local_2c = local_3c - *(int *)(param_1 + 8);
    (**(code **)(**(int **)(param_1 + 0xb0) + 0x10))
              (*(int **)(param_1 + 0xb0),param_2,&local_3c,&local_2c);
  }
  return;
}

