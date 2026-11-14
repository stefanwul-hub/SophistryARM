/* 000b0b40 FUN_000b0b40 */

int FUN_000b0b40(undefined4 param_1,FILE *param_2)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;
  uint local_10;
  
  sVar1 = _fread(&local_10,1,4,param_2);
  if (sVar1 == 4) {
    iVar2 = FUN_000b0a4a(param_1,param_2);
    if (iVar2 == 0) {
      if (1 < local_10) {
        uVar3 = 1;
        do {
          _fseek(param_2,0xc,1);
          uVar3 = uVar3 + 1;
        } while (uVar3 < local_10);
      }
      iVar2 = 0;
    }
  }
  else {
    _fclose(param_2);
    iVar2 = -0x19a;
  }
  return iVar2;
}

