/* 00010eee FUN_00010eee */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00010eee(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(param_1 + 0x4c);
  puVar2 = *(undefined1 **)(param_1 + 0x60);
  if (puVar2 != &DAT_000e2000) {
    if (*(int *)(param_1 + 4) == 7) {
      if (*(int *)(param_1 + 0x30) != 0) {
        FUN_00010e34(param_1,*(int *)(param_1 + 0x30));
        FUN_0000ff7e();
        return;
      }
      *puVar2 = 0;
    }
    else if ((*(int *)(param_1 + 4) == 8) && (0 < *(int *)(param_1 + 0x54))) {
      iVar1 = 0;
      while( true ) {
        *(undefined4 *)(puVar2 + iVar1 * 4) = 0;
        iVar1 = iVar1 + 1;
        if (*(int *)(param_1 + 0x54) <= iVar1) break;
        puVar2 = *(undefined1 **)(param_1 + 0x60);
      }
    }
  }
  FUN_0000ff7e();
  return;
}

