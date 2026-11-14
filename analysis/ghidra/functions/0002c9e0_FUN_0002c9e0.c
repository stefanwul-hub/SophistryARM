/* 0002c9e0 FUN_0002c9e0 */

void FUN_0002c9e0(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 0x2a4) == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x298) < 1) {
    *(undefined4 *)(param_1 + 0x528) = 0;
    return;
  }
  iVar4 = 0;
  do {
    iVar1 = iVar4 * 4;
    iVar3 = *(int *)(param_1 + 0x2a4);
    pvVar2 = *(void **)(iVar3 + iVar1);
    if (pvVar2 == *(void **)(param_1 + 0x2a0)) {
      if (*(int *)(param_1 + 0x298) <= iVar4 + 1) goto LAB_0002ca6d;
    }
    else {
      if (pvVar2 != (void *)0x0) {
        _free(pvVar2);
        iVar3 = *(int *)(param_1 + 0x2a4);
      }
      *(undefined4 *)(iVar3 + iVar1) = 0;
      *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x2a4)) = *(undefined4 *)(param_1 + 0x2a0);
      if (*(int *)(param_1 + 0x298) <= iVar4 + 1) {
LAB_0002ca6d:
        *(undefined4 *)(param_1 + 0x528) = 0;
        return;
      }
    }
    iVar4 = iVar4 + 1;
  } while( true );
}

