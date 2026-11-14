/* 0006b9e0 FUN_0006b9e0 */

void FUN_0006b9e0(int param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  long lVar6;
  undefined1 local_3a [38];
  uint local_14;
  int local_10;
  
  if (0 < param_2) {
    iVar2 = param_1 + 4;
    do {
      iVar3 = FUN_00009b22(iVar2,&local_10);
      param_2 = param_2 - iVar3;
      if (local_10 == 0x6e656769) {
LAB_0006bb61:
        iVar3 = FUN_0006b3da(param_1,param_3);
        param_2 = param_2 - iVar3;
      }
      else {
        if (local_10 < 0x6e65676a) {
          if (local_10 != 0x67616270) {
            if (local_10 < 0x67616271) {
              if (local_10 == 0x646f6d70) goto LAB_0006bb88;
              if (local_10 == 0x67616269) {
LAB_0006bdc1:
                iVar3 = FUN_0006b4e4(param_1,param_3);
                param_2 = param_2 - iVar3;
                goto joined_r0x0006bb7a;
              }
              if (local_10 != 0x646f6d69) goto LAB_0006ba64;
LAB_0006be09:
              FUN_00009b22(iVar2,&local_14);
              iVar3 = (int)local_14 / 10;
              if (iVar3 != 1 && -1 < iVar3 + -1) {
                iVar3 = iVar3 + -2;
                do {
                  FUN_00009b6e(iVar2,local_3a,10);
                  bVar1 = 0 < iVar3;
                  iVar3 = iVar3 + -1;
                } while (bVar1);
              }
              goto LAB_0006bbe8;
            }
            if (local_10 == 0x6967656e) goto LAB_0006bb61;
            if (local_10 < 0x6967656f) {
              if (local_10 == 0x69626167) goto LAB_0006bdc1;
            }
            else {
              if (local_10 == 0x696d6f64) goto LAB_0006be09;
              if (local_10 == 0x696e7374) {
LAB_0006bc9c:
                FUN_00009b22(iVar2,&local_14);
                iVar3 = (int)local_14 / 0x16;
                if (iVar3 != 1 && -1 < iVar3 + -1) {
                  iVar3 = iVar3 + -2;
                  do {
                    FUN_00009b6e(iVar2,local_3a,0x16);
                    bVar1 = 0 < iVar3;
                    iVar3 = iVar3 + -1;
                  } while (bVar1);
                }
                lVar6 = 0x16;
                goto LAB_0006bbf8;
              }
            }
            goto LAB_0006ba64;
          }
LAB_0006bc16:
          FUN_00009b22(iVar2,&local_14);
          uVar4 = local_14;
          if ((int)local_14 < 0) {
            uVar4 = local_14 + 3;
          }
          if ((int)uVar4 >> 2 != 0) {
            iVar3 = 0;
            do {
              FUN_00009b6e(iVar2,local_3a,4);
              iVar3 = iVar3 + 1;
            } while ((int)uVar4 >> 2 != iVar3);
          }
        }
        else {
          if (local_10 == 0x706d6f64) {
LAB_0006bb88:
            FUN_00009b22(iVar2,&local_14);
            iVar3 = (int)local_14 / 10;
            if (iVar3 != 1 && -1 < iVar3 + -1) {
              iVar3 = iVar3 + -2;
              do {
                FUN_00009b6e(iVar2,local_3a,10);
                bVar1 = 0 < iVar3;
                iVar3 = iVar3 + -1;
              } while (bVar1);
            }
LAB_0006bbe8:
            lVar6 = 10;
LAB_0006bbf8:
            _fseek(*(FILE **)(param_1 + 0xc),lVar6,1);
            param_2 = param_2 - (local_14 + 4);
            goto joined_r0x0006bb7a;
          }
          if (local_10 < 0x706d6f65) {
            if (local_10 == 0x70626167) goto LAB_0006bc16;
            if (local_10 < 0x70626168) {
              if (local_10 == 0x6e656770) goto LAB_0006bd48;
            }
            else {
              if (local_10 == 0x7067656e) {
LAB_0006bd48:
                FUN_00009b22(iVar2,&local_14);
                uVar4 = local_14 + 3;
                if (-1 < (int)local_14) {
                  uVar4 = local_14;
                }
                iVar3 = (int)uVar4 >> 2;
                if (iVar3 != 1 && -1 < iVar3 + -1) {
                  iVar3 = iVar3 + -2;
                  do {
                    FUN_00009b6e(iVar2,local_3a,4);
                    bVar1 = 0 < iVar3;
                    iVar3 = iVar3 + -1;
                  } while (bVar1);
                }
                lVar6 = 4;
                goto LAB_0006bbf8;
              }
              if (local_10 == 0x70686472) goto LAB_0006baef;
            }
            goto LAB_0006ba64;
          }
          if (local_10 == 0x72646873) {
LAB_0006bded:
            iVar3 = FUN_0006b6c0(param_1,param_3);
            param_2 = param_2 - iVar3;
            goto joined_r0x0006bb7a;
          }
          if (local_10 < 0x72646874) {
            if (local_10 != 0x72646870) goto LAB_0006ba64;
LAB_0006baef:
            FUN_00009b22(iVar2,&local_14);
            iVar3 = (int)local_14 / 0x26;
            if (iVar3 != 1) {
              iVar5 = 0;
              do {
                FUN_00009b6e(iVar2,local_3a,0x26);
                iVar5 = iVar5 + 1;
              } while (iVar3 + -1 != iVar5);
            }
            uVar4 = 0x26;
          }
          else {
            if (local_10 == 0x73686472) goto LAB_0006bded;
            if (local_10 == 0x74736e69) goto LAB_0006bc9c;
LAB_0006ba64:
            FUN_00009b22(iVar2,&local_14);
            uVar4 = local_14;
            if ((local_14 & 1) != 0) {
              uVar4 = local_14 + 1;
              local_14 = uVar4;
            }
          }
          _fseek(*(FILE **)(param_1 + 0xc),uVar4,1);
        }
        param_2 = param_2 - (local_14 + 4);
      }
joined_r0x0006bb7a:
    } while (0 < param_2);
  }
  return;
}

