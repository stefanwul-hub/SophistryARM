/* 00008b04 CSliderPl_vslot_72 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble CSliderPl_vslot_72(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_1c;
  int local_18;
  int local_14;
  
  local_1c = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0xc);
  if (local_1c < 0x50) {
    local_1c = 0x50;
    local_14 = 0x28;
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0x10);
    local_18 = iVar2 - iVar1;
  }
  else {
    local_14 = local_1c / 2;
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = *(int *)(param_1 + 0x10);
    local_18 = iVar2 - iVar1;
  }
  if (local_18 < 0x50) {
    local_18 = 0x50;
    iVar3 = 0x28;
  }
  else {
    iVar3 = local_18 / 2;
  }
  if (*(char *)(param_1 + 0xd8) == '\0') {
    return (longdouble)
           (1.0 - (float)(param_2[1] -
                         ((*(int *)(param_1 + 0xe0) / 2 + *(int *)(param_1 + 0xc) +
                          (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0xc)) / 2) - local_14)) /
                  (float)(local_1c - *(int *)(param_1 + 0xe0)));
  }
  return (longdouble)
         ((float)(*param_2 -
                 ((*(int *)(param_1 + 0xdc) / 2 + *(int *)(param_1 + 8) + (iVar2 - iVar1) / 2) -
                 iVar3)) / (float)(local_18 - *(int *)(param_1 + 0xdc)));
}

