/* 000987bc CSlider_vslot_12 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 CSlider_vslot_12(int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  char cVar1;
  uint uVar2;
  
  if (*(char *)((int)param_1 + 0x31) == '\0') {
    return 0;
  }
  uVar2 = FUN_0009cba2(param_2);
  if ((uVar2 & 8) == 0) {
    param_1[0x13] = (int)(param_4 * (float)param_1[0x16] + (float)param_1[0x13]);
    (**(code **)(*param_1 + 0xf8))(param_1);
    cVar1 = (**(code **)(*param_1 + 0x50))(param_1);
  }
  else {
    param_1[0x13] = (int)(param_4 * 0.1 * (float)param_1[0x16] + (float)param_1[0x13]);
    (**(code **)(*param_1 + 0xf8))(param_1);
    cVar1 = (**(code **)(*param_1 + 0x50))(param_1);
  }
  if ((cVar1 != '\0') && (param_1[0xf] != 0)) {
    (**(code **)(*param_1 + 0xe0))(param_1);
    (*(code *)**(undefined4 **)param_1[0xf])((undefined4 *)param_1[0xf],param_2,param_1);
    (**(code **)(*param_1 + 0xe4))(param_1);
    return 1;
  }
  return 1;
}

