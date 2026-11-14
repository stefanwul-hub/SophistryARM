/* 00097eba CMenuFileList_vslot_85 */

int CMenuFileList_vslot_85(int param_1,char *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((param_2 != (char *)0x0) && (iVar1 = *(int *)(param_1 + 0xb4), 0 < iVar1)) {
    iVar2 = *(int *)(param_1 + 0xa4);
    iVar4 = 0;
    do {
      iVar3 = _strcmp(*(char **)(iVar2 + iVar4 * 4),param_2);
      if (iVar3 == 0) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != iVar1);
  }
  return -1;
}

