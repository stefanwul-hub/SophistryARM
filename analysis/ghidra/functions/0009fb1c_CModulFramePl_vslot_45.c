/* 0009fb1c CModulFramePl_vslot_45 */

void CModulFramePl_vslot_45(int param_1,int *param_2,char *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 0x28);
  if ((piVar4 != (int *)0x0) &&
     (piVar4 = (int *)(**(code **)(*piVar4 + 0x140))(piVar4), param_2 == piVar4)) {
    (**(code **)(**(int **)(param_1 + 0x28) + 0x13c))(*(int **)(param_1 + 0x28),0);
  }
  puVar1 = *(undefined4 **)(param_1 + 0x3c);
  if (puVar1 != (undefined4 *)0x0) {
    piVar4 = (int *)*puVar1;
    while (param_2 != piVar4) {
      puVar1 = (undefined4 *)puVar1[1];
      if (puVar1 == (undefined4 *)0x0) {
        return;
      }
      piVar4 = (int *)*puVar1;
    }
    iVar2 = puVar1[1];
    iVar3 = puVar1[2];
    if ((param_2 == (int *)0x0) ||
       ((**(code **)(*param_2 + 0x7c))(param_2,param_1), *param_3 == '\0')) {
      piVar4 = (int *)*puVar1;
    }
    else {
      (**(code **)(*(int *)*puVar1 + 8))((int *)*puVar1);
      piVar4 = (int *)*puVar1;
    }
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 8))(piVar4);
    }
    operator_delete(puVar1);
    if (iVar3 == 0) {
      *(int *)(param_1 + 0x3c) = iVar2;
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 8) = 0;
        return;
      }
      *(undefined4 *)(param_1 + 0x40) = 0;
    }
    else {
      *(int *)(iVar3 + 4) = iVar2;
      if (iVar2 == 0) {
        *(int *)(param_1 + 0x40) = iVar3;
        return;
      }
      *(int *)(iVar2 + 8) = iVar3;
    }
  }
  return;
}

