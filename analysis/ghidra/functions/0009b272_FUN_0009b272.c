/* 0009b272 FUN_0009b272 */

int FUN_0009b272(int param_1,undefined4 param_2,undefined4 *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
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
  
  if ((int)*(short *)(param_1 + 0xb0) == *param_4) {
    *param_3 = param_2;
    return param_1;
  }
  if (*(int *)(param_1 + 0xb8) < 1) {
    return 0;
  }
  iVar2 = **(int **)(param_1 + 0xa8);
  if (*param_4 != (int)*(short *)(iVar2 + 0xb0)) {
    local_48 = 0;
    do {
      if (0 < *(int *)(iVar2 + 0xb8)) {
        local_10 = **(int **)(iVar2 + 0xa8);
        if (*param_4 == (int)*(short *)(local_10 + 0xb0)) {
LAB_0009b507:
          *param_3 = param_2;
          return local_10;
        }
        local_44 = 0;
        do {
          if (0 < *(int *)(local_10 + 0xb8)) {
            local_14 = **(int **)(local_10 + 0xa8);
            if (*param_4 == (int)*(short *)(local_14 + 0xb0)) {
LAB_0009b54e:
              *param_3 = param_2;
              return local_14;
            }
            local_40 = 0;
            do {
              if (0 < *(int *)(local_14 + 0xb8)) {
                local_18 = **(int **)(local_14 + 0xa8);
                if (*param_4 == (int)*(short *)(local_18 + 0xb0)) {
LAB_0009b596:
                  *param_3 = param_2;
                  return local_18;
                }
                local_3c = 0;
                do {
                  if (0 < *(int *)(local_18 + 0xb8)) {
                    local_1c = **(int **)(local_18 + 0xa8);
                    if (*param_4 == (int)*(short *)(local_1c + 0xb0)) {
LAB_0009b5de:
                      *param_3 = param_2;
                      return local_1c;
                    }
                    local_38 = 0;
                    do {
                      if (0 < *(int *)(local_1c + 0xb8)) {
                        local_20 = **(int **)(local_1c + 0xa8);
                        if ((int)*(short *)(local_20 + 0xb0) == *param_4) {
LAB_0009b626:
                          *param_3 = param_2;
                          return local_20;
                        }
                        local_34 = 0;
                        do {
                          if (0 < *(int *)(local_20 + 0xb8)) {
                            local_24 = **(int **)(local_20 + 0xa8);
                            if ((int)*(short *)(local_24 + 0xb0) == *param_4) {
LAB_0009b66e:
                              *param_3 = param_2;
                              return local_24;
                            }
                            local_30 = 0;
                            do {
                              if (0 < *(int *)(local_24 + 0xb8)) {
                                local_4c = **(int **)(local_24 + 0xa8);
                                if ((int)*(short *)(local_4c + 0xb0) == *param_4) {
LAB_0009b46d:
                                  *param_3 = param_2;
                                  return local_4c;
                                }
                                local_2c = 0;
                                while( true ) {
                                  if (0 < *(int *)(local_4c + 0xb8)) {
                                    local_28 = 0;
                                    do {
                                      iVar1 = FUN_0009b272(*(undefined4 *)
                                                            (*(int *)(local_4c + 0xa8) +
                                                            local_28 * 4),param_2,param_3,param_4);
                                      if (iVar1 != 0) {
                                        return iVar1;
                                      }
                                      local_28 = local_28 + 1;
                                    } while (local_28 < *(int *)(local_4c + 0xb8));
                                  }
                                  local_2c = local_2c + 1;
                                  if (*(int *)(local_24 + 0xb8) <= local_2c) break;
                                  local_4c = *(int *)(*(int *)(local_24 + 0xa8) + local_2c * 4);
                                  if ((int)*(short *)(local_4c + 0xb0) == *param_4)
                                  goto LAB_0009b46d;
                                }
                              }
                              local_30 = local_30 + 1;
                              if (*(int *)(local_20 + 0xb8) <= local_30) break;
                              local_24 = *(int *)(*(int *)(local_20 + 0xa8) + local_30 * 4);
                              if ((int)*(short *)(local_24 + 0xb0) == *param_4) goto LAB_0009b66e;
                            } while( true );
                          }
                          local_34 = local_34 + 1;
                          if (*(int *)(local_1c + 0xb8) <= local_34) break;
                          local_20 = *(int *)(*(int *)(local_1c + 0xa8) + local_34 * 4);
                          if (*param_4 == (int)*(short *)(local_20 + 0xb0)) goto LAB_0009b626;
                        } while( true );
                      }
                      local_38 = local_38 + 1;
                      if (*(int *)(local_18 + 0xb8) <= local_38) break;
                      local_1c = *(int *)(*(int *)(local_18 + 0xa8) + local_38 * 4);
                      if (*param_4 == (int)*(short *)(local_1c + 0xb0)) goto LAB_0009b5de;
                    } while( true );
                  }
                  local_3c = local_3c + 1;
                  if (*(int *)(local_14 + 0xb8) <= local_3c) break;
                  local_18 = *(int *)(*(int *)(local_14 + 0xa8) + local_3c * 4);
                  if (*param_4 == (int)*(short *)(local_18 + 0xb0)) goto LAB_0009b596;
                } while( true );
              }
              local_40 = local_40 + 1;
              if (*(int *)(local_10 + 0xb8) <= local_40) break;
              local_14 = *(int *)(*(int *)(local_10 + 0xa8) + local_40 * 4);
              if (*param_4 == (int)*(short *)(local_14 + 0xb0)) goto LAB_0009b54e;
            } while( true );
          }
          local_44 = local_44 + 1;
          if (*(int *)(iVar2 + 0xb8) <= local_44) break;
          local_10 = *(int *)(*(int *)(iVar2 + 0xa8) + local_44 * 4);
          if (*param_4 == (int)*(short *)(local_10 + 0xb0)) goto LAB_0009b507;
        } while( true );
      }
      local_48 = local_48 + 1;
      if (*(int *)(param_1 + 0xb8) <= local_48) {
        return 0;
      }
      iVar2 = *(int *)(*(int *)(param_1 + 0xa8) + local_48 * 4);
    } while (*param_4 != (int)*(short *)(iVar2 + 0xb0));
  }
  *param_3 = param_2;
  return iVar2;
}

