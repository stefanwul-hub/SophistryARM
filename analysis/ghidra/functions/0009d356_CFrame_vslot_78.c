/* 0009d356 CFrame_vslot_78 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CFrame_vslot_78(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  switch(param_2) {
  default:
    _SetThemeCursor(0);
    break;
  case 1:
    _SetThemeCursor(7);
    break;
  case 2:
    uVar1 = 5;
    if (0x102f < _DAT_00102840) {
      uVar1 = 0x11;
    }
    _SetThemeCursor(uVar1);
    break;
  case 3:
    uVar1 = 5;
    if (0x102f < _DAT_00102840) {
      uVar1 = 0x15;
    }
    _SetThemeCursor(uVar1);
    break;
  case 4:
  case 5:
  case 6:
    _SetThemeCursor(5);
    return;
  case 7:
    _SetThemeCursor(1);
    break;
  case 8:
    uVar1 = 0;
    if (0x101f < _DAT_00102840) {
      uVar1 = 0x12;
    }
    _SetThemeCursor(uVar1);
    break;
  case 9:
    _SetThemeCursor(9);
  }
  return;
}

