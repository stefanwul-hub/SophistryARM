/* 00025068 FUN_00025068 */

void FUN_00025068(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (0 < *(int *)(param_1 + 0xcfb0)) {
    iVar2 = 0;
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0xcea4) + iVar2 * 4);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x50))(piVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0xcfb0));
  }
  FUN_00024e9e(param_1);
  FUN_0002eb20(param_1 + 0x38cc);
  FUN_0002bb04(param_1 + 0x38a4);
  *(undefined4 *)(param_1 + 0x3ba4) = 0;
  return;
}

