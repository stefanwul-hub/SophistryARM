/* 00097d24 CMenuFileList_vslot_80 */

undefined4 CMenuFileList_vslot_80(int param_1,int param_2,char *param_3)

{
  if ((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xb4))) {
    if (param_3 != (char *)0x0) {
      _strcpy(param_3,*(char **)(*(int *)(param_1 + 0xa4) + param_2 * 4));
    }
    return 1;
  }
  return 0;
}

