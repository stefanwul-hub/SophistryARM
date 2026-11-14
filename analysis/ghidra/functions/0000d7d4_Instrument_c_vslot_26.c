/* 0000d7d4 Instrument_c_vslot_26 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Instrument_c_vslot_26(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  uVar1 = param_2;
  if ((int)param_2 < 0) {
    uVar1 = param_2 + 0x3f;
  }
  iVar4 = (int)uVar1 >> 6;
  if ((param_2 & 0x3f) != 0) {
    iVar4 = ((int)uVar1 >> 6) + 1;
  }
  if (*(char *)(param_1 + 0x150) == '\0') {
    iVar4 = iVar4 + -1;
    *(undefined4 *)(param_1 + 0x1aec + iVar4 * 4) = *(undefined4 *)(param_1 + 0x1ad8);
    *(undefined4 *)(param_1 + 0x1b00 + iVar4 * 4) = *(undefined4 *)(param_1 + 0x1adc);
    *(undefined4 *)(param_1 + 0x1b14 + iVar4 * 4) = *(undefined4 *)(param_1 + 0x1ae0);
    *(undefined4 *)(param_1 + 0x1b28 + iVar4 * 4) = *(undefined4 *)(param_1 + 0x1ae4);
    *(undefined4 *)(param_1 + 0x1b3c + iVar4 * 4) = *(undefined4 *)(param_1 + 0x1ae8);
  }
  else {
    fVar6 = *(float *)(param_1 + 0x10) * 1400.0;
    if ((0.0025 <= fVar6) || (NAN(fVar6))) {
      fVar7 = 0.25;
      if (0.25 < fVar6) {
        fVar5 = 0.75;
      }
      else {
        fVar5 = 1.0 - fVar6;
        fVar7 = fVar6;
      }
    }
    else {
      fVar5 = 0.9975;
      fVar7 = 0.0025;
    }
    fVar10 = fVar7 * *(float *)(param_1 + 0x1ad8);
    *(float *)(param_1 + 0x1aec) = fVar5 * *(float *)(param_1 + 0x11c) + fVar10;
    fVar9 = fVar7 * *(float *)(param_1 + 0x1adc);
    *(float *)(FUN_00001afe + param_1 + 2) = fVar5 * *(float *)(param_1 + 0x120) + fVar9;
    fVar8 = fVar7 * *(float *)(param_1 + 0x1ae0);
    *(float *)(param_1 + 0x1b14) = fVar5 * *(float *)(param_1 + 0x124) + fVar8;
    fVar6 = fVar7 * *(float *)(param_1 + 0x1ae4);
    *(float *)(param_1 + 0x1b28) = fVar5 * *(float *)(param_1 + 0x128) + fVar6;
    fVar7 = fVar7 * *(float *)(param_1 + 0x1ae8);
    *(float *)(param_1 + 0x1b3c) = fVar5 * *(float *)(param_1 + 300) + fVar7;
    if (1 < iVar4) {
      iVar3 = 1;
      iVar2 = param_1;
      do {
        *(float *)(iVar2 + 0x1af0) = fVar5 * *(float *)(iVar2 + 0x1aec) + fVar10;
        *(float *)(iVar2 + 0x1b04) = fVar5 * *(float *)(FUN_00001afe + iVar2 + 2) + fVar9;
        *(float *)(iVar2 + 0x1b18) = fVar5 * *(float *)(iVar2 + 0x1b14) + fVar8;
        *(float *)(iVar2 + 0x1b2c) = fVar5 * *(float *)(iVar2 + 0x1b28) + fVar6;
        *(float *)(iVar2 + 0x1b40) = fVar5 * *(float *)(iVar2 + 0x1b3c) + fVar7;
        iVar3 = iVar3 + 1;
        iVar2 = iVar2 + 4;
      } while (iVar4 != iVar3);
      *(undefined4 *)(param_1 + 0x1b50) = 0;
      return;
    }
  }
  *(undefined4 *)(param_1 + 0x1b50) = 0;
  return;
}

