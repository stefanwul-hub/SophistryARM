/* 000abefa FUN_000abefa */

void FUN_000abefa(int param_1)

{
  int *piVar1;
  void *pvVar2;
  void *pvVar3;
  int *piVar4;
  
  piVar4 = *(int **)(param_1 + 8);
  if (piVar4 != *(int **)(param_1 + 0xc)) {
    do {
      piVar1 = (int *)*piVar4;
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      piVar4 = piVar4 + 1;
    } while (*(int **)(param_1 + 0xc) != piVar4);
  }
  pvVar2 = *(void **)(param_1 + 8);
  for (pvVar3 = pvVar2; *(void **)(param_1 + 0xc) != pvVar3; pvVar3 = (void *)((int)pvVar3 + 4)) {
  }
  if (pvVar2 != (void *)0x0) {
    operator_delete(pvVar2);
    return;
  }
  return;
}

