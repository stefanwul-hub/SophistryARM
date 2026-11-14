/* 0009d458 CFrame_vslot_79 */

void CFrame_vslot_79(int param_1,int *param_2)

{
  int *piVar1;
  char cVar2;
  
  piVar1 = *(int **)(param_1 + 0x6c);
  *(int **)(param_1 + 0x6c) = param_2;
  if (param_2 != (int *)0x0) {
    cVar2 = (**(code **)(*param_2 + 0x9c))(param_2);
    if (cVar2 != '\0') {
      (**(code **)(**(int **)(param_1 + 0x6c) + 0x54))(*(int **)(param_1 + 0x6c),1);
    }
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x48))(piVar1,0);
    cVar2 = (**(code **)(*piVar1 + 0x9c))(piVar1);
    if (cVar2 != '\0') {
                    /* WARNING: Could not recover jumptable at 0x0009d4be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*piVar1 + 0x54))();
      return;
    }
  }
  return;
}

