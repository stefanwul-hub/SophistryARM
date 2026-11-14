/* 00021f2e FUN_00021f2e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00021f2e(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  undefined1 uVar7;
  undefined4 uVar8;
  int *piVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  longdouble lVar16;
  longdouble lVar17;
  float fVar18;
  float fVar19;
  double dVar20;
  int *local_140;
  int local_dc;
  float local_bc;
  int local_90;
  float local_70;
  undefined1 local_64 [4];
  int local_60;
  int local_5c;
  undefined4 local_48;
  int *local_44;
  int local_40;
  int *local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int *local_30;
  undefined4 local_2c;
  float local_28;
  int local_24;
  int local_20 [4];
  
  local_40 = 0;
  if (-1 < param_1[0xed2]) {
    local_2c = 0xffffffff;
    piVar1 = param_1 + 0x1e1;
LAB_00021fab:
    cVar6 = FUN_0008c680(piVar1,param_2,param_3,param_4,&local_2c,local_20,&local_24,&local_40,
                         &local_28);
    if (cVar6 != '\0') {
      (**(code **)(*param_1 + 0x39c))(param_1,local_24);
      if (local_40 != 0) {
        FUN_0001cb52(param_1,local_24,&local_30,&local_34,&local_38);
        if (local_30 == (int *)0x0) {
          return;
        }
        if (local_40 == 1) {
          lVar16 = (longdouble)FUN_0008c3ec(piVar1,local_2c,param_4);
          iVar5 = local_20[0];
          iVar4 = local_24;
          piVar15 = local_30;
          uVar8 = local_34;
          iVar12 = local_20[0] * 4;
          if ((*(int *)(param_1[0x33a9] + iVar12) != 0) && ((char)param_1[0x33f1] != '\0')) {
            iVar10 = param_1[0xed7];
            if ((iVar10 < 0) || (param_1[0x33ec] < 1)) {
LAB_00022604:
              iVar10 = _OSAtomicAdd32Barrier(1,param_1 + 0x26f4);
              if (iVar10 == 1) {
                uVar7 = FUN_0002ddaa(*(int *)(iVar12 + param_1[0x33a9]) + 0xe84);
                *(undefined1 *)(param_1 + 0x26f5) = uVar7;
              }
              (**(code **)(*piVar15 + 0x1c))(piVar15,iVar5,uVar8,(float)lVar16);
              bVar3 = true;
              while ((((param_1[0x22af] != 0 && (-1 < iVar4)) && (iVar4 < param_1[0x2692])) &&
                     (piVar11 = (int *)(param_1[0x22af] + iVar4 * 0x20), iVar4 == *piVar11))) {
                if (bVar3) {
                  if (0 < param_1[0xee2]) {
                    iVar10 = 0;
                    piVar9 = param_1;
                    do {
                      if (((int *)piVar9[0x1447] != (int *)0x0) &&
                         (piVar11[5] == *(int *)piVar9[0x1447])) goto LAB_00022701;
                      iVar10 = iVar10 + 1;
                      piVar9 = piVar9 + 7;
                    } while (param_1[0xee2] != iVar10);
                  }
                  iVar10 = -1;
LAB_00022701:
                  param_1[0x2699] = iVar10;
                  param_1[0x269a] = 0;
                }
                else {
                  iVar10 = param_1[0x2699];
                }
                if ((iVar10 < 0) ||
                   (iVar13 = param_1[0x269a], param_1[iVar10 * 7 + 0x144b] <= iVar13)) break;
                iVar14 = param_1[iVar10 * 7 + 0x1447];
                while( true ) {
                  if ((iVar14 == 0) ||
                     (piVar11 = *(int **)(iVar14 + iVar13 * 4), piVar11 == (int *)0x0))
                  goto LAB_000227b8;
                  iVar14 = piVar11[0x4a];
                  iVar13 = iVar13 + 1;
                  param_1[0x269a] = iVar13;
                  if (iVar5 == iVar14) break;
                  if (param_1[iVar10 * 7 + 0x144b] <= iVar13) goto LAB_000227b8;
                  iVar14 = param_1[iVar10 * 7 + 0x1447];
                }
                if (iVar5 != iVar14) break;
                (**(code **)(*piVar11 + 0x7c))(piVar11,uVar8);
                bVar3 = false;
              }
LAB_000227b8:
              (**(code **)(*param_1 + 0x364))(param_1,iVar5,piVar15,uVar8);
              iVar10 = _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0x26f4);
              if ((iVar10 == 0) && ((char)param_1[0x26f5] != '\0')) {
                FUN_0002ddc8(*(int *)(iVar12 + param_1[0x33a9]) + 0xe84);
              }
              (**(code **)(*param_1 + 0x34c))(param_1,iVar4,0);
              (**(code **)(*param_1 + 0x354))(param_1,1);
            }
            else if (local_24 != iVar10) {
              iVar13 = 0;
              do {
                iVar13 = iVar13 + 1;
                if (param_1[0x33ec] == iVar13) goto LAB_00022604;
              } while (param_1[0xed9] * iVar13 + iVar10 != local_24);
            }
          }
          if (0 < param_1[0x24b1]) {
            local_dc = 0;
            piVar15 = param_1;
            do {
              if (iVar4 == piVar15[0x22b1]) {
                FUN_0001cb52(param_1,piVar15[0x22b2],&local_3c,&local_48,&local_44);
                piVar11 = local_3c;
                uVar8 = local_48;
                if (local_3c == (int *)0x0) break;
                iVar10 = piVar15[0x22b2];
                if ((*(int *)(iVar12 + param_1[0x33a9]) != 0) && ((char)param_1[0x33f1] != '\0')) {
                  iVar13 = param_1[0xed7];
                  if ((iVar13 < 0) || (param_1[0x33ec] < 1)) {
LAB_0002293a:
                    iVar13 = _OSAtomicAdd32Barrier(1,param_1 + 0x26f4);
                    if (iVar13 == 1) {
                      uVar7 = FUN_0002ddaa(*(int *)(iVar12 + param_1[0x33a9]) + 0xe84);
                      *(undefined1 *)(param_1 + 0x26f5) = uVar7;
                    }
                    (**(code **)(*piVar11 + 0x1c))(piVar11,iVar5,uVar8,(float)lVar16);
                    bVar3 = true;
                    while ((((param_1[0x22af] != 0 && (-1 < iVar10)) && (iVar10 < param_1[0x2692]))
                           && (piVar9 = (int *)(param_1[0x22af] + iVar10 * 0x20), iVar10 == *piVar9)
                           )) {
                      if (bVar3) {
                        if (0 < param_1[0xee2]) {
                          local_140 = param_1;
                          iVar13 = 0;
                          do {
                            if (((int *)local_140[0x1447] != (int *)0x0) &&
                               (piVar9[5] == *(int *)local_140[0x1447])) goto LAB_00022a45;
                            iVar13 = iVar13 + 1;
                            local_140 = local_140 + 7;
                          } while (iVar13 != param_1[0xee2]);
                        }
                        iVar13 = -1;
LAB_00022a45:
                        param_1[0x2699] = iVar13;
                        param_1[0x269a] = 0;
                      }
                      iVar13 = param_1[0x2699];
                      if ((iVar13 < 0) ||
                         (iVar14 = param_1[0x269a], param_1[iVar13 * 7 + 0x144b] <= iVar14)) break;
                      iVar2 = param_1[iVar13 * 7 + 0x1447];
                      while( true ) {
                        if ((iVar2 == 0) ||
                           (piVar9 = *(int **)(iVar2 + iVar14 * 4), piVar9 == (int *)0x0))
                        goto LAB_00022b13;
                        iVar2 = piVar9[0x4a];
                        iVar14 = iVar14 + 1;
                        param_1[0x269a] = iVar14;
                        if (iVar5 == iVar2) break;
                        if (param_1[iVar13 * 7 + 0x144b] <= iVar14) goto LAB_00022b13;
                        iVar2 = param_1[iVar13 * 7 + 0x1447];
                      }
                      if (iVar5 != iVar2) break;
                      (**(code **)(*piVar9 + 0x7c))(piVar9,uVar8);
                      bVar3 = false;
                    }
LAB_00022b13:
                    (**(code **)(*param_1 + 0x364))(param_1,iVar5,piVar11,uVar8);
                    iVar13 = _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0x26f4);
                    if ((iVar13 == 0) && ((char)param_1[0x26f5] != '\0')) {
                      FUN_0002ddc8(*(int *)(iVar12 + param_1[0x33a9]) + 0xe84);
                    }
                    (**(code **)(*param_1 + 0x34c))(param_1,iVar10,0);
                    (**(code **)(*param_1 + 0x354))(param_1,1);
                  }
                  else if (iVar10 != iVar13) {
                    iVar14 = 0;
                    do {
                      iVar14 = iVar14 + 1;
                      iVar13 = iVar13 + param_1[0xed9];
                      if (param_1[0x33ec] == iVar14) goto LAB_0002293a;
                    } while (iVar10 != iVar13);
                  }
                }
              }
              local_dc = local_dc + 1;
              piVar15 = piVar15 + 2;
            } while (local_dc < param_1[0x24b1]);
          }
        }
        else if (local_40 - 2U < 2) {
          (**(code **)(*local_30 + 0x5c))(local_30,local_38,local_34,local_64);
          local_bc = (float)(local_5c - local_60);
          if ((1.0 <= local_bc) || (NAN(local_bc))) {
            if (local_bc <= 512.0) {
              dVar20 = (double)(local_5c - local_60);
              local_bc = 1.00001 / local_bc;
            }
            else {
              dVar20 = 512.0;
              local_bc = 0.0019531446;
            }
          }
          else {
            dVar20 = 1.0;
            local_bc = 1.00001;
          }
          fVar18 = (float)((1.00001 / dVar20) * (1.0 - (double)local_28) + (double)local_28 * 0.05);
          if ((local_bc <= fVar18) && (local_bc = 1.0, fVar18 <= 1.0)) {
            local_bc = fVar18;
          }
          lVar16 = (longdouble)(**(code **)(*param_1 + 0x2b4))(param_1,local_24);
          if (local_40 == 2) {
            uVar8 = 1;
            local_70 = 1.0;
          }
          else {
            uVar8 = 0xffffffff;
            local_70 = -1.0;
          }
          lVar17 = (longdouble)FUN_0001dbe0(param_1,local_24,(float)lVar16,uVar8);
          fVar18 = ABS((float)lVar17);
          if (ABS((float)lVar17) <= local_bc) {
            fVar18 = local_bc;
          }
          fVar18 = fVar18 * local_70 + (float)lVar16;
          if ((0.0 <= fVar18) || (NAN(fVar18))) {
            fVar19 = 1.0;
            if (fVar18 <= 1.0) {
              fVar19 = fVar18;
            }
          }
          else {
            fVar19 = 0.0;
          }
          lVar16 = (longdouble)FUN_0008be50(piVar1,local_2c,fVar19);
          iVar5 = local_20[0];
          iVar4 = local_24;
          piVar15 = local_30;
          uVar8 = local_34;
          iVar12 = local_20[0] * 4;
          if ((*(int *)(param_1[0x33a9] + iVar12) != 0) && ((char)param_1[0x33f1] != '\0')) {
            iVar10 = param_1[0xed7];
            if ((iVar10 < 0) || (param_1[0x33ec] < 1)) {
LAB_00022c61:
              iVar10 = _OSAtomicAdd32Barrier(1,param_1 + 0x26f4);
              if (iVar10 == 1) {
                uVar7 = FUN_0002ddaa(*(int *)(iVar12 + param_1[0x33a9]) + 0xe84);
                *(undefined1 *)(param_1 + 0x26f5) = uVar7;
              }
              (**(code **)(*piVar15 + 0x1c))(piVar15,iVar5,uVar8,(float)lVar16);
              bVar3 = true;
              while ((((param_1[0x22af] != 0 && (-1 < iVar4)) && (iVar4 < param_1[0x2692])) &&
                     (piVar11 = (int *)(param_1[0x22af] + iVar4 * 0x20), iVar4 == *piVar11))) {
                if (bVar3) {
                  if (0 < param_1[0xee2]) {
                    iVar10 = 0;
                    piVar9 = param_1;
                    do {
                      if (((int *)piVar9[0x1447] != (int *)0x0) &&
                         (piVar11[5] == *(int *)piVar9[0x1447])) goto LAB_00022d51;
                      iVar10 = iVar10 + 1;
                      piVar9 = piVar9 + 7;
                    } while (param_1[0xee2] != iVar10);
                  }
                  iVar10 = -1;
LAB_00022d51:
                  param_1[0x2699] = iVar10;
                  param_1[0x269a] = 0;
                }
                iVar10 = param_1[0x2699];
                if ((iVar10 < 0) ||
                   (iVar13 = param_1[0x269a], param_1[iVar10 * 7 + 0x144b] <= iVar13)) break;
                iVar14 = param_1[iVar10 * 7 + 0x1447];
                while( true ) {
                  if ((iVar14 == 0) ||
                     (piVar11 = *(int **)(iVar14 + iVar13 * 4), piVar11 == (int *)0x0))
                  goto LAB_00022e09;
                  iVar14 = piVar11[0x4a];
                  iVar13 = iVar13 + 1;
                  param_1[0x269a] = iVar13;
                  if (iVar5 == iVar14) break;
                  if (param_1[iVar10 * 7 + 0x144b] <= iVar13) goto LAB_00022e09;
                  iVar14 = param_1[iVar10 * 7 + 0x1447];
                }
                if (iVar5 != iVar14) break;
                (**(code **)(*piVar11 + 0x7c))(piVar11,uVar8);
                bVar3 = false;
              }
LAB_00022e09:
              (**(code **)(*param_1 + 0x364))(param_1,iVar5,piVar15,uVar8);
              iVar10 = _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0x26f4);
              if ((iVar10 == 0) && ((char)param_1[0x26f5] != '\0')) {
                FUN_0002ddc8(*(int *)(iVar12 + param_1[0x33a9]) + 0xe84);
              }
              (**(code **)(*param_1 + 0x34c))(param_1,iVar4,0);
              (**(code **)(*param_1 + 0x354))(param_1,1);
            }
            else if (local_24 != iVar10) {
              iVar13 = 0;
              do {
                iVar13 = iVar13 + 1;
                if (param_1[0x33ec] == iVar13) goto LAB_00022c61;
              } while (local_24 != iVar10 + param_1[0xed9] * iVar13);
            }
          }
          if (0 < param_1[0x24b1]) {
            local_90 = 0;
            piVar15 = param_1;
            do {
              if (iVar4 == piVar15[0x22b1]) {
                FUN_0001cb52(param_1,piVar15[0x22b2],&local_44,&local_48,&local_3c);
                piVar11 = local_44;
                uVar8 = local_48;
                if (local_44 == (int *)0x0) break;
                iVar10 = piVar15[0x22b2];
                if ((*(int *)(iVar12 + param_1[0x33a9]) != 0) && ((char)param_1[0x33f1] != '\0')) {
                  iVar13 = param_1[0xed7];
                  if ((iVar13 < 0) || (param_1[0x33ec] < 1)) {
LAB_00022325:
                    iVar13 = _OSAtomicAdd32Barrier(1,param_1 + 0x26f4);
                    if (iVar13 == 1) {
                      uVar7 = FUN_0002ddaa(*(int *)(iVar12 + param_1[0x33a9]) + 0xe84);
                      *(undefined1 *)(param_1 + 0x26f5) = uVar7;
                    }
                    (**(code **)(*piVar11 + 0x1c))(piVar11,iVar5,uVar8,(float)lVar16);
                    bVar3 = true;
                    while ((((param_1[0x22af] != 0 && (-1 < iVar10)) && (iVar10 < param_1[0x2692]))
                           && (piVar9 = (int *)(param_1[0x22af] + iVar10 * 0x20), iVar10 == *piVar9)
                           )) {
                      if (bVar3) {
                        if (0 < param_1[0xee2]) {
                          local_140 = param_1;
                          iVar13 = 0;
                          do {
                            if (((int *)local_140[0x1447] != (int *)0x0) &&
                               (piVar9[5] == *(int *)local_140[0x1447])) goto LAB_0002240e;
                            iVar13 = iVar13 + 1;
                            local_140 = local_140 + 7;
                          } while (iVar13 != param_1[0xee2]);
                        }
                        iVar13 = -1;
LAB_0002240e:
                        param_1[0x2699] = iVar13;
                        param_1[0x269a] = 0;
                      }
                      iVar13 = param_1[0x2699];
                      if ((iVar13 < 0) ||
                         (iVar14 = param_1[0x269a], param_1[iVar13 * 7 + 0x144b] <= iVar14)) break;
                      iVar2 = param_1[iVar13 * 7 + 0x1447];
                      while( true ) {
                        if ((iVar2 == 0) ||
                           (piVar9 = *(int **)(iVar2 + iVar14 * 4), piVar9 == (int *)0x0))
                        goto LAB_000224db;
                        iVar2 = piVar9[0x4a];
                        iVar14 = iVar14 + 1;
                        param_1[0x269a] = iVar14;
                        if (iVar5 == iVar2) break;
                        if (param_1[iVar13 * 7 + 0x144b] <= iVar14) goto LAB_000224db;
                        iVar2 = param_1[iVar13 * 7 + 0x1447];
                      }
                      if (iVar5 != iVar2) break;
                      (**(code **)(*piVar9 + 0x7c))(piVar9,uVar8);
                      bVar3 = false;
                    }
LAB_000224db:
                    (**(code **)(*param_1 + 0x364))(param_1,iVar5,piVar11,uVar8);
                    iVar13 = _OSAtomicAdd32Barrier(0xffffffff,param_1 + 0x26f4);
                    if ((iVar13 == 0) && ((char)param_1[0x26f5] != '\0')) {
                      FUN_0002ddc8(*(int *)(iVar12 + param_1[0x33a9]) + 0xe84);
                    }
                    (**(code **)(*param_1 + 0x34c))(param_1,iVar10,0);
                    (**(code **)(*param_1 + 0x354))(param_1,1);
                  }
                  else if (iVar10 != iVar13) {
                    iVar14 = 0;
                    do {
                      iVar14 = iVar14 + 1;
                      iVar13 = iVar13 + param_1[0xed9];
                      if (iVar14 == param_1[0x33ec]) goto LAB_00022325;
                    } while (iVar10 != iVar13);
                  }
                }
              }
              local_90 = local_90 + 1;
              piVar15 = piVar15 + 2;
            } while (local_90 < param_1[0x24b1]);
          }
        }
      }
      goto LAB_00021fab;
    }
  }
  return;
}

