/* 000afa8c FUN_000afa8c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_000afa8c(int param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_2b8 [8];
  FILE *local_2b0;
  undefined4 local_24;
  undefined1 local_20;
  char local_1f;
  char local_1e;
  char local_1d [13];
  
  local_24 = 0;
  uVar1 = (uint)*(ushort *)(param_1 + 0x216) * *(int *)(param_1 + 0x22c) * 4;
  FUN_0000a5d4(local_2b8);
  FUN_00009848(local_2b8,param_2);
  if (local_2b0 == (FILE *)0x0) {
    Disk_c_vslot_0(local_2b8);
    return 0xfffffffb;
  }
  _fwrite(&local_24,1,4,local_2b0);
  _fwrite(&local_24,1,4,local_2b0);
  local_20 = (undefined1)(uVar1 / 1000000);
  uVar1 = uVar1 % 1000000;
  local_1f = (char)(uVar1 / 10000);
  uVar1 = uVar1 % 10000;
  local_1e = (char)(uVar1 / 100);
  local_1d[0] = (char)uVar1 + local_1e * -100;
  _fwrite(&local_20,1,1,local_2b0);
  _fwrite(&local_1f,1,1,local_2b0);
  _fwrite(&local_1e,1,1,local_2b0);
  _fwrite(local_1d,1,1,local_2b0);
  local_20 = (undefined1)*(undefined2 *)(param_1 + 0x216);
  _fwrite(&local_20,1,1,local_2b0);
  iVar2 = (int)((double)*(int *)(param_1 + 0x210) + 0.25);
  local_20 = (undefined1)(iVar2 / 10000);
  iVar2 = iVar2 % 10000;
  local_1f = (char)(iVar2 / 100);
  local_1e = (char)iVar2 + local_1f * -100;
  _fwrite(&local_20,1,1,local_2b0);
  _fwrite(&local_1f,1,1,local_2b0);
  _fwrite(&local_1e,1,1,local_2b0);
  _fwrite(&local_24,1,4,local_2b0);
  _fwrite(&local_24,1,4,local_2b0);
  _fwrite(&local_24,1,4,local_2b0);
  _fwrite(&local_24,1,4,local_2b0);
  _fwrite(&local_24,1,4,local_2b0);
  _fwrite(&local_24,1,4,local_2b0);
  if (*(int *)(param_1 + 0x21c) == 0) {
    _fclose(local_2b0);
    uVar3 = 0xffffff5e;
  }
  else {
    if (*(short *)(param_1 + 0x216) == 1) {
      FUN_000af3fa(param_1,local_2b0,*(undefined4 *)(param_1 + 0x22c));
    }
    else if (*(short *)(param_1 + 0x216) == 2) {
      if (*(int *)(param_1 + 0x220) == 0) {
        _fclose(local_2b0);
        uVar3 = 0xffffff5c;
        goto LAB_000afe06;
      }
      FUN_000af546(param_1,local_2b0,*(undefined4 *)(param_1 + 0x22c));
    }
    FUN_000098c4(local_2b8);
    uVar3 = *(undefined4 *)(param_1 + 0x22c);
  }
LAB_000afe06:
  Disk_c_vslot_0(local_2b8);
  return uVar3;
}

