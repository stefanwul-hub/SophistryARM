/* 00002136 CControlPl_vslot_12 */

undefined4 CControlPl_vslot_12(int *param_1,undefined4 param_2,undefined4 param_3,float param_4)

{
  int iVar1;
  
  if ((param_1[0x2a] != 0x10) && (param_1[0x2a] != 0)) {
    *(bool *)((int)param_1 + 0x6d) = 0.0 < param_4;
    *(bool *)(param_1 + 0x1b) = param_4 < 0.0;
    iVar1 = param_1[0x10];
    (**(code **)(*(int *)param_1[10] + 0x13c))((int *)param_1[10],param_1);
    (**(code **)(*(int *)param_1[10] + 300))((int *)param_1[10],iVar1);
    (*(code *)**(undefined4 **)param_1[0x25])((undefined4 *)param_1[0x25],param_2,param_1);
    (**(code **)(*param_1 + 0xac))(param_1);
    (**(code **)(*(int *)param_1[10] + 0x130))((int *)param_1[10],param_1[0x10]);
    return 1;
  }
  return 1;
}

