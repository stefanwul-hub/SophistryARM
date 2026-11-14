/* 0009cba2 FUN_0009cba2 */

uint FUN_0009cba2(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = _GetCurrentButtonState();
  uVar2 = uVar1 & 1;
  if ((uVar1 & 2) != 0) {
    uVar2 = uVar1 & 1 | 4;
  }
  if ((uVar1 & 4) != 0) {
    uVar2 = uVar2 | 2;
  }
  uVar1 = _GetCurrentKeyModifiers();
  if ((uVar1 & 0x100) != 0) {
    uVar2 = uVar2 | 0x10;
  }
  if ((uVar1 & 0x200) != 0) {
    uVar2 = uVar2 | 8;
  }
  if ((uVar1 & 0x800) != 0) {
    uVar2 = uVar2 | 0x20;
  }
  if ((uVar1 & 0x1000) != 0) {
    uVar2 = uVar2 | 0x40;
  }
  if (((uVar2 & 0x40) != 0) && ((uVar2 & 1) != 0)) {
    uVar2 = uVar2 & 0xffffffbe | 4;
  }
  return uVar2;
}

