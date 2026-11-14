/* 00080a0a CDrawbarPl_vslot_4 */

void CDrawbarPl_vslot_4(int param_1,undefined4 param_2)

{
  int iVar1;
  longdouble lVar2;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  
  if (*(int *)(param_1 + 0xd4) == 0) {
    iVar1 = *(int *)(param_1 + 0xd0);
  }
  else {
    local_10 = *(undefined4 *)(param_1 + 0xb4);
    local_14 = *(undefined4 *)(param_1 + 0xb0);
    (**(code **)(**(int **)(param_1 + 0xd4) + 0x10))
              (*(int **)(param_1 + 0xd4),param_2,param_1 + 0xb0,&local_14);
    iVar1 = *(int *)(param_1 + 0xd0);
  }
  if (iVar1 != 0) {
    lVar2 = (longdouble)FUN_000019e8(param_1);
    local_10 = *(int *)(param_1 + 0xcc) - *(int *)(param_1 + 0xc4);
    iVar1 = (int)((float)local_10 * (float)lVar2);
    local_20 = *(int *)(param_1 + 0xb4);
    local_18 = iVar1 + local_20 + *(int *)(param_1 + 0xd8);
    local_1c = *(undefined4 *)(param_1 + 200);
    local_24 = *(undefined4 *)(param_1 + 0xc0);
    local_10 = local_10 - iVar1;
    local_14 = 0;
    if (*(char *)(param_1 + 0x72) == '\0') {
      (**(code **)(**(int **)(param_1 + 0xd0) + 0x10))
                (*(int **)(param_1 + 0xd0),param_2,&local_24,&local_14);
    }
    else {
      (**(code **)(**(int **)(param_1 + 0xd0) + 0x14))
                (*(int **)(param_1 + 0xd0),param_2,&local_24,&local_14);
    }
    CControlPl_vslot_4(param_1,param_2);
    return;
  }
  CControlPl_vslot_4(param_1,param_2);
  return;
}

