/* 00014582 Instrument_c_vslot_6 */

void Instrument_c_vslot_6(int param_1,undefined4 param_2)

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
        (**(code **)(*piVar1 + 0x78))(piVar1,param_2,0xffffffff);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar3 < *(int *)(param_1 + 0x114));
  }
  return;
}

