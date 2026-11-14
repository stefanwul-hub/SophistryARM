/* 000b1a7a FUN_000b1a7a */

int FUN_000b1a7a(int param_1,undefined4 param_2)

{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  size_t sVar4;
  long lVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  uint local_2c0;
  undefined1 local_2b0 [8];
  FILE *local_2a8;
  uint local_1c;
  int local_18;
  uint local_14;
  int local_10;
  
  puVar3 = (undefined4 *)operator_new__(0x24);
  *puVar3 = 4;
  iVar7 = 4;
  puVar8 = puVar3 + 1;
  do {
    *puVar8 = 0xffffffff;
    puVar8[1] = 0;
    puVar8 = puVar8 + 2;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  *(undefined4 **)(param_1 + 0x264) = puVar3 + 1;
  *(undefined4 *)(param_1 + 0x268) = 0;
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
  FUN_0000a5d4(local_2b0);
  FUN_0000979c(local_2b0,param_2);
  if (local_2a8 == (FILE *)0x0) {
    Disk_c_vslot_0(local_2b0);
    return -5;
  }
  sVar4 = _fread(&local_10,1,4,local_2a8);
  if (sVar4 == 4) {
    if (local_10 == 0x46464952) {
      sVar4 = _fread(&local_10,1,4,local_2a8);
      if (sVar4 == 4) {
        sVar4 = _fread(&local_10,1,4,local_2a8);
        if (sVar4 == 4) {
          if (local_10 == 0x45564157) {
            bVar1 = false;
            bVar2 = false;
            while (sVar4 = _fread(&local_14,1,4,local_2a8), sVar4 == 4) {
              sVar4 = _fread(&local_18,1,4,local_2a8);
              if (sVar4 != 4) {
                FUN_000098c4(local_2b0);
                iVar7 = -0x46;
                goto LAB_000b1d2b;
              }
              lVar5 = _ftell(local_2a8);
              iVar6 = lVar5 + local_18;
              if (local_14 == 0x61746164) {
                *(int *)(param_1 + 0x228) = local_18;
                iVar7 = FUN_000b16fc(param_1,local_2a8);
                if (iVar7 != 0) goto LAB_000b1d2b;
                bVar2 = true;
                iVar7 = _fseek(local_2a8,iVar6,0);
              }
              else {
                if (local_14 < 0x61746165) {
                  if (local_14 == 0x20657563) {
                    sVar4 = _fread(&local_1c,1,4,local_2a8);
                    if (sVar4 != 4) {
                      _fclose(local_2a8);
                      Disk_c_vslot_0(local_2b0);
                      return -0x1fe;
                    }
                    if (local_1c != 0) {
                      local_2c0 = 0;
                      do {
                        iVar7 = FUN_000b0982(param_1,local_2a8);
                        if (iVar7 != 0) goto LAB_000b1d2b;
                        local_2c0 = local_2c0 + 1;
                      } while (local_2c0 < local_1c);
                    }
                  }
                  else if (local_14 == 0x20746d66) {
                    iVar7 = FUN_000af8d6(param_1,local_2a8);
                    if (iVar7 != 0) goto LAB_000b1d2b;
                    bVar1 = true;
                  }
                }
                else if (local_14 == 0x6c706d73) {
                  iVar7 = FUN_000af7d0(param_1,local_2a8);
                  if (iVar7 != 0) goto LAB_000b1d2b;
                  *(undefined1 *)(param_1 + 0x260) = 1;
                }
                else if ((local_14 == 0x746e6c73) &&
                        (iVar7 = FUN_000b0b40(param_1,local_2a8), iVar7 != 0)) goto LAB_000b1d2b;
                iVar7 = _fseek(local_2a8,iVar6,0);
              }
              if (iVar7 != 0) {
                FUN_000098c4(local_2b0);
                Disk_c_vslot_0(local_2b0);
                return -0xb4;
              }
            }
            FUN_000098c4(local_2b0);
            if ((bVar1) && (bVar2)) {
              iVar7 = *(int *)(param_1 + 0x22c);
            }
            else {
              iVar7 = -0x3c;
            }
          }
          else {
            FUN_000098c4(local_2b0);
            iVar7 = -0x32;
          }
        }
        else {
          FUN_000098c4(local_2b0);
          iVar7 = -0x28;
        }
      }
      else {
        FUN_000098c4(local_2b0);
        iVar7 = -0x1e;
      }
    }
    else {
      FUN_000098c4(local_2b0);
      iVar7 = -0x14;
    }
  }
  else {
    FUN_000098c4(local_2b0);
    iVar7 = -10;
  }
LAB_000b1d2b:
  Disk_c_vslot_0(local_2b0);
  return iVar7;
}

