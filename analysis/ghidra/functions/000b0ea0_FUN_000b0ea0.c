/* 000b0ea0 FUN_000b0ea0 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int FUN_000b0ea0(int param_1,undefined4 param_2)

{
  size_t sVar1;
  int iVar2;
  undefined1 local_2b8 [8];
  FILE *local_2b0;
  uint local_24;
  uint local_20 [4];
  
  if ((*(int *)(param_1 + 0x21c) == 0) ||
     ((*(char *)(param_1 + 0x214) != '\0' && (*(int *)(param_1 + 0x220) == 0)))) {
    return -400;
  }
  FUN_0000a5d4(local_2b8);
  FUN_00009848(local_2b8,param_2);
  if (local_2b0 == (FILE *)0x0) {
    iVar2 = -5;
  }
  else {
    sVar1 = _fwrite("FORM",1,4,local_2b0);
    if (sVar1 == 4) {
      local_20[0] = 0;
      sVar1 = _fwrite(local_20,1,4,local_2b0);
      if (sVar1 == 4) {
        sVar1 = _fwrite("AIFF",1,4,local_2b0);
        if (sVar1 == 4) {
          sVar1 = _fwrite("COMM",1,4,local_2b0);
          if (sVar1 == 4) {
            local_20[0] = 0x12000000;
            sVar1 = _fwrite(local_20,1,4,local_2b0);
            if (sVar1 == 4) {
              iVar2 = FUN_000b07a4(param_1,local_2b0);
              if (iVar2 == 0) {
                sVar1 = _fwrite("SSND",1,4,local_2b0);
                if (sVar1 != 4) {
                  FUN_000098c4(local_2b8);
                  iVar2 = -0x6e;
                  goto LAB_000b0f40;
                }
                iVar2 = (uint)*(ushort *)(param_1 + 0x216) * *(int *)(param_1 + 0x22c) * 3;
                local_20[0] = iVar2 + 8;
                if ((local_20[0] & 1) != 0) {
                  local_20[0] = iVar2 + 9;
                }
                local_20[0] = local_20[0] << 0x18 | (local_20[0] & 0xff00) << 8 |
                              (int)(local_20[0] & 0xff0000) >> 8 | local_20[0] >> 0x18;
                sVar1 = _fwrite(local_20,1,4,local_2b0);
                if (sVar1 != 4) {
                  FUN_000098c4(local_2b8);
                  iVar2 = -0x78;
                  goto LAB_000b0f40;
                }
                iVar2 = FUN_000b0bca(param_1,local_2b0);
                if (iVar2 == 0) {
                  local_24 = _ftell(local_2b0);
                  local_24 = _ftell(local_2b0);
                  if ((int)local_24 < 0) {
                    FUN_000098c4(local_2b8);
                    iVar2 = -700;
                  }
                  else {
                    iVar2 = _fseek(local_2b0,4,0);
                    if (iVar2 == 0) {
                      local_24 = local_24 << 0x18 | (local_24 & 0xff00) << 8 |
                                 (int)(local_24 & 0xff0000) >> 8 | local_24 >> 0x18;
                      sVar1 = _fwrite(&local_24,1,4,local_2b0);
                      if (sVar1 == 4) {
                        FUN_000098c4(local_2b8);
                        iVar2 = *(int *)(param_1 + 0x22c);
                      }
                      else {
                        FUN_000098c4(local_2b8);
                        iVar2 = -0x2d0;
                      }
                    }
                    else {
                      FUN_000098c4(local_2b8);
                      iVar2 = -0x2c6;
                    }
                  }
                  goto LAB_000b0f40;
                }
              }
              FUN_000098c4(local_2b8);
            }
            else {
              FUN_000098c4(local_2b8);
              iVar2 = -0x46;
            }
          }
          else {
            FUN_000098c4(local_2b8);
            iVar2 = -0x3c;
          }
        }
        else {
          FUN_000098c4(local_2b8);
          iVar2 = -0x28;
        }
      }
      else {
        FUN_000098c4(local_2b8);
        iVar2 = -0x1e;
      }
    }
    else {
      FUN_000098c4(local_2b8);
      iVar2 = -10;
    }
  }
LAB_000b0f40:
  Disk_c_vslot_0(local_2b8);
  return iVar2;
}

