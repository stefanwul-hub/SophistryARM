/* 00010bb4 FUN_00010bb4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00010bb4(int param_1)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *local_20;
  
  if (*(int *)(param_1 + 4) == 7) {
    local_20 = &DAT_000e2000;
    if (*(char **)(param_1 + 0x60) != &DAT_000e2000) {
      uVar3 = 0xffffffff;
      pcVar2 = *(char **)(param_1 + 0x60);
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      uVar3 = ~uVar3;
      pcVar2 = (char *)_malloc(uVar3 + 1);
      if (pcVar2 != (char *)0x0) {
        _strncpy(pcVar2,*(char **)(param_1 + 0x60),uVar3 - 1);
        pcVar2[uVar3 - 1] = '\0';
        local_20 = pcVar2;
      }
      *(char **)(param_1 + 0x60) = local_20;
      return;
    }
  }
  return;
}

