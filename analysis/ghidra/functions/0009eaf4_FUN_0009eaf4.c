/* 0009eaf4 FUN_0009eaf4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0009eaf4(void)

{
  int in_EAX;
  
  DAT_000fd528 = _NewDragReceiveHandlerUPP(FUN_000a4206);
  DAT_000fd524 = _NewDragTrackingHandlerUPP(FUN_000a431c);
  _InstallReceiveHandler(DAT_000fd528,*(undefined4 *)(in_EAX + 100));
  _InstallTrackingHandler(DAT_000fd524,*(undefined4 *)(in_EAX + 100));
  return;
}

