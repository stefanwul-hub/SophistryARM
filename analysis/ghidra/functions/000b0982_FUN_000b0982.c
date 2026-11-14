/* 000b0982 FUN_000b0982 */

undefined4 FUN_000b0982(int param_1,FILE *param_2)

{
  size_t sVar1;
  undefined4 uVar2;
  undefined4 local_14;
  undefined4 local_10;
  
  sVar1 = _fread(&local_10,1,4,param_2);
  if (sVar1 == 4) {
    _fseek(param_2,0x10,1);
    sVar1 = _fread(&local_14,1,4,param_2);
    if (sVar1 == 4) {
      if (*(int *)(param_1 + 0x268) < 4) {
        *(undefined4 *)(*(int *)(param_1 + 0x264) + *(int *)(param_1 + 0x268) * 8) = local_10;
        *(undefined4 *)(*(int *)(param_1 + 0x264) + 4 + *(int *)(param_1 + 0x268) * 8) = local_14;
        *(int *)(param_1 + 0x268) = *(int *)(param_1 + 0x268) + 1;
      }
      uVar2 = 0;
    }
    else {
      _fclose(param_2);
      uVar2 = 0xfffffdec;
    }
  }
  else {
    _fclose(param_2);
    uVar2 = 0xfffffe52;
  }
  return uVar2;
}

