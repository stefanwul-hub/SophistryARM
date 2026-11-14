/* 000b6884 FUN_000b6884 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000b6884(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 8) <= param_2) {
    return;
  }
  iVar4 = *(int *)(param_1 + 0x18);
  if (*(int *)(param_1 + 8) <= iVar4) {
    *(int *)(param_1 + 0x18) = param_2;
    if (*(int *)(param_1 + 4) == 0) {
      return;
    }
    if (*(int *)(param_1 + 8) < 1) {
      return;
    }
    iVar4 = 0;
    do {
      *(undefined4 *)(*(int *)(param_1 + 4) + iVar4 * 4) = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 8));
    return;
  }
  iVar3 = param_2;
  if (iVar4 < param_2) {
    iVar3 = iVar4;
  }
  if (0x20 < iVar3) {
    iVar5 = 0;
    iVar3 = *(int *)(param_1 + 0x10);
    iVar1 = *(int *)(param_1 + 4);
    iVar2 = param_1;
    do {
      *(float *)(iVar2 + 0x1c) =
           (float)(0x20 - iVar5) * *(float *)(iVar1 + ((iVar5 + iVar3) % iVar4) * 4) * 0.03125;
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + 4;
    } while (iVar5 != 0x20);
    iVar5 = 0;
    iVar3 = iVar3 + iVar4;
    iVar2 = param_1;
    do {
      *(float *)(iVar2 + 0x9c) = (float)iVar5 * *(float *)(iVar1 + (iVar3 % iVar4) * 4) * 0.03125;
      iVar5 = iVar5 + 1;
      iVar3 = iVar3 + -1;
      iVar2 = iVar2 + 4;
    } while (iVar5 != 0x20);
  }
  *(int *)(param_1 + 0x18) = param_2;
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 8) < 1) {
      iVar4 = *(int *)(param_1 + 0x18);
      if (param_2 <= *(int *)(param_1 + 0x18)) {
        iVar4 = param_2;
      }
      goto joined_r0x000b69d9;
    }
    iVar4 = 0;
    do {
      *(undefined4 *)(*(int *)(param_1 + 4) + iVar4 * 4) = 0;
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 8));
  }
  iVar4 = *(int *)(param_1 + 0x18);
  if (param_2 <= *(int *)(param_1 + 0x18)) {
    iVar4 = param_2;
  }
joined_r0x000b69d9:
  if (0x20 < iVar4) {
    _memcpy(*(void **)(param_1 + 4),(void *)(param_1 + 0x1c),0x80);
    _memcpy((void *)(*(int *)(param_1 + 4) + -0x80 + *(int *)(param_1 + 0x18) * 4),
            (void *)(param_1 + 0x9c),0x80);
  }
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}

