/* 0001443a Instrument_c_vslot_3 */

void Instrument_c_vslot_3(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (0 < *(int *)(param_1 + 0x114)) {
    iVar3 = 0;
    iVar2 = param_1;
    do {
      piVar1 = *(int **)(iVar2 + 0x14);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 8))(piVar1);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < *(int *)(param_1 + 0x114));
  }
  return;
}

