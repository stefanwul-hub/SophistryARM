/* 0002fee2 FUN_0002fee2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0002fee2(undefined4 *param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  *param_1 = PTR_DAT_0010380c + 8;
  FUN_0002e178(param_1 + 1);
  *param_1 = &PTR_PolyNoteTable_c_vslot_0_000e7ba8;
  *(undefined1 *)(param_1 + 7) = 0;
  param_1[3] = param_2;
  pvVar2 = _malloc(param_2 * 0x24 + 0x24);
  param_1[4] = pvVar2;
  if (pvVar2 != (void *)0x0) {
    if (0 < (int)param_1[3]) {
      iVar5 = 0;
      iVar4 = 0;
      do {
        while( true ) {
          *(undefined4 *)(param_1[4] + 4 + iVar4) = 0xffffffff;
          *(undefined1 *)(param_1[4] + 0x18 + iVar4) = 0;
          *(undefined4 *)(param_1[4] + 0xc + iVar4) = 0xffffffff;
          *(undefined4 *)(param_1[4] + 0x1c + iVar4) = 0xffffffff;
          *(undefined4 *)(param_1[4] + 0x20 + iVar4) = 0xffffffff;
          *(undefined4 *)(param_1[4] + iVar4) = 0;
          *(undefined4 *)(param_1[4] + 0x10 + iVar4) = 0xffffffff;
          if (*(char *)(param_1 + 7) != '\0') break;
          *(undefined4 *)(param_1[4] + 8 + iVar4) = 0;
          iVar5 = iVar5 + 1;
          iVar4 = iVar4 + 0x24;
          if ((int)param_1[3] <= iVar5) goto LAB_0002ffee;
        }
        iVar3 = param_1[4];
        iVar1 = *(int *)(iVar3 + 8 + iVar4);
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0x154) = 0;
          *(undefined4 *)(*(int *)(param_1[4] + 8 + iVar4) + 0x14c) = 0;
          iVar3 = param_1[4];
        }
        *(undefined4 *)(iVar3 + 8 + iVar4) = 0;
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x24;
      } while (iVar5 < (int)param_1[3]);
    }
LAB_0002ffee:
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[2] = 0xfffffffe;
    *(undefined1 *)(param_1 + 7) = 1;
  }
  return;
}

