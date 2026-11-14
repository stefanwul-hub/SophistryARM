/* 000b2a2a FUN_000b2a2a */

undefined4 FUN_000b2a2a(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined1 local_2a8 [8];
  FILE *local_2a0;
  undefined1 local_14 [4];
  byte local_10;
  byte local_f;
  byte local_e;
  byte local_d;
  
  *(undefined4 *)(param_1 + 0x22c) = 0;
  if (*(int *)(param_1 + 0x21c) != 0) {
    _free(*(void **)(param_1 + 0x21c));
    *(undefined4 *)(param_1 + 0x21c) = 0;
  }
  if (*(int *)(param_1 + 0x220) != 0) {
    *(undefined4 *)(param_1 + 0x22c) = 0;
    _free(*(void **)(param_1 + 0x220));
    *(undefined4 *)(param_1 + 0x220) = 0;
  }
  *(undefined4 *)(param_1 + 0x22c) = 0;
  *(undefined1 *)(param_1 + 0x214) = 0;
  *(undefined1 *)(param_1 + 0x231) = 0;
  *(undefined1 *)(param_1 + 0x232) = 0;
  *(undefined1 *)(param_1 + 600) = 0;
  *(undefined1 *)(param_1 + 0x260) = 0;
  *(undefined1 *)(param_1 + 0x233) = 0;
  *(undefined1 *)(param_1 + 0x234) = 0;
  *(undefined1 *)(param_1 + 0x230) = 0;
  FUN_0000a5d4(local_2a8);
  FUN_0000979c(local_2a8,param_2);
  if (local_2a0 == (FILE *)0x0) {
    Disk_c_vslot_0(local_2a8);
    return 0xfffffffb;
  }
  _fread(local_14,1,4,local_2a0);
  _fread(local_14,1,4,local_2a0);
  _fread(&local_10,1,1,local_2a0);
  _fread(&local_f,1,1,local_2a0);
  _fread(&local_e,1,1,local_2a0);
  _fread(&local_d,1,1,local_2a0);
  uVar5 = (uint)local_10;
  uVar2 = (uint)local_f;
  uVar3 = (uint)local_e;
  _fread(&local_10,1,1,local_2a0);
  *(ushort *)(param_1 + 0x216) = (ushort)local_10;
  if (local_10 < 3) {
    _fread(&local_10,1,1,local_2a0);
    _fread(&local_f,1,1,local_2a0);
    _fread(&local_e,1,1,local_2a0);
    *(uint *)(param_1 + 0x210) = (uint)local_10 * 10000 + (uint)local_f * 100 + (uint)local_e;
    _fread(local_14,1,4,local_2a0);
    _fread(local_14,1,4,local_2a0);
    _fread(local_14,1,4,local_2a0);
    _fread(local_14,1,4,local_2a0);
    _fread(local_14,1,4,local_2a0);
    _fread(local_14,1,4,local_2a0);
    uVar2 = (uVar5 * 1000000 + uVar2 * 10000 + uVar3 * 100 + (uint)local_d) /
            ((uint)*(ushort *)(param_1 + 0x216) * 4);
    *(uint *)(param_1 + 0x22c) = uVar2;
    iVar4 = FUN_00013124(param_1,uVar2);
    *(int *)(param_1 + 0x21c) = iVar4;
    if (iVar4 == 0) {
      _fclose(local_2a0);
      uVar6 = 0xffffff5e;
    }
    else {
      if (*(short *)(param_1 + 0x216) == 1) {
        *(undefined1 *)(param_1 + 0x214) = 0;
        *(undefined1 *)(param_1 + 0x231) = 1;
        FUN_000aedb0(param_1,local_2a0,*(undefined4 *)(param_1 + 0x22c),4);
      }
      else if (*(short *)(param_1 + 0x216) == 2) {
        iVar4 = FUN_00013124(param_1,*(undefined4 *)(param_1 + 0x22c));
        *(int *)(param_1 + 0x220) = iVar4;
        if (iVar4 == 0) {
          _fclose(local_2a0);
          uVar6 = 0xffffff5c;
          goto LAB_000b2e19;
        }
        uVar6 = *(undefined4 *)(param_1 + 0x22c);
        *(undefined1 *)(param_1 + 0x231) = 1;
        FUN_000aedb0(param_1,local_2a0,uVar6,4);
        uVar1 = *(undefined4 *)(param_1 + 0x21c);
        *(undefined4 *)(param_1 + 0x21c) = *(undefined4 *)(param_1 + 0x220);
        FUN_000aedb0(param_1,local_2a0,uVar6,4);
        *(undefined4 *)(param_1 + 0x21c) = uVar1;
        *(undefined1 *)(param_1 + 0x214) = 1;
      }
      FUN_000098c4(local_2a8);
      uVar6 = *(undefined4 *)(param_1 + 0x22c);
    }
  }
  else {
    _fclose(local_2a0);
    uVar6 = 0xffffff97;
  }
LAB_000b2e19:
  Disk_c_vslot_0(local_2a8);
  return uVar6;
}

