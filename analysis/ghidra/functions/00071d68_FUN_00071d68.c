/* 00071d68 FUN_00071d68 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Removing unreachable block (ram,0x000724ff) */
/* WARNING: Removing unreachable block (ram,0x00071f60) */
/* WARNING: Removing unreachable block (ram,0x000724f8) */
/* WARNING: Removing unreachable block (ram,0x00071f79) */

void FUN_00071d68(int param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  longdouble lVar5;
  float fVar6;
  float fVar7;
  undefined4 uVar8;
  undefined **ppuVar9;
  int local_bc;
  int local_ac;
  int local_a8;
  int local_a4;
  undefined *local_94;
  undefined1 local_90;
  int local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined *local_80;
  undefined1 local_7c;
  int local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined *local_6c;
  undefined1 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined *local_58;
  undefined1 local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined *local_44;
  undefined1 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined *local_30;
  undefined1 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (*(int *)(param_1 + 0x1d4) != 0) {
    *(undefined4 *)(param_1 + 0x77c) = *(undefined4 *)(param_1 + 0x778);
    if (*(int *)(param_1 + 0x314) < 1) {
      (**(code **)(**(int **)(param_1 + 0x1d4) + 0x9c))(*(int **)(param_1 + 0x1d4),param_2,param_3);
    }
    else if (param_3 != 0) {
      local_bc = param_3;
      do {
        if (*(int *)(param_1 + 0x1d4) == 0) {
          iVar3 = *(int *)(param_1 + 0x778);
        }
        else {
          if (*(int *)(param_1 + 0x1d8) != 0) {
            bVar1 = *(byte *)(*(int *)(param_1 + 0x794) + 0x28c + param_1);
            if (*(int *)(param_1 + 0x778) == 0) {
              if (bVar1 != 0x80) {
                if ((bVar1 != 0) && (*(int *)(param_1 + 0x314) != 1)) {
                  if (*(int *)(param_1 + 0x314) == 9) {
                    if (0 < *(int *)(param_1 + 0x758)) {
                      local_a4 = param_1;
                      local_ac = 0;
                      do {
                        if (*(int *)(param_1 + 0x1d4) != 0) {
                          fVar6 = *(float *)(*(int *)(param_1 + 0x124) + 0x31c) * 0.01;
                          local_80 = PTR_DAT_00103814 + 8;
                          local_78 = -1;
                          local_74 = 0xffffffff;
                          local_70 = 0xffffffff;
                          local_7c = 1;
                          for (iVar3 = (int)*(char *)(local_a4 + 0x318) +
                                       *(int *)(param_1 + 0x310) * 0xc; 0x7f < iVar3;
                              iVar3 = iVar3 + -0xc) {
                          }
                          for (; (iVar2 = iVar3, iVar3 < 0 && (iVar2 = iVar3 + 0xc, iVar2 < 0));
                              iVar3 = iVar3 + 0x18) {
                          }
                          uVar8 = 0;
                          NoteC_c_vslot_3(&local_80,iVar2,
                                          (int)((float)*(byte *)(*(int *)(param_1 + 0x794) + 0x28c +
                                                                param_1) * (1.0 - fVar6) +
                                               fVar6 * (float)(int)*(char *)(local_a4 + 0x319)),0);
                          iVar3 = local_ac * 0x1c + 800 + param_1;
                          local_40 = *(undefined1 *)(iVar3 + 4);
                          local_3c = *(undefined4 *)(iVar3 + 8);
                          local_38 = *(undefined4 *)(iVar3 + 0xc);
                          local_44 = PTR_DAT_00103814 + 8;
                          local_34 = *(undefined4 *)(iVar3 + 0x10);
                          local_2c = local_7c;
                          local_28 = local_78;
                          local_24 = local_74;
                          local_20 = local_70;
                          ppuVar9 = &local_44;
                          local_30 = local_44;
                          (**(code **)(**(int **)(param_1 + 0x1d4) + 0x94))
                                    (*(int **)(param_1 + 0x1d4),&local_30,ppuVar9,uVar8,ppuVar9);
                          NoteC_c_vslot_0(&local_30);
                          NoteC_c_vslot_0(ppuVar9);
                          iVar3 = *(int *)(param_1 + 0x78c);
                          *(int *)(param_1 + 0x698 + iVar3 * 4) = (int)*(char *)(local_a4 + 0x318);
                          *(int *)(param_1 + 0x78c) = iVar3 + 1;
                          NoteC_c_vslot_0(&local_80);
                        }
                        local_ac = local_ac + 1;
                        local_a4 = local_a4 + 0x1c;
                      } while (local_ac < *(int *)(param_1 + 0x758));
                    }
                  }
                  else {
                    fVar6 = *(float *)(*(int *)(param_1 + 0x124) + 0x31c) * 0.01;
                    local_80 = PTR_DAT_00103814 + 8;
                    local_78 = -1;
                    local_74 = 0xffffffff;
                    local_70 = 0xffffffff;
                    local_7c = 1;
                    for (iVar3 = (int)*(char *)(param_1 + 0x75c) + *(int *)(param_1 + 0x310) * 0xc;
                        (iVar2 = iVar3, 0x7f < iVar3 && (iVar2 = iVar3 + -0xc, 0x7f < iVar2));
                        iVar3 = iVar3 + -0x18) {
                    }
                    for (; (iVar3 = iVar2, iVar2 < 0 && (iVar3 = iVar2 + 0xc, iVar3 < 0));
                        iVar2 = iVar2 + 0x18) {
                    }
                    NoteC_c_vslot_3(&local_80,iVar3,
                                    (int)((float)bVar1 * (1.0 - fVar6) +
                                         fVar6 * (float)(int)*(char *)(param_1 + 0x75d)),0);
                    local_68 = *(undefined1 *)(param_1 + 0x768);
                    local_64 = *(undefined4 *)(param_1 + 0x76c);
                    local_60 = *(undefined4 *)(param_1 + 0x770);
                    local_6c = PTR_DAT_00103814 + 8;
                    local_5c = *(undefined4 *)(param_1 + 0x774);
                    local_54 = local_7c;
                    local_50 = local_78;
                    local_4c = local_74;
                    local_58 = PTR_DAT_00103814 + 8;
                    local_48 = local_70;
                    (**(code **)(**(int **)(param_1 + 0x1d4) + 0x94))
                              (*(int **)(param_1 + 0x1d4),&local_58,&local_6c);
                    NoteC_c_vslot_0(&local_58);
                    NoteC_c_vslot_0(&local_6c);
                    iVar3 = *(int *)(param_1 + 0x78c);
                    *(int *)(param_1 + 0x698 + iVar3 * 4) = (int)*(char *)(param_1 + 0x75c);
                    *(int *)(param_1 + 0x78c) = iVar3 + 1;
                    NoteC_c_vslot_0(&local_80);
                  }
                }
                *(float *)(*(int *)(param_1 + 0x1d4) + 0x31ec) = (float)bVar1 * 0.007874016;
              }
              fVar6 = *(float *)(param_1 + 0x140);
              lVar5 = (longdouble)
                      FUN_0001354c(param_1,*(undefined4 *)(*(int *)(param_1 + 0x124) + 0x158));
              fVar6 = fVar6 * (float)lVar5;
              if ((*(byte *)(param_1 + 0x794) & 1) == 0) {
                *(float *)(param_1 + 0x1e0) = (*(float *)(param_1 + 0x208) * 0.5 + 1.0) * fVar6;
              }
              else {
                *(float *)(param_1 + 0x1e0) = (*(float *)(param_1 + 0x208) * -0.5 + 1.0) * fVar6;
              }
              if (*(char *)(param_1 + 0x8a0) != '\0') {
                if ((ABS(*(float *)(param_1 + 0x89c)) < 0.001) &&
                   (!NAN(ABS(*(float *)(param_1 + 0x89c))))) {
                  lVar5 = (longdouble)
                          FUN_0001a176(*(undefined4 *)(param_1 + 0x1d8),
                                       *(undefined4 *)(*(int *)(param_1 + 0x1d4) + 0x1a4),
                                       *(undefined4 *)(*(int *)(param_1 + 0x124) + 0x158));
                  *(float *)(param_1 + 0x89c) = (float)lVar5;
                }
                fVar7 = *(float *)(param_1 + 0x1e0) + *(float *)(param_1 + 0x89c);
                *(float *)(param_1 + 0x1e0) = fVar7;
                if ((fVar7 < 0.0) && (!NAN(fVar7))) {
                  *(float *)(param_1 + 0x1e0) = fVar7 + fVar6;
                }
                *(undefined4 *)(param_1 + 0x89c) = 0;
              }
              iVar2 = (int)(*(float *)(param_1 + 0x1e0) * *(float *)(param_1 + 0x1f0) + 0.5);
              iVar3 = 1;
              if (0 < iVar2) {
                iVar3 = iVar2;
              }
              *(int *)(param_1 + 0x1e4) = iVar3;
              iVar3 = (int)(*(float *)(param_1 + 0x1e0) + 0.5) - iVar3;
              iVar2 = 0;
              if (-1 < iVar3) {
                iVar2 = iVar3;
              }
              *(int *)(param_1 + 0x1e8) = iVar2;
              *(undefined1 *)(param_1 + 0x8a0) = 0;
            }
          }
          iVar3 = *(int *)(param_1 + 0x778);
        }
        if (iVar3 < 0) {
          (**(code **)(**(int **)(param_1 + 0x1d4) + 0x9c))
                    (*(int **)(param_1 + 0x1d4),param_2,local_bc);
          return;
        }
        iVar2 = *(int *)(param_1 + 0x1e4);
        if (iVar3 < iVar2) {
          piVar4 = *(int **)(param_1 + 0x1d4);
          if (piVar4 != (int *)0x0) {
            if (local_bc + iVar3 < iVar2) goto LAB_000721f5;
            iVar2 = iVar2 - iVar3;
            if (0 < iVar2) {
              (**(code **)(*piVar4 + 0x9c))(piVar4,param_2,iVar2);
              iVar3 = *(int *)(param_1 + 0x778);
            }
            *(int *)(param_1 + 0x778) = iVar2 + iVar3;
            local_bc = local_bc - iVar2;
            if ((((*(char *)((*(int *)(param_1 + 0x794) + 1) % *(int *)(param_1 + 0x1ec) + 0x28c +
                            param_1) != -0x80) &&
                 (*(char *)(*(int *)(param_1 + 0x794) + 0x28c + param_1) != '\0')) &&
                (*(int *)(param_1 + 0x314) != 1)) && (*(int *)(param_1 + 0x1d4) != 0)) {
              if (0 < *(int *)(param_1 + 0x78c)) {
                local_a8 = 0;
                iVar3 = param_1;
                do {
                  for (iVar2 = *(int *)(iVar3 + 0x698) + *(int *)(param_1 + 0x310) * 0xc;
                      0x7f < iVar2; iVar2 = iVar2 + -0xc) {
                  }
                  for (; (local_8c = iVar2, iVar2 < 0 && (local_8c = iVar2 + 0xc, local_8c < 0));
                      iVar2 = iVar2 + 0x18) {
                  }
                  local_7c = 0;
                  local_80 = PTR_DAT_00103814 + 8;
                  if (local_8c < 0) {
                    local_8c = 0;
                  }
                  else if (0x7f < local_8c) {
                    local_8c = 0x7f;
                  }
                  local_88 = 0;
                  local_84 = 0;
                  local_90 = 0;
                  local_94 = PTR_DAT_00103814 + 8;
                  local_78 = local_8c;
                  local_74 = local_88;
                  local_70 = local_84;
                  (**(code **)(**(int **)(param_1 + 0x1d4) + 0x98))
                            (*(int **)(param_1 + 0x1d4),&local_94);
                  NoteC_c_vslot_0(&local_94);
                  NoteC_c_vslot_0(&local_80);
                  local_a8 = local_a8 + 1;
                  iVar3 = iVar3 + 4;
                } while (local_a8 < *(int *)(param_1 + 0x78c));
              }
              *(undefined4 *)(param_1 + 0x78c) = 0;
            }
          }
        }
        else {
          piVar4 = *(int **)(param_1 + 0x1d4);
          if (piVar4 != (int *)0x0) {
            iVar2 = iVar2 + *(int *)(param_1 + 0x1e8);
            if (local_bc + iVar3 < iVar2) {
LAB_000721f5:
              (**(code **)(*piVar4 + 0x9c))(piVar4,param_2,local_bc);
              *(int *)(param_1 + 0x778) = *(int *)(param_1 + 0x778) + local_bc;
              return;
            }
            iVar2 = iVar2 - iVar3;
            if (0 < iVar2) {
              (**(code **)(*piVar4 + 0x9c))(piVar4,param_2,iVar2);
              iVar3 = *(int *)(param_1 + 0x778);
            }
            *(int *)(param_1 + 0x778) = iVar2 + iVar3;
            local_bc = local_bc - iVar2;
            FUN_00071336(param_1);
          }
        }
      } while (local_bc != 0);
    }
  }
  return;
}

