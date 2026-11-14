/* 000af8d6 FUN_000af8d6 */

undefined4 FUN_000af8d6(int param_1,FILE *param_2)

{
  size_t sVar1;
  undefined4 uVar2;
  undefined4 local_18;
  undefined1 local_14 [6];
  short local_e;
  
  sVar1 = _fread(&local_e,1,2,param_2);
  if (sVar1 == 2) {
    if ((local_e == 1) || (local_e == 3)) {
      *(bool *)(param_1 + 0x231) = local_e == 3;
      sVar1 = _fread((void *)(param_1 + 0x216),1,2,param_2);
      if (sVar1 == 2) {
        if (*(ushort *)(param_1 + 0x216) < 3) {
          sVar1 = _fread(&local_18,1,4,param_2);
          if (sVar1 == 4) {
            *(undefined4 *)(param_1 + 0x210) = local_18;
            sVar1 = _fread(local_14,1,4,param_2);
            if (sVar1 == 4) {
              sVar1 = _fread((void *)(param_1 + 0x218),1,2,param_2);
              if (sVar1 == 2) {
                sVar1 = _fread((void *)(param_1 + 0x21a),1,2,param_2);
                if (sVar1 == 2) {
                  uVar2 = 0;
                }
                else {
                  _fclose(param_2);
                  uVar2 = 0xffffff74;
                }
              }
              else {
                _fclose(param_2);
                uVar2 = 0xffffff7e;
              }
            }
            else {
              _fclose(param_2);
              uVar2 = 0xffffff88;
            }
          }
          else {
            _fclose(param_2);
            uVar2 = 0xffffff92;
          }
        }
        else {
          _fclose(param_2);
          uVar2 = 0xffffff97;
        }
      }
      else {
        _fclose(param_2);
        uVar2 = 0xffffff9c;
      }
    }
    else {
      _fclose(param_2);
      uVar2 = 0xffffffa6;
    }
  }
  else {
    _fclose(param_2);
    uVar2 = 0xffffffb0;
  }
  return uVar2;
}

