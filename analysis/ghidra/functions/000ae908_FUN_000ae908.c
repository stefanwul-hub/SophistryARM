/* 000ae908 FUN_000ae908 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined1 FUN_000ae908(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x14) != '\0') {
    return 1;
  }
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 8) = param_3;
  iVar1 = _GetMainEventLoop();
  if (iVar1 != 0) {
    iVar2 = _NewEventLoopTimerUPP(FUN_000ae9ec);
    *(int *)(param_1 + 0x1c) = iVar2;
    if (iVar2 != 0) {
      iVar1 = _InstallEventLoopTimer
                        (iVar1,0,0x3ff00000,(double)*(int *)(param_1 + 8) * 0.001,iVar2,param_1,
                         param_1 + 0x18);
      *(bool *)(param_1 + 0x14) = iVar1 == 0;
    }
  }
  return *(undefined1 *)(param_1 + 0x14);
}

