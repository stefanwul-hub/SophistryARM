/* 000ae8a0 FUN_000ae8a0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_000ae8a0(void)

{
  short sVar1;
  undefined4 uVar2;
  byte local_20 [3];
  byte local_1d;
  
  sVar1 = _Gestalt(0x78383666,local_20);
  if ((sVar1 == 0) && ((local_1d & 4) != 0)) {
    uVar2 = 100;
  }
  else {
    uVar2 = 0;
  }
  sVar1 = _Gestalt(0x78383661,local_20);
  if ((sVar1 == 0) && ((local_20[0] & 1) != 0)) {
    uVar2 = 0x65;
  }
  DAT_000e2240 = uVar2;
  return uVar2;
}

