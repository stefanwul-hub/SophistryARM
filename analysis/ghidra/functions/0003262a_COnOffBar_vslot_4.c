/* 0003262a COnOffBar_vslot_4 */

void COnOffBar_vslot_4(int param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
  CControlPl_vslot_4(param_1,param_2);
  pcVar3 = *(char **)(param_1 + 0x84);
  uVar2 = 0xffffffff;
  pcVar4 = pcVar3;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  iVar5 = ~uVar2 - 1;
  if ((iVar5 == *(int *)(param_1 + 0xb4)) && (~uVar2 != 1 && -1 < iVar5)) {
    iVar5 = 0;
    while( true ) {
      local_10 = pcVar3[iVar5] + -0x30;
      if (local_10 < 0) {
        local_10 = 0;
      }
      else if (1 < local_10) {
        local_10 = 1;
      }
      local_10 = local_10 * (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0xc));
      local_14 = 0;
      local_24 = iVar5 * *(int *)(param_1 + 0xb8) + *(int *)(param_1 + 8);
      local_18 = *(undefined4 *)(param_1 + 0x14);
      local_20 = *(undefined4 *)(param_1 + 0xc);
      local_1c = *(int *)(param_1 + 0xb8) + -1 + local_24;
      if (*(char *)(param_1 + 0x72) == '\0') {
        (**(code **)(**(int **)(param_1 + 0xb0) + 0x10))
                  (*(int **)(param_1 + 0xb0),param_2,&local_24,&local_14);
      }
      else {
        (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))
                  (*(int **)(param_1 + 0xb0),param_2,&local_24,&local_14);
      }
      iVar5 = iVar5 + 1;
      if (*(int *)(param_1 + 0xb4) <= iVar5) break;
      pcVar3 = *(char **)(param_1 + 0x84);
    }
  }
  return;
}

