/* 000257cc FUN_000257cc */

void FUN_000257cc(int param_1,char *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  
  cVar1 = *param_2;
  if (cVar1 == -0x10) {
    *(undefined4 *)(param_1 + 0x3ba4) = 1;
    return;
  }
  if (cVar1 != -9) {
    if (cVar1 != -1) {
      return;
    }
    if (0 < *(int *)(param_1 + 0xcfb0)) {
      iVar3 = 0;
      do {
        piVar2 = *(int **)(*(int *)(param_1 + 0xcea4) + iVar3 * 4);
        if (piVar2 != (int *)0x0) {
          (**(code **)(*piVar2 + 0x50))(piVar2);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0xcfb0));
    }
    FUN_00024e9e(param_1);
    FUN_0002eb20(param_1 + 0x38cc);
    FUN_0002bb04(param_1 + 0x38a4);
  }
  *(undefined4 *)(param_1 + 0x3ba4) = 0;
  return;
}

