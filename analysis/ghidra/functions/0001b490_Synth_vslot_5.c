/* 0001b490 Synth_vslot_5 */

void Synth_vslot_5(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0xcfc4) == '\0') {
    return;
  }
  _OSAtomicAdd32Barrier(1,param_1 + 0x3b30);
  *(undefined1 *)(param_1 + 0xcfce) = 0;
  if (*(int *)(param_1 + 0xcfb0) < 1) {
    iVar2 = *(int *)(param_1 + 0x3b24);
  }
  else {
    iVar2 = 0;
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0xcea4) + iVar2 * 4);
      (**(code **)(*piVar1 + 0xc))(piVar1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0xcfb0));
    iVar2 = *(int *)(param_1 + 0x3b24);
  }
  if (0 < iVar2) {
    iVar2 = 0;
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x3b0c) + iVar2 * 4);
      (**(code **)(*piVar1 + 0xc))(piVar1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < *(int *)(param_1 + 0x3b24));
  }
  _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0x3b30);
  return;
}

