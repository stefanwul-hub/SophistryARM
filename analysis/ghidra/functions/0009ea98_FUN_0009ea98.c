/* 0009ea98 FUN_0009ea98 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0009ea98(void)

{
  int in_EAX;
  
  _RemoveReceiveHandler(DAT_000fd528,*(undefined4 *)(in_EAX + 100));
  _RemoveTrackingHandler(DAT_000fd524,*(undefined4 *)(in_EAX + 100));
  _DisposeDragReceiveHandlerUPP(DAT_000fd528);
  _DisposeDragTrackingHandlerUPP(DAT_000fd524);
  return;
}

