/* 000b07a4 FUN_000b07a4 */

undefined4 FUN_000b07a4(int param_1,FILE *param_2)

{
  size_t sVar1;
  uint uVar2;
  short sVar3;
  undefined4 uVar4;
  uint local_18;
  uint local_14;
  ushort local_10;
  ushort local_e;
  
  local_e = *(ushort *)(param_1 + 0x216) << 8 | *(ushort *)(param_1 + 0x216) >> 8;
  sVar1 = _fwrite(&local_e,1,2,param_2);
  if (sVar1 == 2) {
    uVar2 = *(uint *)(param_1 + 0x22c);
    local_14 = uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | (int)(uVar2 & 0xff0000) >> 8 | uVar2 >> 0x18;
    sVar1 = _fwrite(&local_14,1,4,param_2);
    if (sVar1 == 4) {
      local_e = 0x1800;
      sVar1 = _fwrite(&local_e,1,2,param_2);
      if (sVar1 == 2) {
        uVar2 = *(uint *)(param_1 + 0x210);
        if ((int)uVar2 < 0) {
          sVar3 = 0;
        }
        else {
          sVar3 = 0;
          do {
            uVar2 = uVar2 * 2;
            sVar3 = sVar3 + 1;
          } while (-1 < (int)uVar2);
        }
        local_10 = (0x1eU - sVar3) * 0x100 | (ushort)(0x1eU - sVar3 | 0x4000) >> 8;
        local_18 = uVar2 << 0x18 | (uVar2 & 0xff00) << 8 | (int)(uVar2 & 0xff0000) >> 8 |
                   uVar2 >> 0x18;
        sVar1 = _fwrite(&local_10,1,2,param_2);
        if (sVar1 == 2) {
          sVar1 = _fwrite(&local_18,1,4,param_2);
          if (sVar1 == 4) {
            local_18 = 0;
            sVar1 = _fwrite(&local_18,1,4,param_2);
            uVar4 = 0xfffffe98;
            if (sVar1 == 4) {
              uVar4 = 0;
            }
          }
          else {
            uVar4 = 0xfffffea2;
          }
        }
        else {
          uVar4 = 0xfffffeac;
        }
      }
      else {
        uVar4 = 0xfffffeb6;
      }
    }
    else {
      uVar4 = 0xfffffec0;
    }
  }
  else {
    uVar4 = 0xfffffeca;
  }
  return uVar4;
}

