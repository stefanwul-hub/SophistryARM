/* 0009d91c CModulFramePl_vslot_57 */

void CModulFramePl_vslot_57(int param_1,char param_2)

{
  int *piVar1;
  
  *(char *)(param_1 + 0x58) = param_2;
  if ((param_2 == '\0') && (piVar1 = *(int **)(param_1 + 0x48), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x48) = 0;
  }
  return;
}

