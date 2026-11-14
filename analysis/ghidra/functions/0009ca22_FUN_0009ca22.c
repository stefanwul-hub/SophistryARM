/* 0009ca22 FUN_0009ca22 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0009ca22(int param_1,uint param_2,int param_3,uint param_4)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char acStack_11c [8];
  undefined2 uStack_114;
  undefined1 auStack_112 [258];
  
  if (7 < param_2) {
    param_2 = 0;
  }
  if (param_2 == *(uint *)(param_1 + 0x2c)) {
    iVar3 = param_3;
    if (param_3 == 0) {
      iVar3 = *(int *)(&DAT_000e20e0 + param_2 * 4);
    }
    if ((iVar3 == *(int *)(param_1 + 0x24)) && (param_4 == *(uint *)(param_1 + 0x28))) {
      return;
    }
  }
  *(uint *)(param_1 + 0x28) = param_4;
  *(uint *)(param_1 + 0x2c) = param_2;
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(&DAT_000e20e0 + param_2 * 4);
  }
  else {
    *(int *)(param_1 + 0x24) = param_3;
  }
  pcVar1 = acStack_11c + 1;
  _strcpy(pcVar1,(&PTR_s_Helvetica_000e2100)[*(int *)(param_1 + 0x2c)]);
  if ((param_4 & 1) != 0) {
    uVar4 = 0xffffffff;
    pcVar5 = pcVar1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    builtin_strncpy(acStack_11c + (~uVar4 - 1) + 1," Bol",4);
    (acStack_11c + ~uVar4 + 4)[0] = 'd';
    (acStack_11c + ~uVar4 + 4)[1] = '\0';
  }
  if ((param_4 & 2) != 0) {
    uVar4 = 0xffffffff;
    pcVar5 = pcVar1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    builtin_strncpy(acStack_11c + (~uVar4 - 1) + 1," Ita",4);
    builtin_strncpy(acStack_11c + ~uVar4 + 4,"lic",4);
  }
  if ((param_4 & 4) != 0) {
    uVar4 = 0xffffffff;
    pcVar5 = pcVar1;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    uVar4 = ~uVar4;
    builtin_strncpy(acStack_11c + (uVar4 - 1) + 1," Und",4);
    builtin_strncpy(acStack_11c + uVar4 + 4,"erli",4);
    *(undefined2 *)((int)&uStack_114 + uVar4) = 0x656e;
    auStack_112[uVar4] = 0;
  }
  if (*(int *)(param_1 + 0x60) != 0) {
    _CGContextSelectFont(*(int *)(param_1 + 0x60),pcVar1,(float)*(int *)(param_1 + 0x24),1);
  }
  return;
}

