/* 00097554 CMenuFileList_vslot_83 */

undefined4 CMenuFileList_vslot_83(int param_1)

{
  int iVar1;
  int *piVar2;
  int local_14;
  int local_10;
  
  if (*(int *)(param_1 + 0xb4) < 1) {
    *(undefined4 *)(param_1 + 0xb4) = 0;
    *(undefined4 *)(param_1 + 0xbc) = 0xffffffff;
    iVar1 = *(int *)(param_1 + 0xb8);
  }
  else {
    local_14 = 0;
    do {
      _free(*(void **)(local_14 * 4 + *(int *)(param_1 + 0xa4)));
      *(undefined4 *)(local_14 * 4 + *(int *)(param_1 + 0xa4)) = 0;
      *(undefined1 *)(local_14 + *(int *)(param_1 + 0xac)) = 0;
      local_14 = local_14 + 1;
    } while (local_14 < *(int *)(param_1 + 0xb4));
    *(undefined4 *)(param_1 + 0xb4) = 0;
    *(undefined4 *)(param_1 + 0xbc) = 0xffffffff;
    iVar1 = *(int *)(param_1 + 0xb8);
  }
  if (0 < iVar1) {
    local_10 = 0;
    do {
      piVar2 = *(int **)(*(int *)(param_1 + 0xa8) + local_10 * 4);
      (**(code **)(*piVar2 + 8))(piVar2);
      *(undefined4 *)(local_10 * 4 + *(int *)(param_1 + 0xa8)) = 0;
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)(param_1 + 0xb8));
  }
  *(undefined4 *)(param_1 + 0xb8) = 0;
  if (*(void **)(param_1 + 0xac) != (void *)0x0) {
    _free(*(void **)(param_1 + 0xac));
  }
  *(undefined4 *)(param_1 + 0xac) = 0;
  if (*(void **)(param_1 + 0xa4) != (void *)0x0) {
    _free(*(void **)(param_1 + 0xa4));
  }
  *(undefined4 *)(param_1 + 0xa4) = 0;
  if (*(void **)(param_1 + 0xa8) != (void *)0x0) {
    _free(*(void **)(param_1 + 0xa8));
  }
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  return 1;
}

