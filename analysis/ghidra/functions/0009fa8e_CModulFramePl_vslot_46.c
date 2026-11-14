/* 0009fa8e CModulFramePl_vslot_46 */

void CModulFramePl_vslot_46(int param_1,char *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = *(int **)(param_1 + 0x3c);
  if (*(int **)(param_1 + 0x3c) != (int *)0x0) {
    do {
      piVar1 = (int *)piVar3[1];
      piVar2 = (int *)*piVar3;
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 0x7c))(piVar2,param_1);
        if (*param_2 == '\0') {
          piVar2 = (int *)*piVar3;
        }
        else {
          (**(code **)(*(int *)*piVar3 + 8))((int *)*piVar3);
          piVar2 = (int *)*piVar3;
        }
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 8))(piVar2);
        }
      }
      operator_delete(piVar3);
      piVar3 = piVar1;
    } while (piVar1 != (int *)0x0);
    *(undefined4 *)(param_1 + 0x3c) = 0;
    *(undefined4 *)(param_1 + 0x40) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  return;
}

