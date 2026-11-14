/* 000145d2 Instrument_c_vslot_9 */

void Instrument_c_vslot_9(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (0 < *(int *)(param_1 + 0x114)) {
    iVar3 = 0;
    iVar2 = param_1;
    do {
      while ((piVar1 = *(int **)(iVar2 + 0x14), piVar1 != (int *)0x0 &&
             (*(char *)(param_2 + 0x1b4 + (int)piVar1) != '\0'))) {
        (**(code **)(*piVar1 + 0x94))(piVar1);
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
        if (*(int *)(param_1 + 0x114) <= iVar3) {
          return;
        }
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < *(int *)(param_1 + 0x114));
  }
  return;
}

