/* 000c39c8 CSplashScreenView_vslot_41 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool CSplashScreenView_vslot_41(undefined4 param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 in_ZF;
  
  iVar1 = 6;
  pcVar3 = "CView";
  do {
    pcVar2 = param_2;
    pcVar4 = pcVar3;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar4 = pcVar3 + 1;
    pcVar2 = param_2 + 1;
    in_ZF = *param_2 == *pcVar3;
    param_2 = pcVar2;
    pcVar3 = pcVar4;
  } while ((bool)in_ZF);
  iVar1 = 0;
  if (!(bool)in_ZF) {
    iVar1 = (uint)(byte)pcVar2[-1] - (uint)(byte)pcVar4[-1];
  }
  return iVar1 == 0;
}

