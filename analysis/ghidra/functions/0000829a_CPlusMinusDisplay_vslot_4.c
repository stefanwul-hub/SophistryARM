/* 0000829a CPlusMinusDisplay_vslot_4 */

void CPlusMinusDisplay_vslot_4(int param_1,undefined4 param_2)

{
  undefined4 local_14;
  undefined4 local_10;
  
  if (*(int *)(param_1 + 0xf0) != 0) {
    local_10 = *(undefined4 *)(param_1 + 0xb4);
    local_14 = *(undefined4 *)(param_1 + 0xb0);
    (**(code **)(**(int **)(param_1 + 0xf0) + 0x10))
              (*(int **)(param_1 + 0xf0),param_2,param_1 + 0xc0,&local_14);
  }
  FUN_0009e6ac(param_2,*(undefined4 *)(param_1 + 0x88));
  FUN_0009ca22(param_2,*(undefined4 *)(param_1 + 0xf4),0,0);
  FUN_0009fe14(param_2,*(undefined4 *)(param_1 + 0x84),param_1 + 0xc0,0,1);
  CControlPl_vslot_4(param_1,param_2);
  return;
}

