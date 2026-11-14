/* 0008f402 FUN_0008f402 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_0008f402(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  float fVar6;
  float fVar7;
  
  if (0 < (int)param_2) {
    uVar5 = 0;
    iVar4 = param_2 + 1;
    do {
      iVar1 = param_2 - uVar5;
      uVar2 = uVar5 & 7;
      uVar5 = uVar5 + 1;
      if (uVar2 == 0) {
        param_1[0x261] = (int)((float)param_1[0x261] + (float)param_1[0x262]);
        param_1[0x263] = param_1[0x263] + -1;
        iVar3 = 0;
        if (iVar4 + -2 < 7) {
          iVar3 = 7 - (iVar4 + -2);
        }
        iVar3 = iVar3 + param_1[0x4f];
        param_1[0x4f] = iVar3;
        if (8 < iVar3) {
          param_1[0x261] = (int)((float)param_1[0x261] - (float)param_1[0x262]);
          param_1[0x263] = param_1[0x263] + 1;
          param_1[0x4f] = iVar3 + -8;
        }
        if (param_1[0x263] < 1) {
          LFOSimp_c_vslot_57(param_1 + 0x78);
        }
        param_1[0x280] =
             (int)(((float)param_1[0x286] * (float)param_1[0x261] + 1.0) * (float)param_1[0x287] *
                  (float)param_1[0x52]);
        if ((float)param_1[0x262] <= 0.0 && (float)param_1[0x262] != 0.0) {
          fVar7 = (float)param_1[0x261] * -0.25 + 0.5;
        }
        else {
          fVar7 = (float)param_1[0x261] * 0.25 + 1.0;
        }
        fVar7 = (float)param_1[0x283] * 0.5 + fVar7;
        if (1.0 < fVar7) {
          fVar7 = fVar7 - 1.0;
        }
        fVar7 = fVar7 * 4.0;
        if (3.0 < fVar7) {
          fVar7 = fVar7 - 4.0;
        }
        else if (1.0 < fVar7) {
          fVar7 = 2.0 - fVar7;
        }
        param_1[0x281] =
             (int)((fVar7 * (float)param_1[0x286] + 1.0) * (float)param_1[0x287] *
                  (float)param_1[0x52]);
      }
      param_1[0x26c] = (int)(*(float *)param_1[0x264] * 0.05);
      param_1[0x264] = (int)((float *)param_1[0x264] + 1);
      param_1[0x26d] = (int)(*(float *)param_1[0x265] * 0.05);
      param_1[0x265] = (int)((float *)param_1[0x265] + 1);
      fVar7 = ((float)param_1[0x288] * (float)param_1[0x268] + (float)param_1[0x26c]) -
              (float)param_1[0x26e];
      param_1[0x26a] = (int)fVar7;
      fVar6 = fVar7 * (float)param_1[0x280] + (float)param_1[0x26e];
      param_1[0x26e] = (int)fVar6;
      fVar7 = ((float)param_1[0x288] * (float)param_1[0x269] + (float)param_1[0x26d]) -
              (float)param_1[0x277];
      param_1[0x26b] = (int)fVar7;
      fVar7 = fVar7 * (float)param_1[0x281] + (float)param_1[0x277];
      param_1[0x277] = (int)fVar7;
      fVar6 = (fVar6 - (float)param_1[0x26a]) - (float)param_1[0x26f];
      param_1[0x26a] = (int)fVar6;
      fVar6 = fVar6 * (float)param_1[0x280] + (float)param_1[0x26f];
      param_1[0x26f] = (int)fVar6;
      fVar7 = (fVar7 - (float)param_1[0x26b]) - (float)param_1[0x278];
      param_1[0x26b] = (int)fVar7;
      fVar7 = fVar7 * (float)param_1[0x281] + (float)param_1[0x278];
      param_1[0x278] = (int)fVar7;
      fVar6 = (fVar6 - (float)param_1[0x26a]) - (float)param_1[0x270];
      param_1[0x26a] = (int)fVar6;
      fVar6 = fVar6 * (float)param_1[0x280] + (float)param_1[0x270];
      param_1[0x270] = (int)fVar6;
      fVar7 = (fVar7 - (float)param_1[0x26b]) - (float)param_1[0x279];
      param_1[0x26b] = (int)fVar7;
      fVar7 = fVar7 * (float)param_1[0x281] + (float)param_1[0x279];
      param_1[0x279] = (int)fVar7;
      fVar6 = (fVar6 - (float)param_1[0x26a]) - (float)param_1[0x271];
      param_1[0x26a] = (int)fVar6;
      fVar6 = fVar6 * (float)param_1[0x280] + (float)param_1[0x271];
      param_1[0x271] = (int)fVar6;
      fVar7 = (fVar7 - (float)param_1[0x26b]) - (float)param_1[0x27a];
      param_1[0x26b] = (int)fVar7;
      fVar7 = fVar7 * (float)param_1[0x281] + (float)param_1[0x27a];
      param_1[0x27a] = (int)fVar7;
      fVar6 = (fVar6 - (float)param_1[0x26a]) - (float)param_1[0x272];
      param_1[0x26a] = (int)fVar6;
      fVar6 = fVar6 * (float)param_1[0x280] + (float)param_1[0x272];
      param_1[0x272] = (int)fVar6;
      fVar7 = (fVar7 - (float)param_1[0x26b]) - (float)param_1[0x27b];
      param_1[0x26b] = (int)fVar7;
      fVar7 = fVar7 * (float)param_1[0x281] + (float)param_1[0x27b];
      param_1[0x27b] = (int)fVar7;
      fVar6 = (fVar6 - (float)param_1[0x26a]) - (float)param_1[0x273];
      param_1[0x26a] = (int)fVar6;
      fVar6 = fVar6 * (float)param_1[0x280] + (float)param_1[0x273];
      param_1[0x273] = (int)fVar6;
      fVar7 = (fVar7 - (float)param_1[0x26b]) - (float)param_1[0x27c];
      param_1[0x26b] = (int)fVar7;
      fVar7 = fVar7 * (float)param_1[0x281] + (float)param_1[0x27c];
      param_1[0x27c] = (int)fVar7;
      fVar6 = (fVar6 - (float)param_1[0x26a]) - (float)param_1[0x274];
      param_1[0x26a] = (int)fVar6;
      fVar6 = fVar6 * (float)param_1[0x280] + (float)param_1[0x274];
      param_1[0x274] = (int)fVar6;
      fVar7 = (fVar7 - (float)param_1[0x26b]) - (float)param_1[0x27d];
      param_1[0x26b] = (int)fVar7;
      fVar7 = fVar7 * (float)param_1[0x281] + (float)param_1[0x27d];
      param_1[0x27d] = (int)fVar7;
      fVar6 = (fVar6 - (float)param_1[0x26a]) - (float)param_1[0x275];
      param_1[0x26a] = (int)fVar6;
      fVar6 = fVar6 * (float)param_1[0x280] + (float)param_1[0x275];
      param_1[0x275] = (int)fVar6;
      fVar7 = (fVar7 - (float)param_1[0x26b]) - (float)param_1[0x27e];
      param_1[0x26b] = (int)fVar7;
      fVar7 = fVar7 * (float)param_1[0x281] + (float)param_1[0x27e];
      param_1[0x27e] = (int)fVar7;
      fVar6 = (fVar6 - (float)param_1[0x26a]) - (float)param_1[0x276];
      param_1[0x26a] = (int)fVar6;
      fVar6 = fVar6 * (float)param_1[0x280] + (float)param_1[0x276];
      param_1[0x276] = (int)fVar6;
      fVar7 = (fVar7 - (float)param_1[0x26b]) - (float)param_1[0x27f];
      param_1[0x26b] = (int)fVar7;
      fVar7 = fVar7 * (float)param_1[0x281] + (float)param_1[0x27f];
      param_1[0x27f] = (int)fVar7;
      (**(code **)(*param_1 + 0xf8))(param_1,fVar6,fVar7);
      iVar4 = iVar1;
    } while (uVar5 != param_2);
  }
  return;
}

