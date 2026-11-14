/* 000a69a4 LPAUSynth_vslot_13 */

undefined4 LPAUSynth_vslot_13(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc0) - *(int *)(param_1 + 0xbc) >> 2;
  iVar1 = iVar3 * -0x55555555;
  iVar3 = iVar3 * 4;
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    iVar3 = iVar3 + -0xc;
    piVar2 = (int *)(iVar3 + *(int *)(param_1 + 0xbc));
    if ((*piVar2 == param_2) && (piVar2[1] == param_3)) {
      FUN_000c5172((int *)(param_1 + 0xbc),piVar2);
    }
  }
  return 0;
}

