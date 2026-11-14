/* 00008d98 CSliderPl_vslot_4 */

void CSliderPl_vslot_4(int param_1,undefined4 param_2)

{
  longdouble lVar1;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  lVar1 = (longdouble)FUN_000019e8(param_1);
  if (*(int *)(param_1 + 0xd4) != 0) {
    local_20 = *(int *)(param_1 + 0xb4);
    local_24 = *(int *)(param_1 + 0xb0);
    (**(code **)(**(int **)(param_1 + 0xd4) + 0x10))
              (*(int **)(param_1 + 0xd4),param_2,param_1 + 0xc0,&local_24);
  }
  if (*(int *)(param_1 + 0xd0) != 0) {
    if (*(char *)(param_1 + 0xd8) == '\0') {
      *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 8);
      local_18 = *(int *)(param_1 + 0xe0);
      *(int *)(param_1 + 0xe8) =
           (*(int *)(param_1 + 0x14) -
           (int)((float)((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0xc)) - local_18) *
                (float)lVar1)) - local_18;
      local_1c = *(int *)(param_1 + 0xdc);
      local_20 = *(int *)(param_1 + 0xe8);
    }
    else {
      local_1c = *(int *)(param_1 + 0xdc);
      *(int *)(param_1 + 0xe4) =
           (int)((float)((*(int *)(param_1 + 0x10) - *(int *)(param_1 + 8)) - local_1c) *
                (float)lVar1) + *(int *)(param_1 + 8);
      local_20 = *(int *)(param_1 + 0xc);
      *(int *)(param_1 + 0xe8) = local_20;
      local_18 = *(int *)(param_1 + 0xe0);
    }
    local_18 = local_20 + local_18;
    local_24 = *(int *)(param_1 + 0xe4);
    local_1c = local_1c + local_24;
    local_14 = 0;
    local_10 = 0;
    (**(code **)(**(int **)(param_1 + 0xd0) + 0x14))
              (*(int **)(param_1 + 0xd0),param_2,&local_24,&local_14);
  }
  CControlPl_vslot_4(param_1,param_2);
  return;
}

