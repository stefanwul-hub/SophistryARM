/* 000c42e6 FUN_000c42e6 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_000c42e6(undefined4 param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  bVar6 = (segment_command *)&stack0x00000000 == &segment_command_0000001c;
  iVar1 = 0xd;
  pcVar2 = param_2;
  pcVar4 = "CMovieBitmap";
  do {
    pcVar3 = pcVar2;
    pcVar5 = pcVar4;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar5 = pcVar4 + 1;
    pcVar3 = pcVar2 + 1;
    bVar6 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar3;
    pcVar4 = pcVar5;
  } while (bVar6);
  iVar1 = 0;
  if (!bVar6) {
    iVar1 = (uint)(byte)pcVar3[-1] - (uint)(byte)pcVar5[-1];
  }
  bVar6 = iVar1 == 0;
  if (bVar6) {
    return true;
  }
  iVar1 = 9;
  pcVar2 = param_2;
  pcVar4 = "CControl";
  do {
    pcVar3 = pcVar2;
    pcVar5 = pcVar4;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar5 = pcVar4 + 1;
    pcVar3 = pcVar2 + 1;
    bVar6 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar3;
    pcVar4 = pcVar5;
  } while (bVar6);
  iVar1 = 0;
  if (!bVar6) {
    iVar1 = (uint)(byte)pcVar3[-1] - (uint)(byte)pcVar5[-1];
  }
  bVar6 = iVar1 == 0;
  if (bVar6) {
    bVar6 = true;
  }
  else {
    iVar1 = 6;
    pcVar2 = "CView";
    do {
      pcVar4 = param_2;
      pcVar3 = pcVar2;
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      pcVar3 = pcVar2 + 1;
      pcVar4 = param_2 + 1;
      bVar6 = *param_2 == *pcVar2;
      param_2 = pcVar4;
      pcVar2 = pcVar3;
    } while (bVar6);
    iVar1 = 0;
    if (!bVar6) {
      iVar1 = (uint)(byte)pcVar4[-1] - (uint)(byte)pcVar3[-1];
    }
    bVar6 = iVar1 == 0;
  }
  return bVar6;
}

