/* 000977f0 CMenuFileList_vslot_77 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 CMenuFileList_vslot_77(int param_1,char *param_2,int param_3)

{
  char cVar1;
  void *pvVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = *(int *)(param_1 + 0xb4);
  if (0x3ff < iVar5) {
    return 0;
  }
  if (*(int *)(param_1 + 0xcc) <= iVar5) {
    cVar1 = FUN_000976d0(param_1,0x20);
    if (cVar1 == '\0') {
      return 0;
    }
    iVar5 = *(int *)(param_1 + 0xb4);
  }
  iVar6 = *(int *)(param_1 + 0xa4);
  pvVar2 = _malloc(0x100);
  *(void **)(iVar6 + iVar5 * 4) = pvVar2;
  iVar5 = *(int *)(param_1 + 0xb4);
  if (-1 < param_3) {
    iVar6 = iVar5;
    if (param_3 < iVar5) {
      iVar6 = iVar5 * 4;
      do {
        puVar3 = (undefined4 *)(iVar6 + *(int *)(param_1 + 0xa4));
        _strcpy((char *)*puVar3,(char *)puVar3[-1]);
        iVar5 = iVar5 + -1;
        iVar6 = iVar6 + -4;
      } while (param_3 < iVar5);
      iVar6 = *(int *)(param_1 + 0xb4);
    }
    iVar5 = param_3;
    if (iVar6 <= param_3) {
      iVar5 = iVar6;
    }
    if (param_3 <= *(int *)(param_1 + 0xbc)) {
      *(int *)(param_1 + 0xbc) = *(int *)(param_1 + 0xbc) + 1;
    }
  }
  iVar5 = iVar5 * 4;
  **(undefined1 **)(*(int *)(param_1 + 0xa4) + iVar5) = 0;
  if (param_2 == (char *)0x0) {
LAB_000978d1:
    *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;
    iVar5 = *(int *)(param_1 + 0xbc);
  }
  else {
    iVar6 = *(int *)(param_1 + 0xd8);
    if (iVar6 == 3) {
      pcVar4 = "%02d %s";
    }
    else {
      if (iVar6 != 4) {
        if (iVar6 == 2) {
          _sprintf(*(char **)(iVar5 + *(int *)(param_1 + 0xa4)),"%1d %s",param_3 + 1,param_2);
        }
        else {
          _strncpy(*(char **)(iVar5 + *(int *)(param_1 + 0xa4)),param_2,0x100);
        }
        goto LAB_000978d1;
      }
      pcVar4 = "%03d %s";
    }
    _sprintf(*(char **)(iVar5 + *(int *)(param_1 + 0xa4)),pcVar4,param_3 + 1,param_2);
    *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;
    iVar5 = *(int *)(param_1 + 0xbc);
  }
  if (iVar5 < 0) {
    *(undefined4 *)(param_1 + 0xbc) = 0;
  }
  return 1;
}

