/* 000ac992 FUN_000ac992 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_000ac992(int param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  double dVar2;
  
  if (*(int *)(param_1 + 0x30) != 0) {
    return 0;
  }
  uVar1 = _NewEventLoopTimerUPP(FUN_000ac974);
  *(undefined4 *)(param_1 + 0x30) = uVar1;
  uVar1 = _GetMainEventLoop();
  dVar2 = (double)param_2;
  if ((dVar2 < 0.005) && (!NAN(dVar2))) {
    dVar2 = 0.004999999888241291;
  }
  uVar1 = _InstallEventLoopTimer
                    (uVar1,dVar2,(double)param_3,*(undefined4 *)(param_1 + 0x30),param_1,
                     param_1 + 0x2c);
  return uVar1;
}

