/* 000351d6 WaveRAM2_c_vslot_30 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void WaveRAM2_c_vslot_30(int *param_1,int param_2,int param_3)

{
  float fVar1;
  byte bVar2;
  bool bVar3;
  bool bVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  longdouble lVar11;
  int local_2f0;
  int local_2dc;
  int local_2d0;
  int local_2c4;
  int local_2c0;
  int local_2bc;
  int local_2b8;
  int local_2b4;
  int local_2b0;
  char local_2a4 [320];
  char local_164 [320];
  int local_24;
  int local_20 [4];
  
  if (((param_1[0x48] != 0) && (-1 < param_2)) && (param_2 < 1)) {
    iVar6 = FUN_00011b72(param_1[0x48],param_2);
    param_1[0x49] = iVar6;
    if (iVar6 != 0) {
      local_2dc = 0;
      local_2c0 = 0x13;
      local_2bc = 0x19;
      local_2b8 = 0x15;
      local_2b4 = 0x14;
      local_2b0 = 0;
      local_2f0 = 0;
      do {
        iVar6 = local_2f0 + local_2dc + 0x1e0 + param_2 * 0x9d00 + (int)param_1;
        if (iVar6 == 0) {
          return;
        }
        iVar7 = local_2c0 + -10;
        if (((param_3 == -1) || (param_3 == iVar7)) || (iVar7 == -1)) {
          FUN_00012482(param_1[0x48],param_2,iVar7,local_164);
          cVar5 = FUN_0002ddaa(iVar6 + 0x1d4);
          FUN_000aecdc(iVar6);
          if (cVar5 != '\0') {
            FUN_0002ddc8(iVar6 + 0x1d4);
          }
          if (((char)param_1[0x77] == '\0') || (local_164[0] == '\0')) goto LAB_000352af;
          _strcpy(local_2a4,local_164);
          FUN_00010e34(local_2b0 + param_1[0x49] + 0x3f0,local_2a4);
          bVar2 = *(byte *)((int)param_1 + 0x1d7);
          *(byte *)((int)param_1 + 0x1d7) = param_3 != -1 & bVar2;
          FUN_000122c2(param_1[0x48],param_2,local_2b4);
          FUN_000122c2(param_1[0x48],param_2,local_2b8);
          cVar5 = FUN_0003400e(param_1,param_2,local_2dc,local_2a4);
          if (cVar5 == '\0') {
            FUN_0002e53a(param_1 + 0x286d,"File Error - Load failed",local_164);
          }
          else {
            (**(code **)(*param_1 + 0x78))(param_1,param_2,local_2c0);
          }
          *(byte *)((int)param_1 + 0x1d7) = bVar2;
          if (param_3 != -1) goto LAB_000352c8;
LAB_00035ac1:
          local_2d0 = local_2c0 + -8;
          iVar7 = FUN_000122c2(param_1[0x48],param_2,local_2d0);
          *(int *)(iVar6 + 0x23c) = iVar7;
          iVar9 = FUN_000122c2(param_1[0x48],param_2,5);
          if (iVar9 != 0) {
            piVar10 = param_1 + param_2 * 0x2740 + 0x78;
            iVar9 = 0xb;
            do {
              FUN_00012222(param_1[0x48],param_2,iVar9,iVar7);
              piVar10[0x8f] = iVar7;
              iVar9 = iVar9 + 0x14;
              piVar10 = piVar10 + 0x9d;
            } while (iVar9 != 0x50b);
          }
        }
        else {
LAB_000352af:
          if (param_3 == -1) goto LAB_00035ac1;
LAB_000352c8:
          if ((param_3 == local_2c0 + -8) || (local_2c0 + -8 == -1)) goto LAB_00035ac1;
        }
        local_2d0 = local_2c0 + -8;
        iVar7 = local_2c0 + -7;
        if (((param_3 == -1) || (param_3 == iVar7)) || (iVar7 == -1)) {
          iVar9 = FUN_000122c2(param_1[0x48],param_2,iVar7);
          if (iVar9 == 0x80) {
            if (*(char *)((int)param_1 + 0x1dd) == '\0') {
              FUN_00012222(param_1[0x48],param_2,iVar7,0x7f);
            }
            else {
              FUN_00012222(param_1[0x48],param_2,local_2d0,0);
            }
          }
          *(int *)(iVar6 + 0x240) = iVar9;
          if ((*(char *)((int)param_1 + 0x1dd) != '\0') && (iVar9 != 0x80)) {
            (**(code **)(*param_1 + 0x24))(param_1,param_2,local_2d0,iVar9);
          }
          iVar7 = FUN_000122c2(param_1[0x48],param_2,5);
          if (iVar7 != 0) {
            piVar10 = param_1 + param_2 * 0x2740 + 0x78;
            iVar7 = 0xc;
            do {
              FUN_00012222(param_1[0x48],param_2,iVar7,iVar9);
              piVar10[0x90] = iVar9;
              iVar7 = iVar7 + 0x14;
              piVar10 = piVar10 + 0x9d;
            } while (iVar7 != 0x50c);
          }
        }
        iVar7 = local_2c0 + -6;
        if (((param_3 == -1) || (param_3 == iVar7)) || (iVar7 == -1)) {
          uVar8 = FUN_000122c2(param_1[0x48],param_2,iVar7);
          *(undefined4 *)(iVar6 + 0x244) = uVar8;
        }
        iVar7 = local_2c0 + -5;
        if (((param_3 == -1) || (param_3 == iVar7)) || (iVar7 == -1)) {
          uVar8 = FUN_000122c2(param_1[0x48],param_2,iVar7);
          *(undefined4 *)(iVar6 + 0x248) = uVar8;
        }
        FUN_00034b94(param_1,param_2,param_3,local_2dc);
        iVar7 = local_2c0 + -2;
        if (((param_3 == -1) || (param_3 == iVar7)) || (iVar7 == -1)) {
          lVar11 = (longdouble)FUN_000123ec(param_1[0x48],param_2,iVar7);
          fVar1 = (float)lVar11;
          *(float *)(iVar6 + 0x25c) = fVar1;
          if ((fVar1 < -0.0001) && (!NAN(fVar1))) {
            *(undefined4 *)(iVar6 + 0x25c) = 0xb8d1b717;
          }
          if (*(float *)(iVar6 + 0x25c) <= 4.0) goto LAB_00035391;
          *(float *)(iVar6 + 0x25c) = 4.0;
          if (param_3 != -1) goto LAB_000353aa;
LAB_00035b7a:
          local_2c4 = local_2c0 + -4;
          local_20[0] = FUN_000122c2(param_1[0x48],param_2,local_2c4);
          if (param_3 != -1) {
            iVar7 = *(int *)(iVar6 + 0x22c) + -1;
            if (local_20[0] < 0) {
              local_20[0] = 0;
            }
            else if (iVar7 < local_20[0]) {
              local_20[0] = iVar7;
            }
            iVar7 = FUN_000122c2(param_1[0x48],param_2,local_2b4);
            if (local_20[0] < 0) {
              iVar7 = 0;
            }
            else if (local_20[0] <= iVar7) {
              iVar7 = local_20[0];
            }
            local_20[0] = iVar7;
            if ((0 < iVar7) &&
               (iVar7 = FUN_000122c2(param_1[0x48],param_2,local_2c0 + 7), iVar7 == 0)) {
              FUN_000b12ac(iVar6,(char)param_1[0x75],0,local_20);
            }
            local_2c4 = local_2c0 + -4;
            FUN_00012222(param_1[0x48],param_2,local_2c4,local_20[0]);
          }
          FUN_000af6ec(iVar6,local_20[0]);
        }
        else {
LAB_00035391:
          if (param_3 == -1) goto LAB_00035b7a;
LAB_000353aa:
          if ((param_3 == local_2c0 + -4) || (local_2c0 + -4 == -1)) goto LAB_00035b7a;
        }
        local_2c4 = local_2c0 + -4;
        if (((param_3 == -1) || (param_3 == local_2b4)) || (local_2b4 == -1)) {
          bVar4 = true;
        }
        else {
          bVar4 = false;
        }
        if (((param_3 == -1) || (param_3 == local_2b8)) || (local_2b8 == -1)) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
        if ((bVar4) || (bVar3)) {
          local_20[0] = FUN_000122c2(param_1[0x48],param_2,local_2b4);
          local_24 = FUN_000122c2(param_1[0x48],param_2,local_2b8);
          if (param_3 != -1) {
            iVar7 = *(int *)(iVar6 + 0x22c) + -1;
            if (local_20[0] < 0) {
              iVar7 = 0;
            }
            else if (local_20[0] <= iVar7) {
              iVar7 = local_20[0];
            }
            iVar9 = *(int *)(iVar6 + 0x22c) + -1;
            if (local_24 < 0) {
              local_24 = 0;
            }
            else if (iVar9 < local_24) {
              local_24 = iVar9;
            }
            local_20[0] = iVar7;
            iVar7 = FUN_000122c2(param_1[0x48],param_2,local_2c0 + 7);
            if (iVar7 == 0) {
              FUN_000b12ac(iVar6,(char)param_1[0x75],0,local_20);
              FUN_000b12ac(iVar6,(char)param_1[0x75],0,&local_24);
            }
            iVar7 = FUN_000122c2(param_1[0x48],param_2,local_2c4);
            if (iVar7 <= local_20[0]) {
              iVar7 = local_20[0];
            }
            local_20[0] = iVar7;
            if ((bVar4) && (local_24 < iVar7)) {
              local_20[0] = local_24;
            }
            iVar7 = local_20[0];
            if (local_20[0] <= local_24) {
              iVar7 = local_24;
            }
            local_24 = iVar7;
            FUN_00012222(param_1[0x48],param_2,local_2b4,local_20[0]);
            FUN_00012222(param_1[0x48],param_2,local_2b8,local_24);
          }
          *(int *)(iVar6 + 0x24c) = local_20[0];
          *(int *)(iVar6 + 0x250) = local_24;
        }
        if (((param_3 == -1) || (param_3 == local_2bc)) || (local_2bc == -1)) {
          iVar7 = FUN_000122c2(param_1[0x48],param_2,local_2bc);
          if (param_3 != -1) {
            iVar9 = *(int *)(iVar6 + 0x22c) + -1;
            if (iVar7 < 0) {
              iVar7 = 0;
            }
            else if (iVar9 < iVar7) {
              iVar7 = iVar9;
            }
            FUN_00012222(param_1[0x48],param_2,local_2bc,iVar7);
          }
          *(int *)(iVar6 + 0x254) = iVar7;
        }
        if (((param_3 == -1) || (param_3 == local_2c0)) || (local_2c0 == -1)) {
          cVar5 = FUN_0002ddaa(iVar6 + 0x1d4);
          if (cVar5 != '\0') {
            iVar7 = FUN_000122c2(param_1[0x48],param_2,local_2c0);
            FUN_000af164(iVar6,iVar7 != 0);
            FUN_0002ddc8(iVar6 + 0x1d4);
          }
        }
        local_2dc = local_2dc + 1;
        local_2f0 = local_2f0 + 0x273;
        local_2c0 = local_2c0 + 0x14;
        local_2bc = local_2bc + 0x14;
        local_2b8 = local_2b8 + 0x14;
        local_2b4 = local_2b4 + 0x14;
        local_2b0 = local_2b0 + 0x8c0;
      } while (local_2dc != 0x40);
      if ((0x17 < param_3) && (iVar6 = param_3 + -0x18, iVar6 == (iVar6 / 0x14) * 0x14)) {
        FUN_00012482(param_1[0x48],param_2,param_3,local_2a4);
        if (local_2a4[0] != '\0') {
          FUN_00010e34(iVar6 * 0x70 + param_1[0x49] + 0x3f0,local_2a4);
          (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3 + -0xf);
          (**(code **)(*param_1 + 0x78))(param_1,param_2,param_3 + -5);
        }
      }
    }
  }
  return;
}

