/* 0009d8be CModulFramePl_vslot_19 */

void CModulFramePl_vslot_19(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 0x3c); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)puVar1[1]) {
    (**(code **)(*(int *)*puVar1 + 0x4c))((int *)*puVar1,param_2);
  }
  return;
}

