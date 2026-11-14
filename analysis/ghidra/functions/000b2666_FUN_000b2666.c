/* 000b2666 FUN_000b2666 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool FUN_000b2666(int param_1,ushort *param_2,int param_3)

{
  ushort uVar1;
  undefined1 auVar2 [12];
  undefined1 auVar3 [12];
  undefined1 auVar4 [12];
  undefined1 auVar5 [12];
  int iVar6;
  int iVar7;
  uint uVar8;
  float fVar9;
  double dVar10;
  undefined1 auVar11 [16];
  undefined1 auVar12 [16];
  int local_24;
  uint local_20;
  
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
  *(undefined1 *)(param_1 + 0x230) = 0;
  *(undefined1 *)(param_1 + 0x231) = 0;
  *(undefined1 *)(param_1 + 0x232) = 0;
  *(undefined1 *)(param_1 + 600) = 0;
  *(undefined1 *)(param_1 + 0x260) = 0;
  *(undefined1 *)(param_1 + 0x233) = 0;
  *(undefined1 *)(param_1 + 0x234) = 0;
  iVar6 = FUN_00013124(param_1,param_3);
  *(int *)(param_1 + 0x21c) = iVar6;
  if (iVar6 != 0) {
    *(int *)(param_1 + 0x22c) = param_3;
    *(int *)(param_1 + 0x228) = param_3 * 2;
    *(undefined2 *)(param_1 + 0x216) = 1;
    *(undefined2 *)(param_1 + 0x21a) = 0x10;
    if (0 < param_3) {
      local_24 = 0;
      do {
        if (*(char *)(param_1 + 0x231) == '\0') {
          if (*(char *)(param_1 + 0x230) == '\0') {
            uVar1 = *param_2;
          }
          else {
            uVar1 = CONCAT11((char)*param_2,*(undefined1 *)((int)param_2 + 1));
          }
          if (uVar1 < 0x8000) {
            auVar12._0_12_ = ZEXT212(uVar1) << 0x40;
            auVar12._12_4_ = 0x43300000;
            dVar10 = ((auVar12._8_8_ - 4503599627370496.0) + 0.0) * 3.051850947599719e-05;
          }
          else {
            auVar11._0_12_ = ZEXT212(uVar1) << 0x40;
            auVar11._12_4_ = 0x43300000;
            dVar10 = (((auVar11._8_8_ - 4503599627370496.0) + 0.0) - 65536.0) * 3.0517578125e-05;
          }
          fVar9 = (float)dVar10;
        }
        else {
          if (*(char *)(param_1 + 0x230) == '\0') {
            uVar8 = 0;
            local_20 = 0x7f;
            iVar7 = 2;
            do {
              uVar8 = uVar8 * 0x100 + (uint)*(byte *)(iVar7 + -1 + (int)param_2);
              if (1 < iVar7) {
                local_20 = local_20 * 0x100 + 0xff;
              }
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
          else {
            uVar8 = 0;
            local_20 = 0x7f;
            iVar7 = 2;
            do {
              uVar8 = uVar8 * 0x100 + (uint)*(byte *)((int)param_2 + (2 - iVar7));
              if (1 < iVar7) {
                local_20 = local_20 * 0x100 + 0xff;
              }
              iVar7 = iVar7 + -1;
            } while (iVar7 != 0);
          }
          if (local_20 < uVar8) {
            auVar2._4_4_ = local_20;
            auVar2._0_4_ = local_20;
            auVar2._8_4_ = 0x43300000;
            dVar10 = (auVar2._4_8_ - 4503599627370496.0) + 0.0 + 1.0;
            auVar3._4_4_ = uVar8;
            auVar3._0_4_ = uVar8;
            auVar3._8_4_ = 0x43300000;
            fVar9 = (float)((dVar10 * -2.0 + (auVar3._4_8_ - 4503599627370496.0) + 0.0) / dVar10);
          }
          else {
            auVar4._4_4_ = uVar8;
            auVar4._0_4_ = uVar8;
            auVar4._8_4_ = 0x43300000;
            auVar5._4_4_ = local_20;
            auVar5._0_4_ = local_20;
            auVar5._8_4_ = 0x43300000;
            fVar9 = (float)(((auVar4._4_8_ - 4503599627370496.0) + 0.0) /
                           ((auVar5._4_8_ - 4503599627370496.0) + 0.0));
          }
        }
        *(float *)(*(int *)(param_1 + 0x21c) + local_24 * 4) = fVar9;
        local_24 = local_24 + 1;
        param_2 = param_2 + 1;
      } while (param_3 != local_24);
    }
  }
  return iVar6 != 0;
}

