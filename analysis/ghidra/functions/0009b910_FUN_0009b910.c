/* 0009b910 FUN_0009b910 */

void FUN_0009b910(int param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_48;
  int local_40;
  int local_38;
  int local_30;
  int local_28;
  int local_20;
  int local_18;
  int local_10;
  
  if (0 < *(int *)(param_1 + 0xb8)) {
    local_48 = 0;
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0xa8) + local_48 * 4);
      if (0 < *(int *)(iVar2 + 0xb8)) {
        local_40 = 0;
        do {
          iVar3 = *(int *)(*(int *)(iVar2 + 0xa8) + local_40 * 4);
          if (0 < *(int *)(iVar3 + 0xb8)) {
            local_38 = 0;
            do {
              iVar4 = *(int *)(*(int *)(iVar3 + 0xa8) + local_38 * 4);
              if (0 < *(int *)(iVar4 + 0xb8)) {
                local_30 = 0;
                do {
                  iVar5 = *(int *)(*(int *)(iVar4 + 0xa8) + local_30 * 4);
                  if (0 < *(int *)(iVar5 + 0xb8)) {
                    local_28 = 0;
                    do {
                      iVar6 = *(int *)(*(int *)(iVar5 + 0xa8) + local_28 * 4);
                      if (0 < *(int *)(iVar6 + 0xb8)) {
                        local_20 = 0;
                        do {
                          iVar7 = *(int *)(*(int *)(iVar6 + 0xa8) + local_20 * 4);
                          if (0 < *(int *)(iVar7 + 0xb8)) {
                            local_18 = 0;
                            do {
                              iVar8 = *(int *)(*(int *)(iVar7 + 0xa8) + local_18 * 4);
                              if (0 < *(int *)(iVar8 + 0xb8)) {
                                local_10 = 0;
                                do {
                                  iVar9 = *(int *)(*(int *)(iVar8 + 0xa8) + local_10 * 4);
                                  if (*(int *)(iVar9 + 0xb8) < 1) {
                                    sVar1 = *(short *)(iVar9 + 0xb0);
                                  }
                                  else {
                                    iVar10 = 0;
                                    do {
                                      FUN_0009b910(*(undefined4 *)
                                                    (*(int *)(iVar9 + 0xa8) + iVar10 * 4));
                                      iVar10 = iVar10 + 1;
                                    } while (iVar10 < *(int *)(iVar9 + 0xb8));
                                    sVar1 = *(short *)(iVar9 + 0xb0);
                                  }
                                  if (sVar1 != 0) {
                                    _DeleteMenu((int)sVar1);
                                  }
                                  if (*(int *)(iVar9 + 0xa0) != 0) {
                                    _DisposeMenu(*(int *)(iVar9 + 0xa0));
                                  }
                                  *(undefined4 *)(iVar9 + 0xa0) = 0;
                                  local_10 = local_10 + 1;
                                } while (local_10 < *(int *)(iVar8 + 0xb8));
                              }
                              if (*(short *)(iVar8 + 0xb0) != 0) {
                                _DeleteMenu((int)*(short *)(iVar8 + 0xb0));
                              }
                              if (*(int *)(iVar8 + 0xa0) == 0) {
                                *(undefined4 *)(iVar8 + 0xa0) = 0;
                                if (*(int *)(iVar7 + 0xb8) <= local_18 + 1) break;
                              }
                              else {
                                _DisposeMenu(*(int *)(iVar8 + 0xa0));
                                *(undefined4 *)(iVar8 + 0xa0) = 0;
                                if (*(int *)(iVar7 + 0xb8) <= local_18 + 1) break;
                              }
                              local_18 = local_18 + 1;
                            } while( true );
                          }
                          if (*(short *)(iVar7 + 0xb0) != 0) {
                            _DeleteMenu((int)*(short *)(iVar7 + 0xb0));
                          }
                          if (*(int *)(iVar7 + 0xa0) == 0) {
                            *(undefined4 *)(iVar7 + 0xa0) = 0;
                            if (*(int *)(iVar6 + 0xb8) <= local_20 + 1) break;
                          }
                          else {
                            _DisposeMenu(*(int *)(iVar7 + 0xa0));
                            *(undefined4 *)(iVar7 + 0xa0) = 0;
                            if (*(int *)(iVar6 + 0xb8) <= local_20 + 1) break;
                          }
                          local_20 = local_20 + 1;
                        } while( true );
                      }
                      if (*(short *)(iVar6 + 0xb0) != 0) {
                        _DeleteMenu((int)*(short *)(iVar6 + 0xb0));
                      }
                      if (*(int *)(iVar6 + 0xa0) == 0) {
                        *(undefined4 *)(iVar6 + 0xa0) = 0;
                        if (*(int *)(iVar5 + 0xb8) <= local_28 + 1) break;
                      }
                      else {
                        _DisposeMenu(*(int *)(iVar6 + 0xa0));
                        *(undefined4 *)(iVar6 + 0xa0) = 0;
                        if (*(int *)(iVar5 + 0xb8) <= local_28 + 1) break;
                      }
                      local_28 = local_28 + 1;
                    } while( true );
                  }
                  if (*(short *)(iVar5 + 0xb0) != 0) {
                    _DeleteMenu((int)*(short *)(iVar5 + 0xb0));
                  }
                  if (*(int *)(iVar5 + 0xa0) != 0) {
                    _DisposeMenu(*(int *)(iVar5 + 0xa0));
                  }
                  *(undefined4 *)(iVar5 + 0xa0) = 0;
                  local_30 = local_30 + 1;
                } while (local_30 < *(int *)(iVar4 + 0xb8));
              }
              if (*(short *)(iVar4 + 0xb0) != 0) {
                _DeleteMenu((int)*(short *)(iVar4 + 0xb0));
              }
              if (*(int *)(iVar4 + 0xa0) != 0) {
                _DisposeMenu(*(int *)(iVar4 + 0xa0));
              }
              *(undefined4 *)(iVar4 + 0xa0) = 0;
              local_38 = local_38 + 1;
            } while (local_38 < *(int *)(iVar3 + 0xb8));
          }
          if (*(short *)(iVar3 + 0xb0) != 0) {
            _DeleteMenu((int)*(short *)(iVar3 + 0xb0));
          }
          if (*(int *)(iVar3 + 0xa0) != 0) {
            _DisposeMenu(*(int *)(iVar3 + 0xa0));
          }
          *(undefined4 *)(iVar3 + 0xa0) = 0;
          local_40 = local_40 + 1;
        } while (local_40 < *(int *)(iVar2 + 0xb8));
      }
      if (*(short *)(iVar2 + 0xb0) != 0) {
        _DeleteMenu((int)*(short *)(iVar2 + 0xb0));
      }
      if (*(int *)(iVar2 + 0xa0) != 0) {
        _DisposeMenu(*(int *)(iVar2 + 0xa0));
      }
      *(undefined4 *)(iVar2 + 0xa0) = 0;
      local_48 = local_48 + 1;
    } while (local_48 < *(int *)(param_1 + 0xb8));
  }
  if (*(short *)(param_1 + 0xb0) != 0) {
    _DeleteMenu((int)*(short *)(param_1 + 0xb0));
  }
  if (*(int *)(param_1 + 0xa0) != 0) {
    _DisposeMenu(*(int *)(param_1 + 0xa0));
  }
  *(undefined4 *)(param_1 + 0xa0) = 0;
  return;
}

