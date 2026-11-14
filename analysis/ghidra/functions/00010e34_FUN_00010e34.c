/* 00010e34 FUN_00010e34 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00010e34(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  char *pcVar4;
  uint uVar5;
  
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    if (iVar2 == 2) {
      FUN_00010d02();
      return;
    }
    if (iVar2 == 7) {
      uVar5 = 0xffffffff;
      pcVar4 = param_2;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      uVar5 = ~uVar5;
      pcVar4 = (char *)_malloc(uVar5 + 1);
      if (pcVar4 == (char *)0x0) {
        pcVar4 = &DAT_000e2000;
      }
      else {
        _strncpy(pcVar4,param_2,uVar5 - 1);
        pcVar4[uVar5 - 1] = '\0';
      }
      puVar3 = *(undefined **)(param_1 + 0x60);
      *(char **)(param_1 + 0x60) = pcVar4;
      if (puVar3 != &DAT_000e2000) {
        _free(puVar3);
        return;
      }
    }
  }
  return;
}

