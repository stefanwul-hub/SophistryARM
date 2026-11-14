/* 0009163c Phaser1SR_c_vslot_56 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void Phaser1SR_c_vslot_56(int *param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  uint uStack_2c;
  uint uStack_28;
  
  if ((char)param_1[0x57] == '\0') {
    return;
  }
  (**(code **)(*(int *)param_1[0x46] + 0x2c))((int *)param_1[0x46],param_1 + 0x266,param_1 + 0x267);
  (**(code **)(*(int *)param_1[4] + 0x38))((int *)param_1[4],param_1 + 0x264,param_1 + 0x265);
  switch(param_1[0x282]) {
  case 1:
    if (0 < (int)param_2) {
      uStack_2c = 0;
      iVar4 = param_2 + 1;
      do {
        iVar1 = param_2 - uStack_2c;
        uVar2 = uStack_2c & 7;
        uStack_2c = uStack_2c + 1;
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
            fVar6 = (float)param_1[0x261] * -0.25 + 0.5;
          }
          else {
            fVar6 = (float)param_1[0x261] * 0.25 + 1.0;
          }
          fVar6 = (float)param_1[0x283] * 0.5 + fVar6;
          if (1.0 < fVar6) {
            fVar6 = fVar6 - 1.0;
          }
          fVar6 = fVar6 * 4.0;
          if (3.0 < fVar6) {
            fVar6 = fVar6 - 4.0;
          }
          else if (1.0 < fVar6) {
            fVar6 = 2.0 - fVar6;
          }
          param_1[0x281] =
               (int)((fVar6 * (float)param_1[0x286] + 1.0) * (float)param_1[0x287] *
                    (float)param_1[0x52]);
        }
        param_1[0x26c] = (int)(*(float *)param_1[0x264] * 0.05);
        param_1[0x264] = (int)((float *)param_1[0x264] + 1);
        param_1[0x26d] = (int)(*(float *)param_1[0x265] * 0.05);
        param_1[0x265] = (int)((float *)param_1[0x265] + 1);
        fVar6 = ((float)param_1[0x288] * (float)param_1[0x268] + (float)param_1[0x26c]) -
                (float)param_1[0x26e];
        param_1[0x26a] = (int)fVar6;
        fVar5 = fVar6 * (float)param_1[0x280] + (float)param_1[0x26e];
        param_1[0x26e] = (int)fVar5;
        fVar6 = ((float)param_1[0x288] * (float)param_1[0x269] + (float)param_1[0x26d]) -
                (float)param_1[0x277];
        param_1[0x26b] = (int)fVar6;
        fVar6 = fVar6 * (float)param_1[0x281] + (float)param_1[0x277];
        param_1[0x277] = (int)fVar6;
        (**(code **)(*param_1 + 0xf8))(param_1,fVar5,fVar6);
        iVar4 = iVar1;
      } while (param_2 != uStack_2c);
    }
    break;
  case 2:
    if (0 < (int)param_2) {
      uStack_28 = 0;
      iVar4 = param_2 + 1;
      do {
        iVar1 = param_2 - uStack_28;
        uVar2 = uStack_28 & 7;
        uStack_28 = uStack_28 + 1;
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
            fVar6 = (float)param_1[0x261] * -0.25 + 0.5;
          }
          else {
            fVar6 = (float)param_1[0x261] * 0.25 + 1.0;
          }
          fVar6 = (float)param_1[0x283] * 0.5 + fVar6;
          if (1.0 < fVar6) {
            fVar6 = fVar6 - 1.0;
          }
          fVar6 = fVar6 * 4.0;
          if (3.0 < fVar6) {
            fVar6 = fVar6 - 4.0;
          }
          else if (1.0 < fVar6) {
            fVar6 = 2.0 - fVar6;
          }
          param_1[0x281] =
               (int)((fVar6 * (float)param_1[0x286] + 1.0) * (float)param_1[0x287] *
                    (float)param_1[0x52]);
        }
        param_1[0x26c] = (int)(*(float *)param_1[0x264] * 0.05);
        param_1[0x264] = (int)((float *)param_1[0x264] + 1);
        param_1[0x26d] = (int)(*(float *)param_1[0x265] * 0.05);
        param_1[0x265] = (int)((float *)param_1[0x265] + 1);
        fVar6 = ((float)param_1[0x288] * (float)param_1[0x268] + (float)param_1[0x26c]) -
                (float)param_1[0x26e];
        param_1[0x26a] = (int)fVar6;
        fVar5 = fVar6 * (float)param_1[0x280] + (float)param_1[0x26e];
        param_1[0x26e] = (int)fVar5;
        fVar6 = ((float)param_1[0x288] * (float)param_1[0x269] + (float)param_1[0x26d]) -
                (float)param_1[0x277];
        param_1[0x26b] = (int)fVar6;
        fVar6 = fVar6 * (float)param_1[0x281] + (float)param_1[0x277];
        param_1[0x277] = (int)fVar6;
        fVar5 = (fVar5 - (float)param_1[0x26a]) - (float)param_1[0x26f];
        param_1[0x26a] = (int)fVar5;
        fVar5 = fVar5 * (float)param_1[0x280] + (float)param_1[0x26f];
        param_1[0x26f] = (int)fVar5;
        fVar6 = (fVar6 - (float)param_1[0x26b]) - (float)param_1[0x278];
        param_1[0x26b] = (int)fVar6;
        fVar6 = fVar6 * (float)param_1[0x281] + (float)param_1[0x278];
        param_1[0x278] = (int)fVar6;
        (**(code **)(*param_1 + 0xf8))(param_1,fVar5,fVar6);
        iVar4 = iVar1;
      } while (uStack_28 != param_2);
    }
    break;
  case 3:
    FUN_0008fc36(param_1,param_2);
    break;
  case 4:
    FUN_0008ff9c(param_1,param_2);
    break;
  case 5:
    FUN_00090362(param_1,param_2);
    break;
  case 6:
    FUN_0009078a(param_1,param_2);
    break;
  case 7:
    FUN_00090c10(param_1,param_2);
    break;
  case 8:
    FUN_000910f6(param_1,param_2);
    break;
  case 9:
    FUN_0008f402(param_1,param_2);
  }
                    /* WARNING: Could not recover jumptable at 0x00091705. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)param_1[0x46] + 0x44))();
  return;
}

