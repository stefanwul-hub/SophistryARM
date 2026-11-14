/* 0009cc16 FUN_0009cc16 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_0009cc16(void)

{
  undefined1 auVar1 [12];
  undefined4 uVar2;
  int iVar3;
  undefined4 local_10;
  
  uVar2 = _GetDblTime();
  auVar1._4_4_ = uVar2;
  auVar1._0_4_ = uVar2;
  auVar1._8_4_ = 0x43300000;
  iVar3 = _ReceiveNextEvent(2,&DAT_000e1e80,((auVar1._4_8_ - 4503599627370496.0) + 0.0) / 60.0,1,
                            &local_10);
  if (iVar3 != 0) {
    return false;
  }
  iVar3 = _GetEventKind(local_10);
  _ReleaseEvent(local_10);
  return iVar3 == 1;
}

