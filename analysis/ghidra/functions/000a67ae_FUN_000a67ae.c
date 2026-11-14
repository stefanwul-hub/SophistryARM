/* 000a67ae FUN_000a67ae */

void FUN_000a67ae(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xbc);
  if (piVar1 != *(int **)(param_1 + 0xc0)) {
    do {
      while (*piVar1 != param_2) {
        piVar1 = piVar1 + 3;
        if (piVar1 == *(int **)(param_1 + 0xc0)) {
          return;
        }
      }
      (*(code *)piVar1[1])(piVar1[2],*(undefined4 *)(param_1 + 4),param_2,param_3,param_4);
      piVar1 = piVar1 + 3;
    } while (piVar1 != *(int **)(param_1 + 0xc0));
  }
  return;
}

