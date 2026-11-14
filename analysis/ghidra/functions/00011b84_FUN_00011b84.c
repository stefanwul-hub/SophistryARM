/* 00011b84 FUN_00011b84 */

void FUN_00011b84(int param_1)

{
  void *pvVar1;
  int iVar2;
  int local_10;
  
  if (*(int *)(param_1 + 4) != 0) {
    if (1 < *(int *)(param_1 + 8)) {
      local_10 = 1;
      do {
        pvVar1 = *(void **)(*(int *)(param_1 + 0x1c) + local_10 * 4);
        _memcpy(pvVar1,*(void **)(param_1 + 4),*(int *)(param_1 + 0x18) * 0x70);
        if (0 < *(int *)(param_1 + 0x18)) {
          iVar2 = 0;
          do {
            while (*(int *)((int)pvVar1 + 4) != 7) {
              iVar2 = iVar2 + 1;
              pvVar1 = (void *)((int)pvVar1 + 0x70);
              if (*(int *)(param_1 + 0x18) <= iVar2) goto LAB_00011c1a;
            }
            FUN_00010bb4(pvVar1);
            iVar2 = iVar2 + 1;
            pvVar1 = (void *)((int)pvVar1 + 0x70);
          } while (iVar2 < *(int *)(param_1 + 0x18));
        }
LAB_00011c1a:
        local_10 = local_10 + 1;
      } while (local_10 < *(int *)(param_1 + 8));
    }
    *(undefined1 *)(param_1 + 0x11) = 1;
  }
  return;
}

