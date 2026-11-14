/* 000c08aa CControlPl_vslot_6 */

undefined4 CControlPl_vslot_6(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((((param_2[2] < *(int *)(param_1 + 8)) || (*(int *)(param_1 + 0x10) < *param_2)) ||
      (param_2[3] < *(int *)(param_1 + 0xc))) || (*(int *)(param_1 + 0x14) < param_2[1])) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

