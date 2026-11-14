/* 000166b0 Synth_vslot_154 */

void Synth_vslot_154(int param_1)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  if (*(char *)(param_1 + 0x9a38) != '\0') {
    FUN_000ae9ac(FUN_00009a24 + param_1);
    *(undefined1 *)(param_1 + 0xcfd6) = 0;
  }
  iVar4 = 0;
  iVar3 = param_1;
  do {
    if (*(void **)(iVar3 + 0x511c) != (void *)0x0) {
      _free(*(void **)(iVar3 + 0x511c));
    }
    *(undefined4 *)(iVar3 + 0x511c) = 0;
    *(undefined4 *)(iVar3 + 0x5130) = 0;
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 0x1c;
  } while (iVar4 != 0xa0);
  if (0 < *(int *)(param_1 + 0x9a4c)) {
    iVar3 = 0;
    do {
      iVar4 = *(int *)(param_1 + 0xcea0);
      piVar2 = *(int **)(iVar4 + iVar3 * 4);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
        iVar4 = *(int *)(param_1 + 0xcea0);
      }
      *(undefined4 *)(iVar4 + iVar3 * 4) = 0;
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(param_1 + 0x9a4c));
  }
  *(undefined4 *)(param_1 + 0x3b88) = 0;
  if (*(void **)(param_1 + 0xcea0) != (void *)0x0) {
    _free(*(void **)(param_1 + 0xcea0));
  }
  *(undefined4 *)(param_1 + 0xcea0) = 0;
  if (*(void **)(param_1 + 0x9bc4) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x9bc4));
  }
  *(undefined4 *)(param_1 + 0x9bc4) = 0;
  if (*(void **)(param_1 + 0x3b0c) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x3b0c));
  }
  *(undefined4 *)(param_1 + 0x3b0c) = 0;
  iVar4 = 5;
  iVar3 = param_1;
  do {
    if (*(void **)(iVar3 + 0x7998) != (void *)0x0) {
      _free(*(void **)(iVar3 + 0x7998));
    }
    *(undefined4 *)(iVar3 + 0x7998) = 0;
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (*(void **)(param_1 + 0xcea4) != (void *)0x0) {
    _free(*(void **)(param_1 + 0xcea4));
  }
  *(undefined4 *)(param_1 + 0xcea4) = 0;
  if (*(void **)(param_1 + 0x8abc) == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x8abc) = 0;
    pvVar1 = *(void **)(param_1 + 0x8ac0);
  }
  else {
    _free(*(void **)(param_1 + 0x8abc));
    *(undefined4 *)(param_1 + 0x8abc) = 0;
    pvVar1 = *(void **)(param_1 + 0x8ac0);
  }
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x8ac0) = 0;
    *(undefined1 *)(param_1 + 0xcfc4) = 0;
    return;
  }
  _free(pvVar1);
  *(undefined4 *)(param_1 + 0x8ac0) = 0;
  *(undefined1 *)(param_1 + 0xcfc4) = 0;
  return;
}

