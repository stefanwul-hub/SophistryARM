/* 000af2b2 FUN_000af2b2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000af2b2(int param_1)

{
  float *pfVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x220) != 0) {
    if (0 < *(int *)(param_1 + 0x22c)) {
      iVar2 = 0;
      do {
        pfVar1 = (float *)(iVar2 * 4 + *(int *)(param_1 + 0x21c));
        *pfVar1 = (*pfVar1 + *(float *)(iVar2 * 4 + *(int *)(param_1 + 0x220))) * 0.5;
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_1 + 0x22c));
    }
    *(undefined1 *)(param_1 + 0x214) = 0;
    *(undefined2 *)(param_1 + 0x216) = 1;
    _free(*(void **)(param_1 + 0x220));
    *(undefined4 *)(param_1 + 0x220) = 0;
  }
  return;
}

