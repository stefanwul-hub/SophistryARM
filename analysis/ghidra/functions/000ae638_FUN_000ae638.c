/* 000ae638 FUN_000ae638 */

void FUN_000ae638(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_1;
  if (piVar1 != (int *)0x0) {
    iVar2 = _DecrementAtomic(piVar1 + 1);
    if (iVar2 == 1) {
      (**(code **)(*piVar1 + 4))(piVar1);
    }
    *param_1 = 0;
  }
  return;
}

