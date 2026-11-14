/* 000b0562 FUN_000b0562 */

undefined4 FUN_000b0562(int param_1,FILE *param_2,ushort param_3,ushort param_4)

{
  bool bVar1;
  bool bVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  ushort uVar6;
  uint local_18;
  ushort local_12;
  ushort local_10;
  byte local_d;
  
  local_10 = 0;
  sVar3 = _fread(&local_10,1,2,param_2);
  if (sVar3 == 2) {
    local_10 = local_10 << 8 | local_10 >> 8;
    if ((local_10 != 0) && (1 < local_10)) {
      uVar6 = 0;
      bVar1 = false;
      bVar2 = false;
      do {
        sVar3 = _fread(&local_12,1,2,param_2);
        if (sVar3 != 2) {
          _fclose(param_2);
          return 0xfffffd39;
        }
        local_12 = local_12 << 8 | local_12 >> 8;
        sVar3 = _fread(&local_18,1,4,param_2);
        if (sVar3 != 4) {
          _fclose(param_2);
          return 0xfffffd38;
        }
        local_18 = local_18 << 0x18 | (local_18 & 0xff00) << 8 | (int)(local_18 & 0xff0000) >> 8 |
                   local_18 >> 0x18;
        sVar3 = _fread(&local_d,1,1,param_2);
        if (sVar3 != 1) {
          _fclose(param_2);
          return 0xfffffd37;
        }
        if ((local_d & 1) == 0) {
          local_d = local_d + 1;
        }
        iVar4 = _fseek(param_2,(uint)local_d,1);
        if (iVar4 != 0) {
          _fclose(param_2);
          return 0xfffffd36;
        }
        if (-1 < (int)local_18) {
          if (local_12 == param_3) {
            *(uint *)(param_1 + 0x24c) = local_18;
            bVar1 = true;
          }
          if (local_12 == param_4) {
            *(uint *)(param_1 + 0x250) = local_18;
            bVar2 = true;
          }
        }
        uVar6 = uVar6 + 1;
      } while ((uVar6 < local_10) && (1 < local_10));
      if ((bVar1) && (bVar2)) {
        *(undefined1 *)(param_1 + 0x260) = 1;
        return 0;
      }
    }
    uVar5 = 0;
  }
  else {
    _fclose(param_2);
    uVar5 = 0xfffffd3a;
  }
  return uVar5;
}

