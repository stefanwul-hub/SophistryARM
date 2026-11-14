/* 000ae542 FUN_000ae542 */

uint FUN_000ae542(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if (uVar1 == 0) {
    return param_1[2];
  }
  if (uVar1 != 0x10000) {
    return uVar1 & 0xffff;
  }
  uVar1 = param_1[1] - (param_1[1] >> 1 & 0x55555555);
  uVar1 = (uVar1 >> 2 & 0x33333333) + (uVar1 & 0x33333333);
  return (uVar1 + (uVar1 >> 4) & 0xf0f0f0f) * 0x1010101 >> 0x18;
}

