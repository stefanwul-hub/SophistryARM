/* 00097da8 CMenuFileList_vslot_82 */

undefined4 CMenuFileList_vslot_82(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xb4))) {
    iVar1 = *(int *)(param_1 + 0xb4) + -1;
    *(int *)(param_1 + 0xb4) = iVar1;
    if (param_2 < iVar1) {
      iVar4 = param_2 << 2;
      iVar1 = param_2;
      do {
        puVar2 = (undefined4 *)(iVar4 + *(int *)(param_1 + 0xa4));
        _strcpy((char *)*puVar2,(char *)puVar2[1]);
        puVar3 = (undefined1 *)(iVar1 + *(int *)(param_1 + 0xac));
        *puVar3 = puVar3[1];
        iVar1 = iVar1 + 1;
        iVar4 = iVar4 + 4;
      } while (iVar1 < *(int *)(param_1 + 0xb4));
    }
    if (param_2 <= *(int *)(param_1 + 0xbc)) {
      *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + -1;
    }
    _free(*(void **)(*(int *)(param_1 + 0xa4) + *(int *)(param_1 + 0xb4) * 4));
    *(undefined4 *)(*(int *)(param_1 + 0xa4) + *(int *)(param_1 + 0xb4) * 4) = 0;
    *(undefined1 *)(*(int *)(param_1 + 0xac) + *(int *)(param_1 + 0xb4)) = 0;
    if (*(int *)(param_1 + 0xb4) == 0) {
      *(undefined4 *)(param_1 + 0xbc) = 0xffffffff;
    }
    return 1;
  }
  return 0;
}

