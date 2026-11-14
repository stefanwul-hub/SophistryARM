/* 000b02da FUN_000b02da */

undefined4 FUN_000b02da(int param_1,FILE *param_2)

{
  ushort uVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  int local_20;
  uint local_14;
  uint local_10;
  
  sVar3 = _fread(&local_10,1,4,param_2);
  if (sVar3 != 4) {
    _fclose(param_2);
    return 0xffffff2e;
  }
  local_10 = local_10 << 0x18 | (local_10 & 0xff00) << 8 | (int)(local_10 & 0xff0000) >> 8 |
             local_10 >> 0x18;
  sVar3 = _fread(&local_14,1,4,param_2);
  if (sVar3 != 4) {
    _fclose(param_2);
    return 0xffffff24;
  }
  local_14 = local_14 << 0x18 | (local_14 & 0xff00) << 8 | (int)(local_14 & 0xff0000) >> 8 |
             local_14 >> 0x18;
  uVar1 = *(ushort *)(param_1 + 0x21a);
  if (uVar1 == 0x18) {
    local_20 = 3;
  }
  else if (uVar1 < 0x19) {
    if (uVar1 == 8) {
      local_20 = 1;
    }
    else {
      if (uVar1 != 0x10) goto LAB_000b03ab;
      local_20 = 2;
    }
  }
  else if (uVar1 == 0x20) {
    local_20 = 4;
  }
  else {
    if (uVar1 != 0x40) {
LAB_000b03ab:
      _fclose(param_2);
      return 0xffffff6a;
    }
    local_20 = 8;
  }
  *(uint *)(param_1 + 0x228) =
       (uint)*(ushort *)(param_1 + 0x216) * local_20 * *(int *)(param_1 + 0x22c);
  iVar4 = FUN_00013124(param_1,*(undefined4 *)(param_1 + 0x22c));
  *(int *)(param_1 + 0x21c) = iVar4;
  if (iVar4 == 0) {
    _fclose(param_2);
    uVar5 = 0xffffff5e;
  }
  else {
    if ((0 < (int)local_10) && (iVar4 = _fseek(param_2,local_10,1), iVar4 != 0)) {
      _fclose(param_2);
      return 0xffffff5b;
    }
    if (*(short *)(param_1 + 0x216) == 1) {
      cVar2 = FUN_000aedb0(param_1,param_2,*(undefined4 *)(param_1 + 0x22c),local_20);
      if (cVar2 != '\0') {
        return 0;
      }
      _fclose(param_2);
      uVar5 = 0xffffff56;
    }
    else {
      if (*(short *)(param_1 + 0x216) != 2) {
        return 0;
      }
      iVar4 = FUN_00013124(param_1,*(undefined4 *)(param_1 + 0x22c));
      *(int *)(param_1 + 0x220) = iVar4;
      if (iVar4 == 0) {
        _fclose(param_2);
        uVar5 = 0xffffff5c;
      }
      else {
        cVar2 = FUN_000aef4c(param_1,param_2,*(undefined4 *)(param_1 + 0x22c),local_20);
        if (cVar2 != '\0') {
          return 0;
        }
        _fclose(param_2);
        uVar5 = 0xffffff55;
      }
    }
  }
  return uVar5;
}

