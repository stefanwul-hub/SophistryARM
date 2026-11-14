/* 000b1f94 FUN_000b1f94 */

int FUN_000b1f94(int param_1,undefined4 param_2)

{
  bool bVar1;
  size_t sVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  long local_2cc;
  uint local_2c8;
  long local_2c4;
  uint local_2c0;
  long local_2bc;
  uint local_2b8;
  long local_2b4;
  uint local_2b0;
  undefined1 local_2ac [8];
  FILE *local_2a4;
  uint local_18;
  uint local_14;
  uint local_10;
  
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
  *(undefined1 *)(param_1 + 600) = 0;
  *(undefined1 *)(param_1 + 0x260) = 0;
  *(undefined1 *)(param_1 + 0x233) = 0;
  *(undefined1 *)(param_1 + 0x234) = 0;
  *(undefined1 *)(param_1 + 0x230) = 1;
  *(undefined1 *)(param_1 + 0x232) = 0;
  *(undefined1 *)(param_1 + 0x231) = 0;
  FUN_0000a5d4(local_2ac);
  FUN_0000979c(local_2ac,param_2);
  if (local_2a4 == (FILE *)0x0) {
    iVar4 = -5;
  }
  else {
    local_2cc = 0;
    local_2c8 = 0;
    local_2c4 = 0;
    local_2c0 = 0;
    local_2bc = 0;
    local_2b8 = 0;
    local_2b4 = 0;
    local_2b0 = 0;
    while (sVar2 = _fread(&local_10,1,4,local_2a4), sVar2 == 4) {
      local_10 = local_10 << 0x18 | (local_10 & 0xff00) << 8 | (int)(local_10 & 0xff0000) >> 8 |
                 local_10 >> 0x18;
      sVar2 = _fread(&local_14,1,4,local_2a4);
      if (sVar2 != 4) {
        FUN_000098c4(local_2ac);
        Disk_c_vslot_0(local_2ac);
        return -0x46;
      }
      local_14 = local_14 << 0x18 | (local_14 & 0xff00) << 8 | (int)(local_14 & 0xff0000) >> 8 |
                 local_14 >> 0x18;
      lVar3 = _ftell(local_2a4);
      if (local_10 == 0x494e5354) {
        local_2c0 = local_14;
        local_2c4 = lVar3;
      }
      else if (local_10 < 0x494e5355) {
        if (local_10 == 0x434f4d4d) {
          local_2b0 = local_14;
          local_2b4 = lVar3;
        }
        else if (local_10 == 0x464f524d) {
          sVar2 = _fread(&local_18,1,4,local_2a4);
          if (sVar2 != 4) {
            FUN_000098c4(local_2ac);
            iVar4 = -0x4b;
            goto LAB_000b243f;
          }
          local_18 = local_18 << 0x18 | (local_18 & 0xff00) << 8 | (int)(local_18 & 0xff0000) >> 8 |
                     local_18 >> 0x18;
          if (local_18 == 0x41494643) {
            *(undefined1 *)(param_1 + 0x232) = 1;
          }
          else if (local_18 != 0x41494646) {
            FUN_000098c4(local_2ac);
            iVar4 = -0x50;
            goto LAB_000b243f;
          }
          local_14 = 4;
        }
      }
      else if (local_10 == 0x4d41524b) {
        local_2c8 = local_14;
        local_2cc = lVar3;
      }
      else if (local_10 == 0x53534e44) {
        local_2b8 = local_14;
        local_2bc = lVar3;
      }
      if ((local_14 & 1) != 0) {
        local_14 = local_14 + 1;
      }
      iVar5 = lVar3 + local_14;
      iVar4 = _feof(local_2a4);
      if (iVar4 != 0) goto LAB_000b22f4;
      if ((0 < iVar5) && (iVar4 = _fseek(local_2a4,iVar5,0), iVar4 != 0)) {
        FUN_000098c4(local_2ac);
        Disk_c_vslot_0(local_2ac);
        return -0x3c;
      }
    }
    iVar4 = _feof(local_2a4);
    if (iVar4 == 0) {
      FUN_000098c4(local_2ac);
      iVar4 = -0x41;
    }
    else {
LAB_000b22f4:
      if ((((local_2b4 < 1) || ((int)local_2b0 < 1)) || (local_2bc < 1)) || ((int)local_2b8 < 1)) {
        bVar1 = false;
      }
      else {
        if ((int)local_2b0 < 0x12) {
          FUN_000098c4(local_2ac);
          iVar4 = -0x5a;
          goto LAB_000b243f;
        }
        if ((*(char *)(param_1 + 0x232) != '\0') && (local_2b0 == 0x12)) {
          *(undefined1 *)(param_1 + 0x232) = 0;
        }
        if ((*(char *)(param_1 + 0x232) == '\0') && (0x16 < (int)local_2b0)) {
          *(undefined1 *)(param_1 + 0x232) = 1;
        }
        iVar4 = _fseek(local_2a4,local_2b4,0);
        if (iVar4 != 0) {
          FUN_000098c4(local_2ac);
          iVar4 = -0x5b;
          goto LAB_000b243f;
        }
        iVar4 = FUN_000aff46(param_1,local_2a4);
        if (iVar4 != 0) goto LAB_000b243f;
        iVar4 = _fseek(local_2a4,local_2bc,0);
        if (iVar4 != 0) {
          FUN_000098c4(local_2ac);
          iVar4 = -0x5c;
          goto LAB_000b243f;
        }
        iVar4 = FUN_000b02da(param_1,local_2a4);
        if (iVar4 != 0) goto LAB_000b243f;
        bVar1 = true;
      }
      if ((((0 < local_2c4) && (0 < (int)local_2c0)) && (0 < local_2cc)) &&
         ((0 < (int)local_2c8 && (local_2c0 == 0x14)))) {
        local_14 = CONCAT22(local_14._2_2_,0xffff);
        local_10 = CONCAT22(local_10._2_2_,0xffff);
        iVar4 = _fseek(local_2a4,local_2c4,0);
        if (iVar4 != 0) {
          FUN_000098c4(local_2ac);
          iVar4 = -0x5d;
          goto LAB_000b243f;
        }
        iVar4 = FUN_000afebc(param_1,local_2a4,&local_14,&local_10);
        if (iVar4 == 0) {
          iVar4 = _fseek(local_2a4,local_2cc,0);
          if (iVar4 != 0) {
            FUN_000098c4(local_2ac);
            iVar4 = -0x5e;
            goto LAB_000b243f;
          }
          FUN_000b0562(param_1,local_2a4,(int)(short)local_14,(int)(short)local_10);
        }
      }
      FUN_000098c4(local_2ac);
      if (!bVar1) {
        Disk_c_vslot_0(local_2ac);
        return -6;
      }
      iVar4 = *(int *)(param_1 + 0x22c);
    }
  }
LAB_000b243f:
  Disk_c_vslot_0(local_2ac);
  return iVar4;
}

