/* 00009cd6 FUN_00009cd6 */

void FUN_00009cd6(undefined4 param_1,char *param_2,int param_3)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int local_290;
  char local_28c [320];
  char local_14c [320];
  
  if (param_3 < 2) {
    return;
  }
  _strcpy(local_14c,param_2);
  local_290 = 0;
  iVar5 = param_3;
  iVar1 = local_290;
LAB_00009d1f:
  local_290 = iVar1;
  iVar1 = local_290 + 1;
  pcVar2 = param_2 + iVar1 * 0x140;
  iVar3 = _strcasecmp(pcVar2,local_14c);
  if (iVar3 < 0) goto LAB_00009dcb;
  goto LAB_00009d57;
LAB_00009dcb:
  if (param_3 <= iVar1) {
LAB_00009d57:
    pcVar4 = param_2 + iVar5 * 0x140;
    do {
      iVar5 = iVar5 + -1;
      pcVar4 = pcVar4 + -0x140;
      iVar3 = _strcasecmp(pcVar4,local_14c);
    } while (0 < iVar3);
    if (iVar5 <= iVar1) {
      _strcpy(local_28c,param_2 + local_290 * 0x140);
      _strcpy(param_2 + local_290 * 0x140,param_2);
      _strcpy(param_2,local_28c);
      FUN_00009cd6(param_1,param_2,local_290);
      FUN_00009cd6(param_1,param_2 + iVar1 * 0x140,param_3 - iVar1);
      return;
    }
    _strcpy(local_28c,pcVar2);
    _strcpy(pcVar2,pcVar4);
    _strcpy(pcVar4,local_28c);
  }
  goto LAB_00009d1f;
}

