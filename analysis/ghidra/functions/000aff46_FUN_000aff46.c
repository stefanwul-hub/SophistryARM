/* 000aff46 FUN_000aff46 */

undefined4 FUN_000aff46(int param_1,FILE *param_2)

{
  uint uVar1;
  size_t sVar2;
  undefined4 uVar3;
  long lVar4;
  int iVar5;
  ushort uVar6;
  uint local_18;
  uint local_14;
  undefined2 local_e;
  
  sVar2 = _fread((void *)(param_1 + 0x216),1,2,param_2);
  if (sVar2 != 2) {
    _fclose(param_2);
    return 0xffffff9c;
  }
  uVar6 = *(ushort *)(param_1 + 0x216) << 8 | *(ushort *)(param_1 + 0x216) >> 8;
  *(ushort *)(param_1 + 0x216) = uVar6;
  if (2 < uVar6) {
    _fclose(param_2);
    return 0xffffff97;
  }
  sVar2 = _fread((void *)(param_1 + 0x22c),1,4,param_2);
  if (sVar2 != 4) {
    _fclose(param_2);
    return 0xffffff95;
  }
  uVar1 = *(uint *)(param_1 + 0x22c);
  *(uint *)(param_1 + 0x22c) =
       uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | (int)(uVar1 & 0xff0000) >> 8 | uVar1 >> 0x18;
  sVar2 = _fread((void *)(param_1 + 0x21a),1,2,param_2);
  if (sVar2 != 2) {
    _fclose(param_2);
    return 0xffffff92;
  }
  *(ushort *)(param_1 + 0x21a) =
       *(ushort *)(param_1 + 0x21a) << 8 | *(ushort *)(param_1 + 0x21a) >> 8;
  sVar2 = _fread(&local_e,1,2,param_2);
  if (sVar2 != 2) {
    _fclose(param_2);
    return 0xfffffeca;
  }
  uVar6 = 1;
  if (local_e._1_1_ != 0) {
    uVar6 = (ushort)local_e._1_1_;
  }
  local_e = 0x1e;
  if (uVar6 < 0x1f) {
    local_e = uVar6;
  }
  sVar2 = _fread(&local_14,1,4,param_2);
  if (sVar2 != 4) {
    _fclose(param_2);
    return 0xfffffec0;
  }
  local_14 = local_14 << 0x18 | (local_14 & 0xff00) << 8 | (int)(local_14 & 0xff0000) >> 8 |
             local_14 >> 0x18;
  *(uint *)(param_1 + 0x210) = local_14 >> (0x1eU - (char)local_e & 0x1f);
  if (*(char *)(param_1 + 0x232) == '\0') {
LAB_000b00f7:
    uVar3 = 0;
  }
  else {
    lVar4 = _ftell(param_2);
    iVar5 = _fseek(param_2,lVar4 + 4,0);
    if (iVar5 != 0) {
      _fclose(param_2);
      return 0xfffffeb6;
    }
    sVar2 = _fread(&local_18,1,4,param_2);
    if (sVar2 != 4) {
      _fclose(param_2);
      return 0xfffffeb1;
    }
    local_18 = local_18 << 0x18 | (local_18 & 0xff00) << 8 | (int)(local_18 & 0xff0000) >> 8 |
               local_18 >> 0x18;
    if (local_18 == 0x666c3634) {
      *(undefined2 *)(param_1 + 0x21a) = 0x40;
      *(undefined1 *)(param_1 + 0x231) = 1;
      return 0;
    }
    if (local_18 < 0x666c3635) {
      if (local_18 == 0x4e4f4e45) goto LAB_000b00f7;
      if (local_18 == 0x666c3332) {
        *(undefined2 *)(param_1 + 0x21a) = 0x20;
        *(undefined1 *)(param_1 + 0x231) = 1;
        return 0;
      }
      if (local_18 == 0x32336e69) {
        *(undefined2 *)(param_1 + 0x21a) = 0x20;
LAB_000b0238:
        *(undefined1 *)(param_1 + 0x230) = 0;
        return 0;
      }
    }
    else {
      if (local_18 == 0x696e3332) {
        *(undefined2 *)(param_1 + 0x21a) = 0x20;
        return 0;
      }
      if (local_18 < 0x696e3333) {
        if (local_18 == 0x696e3234) {
          *(undefined2 *)(param_1 + 0x21a) = 0x18;
          return 0;
        }
      }
      else {
        if (local_18 == 0x736f7774) goto LAB_000b0238;
        if (local_18 == 0x74776f73) goto LAB_000b00f7;
      }
    }
    _fclose(param_2);
    uVar3 = 0xfffffeac;
  }
  return uVar3;
}

