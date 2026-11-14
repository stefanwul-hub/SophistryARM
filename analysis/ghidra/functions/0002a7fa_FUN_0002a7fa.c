/* 0002a7fa FUN_0002a7fa */

uint FUN_0002a7fa(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  byte local_c1;
  int local_84;
  int local_7c;
  int local_74;
  int local_6c;
  int local_64;
  int local_5c;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  iVar3 = FUN_00012888(*(undefined4 *)(param_1 + 0xc38),*(undefined4 *)(param_1 + 0x140));
  if (iVar3 == 0) {
    return 0;
  }
  if (param_7 < 7) {
    if (*(char *)(*(int *)((param_3 + param_2) * 0x70 + 8 + iVar3) + 0x4c0 + param_1) == '\0') {
      return 0;
    }
    if (0 < param_5) {
      iVar1 = param_3 * 0x70;
      iVar2 = param_4 * 0x70;
      iVar3 = iVar3 + iVar2;
      uVar5 = 1;
      iVar6 = 0;
      local_10 = iVar1;
      do {
        if (((iVar6 != param_2) && (*(int *)(iVar3 + 8) == param_2 + param_6)) &&
           (uVar4 = FUN_00012888(*(undefined4 *)(param_1 + 0xc38),*(undefined4 *)(param_1 + 0x140)),
           uVar5 = uVar4, uVar4 != 0)) {
          if (param_7 + 1 < 7) {
            local_c1 = *(byte *)(*(int *)(uVar4 + 8 + local_10) + 0x4c0 + param_1);
            uVar5 = (uint)local_c1;
            if (local_c1 != 0) {
              local_14 = uVar4 + iVar2;
              local_84 = 0;
              local_18 = iVar1;
              do {
                if ((iVar6 != local_84) && (*(int *)(local_14 + 8) == iVar6 + param_6)) {
                  local_1c = FUN_00012888(*(undefined4 *)(param_1 + 0xc38),
                                          *(undefined4 *)(param_1 + 0x140));
                  if (local_1c == 0) {
                    local_c1 = 0;
                  }
                  else if (param_7 + 2 < 7) {
                    local_c1 = *(byte *)(*(int *)(local_1c + 8 + local_18) + 0x4c0 + param_1);
                    if (local_c1 != 0) {
                      local_1c = local_1c + iVar2;
                      local_7c = 0;
                      local_20 = iVar1;
                      do {
                        if ((local_84 != local_7c) && (*(int *)(local_1c + 8) == local_84 + param_6)
                           ) {
                          local_24 = FUN_00012888(*(undefined4 *)(param_1 + 0xc38),
                                                  *(undefined4 *)(param_1 + 0x140));
                          if (local_24 == 0) {
                            local_c1 = 0;
                          }
                          else if (param_7 + 3 < 7) {
                            local_c1 = *(byte *)(*(int *)(local_24 + 8 + local_20) + 0x4c0 + param_1
                                                );
                            if (local_c1 != 0) {
                              local_24 = local_24 + iVar2;
                              local_74 = 0;
                              local_28 = iVar1;
                              do {
                                if ((local_7c != local_74) &&
                                   (*(int *)(local_24 + 8) == local_7c + param_6)) {
                                  local_2c = FUN_00012888(*(undefined4 *)(param_1 + 0xc38),
                                                          *(undefined4 *)(param_1 + 0x140));
                                  if (local_2c == 0) {
                                    local_c1 = 0;
                                  }
                                  else if (param_7 + 4 < 7) {
                                    local_c1 = *(byte *)(*(int *)(local_2c + 8 + local_28) + 0x4c0 +
                                                        param_1);
                                    if (local_c1 != 0) {
                                      local_2c = local_2c + iVar2;
                                      local_6c = 0;
                                      local_30 = iVar1;
                                      do {
                                        if ((local_74 != local_6c) &&
                                           (*(int *)(local_2c + 8) == local_74 + param_6)) {
                                          local_34 = FUN_00012888(*(undefined4 *)(param_1 + 0xc38),
                                                                  *(undefined4 *)(param_1 + 0x140));
                                          if (local_34 == 0) {
                                            local_c1 = 0;
                                          }
                                          else if (param_7 + 5 < 7) {
                                            local_c1 = *(byte *)(*(int *)(local_34 + 8 + local_30) +
                                                                 0x4c0 + param_1);
                                            if (local_c1 != 0) {
                                              local_34 = local_34 + iVar2;
                                              local_64 = 0;
                                              local_38 = iVar1;
                                              do {
                                                if ((local_6c != local_64) &&
                                                   (*(int *)(local_34 + 8) == local_6c + param_6)) {
                                                  local_3c = FUN_00012888(*(undefined4 *)
                                                                           (param_1 + 0xc38),
                                                                          *(undefined4 *)
                                                                           (param_1 + 0x140));
                                                  if (local_3c == 0) {
                                                    local_c1 = 0;
                                                  }
                                                  else if (param_7 + 6 < 7) {
                                                    local_c1 = *(byte *)(*(int *)(local_38 + 8 +
                                                                                 local_3c) + 0x4c0 +
                                                                        param_1);
                                                    if (local_c1 != 0) {
                                                      local_3c = local_3c + iVar2;
                                                      local_5c = 0;
                                                      local_40 = iVar1;
                                                      do {
                                                        if ((local_64 != local_5c) &&
                                                           (local_64 + param_6 ==
                                                            *(int *)(local_3c + 8))) {
                                                          local_44 = FUN_00012888(*(undefined4 *)
                                                                                   (param_1 + 0xc38)
                                                                                  ,*(undefined4 *)
                                                                                    (param_1 + 0x140
                                                                                    ));
                                                          if (local_44 == 0) {
                                                            local_c1 = 0;
                                                          }
                                                          else if (param_7 + 7 < 7) {
                                                            local_c1 = *(byte *)(*(int *)(local_40 +
                                                                                          8 + 
                                                  local_44) + 0x4c0 + param_1);
                                                  if (local_c1 != 0) {
                                                    local_44 = local_44 + iVar2;
                                                    local_54 = 0;
                                                    local_48 = iVar1;
                                                    do {
                                                      if ((local_5c != local_54) &&
                                                         (local_5c + param_6 ==
                                                          *(int *)(local_44 + 8))) {
                                                        local_4c = FUN_00012888(*(undefined4 *)
                                                                                 (param_1 + 0xc38),
                                                                                *(undefined4 *)
                                                                                 (param_1 + 0x140));
                                                        if (local_4c == 0) {
                                                          local_c1 = 0;
                                                        }
                                                        else if (param_7 + 8 < 7) {
                                                          local_c1 = *(byte *)(*(int *)(local_48 + 8
                                                                                       + local_4c) +
                                                                               0x4c0 + param_1);
                                                          if (local_c1 != 0) {
                                                            local_4c = local_4c + iVar2;
                                                            local_50 = 0;
                                                            do {
                                                              if ((local_54 != local_50) &&
                                                                 (local_54 + param_6 ==
                                                                  *(int *)(local_4c + 8))) {
                                                                local_c1 = FUN_0002a7fa(param_1,
                                                  local_50,param_3,param_4,param_5,param_6,
                                                  param_7 + 9);
                                                  }
                                                  local_50 = local_50 + 1;
                                                  local_4c = local_4c + 0x70;
                                                  } while (param_5 != local_50);
                                                  }
                                                  }
                                                  else {
                                                    local_c1 = 1;
                                                  }
                                                  }
                                                  local_54 = local_54 + 1;
                                                  local_48 = local_48 + 0x70;
                                                  local_44 = local_44 + 0x70;
                                                  } while (param_5 != local_54);
                                                  }
                                                  }
                                                  else {
                                                    local_c1 = 1;
                                                  }
                                                  }
                                                  local_5c = local_5c + 1;
                                                  local_40 = local_40 + 0x70;
                                                  local_3c = local_3c + 0x70;
                                                  } while (param_5 != local_5c);
                                                  }
                                                  }
                                                  else {
                                                    local_c1 = 1;
                                                  }
                                                }
                                                local_64 = local_64 + 1;
                                                local_38 = local_38 + 0x70;
                                                local_34 = local_34 + 0x70;
                                              } while (param_5 != local_64);
                                            }
                                          }
                                          else {
                                            local_c1 = 1;
                                          }
                                        }
                                        local_6c = local_6c + 1;
                                        local_30 = local_30 + 0x70;
                                        local_2c = local_2c + 0x70;
                                      } while (param_5 != local_6c);
                                    }
                                  }
                                  else {
                                    local_c1 = 1;
                                  }
                                }
                                local_74 = local_74 + 1;
                                local_28 = local_28 + 0x70;
                                local_24 = local_24 + 0x70;
                              } while (param_5 != local_74);
                            }
                          }
                          else {
                            local_c1 = 1;
                          }
                        }
                        local_7c = local_7c + 1;
                        local_20 = local_20 + 0x70;
                        local_1c = local_1c + 0x70;
                      } while (param_5 != local_7c);
                    }
                  }
                  else {
                    local_c1 = 1;
                  }
                }
                local_84 = local_84 + 1;
                local_18 = local_18 + 0x70;
                local_14 = local_14 + 0x70;
              } while (param_5 != local_84);
              uVar5 = (uint)local_c1;
            }
          }
          else {
            uVar5 = 1;
          }
        }
        iVar6 = iVar6 + 1;
        local_10 = local_10 + 0x70;
        iVar3 = iVar3 + 0x70;
      } while (param_5 != iVar6);
      return uVar5 & 0xff;
    }
  }
  return 1;
}

