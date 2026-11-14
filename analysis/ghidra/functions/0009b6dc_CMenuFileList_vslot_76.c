/* 0009b6dc CMenuFileList_vslot_76 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 CMenuFileList_vslot_76(int param_1,int *param_2,int param_3)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = *(int *)(param_1 + 0xb4);
  if (((0x3ff < iVar3) || (param_2 == (int *)0x0)) || (param_3 == 0)) {
    return 0;
  }
  if (iVar3 < *(int *)(param_1 + 0xcc)) {
    iVar7 = *(int *)(param_1 + 0xa4);
    pvVar2 = _malloc(0x100);
    *(void **)(iVar7 + iVar3 * 4) = pvVar2;
    iVar3 = *(int *)(param_1 + 0xd8);
    if (iVar3 != 3) goto LAB_0009b747;
LAB_0009b87c:
    iVar7 = *(int *)(param_1 + 0xb4);
    iVar3 = iVar7 + 1;
    pcVar4 = "-M%02d %s";
  }
  else {
    cVar1 = FUN_000976d0(param_1,0x20);
    if (cVar1 == '\0') {
      return 0;
    }
    iVar3 = *(int *)(param_1 + 0xb4);
    iVar7 = *(int *)(param_1 + 0xa4);
    pvVar2 = _malloc(0x100);
    *(void **)(iVar7 + iVar3 * 4) = pvVar2;
    iVar3 = *(int *)(param_1 + 0xd8);
    if (iVar3 == 3) goto LAB_0009b87c;
LAB_0009b747:
    if (iVar3 == 4) {
      iVar7 = *(int *)(param_1 + 0xb4);
      iVar3 = iVar7 + 1;
      pcVar4 = "-M%03d %s";
    }
    else {
      if (iVar3 != 2) {
        _sprintf(*(char **)(*(int *)(param_1 + 0xa4) + *(int *)(param_1 + 0xb4) * 4),"-M%s",param_3)
        ;
        goto LAB_0009b781;
      }
      iVar7 = *(int *)(param_1 + 0xb4);
      iVar3 = iVar7 + 1;
      pcVar4 = "-M%1d %s";
    }
  }
  _sprintf(*(char **)(*(int *)(param_1 + 0xa4) + iVar7 * 4),pcVar4,iVar3,param_3);
LAB_0009b781:
  if (*(int *)(param_1 + 0xd0) <= *(int *)(param_1 + 0xb8)) {
    iVar3 = *(int *)(param_1 + 0xd0) + 10;
    if (*(void **)(param_1 + 0xa8) == (void *)0x0) {
      pvVar2 = _malloc(iVar3 * 4);
      *(void **)(param_1 + 0xa8) = pvVar2;
    }
    else {
      pvVar2 = _realloc(*(void **)(param_1 + 0xa8),iVar3 * 4);
      *(void **)(param_1 + 0xa8) = pvVar2;
    }
    iVar7 = *(int *)(param_1 + 0xd0);
    if (iVar7 < iVar3) {
      iVar6 = iVar7 * 4;
      iVar5 = 0;
      do {
        *(undefined4 *)(*(int *)(param_1 + 0xa8) + iVar6) = 0;
        iVar5 = iVar5 + 1;
        iVar6 = iVar6 + 4;
      } while (iVar3 - iVar7 != iVar5);
    }
    *(int *)(param_1 + 0xd0) = iVar3;
  }
  iVar3 = *(int *)(param_1 + 0xb8);
  *(int **)(*(int *)(param_1 + 0xa8) + iVar3 * 4) = param_2;
  *(int *)(param_1 + 0xb8) = iVar3 + 1;
  (**(code **)(*param_2 + 0xc))(param_2);
  *(int *)(param_1 + 0xb4) = *(int *)(param_1 + 0xb4) + 1;
  if (*(int *)(param_1 + 0xbc) < 0) {
    *(undefined4 *)(param_1 + 0xbc) = 0;
  }
  return 1;
}

