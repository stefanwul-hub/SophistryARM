/* 0009d81c CModulFramePl_vslot_11 */

undefined4 CModulFramePl_vslot_11(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x40);
  while ((puVar1 != (undefined4 *)0x0 &&
         (iVar2 = (**(code **)(*(int *)*puVar1 + 0x2c))((int *)*puVar1,param_2), iVar2 == -1))) {
    puVar1 = (undefined4 *)puVar1[2];
  }
  return 0xffffffff;
}

