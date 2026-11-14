/* 0009d8f0 CModulFramePl_vslot_31 */

undefined4 CModulFramePl_vslot_31(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x48);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)(param_1 + 0x48) = 0;
  return 1;
}

