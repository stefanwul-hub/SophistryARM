/* 000afebc FUN_000afebc */

undefined4 FUN_000afebc(undefined4 param_1,FILE *param_2,ushort *param_3,ushort *param_4)

{
  size_t sVar1;
  undefined4 uVar2;
  undefined1 local_22 [8];
  ushort local_1a;
  ushort local_18;
  ushort local_16;
  
  sVar1 = _fread(local_22,1,0x14,param_2);
  if (sVar1 == 0x14) {
    if ((ushort)((local_1a << 8 | local_1a >> 8) - 1) < 2) {
      *param_3 = local_18 << 8 | local_18 >> 8;
      *param_4 = local_16 << 8 | local_16 >> 8;
    }
    uVar2 = 0;
  }
  else {
    _fclose(param_2);
    uVar2 = 0xfffffd43;
  }
  return uVar2;
}

