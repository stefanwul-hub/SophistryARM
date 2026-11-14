/* 00029a14 FUN_00029a14 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00029a14(undefined4 *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  
  FUN_00013e4c(param_1);
  *param_1 = &PTR_SysGlo_c_vslot_0_000e7508;
  if (param_2 != (char *)0x0) {
    pcVar1 = (char *)(param_1 + 0x75);
    _strcpy(pcVar1,param_2);
    uVar3 = 0xffffffff;
    pcVar4 = pcVar1;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar2 != '\0');
    pcVar1 = pcVar1 + (~uVar3 - 1);
    pcVar1[0] = 'S';
    pcVar1[1] = 'y';
    pcVar1[2] = 's';
    pcVar1[3] = 'G';
    pcVar1[4] = 'l';
    pcVar1[5] = 'o';
    pcVar1[6] = '\0';
    *(undefined1 *)(param_1 + 0xc5) = 0;
    *(undefined1 *)((int)param_1 + 0x315) = 0;
  }
  return;
}

