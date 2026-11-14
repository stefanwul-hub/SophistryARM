/* 00097f90 CMenuFileList_vslot_88 */

undefined1 CMenuFileList_vslot_88(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xb4))) {
    return *(undefined1 *)(*(int *)(param_1 + 0xac) + param_2);
  }
  return 0;
}

