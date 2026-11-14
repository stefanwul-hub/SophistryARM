/* 000af7d0 FUN_000af7d0 */

int FUN_000af7d0(undefined4 param_1,FILE *param_2)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;
  int local_14;
  uint local_10;
  
  _fseek(param_2,0x1c,1);
  sVar1 = _fread(&local_10,1,4,param_2);
  if (sVar1 == 4) {
    sVar1 = _fread(&local_14,1,4,param_2);
    if (sVar1 == 4) {
      if (local_10 != 0) {
        iVar2 = FUN_000af710(param_1,param_2);
        if (iVar2 != 0) {
          return iVar2;
        }
        if (1 < local_10) {
          uVar3 = 1;
          do {
            _fseek(param_2,0x18,1);
            uVar3 = uVar3 + 1;
          } while (uVar3 < local_10);
        }
      }
      if (local_14 != 0) {
        _fseek(param_2,local_14,1);
        return 0;
      }
    }
    else {
      _fclose(param_2);
      local_14 = -0x138;
    }
  }
  else {
    _fclose(param_2);
    local_14 = -0x136;
  }
  return local_14;
}

