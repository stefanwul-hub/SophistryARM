/* 000abe9e FUN_000abe9e */

undefined4 FUN_000abe9e(int param_1)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  uVar3 = 0;
  piVar2 = piVar1;
  while( true ) {
    if ((uint)(*(int *)(param_1 + 0xc) - (int)piVar1 >> 2) <= uVar3) {
      return 0;
    }
    if ((((piVar2 < *(int **)(param_1 + 0xc)) && (piVar1 <= piVar2)) && (*piVar2 != 0)) &&
       (*(int *)(*piVar2 + 0x30) != 0)) break;
    uVar3 = uVar3 + 1;
    piVar2 = piVar2 + 1;
  }
  return 1;
}

