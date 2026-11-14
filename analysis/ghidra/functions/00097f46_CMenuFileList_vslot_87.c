/* 00097f46 CMenuFileList_vslot_87 */

undefined4 CMenuFileList_vslot_87(int param_1,int param_2)

{
  int iVar1;
  
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xb4))) {
    if (0 < *(int *)(param_1 + 0xb4)) {
      iVar1 = 0;
      do {
        *(undefined1 *)(*(int *)(param_1 + 0xac) + iVar1) = 0;
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(param_1 + 0xb4));
    }
    *(undefined1 *)(*(int *)(param_1 + 0xac) + param_2) = 1;
    return 1;
  }
  return 0;
}

