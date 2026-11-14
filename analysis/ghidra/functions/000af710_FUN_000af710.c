/* 000af710 FUN_000af710 */

undefined4 FUN_000af710(int param_1,FILE *param_2)

{
  size_t sVar1;
  undefined4 uVar2;
  undefined4 local_14;
  undefined4 local_10;
  
  _fseek(param_2,8,1);
  sVar1 = _fread(&local_10,1,4,param_2);
  if (sVar1 == 4) {
    sVar1 = _fread(&local_14,1,4,param_2);
    if (sVar1 == 4) {
      *(undefined4 *)(param_1 + 0x24c) = local_10;
      *(undefined4 *)(param_1 + 0x250) = local_14;
      _fseek(param_2,8,1);
      uVar2 = 0;
    }
    else {
      _fclose(param_2);
      uVar2 = 0xfffffeb4;
    }
  }
  else {
    _fclose(param_2);
    uVar2 = 0xfffffeb6;
  }
  return uVar2;
}

