/* 00097f1a CMenuFileList_vslot_86 */

undefined4 CMenuFileList_vslot_86(int param_1,int param_2,undefined1 param_3)

{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xb4))) {
    *(undefined1 *)(*(int *)(param_1 + 0xac) + param_2) = param_3;
    return 1;
  }
  return 0;
}

