/* 00007ec2 CModulFramePl_vslot_5 */

void CModulFramePl_vslot_5(int param_1,undefined4 param_2,undefined4 param_3)

{
  CViewContainer_vslot_5(param_1,param_2,param_3);
  if (*(code **)(param_1 + 0x60) != (code *)0x0) {
    (**(code **)(param_1 + 0x60))(param_2);
  }
  *(undefined1 *)(param_1 + 0x30) = 0;
  *(undefined1 *)(param_1 + 100) = 0;
  return;
}

