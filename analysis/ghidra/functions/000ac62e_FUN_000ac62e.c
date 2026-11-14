/* 000ac62e FUN_000ac62e */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint * FUN_000ac62e(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint local_24;
  
  uVar3 = *param_2;
  uVar3 = uVar3 >> 0x18 | (uVar3 & 0xff0000) >> 8 | (uVar3 & 0xff00) << 8 | uVar3 << 0x18;
  param_2 = param_2 + 1;
  if (uVar3 != 0) {
    local_24 = 0;
    do {
      uVar1 = *param_2;
      uVar2 = param_2[1];
      param_2 = param_2 + 2;
      FUN_000ac49e(param_1,uVar1 >> 0x18 | (uVar1 & 0xff0000) >> 8 | (uVar1 & 0xff00) << 8 |
                           uVar1 << 0x18,
                   uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18);
      local_24 = local_24 + 1;
    } while (local_24 != uVar3);
    return param_2;
  }
  return param_2;
}

