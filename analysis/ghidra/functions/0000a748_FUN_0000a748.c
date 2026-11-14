/* 0000a748 FUN_0000a748 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

char * FUN_0000a748(int param_1,char *param_2,undefined4 param_3)

{
  char *pcVar1;
  char cVar2;
  FILE *pFVar3;
  FILE *pFVar4;
  size_t sVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  int local_7fc;
  undefined1 local_7dc [1024];
  char local_3dc [320];
  char local_29c [318];
  char local_15e [334];
  
  pcVar1 = local_15e + 2;
  _strcpy(pcVar1,param_2);
  _strcpy(local_29c,pcVar1);
  uVar6 = 0xffffffff;
  pcVar8 = pcVar1;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  iVar7 = ~uVar6 - 2;
  if (-1 < iVar7) {
    pcVar8 = pcVar1 + iVar7;
    iVar9 = (int)*pcVar8;
    if (((iVar9 != *(char *)(param_1 + 0x10)) &&
        (local_7fc = (int)*(char *)(param_1 + 0x11), iVar9 != local_7fc)) &&
       (iVar9 != *(char *)(param_1 + 0x12))) {
      iVar9 = 0;
      do {
        pcVar8 = pcVar8 + -1;
        if (iVar9 == iVar7) goto LAB_0000a83a;
        iVar10 = (int)*pcVar8;
      } while (((*(char *)(param_1 + 0x10) != iVar10) && (local_7fc != iVar10)) &&
              (iVar9 = iVar9 + 1, *(char *)(param_1 + 0x12) != iVar10));
    }
    _strcpy(local_29c,pcVar8 + 1);
  }
  local_7fc = (int)*(char *)(param_1 + 0x11);
LAB_0000a83a:
  pcVar8 = (char *)(param_1 + 0x153);
  _sprintf(pcVar8,"%s%c%s",param_3,local_7fc,local_29c);
  uVar6 = 0xffffffff;
  pcVar11 = pcVar8;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar2 != '\0');
  iVar7 = ~uVar6 - 2;
  if (-1 < iVar7) {
    pcVar11 = pcVar8 + iVar7;
    iVar9 = 0;
    iVar7 = ~uVar6 - 1;
    do {
      while (((cVar2 = *pcVar11, cVar2 != *(char *)(param_1 + 0x10) &&
              (cVar2 != *(char *)(param_1 + 0x11))) && (cVar2 != *(char *)(param_1 + 0x12)))) {
        iVar9 = iVar9 + 1;
        pcVar11 = pcVar11 + -1;
        if (iVar7 == iVar9) goto LAB_0000a8cd;
      }
      *pcVar11 = *(char *)(param_1 + 0x11);
      iVar9 = iVar9 + 1;
      pcVar11 = pcVar11 + -1;
    } while (iVar7 != iVar9);
  }
LAB_0000a8cd:
  uVar6 = 0xffffffff;
  pcVar11 = pcVar1;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar2 != '\0');
  if (-1 < (int)(~uVar6 - 2)) {
    pcVar11 = pcVar1 + (~uVar6 - 2);
    do {
      while (((cVar2 = *pcVar11, cVar2 != *(char *)(param_1 + 0x10) &&
              (cVar2 != *(char *)(param_1 + 0x11))) && (cVar2 != *(char *)(param_1 + 0x12)))) {
        pcVar11 = pcVar11 + -1;
        if (local_15e + 1 == pcVar11) goto LAB_0000a91a;
      }
      *pcVar11 = *(char *)(param_1 + 0x11);
      pcVar11 = pcVar11 + -1;
    } while (local_15e + 1 != pcVar11);
  }
LAB_0000a91a:
  iVar7 = _strcasecmp(pcVar8,pcVar1);
  if (iVar7 != 0) {
    _strcpy(local_3dc,pcVar8);
    pFVar3 = _fopen(local_3dc,"rb");
    if (pFVar3 != (FILE *)0x0) {
      _fclose(pFVar3);
      cVar2 = FUN_0002e50e(param_1 + 4,"Overwrite existing file ?",pcVar8);
      if (cVar2 == '\0') {
        return (char *)0x0;
      }
    }
    pFVar3 = _fopen(pcVar1,"rb");
    pFVar4 = _fopen(local_3dc,"wb");
    if (pFVar3 != (FILE *)0x0) {
      if (pFVar4 != (FILE *)0x0) {
        while (sVar5 = _fread(local_7dc,1,0x400,pFVar3), 0 < (int)sVar5) {
          _fwrite(local_7dc,1,sVar5,pFVar4);
        }
      }
      _fclose(pFVar3);
    }
    if (pFVar4 != (FILE *)0x0) {
      _fclose(pFVar4);
      return pcVar8;
    }
  }
  return pcVar8;
}

