/* 0009fc6c CFrame_vslot_65 */

void CFrame_vslot_65(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x60);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x50))(piVar1);
  }
  iVar2 = *(int *)(param_1 + 0x94);
  if (((iVar2 != 0) && (*(char *)(iVar2 + 100) != '\0')) && (*(int *)(iVar2 + 0x60) != 0)) {
    _CGContextSynchronize(*(int *)(iVar2 + 0x60));
    *(undefined1 *)(iVar2 + 100) = 0;
  }
  return;
}

