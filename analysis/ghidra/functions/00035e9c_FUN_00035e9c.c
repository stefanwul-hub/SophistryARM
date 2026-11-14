/* 00035e9c FUN_00035e9c */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_00035e9c(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  longdouble lVar9;
  float fVar10;
  float fVar11;
  int local_38;
  uint local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  
  if (*(int *)(param_1 + 0x120) != 0) {
    iVar3 = FUN_00011b72(*(int *)(param_1 + 0x120),param_2);
    *(int *)(param_1 + 0x124) = iVar3;
    if (iVar3 != 0) {
      local_38 = 0;
      iVar3 = param_2 * 0x40 + param_1;
      uVar8 = 0;
      do {
        iVar4 = uVar8 * 0x274 + 0x1e0 + param_2 * 0x9d00 + param_1;
        local_30 = uVar8 + 1;
        iVar5 = *(int *)(param_1 + 0x124);
        iVar2 = uVar8 * 0x8c0;
        iVar6 = iVar5 + iVar2;
        if (((((*(int *)(iVar6 + 0x4d8) <= *(int *)(param_3 + 8)) &&
              (*(int *)(param_3 + 8) <= *(int *)(iVar6 + 0x548))) &&
             (*(int *)(iVar6 + 0x5b8) <= *(int *)(param_3 + 0xc))) &&
            ((*(int *)(param_3 + 0xc) <= *(int *)(iVar6 + 0x628) && (*(int *)(iVar4 + 0x21c) != 0)))
            ) && (local_38 < param_5)) {
          if (((iVar5 != 0) && ((int)uVar8 < 0x3f)) && (*(char *)(iVar6 + 0x14ac) != '\0')) {
            iVar6 = local_30 * 0x8c0 + iVar5;
            if (*(char *)(iVar6 + 0xbec) == '\0') {
              local_2c = 1;
            }
            else {
              pcVar7 = (char *)(iVar6 + 0x14ac);
              local_2c = 1;
              do {
                local_2c = local_2c + 1;
                cVar1 = *pcVar7;
                pcVar7 = pcVar7 + 0x8c0;
              } while (cVar1 != '\0');
              local_30 = local_2c + uVar8;
            }
            iVar6 = *(int *)(iVar5 + 0x233f8);
            if (iVar6 == 2) {
              iVar6 = FUN_0002e30a();
              local_28 = uVar8 + iVar6 % local_2c;
            }
            else if (iVar6 == 3) {
              do {
                iVar6 = FUN_0002e30a();
                local_28 = uVar8 + iVar6 % local_2c;
              } while (local_28 == *(byte *)(iVar3 + 0x9ee0 + uVar8));
            }
            else if ((iVar6 == 1) &&
                    (local_28 = *(byte *)(iVar3 + 0x9ee0 + uVar8) + 1,
                    (int)local_30 <= (int)local_28)) {
              local_28 = uVar8;
            }
            *(undefined1 *)(iVar3 + 0x9ee0 + uVar8) = (undefined1)local_28;
          }
          *(int *)(param_4 + local_38 * 4) = iVar4;
          local_38 = local_38 + 1;
          lVar9 = (longdouble)
                  _pow(0,0x40000000,
                       (double)*(int *)(iVar2 + 0x468 + *(int *)(param_1 + 0x124)) / 12.0);
          *(float *)(iVar4 + 0x238) = (float)((double)lVar9 * 8.175798915643707);
          lVar9 = (longdouble)
                  FUN_000152c0((float)*(int *)(iVar4 + 0x210),
                               (float)((double)lVar9 * 8.175798915643707));
          *(float *)(iVar4 + 0x224) = (float)lVar9;
          *(undefined4 *)(iVar4 + 0x25c) =
               *(undefined4 *)(iVar2 + 0x788 + *(int *)(param_1 + 0x124));
        }
        uVar8 = local_30;
      } while ((int)local_30 < 0x40);
      *(undefined4 *)(param_4 + local_38 * 4) = 0;
      if (1 < local_38) {
        iVar3 = 1;
        local_20 = 0x7f;
        iVar6 = 0;
        do {
          iVar5 = *(int *)(param_4 + iVar6 * 4);
          iVar2 = *(int *)(iVar5 + 0x244);
          if (iVar3 < iVar2) {
            iVar3 = iVar2;
          }
          iVar5 = *(int *)(iVar5 + 0x248);
          if (local_20 < iVar5) {
            iVar5 = local_20;
          }
          iVar6 = iVar6 + 1;
          local_20 = iVar5;
        } while (iVar6 != local_38);
        if (iVar3 < iVar5) {
          fVar11 = (float)((*(int *)(param_3 + 0xc) - iVar3) + 1) / (float)((iVar5 - iVar3) + 2);
        }
        else {
          fVar11 = 1.0;
        }
        local_24 = 0;
        do {
          iVar6 = *(int *)(param_4 + local_24 * 4);
          iVar2 = *(int *)(iVar6 + 0x208);
          if ((*(int *)(iVar6 + 0x244) == iVar3) && (iVar5 < *(int *)(iVar6 + 0x248))) {
            fVar10 = fVar11 * *(float *)(iVar2 * 0x8c0 + *(int *)(param_1 + 0x124) + 0x788);
LAB_000360bb:
            *(float *)(iVar6 + 0x25c) = fVar10;
            fVar10 = (float)(~-(uint)(-0.0001 <= fVar10) & (uint)-0.0001 |
                            (uint)fVar10 & -(uint)(-0.0001 <= fVar10));
            *(float *)(iVar6 + 0x25c) = fVar10;
            if (4.0 < fVar10) {
              *(undefined4 *)(iVar6 + 0x25c) = 0x40800000;
            }
          }
          else {
            if ((*(int *)(iVar6 + 0x248) == iVar5) && (*(int *)(iVar6 + 0x244) < iVar3)) {
              fVar10 = (1.0 - fVar11) *
                       *(float *)(iVar2 * 0x8c0 + *(int *)(param_1 + 0x124) + 0x788);
              goto LAB_000360bb;
            }
            *(undefined4 *)(iVar6 + 0x25c) =
                 *(undefined4 *)(iVar2 * 0x8c0 + *(int *)(param_1 + 0x124) + 0x788);
          }
          if (*(float *)(iVar6 + 0x25c) <= -0.0001 && *(float *)(iVar6 + 0x25c) != -0.0001) {
            *(undefined4 *)(iVar6 + 0x25c) = 0xb8d1b717;
          }
          if (4.0 < *(float *)(iVar6 + 0x25c)) {
            *(undefined4 *)(iVar6 + 0x25c) = 0x40800000;
          }
          local_24 = local_24 + 1;
        } while (local_24 != local_38);
      }
    }
  }
  return;
}

