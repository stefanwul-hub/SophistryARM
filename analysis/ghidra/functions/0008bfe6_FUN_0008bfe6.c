/* 0008bfe6 FUN_0008bfe6 */

void FUN_0008bfe6(int param_1)

{
  int iVar1;
  void *pvVar2;
  
  if (*(int *)(param_1 + 0x318) != 0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x120) + 8))(*(int **)(param_1 + 0x120),0);
    pvVar2 = _malloc(iVar1 + 1);
    if (pvVar2 != (void *)0x0) {
      (**(code **)(**(int **)(param_1 + 0x120) + 0xc))(*(int **)(param_1 + 0x120),pvVar2,0);
      FUN_0002e9fe(param_1 + 0x168,param_1 + 0x1d5,pvVar2,iVar1);
      _free(pvVar2);
      return;
    }
  }
  return;
}

