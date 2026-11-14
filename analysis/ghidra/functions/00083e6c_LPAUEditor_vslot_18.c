/* 00083e6c LPAUEditor_vslot_18 */

void LPAUEditor_vslot_18(int param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  
  piVar1 = *(int **)(param_1 + 0x279c4);
  if (piVar1 != (int *)0x0) {
    cVar2 = (**(code **)(*piVar1 + 0x24))(piVar1,param_2);
    if (cVar2 != '\0') {
      SynthEditor_c_vslot_18();
      return;
    }
  }
  return;
}

