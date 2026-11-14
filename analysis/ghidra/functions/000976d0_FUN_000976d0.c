/* 000976d0 FUN_000976d0 */

undefined4 FUN_000976d0(int param_1,int param_2)

{
  size_t sVar1;
  void *pvVar2;
  int iVar3;
  size_t sVar4;
  
  sVar1 = *(int *)(param_1 + 0xcc) + param_2;
  if (*(void **)(param_1 + 0xac) == (void *)0x0) {
    pvVar2 = _malloc(sVar1);
    *(void **)(param_1 + 0xac) = pvVar2;
    iVar3 = *(int *)(param_1 + 0xac);
  }
  else {
    pvVar2 = _realloc(*(void **)(param_1 + 0xac),sVar1);
    *(void **)(param_1 + 0xac) = pvVar2;
    iVar3 = *(int *)(param_1 + 0xac);
  }
  if (iVar3 != 0) {
    if (*(void **)(param_1 + 0xa4) == (void *)0x0) {
      pvVar2 = _malloc(sVar1 * 4);
      *(void **)(param_1 + 0xa4) = pvVar2;
    }
    else {
      pvVar2 = _realloc(*(void **)(param_1 + 0xa4),sVar1 * 4);
      *(void **)(param_1 + 0xa4) = pvVar2;
    }
    if (*(int *)(param_1 + 0xa4) != 0) {
      sVar4 = *(size_t *)(param_1 + 0xcc);
      if ((int)sVar4 < (int)sVar1) {
        iVar3 = sVar4 * 4;
        do {
          *(undefined1 *)(*(int *)(param_1 + 0xac) + sVar4) = 0;
          *(undefined4 *)(*(int *)(param_1 + 0xa4) + iVar3) = 0;
          sVar4 = sVar4 + 1;
          iVar3 = iVar3 + 4;
        } while (sVar4 != sVar1);
      }
      *(size_t *)(param_1 + 0xcc) = sVar1;
      return 1;
    }
    _free(*(void **)(param_1 + 0xac));
  }
  return 0;
}

