/* 00005daa CLabelPl_vslot_4 */

void CLabelPl_vslot_4(int param_1,undefined4 param_2)

{
  int *piVar1;
  int local_160;
  char local_154 [320];
  undefined4 local_14;
  undefined4 local_10;
  
  local_10 = *(undefined4 *)(param_1 + 0xd4);
  local_14 = *(undefined4 *)(param_1 + 0xd0);
  piVar1 = *(int **)(param_1 + 0xb4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(piVar1,param_2,param_1 + 8,&local_14);
  }
  local_160 = param_1 + 8;
  FUN_0009e6ac(param_2,*(undefined4 *)(param_1 + 0x88));
  FUN_0009ca22(param_2,*(undefined4 *)(param_1 + 200),0,0);
  if (*(char **)(param_1 + 0xb0) == (char *)0x0) {
    FUN_0009fe14(param_2,*(undefined4 *)(param_1 + 0x84),local_160,0,*(undefined4 *)(param_1 + 0xcc)
                );
    CControlPl_vslot_4(param_1,param_2);
    return;
  }
  _sprintf(local_154,*(char **)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0x84));
  FUN_0009fe14(param_2,local_154,local_160,0,*(undefined4 *)(param_1 + 0xcc));
  CControlPl_vslot_4(param_1,param_2);
  return;
}

