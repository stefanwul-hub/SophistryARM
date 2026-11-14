/* 000b2f68 FUN_000b2f68 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_000b2f68(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  
  *(undefined4 *)(param_1 + 0x22c) = 0;
  if (*(int *)(param_1 + 0x21c) != 0) {
    _free(*(void **)(param_1 + 0x21c));
    *(undefined4 *)(param_1 + 0x21c) = 0;
  }
  if (*(int *)(param_1 + 0x220) != 0) {
    *(undefined4 *)(param_1 + 0x22c) = 0;
    _free(*(void **)(param_1 + 0x220));
    *(undefined4 *)(param_1 + 0x220) = 0;
  }
  *(undefined4 *)(param_1 + 0x22c) = 0;
  *(undefined1 *)(param_1 + 0x214) = 0;
  *(undefined1 *)(param_1 + 0x230) = 0;
  *(undefined1 *)(param_1 + 0x231) = 0;
  *(undefined1 *)(param_1 + 0x232) = 0;
  *(undefined1 *)(param_1 + 600) = 0;
  *(undefined1 *)(param_1 + 0x260) = 0;
  *(undefined1 *)(param_1 + 0x233) = 0;
  *(undefined1 *)(param_1 + 0x234) = 0;
  *(char **)(param_1 + 0x20c) = param_2;
  uVar5 = 0xffffffff;
  pcVar6 = param_2;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iVar2 = _strcasecmp(param_2 + (~uVar5 - 4),"WAV");
  if (iVar2 == 0) {
    iVar3 = FUN_000b1a7a(param_1,*(undefined4 *)(param_1 + 0x20c));
    iVar2 = *(int *)(param_1 + 0x264);
    if (iVar2 != 0) {
      for (iVar4 = iVar2 + *(int *)(iVar2 + -4) * 8; iVar2 != iVar4; iVar4 = iVar4 + -8) {
      }
      operator_delete__((void *)(iVar2 + -4));
    }
    *(undefined4 *)(param_1 + 0x264) = 0;
    *(undefined1 *)(param_1 + 600) = 0;
    return 0 < iVar3;
  }
  uVar5 = 0xffffffff;
  pcVar6 = *(char **)(param_1 + 0x20c);
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iVar2 = _strcasecmp(*(char **)(param_1 + 0x20c) + (~uVar5 - 4),"D4T");
  if (iVar2 == 0) {
    iVar2 = FUN_000b2a2a(param_1,*(undefined4 *)(param_1 + 0x20c));
    *(undefined1 *)(param_1 + 0x233) = 1;
    *(undefined1 *)(param_1 + 600) = 0;
    return 0 < iVar2;
  }
  uVar5 = 0xffffffff;
  pcVar6 = *(char **)(param_1 + 0x20c);
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  iVar2 = _strcasecmp(*(char **)(param_1 + 0x20c) + (~uVar5 - 4),"D4U");
  if (iVar2 == 0) {
    iVar2 = FUN_000b2a2a(param_1,*(undefined4 *)(param_1 + 0x20c));
    *(undefined1 *)(param_1 + 0x234) = 1;
    *(undefined1 *)(param_1 + 600) = 0;
    return 0 < iVar2;
  }
  iVar2 = FUN_000b1f94(param_1,*(undefined4 *)(param_1 + 0x20c));
  *(undefined1 *)(param_1 + 600) = 0;
  return 0 < iVar2;
}

