/* 000c0950 CControlPl_vslot_26 */

undefined4 CControlPl_vslot_26(int param_1,int *param_2)

{
  if ((((*(int *)(param_1 + 0x18) <= *param_2) && (*param_2 <= *(int *)(param_1 + 0x20))) &&
      (*(int *)(param_1 + 0x1c) <= param_2[1])) && (param_2[1] <= *(int *)(param_1 + 0x24))) {
    return 1;
  }
  return 0;
}

