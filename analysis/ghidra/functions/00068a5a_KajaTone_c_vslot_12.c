/* 00068a5a KajaTone_c_vslot_12 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

bool KajaTone_c_vslot_12(int param_1,uint param_2)

{
  char cVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  longdouble lVar10;
  float fVar11;
  float local_34;
  float local_30;
  int local_2c;
  byte local_24;
  int local_20;
  
  iVar7 = *(int *)(*(int *)(param_1 + 0x160) + 0x2618);
  if (iVar7 == 1) {
    *(undefined4 *)(&DAT_00013960 + param_1) = 2;
  }
  else if (iVar7 == 2) {
    *(undefined4 *)(&DAT_00013960 + param_1) = 1;
  }
  else if (iVar7 == 0) {
    *(undefined4 *)(&DAT_00013960 + param_1) = 0;
  }
  (**(code **)(**(int **)(&DAT_000136f0 + param_1) + 0xe8))
            (*(int **)(&DAT_000136f0 + param_1),*(undefined4 *)(&DAT_00013960 + param_1));
  (**(code **)(**(int **)(&DAT_000136f4 + param_1) + 0xe4))
            (*(int **)(&DAT_000136f4 + param_1),*(undefined4 *)(&DAT_00013960 + param_1));
  iVar7 = *(int *)(LPAUSynth_vslot_35 + *(int *)(param_1 + 0x160) + 4);
  if (iVar7 == 1) {
    *(undefined4 *)(&DAT_00013964 + param_1) = 2;
  }
  else if (iVar7 == 2) {
    *(undefined4 *)(&DAT_00013964 + param_1) = 1;
  }
  else if (iVar7 == 0) {
    *(undefined4 *)(&DAT_00013964 + param_1) = 0;
  }
  (**(code **)(**(int **)(&DAT_000136f8 + param_1) + 0xe8))
            (*(int **)(&DAT_000136f8 + param_1),*(undefined4 *)(&DAT_00013964 + param_1));
  (**(code **)(**(int **)(&DAT_000136fc + param_1) + 0xe4))
            (*(int **)(&DAT_000136fc + param_1),*(undefined4 *)(&DAT_00013964 + param_1));
  if ((*(int *)(param_1 + 0x144) == 0) || (*(int *)(param_1 + 0x160) == 0)) goto LAB_00069375;
  uVar8 = param_2;
  if ((int)param_2 < 0) {
    uVar8 = param_2 + 7;
  }
  iVar7 = ((int)uVar8 >> 3) + 1;
  if ((param_2 & 7) == 0) {
    iVar7 = (int)uVar8 >> 3;
  }
  iVar5 = (iVar7 * 8 - param_2) + *(int *)(param_1 + 0x164);
  *(int *)(param_1 + 0x164) = iVar5;
  if (iVar5 < 9) {
    fVar11 = *(float *)(*(int *)(param_1 + 0x144) + 0x11c);
    if (0.0 <= fVar11) goto LAB_00068b94;
LAB_00069792:
    if (NAN(fVar11)) goto LAB_00068b94;
    *(float *)(param_1 + 0x174) = fVar11 * *(float *)(param_1 + 0x170);
  }
  else {
    *(float *)(&DAT_000137a8 + param_1) =
         *(float *)(&DAT_000137a8 + param_1) - *(float *)(&DAT_000137d8 + param_1);
    *(int *)(&DAT_00013778 + param_1) = *(int *)(&DAT_00013778 + param_1) + 1;
    *(float *)(&DAT_000137ac + param_1) =
         *(float *)(&DAT_000137ac + param_1) - *(float *)(&DAT_000137dc + param_1);
    *(int *)(&DAT_0001377c + param_1) = *(int *)(&DAT_0001377c + param_1) + 1;
    *(float *)(&DAT_000137b0 + param_1) =
         *(float *)(&DAT_000137b0 + param_1) - *(float *)(&DAT_000137e0 + param_1);
    *(int *)(&DAT_00013780 + param_1) = *(int *)(&DAT_00013780 + param_1) + 1;
    *(float *)(&DAT_000137b4 + param_1) =
         *(float *)(&DAT_000137b4 + param_1) - *(float *)(&DAT_000137e4 + param_1);
    *(int *)(&DAT_00013784 + param_1) = *(int *)(&DAT_00013784 + param_1) + 1;
    *(float *)(&DAT_000137b8 + param_1) =
         *(float *)(&DAT_000137b8 + param_1) - *(float *)(&DAT_000137e8 + param_1);
    *(int *)(&DAT_00013788 + param_1) = *(int *)(&DAT_00013788 + param_1) + 1;
    *(float *)(&DAT_000137bc + param_1) =
         *(float *)(&DAT_000137bc + param_1) - *(float *)(&DAT_000137ec + param_1);
    *(int *)(&DAT_0001378c + param_1) = *(int *)(&DAT_0001378c + param_1) + 1;
    *(float *)(&DAT_000137c0 + param_1) =
         *(float *)(&DAT_000137c0 + param_1) - *(float *)(&DAT_000137f0 + param_1);
    *(int *)(&DAT_00013790 + param_1) = *(int *)(&DAT_00013790 + param_1) + 1;
    *(float *)(&DAT_000137c4 + param_1) =
         *(float *)(&DAT_000137c4 + param_1) - *(float *)(&DAT_000137f4 + param_1);
    *(int *)(&DAT_00013794 + param_1) = *(int *)(&DAT_00013794 + param_1) + 1;
    *(float *)(&DAT_000137c8 + param_1) =
         *(float *)(&DAT_000137c8 + param_1) - *(float *)(&DAT_000137f8 + param_1);
    *(int *)(&DAT_00013798 + param_1) = *(int *)(&DAT_00013798 + param_1) + 1;
    *(float *)(&DAT_000137cc + param_1) =
         *(float *)(&DAT_000137cc + param_1) - *(float *)(&DAT_000137fc + param_1);
    *(int *)(&DAT_0001379c + param_1) = *(int *)(&DAT_0001379c + param_1) + 1;
    *(float *)(&DAT_000137d0 + param_1) =
         *(float *)(&DAT_000137d0 + param_1) - *(float *)(FUN_000137fe + param_1 + 2);
    *(int *)(&DAT_000137a0 + param_1) = *(int *)(&DAT_000137a0 + param_1) + 1;
    *(float *)(&DAT_000137d4 + param_1) =
         *(float *)(&DAT_000137d4 + param_1) - *(float *)(param_1 + 0x13804);
    *(int *)(&DAT_000137a4 + param_1) = *(int *)(&DAT_000137a4 + param_1) + 1;
    *(int *)(param_1 + 0x164) = iVar5 + -8;
    fVar11 = *(float *)(*(int *)(param_1 + 0x144) + 0x11c);
    if (fVar11 < 0.0) goto LAB_00069792;
LAB_00068b94:
    *(float *)(param_1 + 0x174) = fVar11 * *(float *)(param_1 + 0x16c);
  }
  FUN_000c20a4(param_1);
  *(undefined4 *)(param_1 + 0x168) = 0;
  for (; 0 < iVar7; iVar7 = iVar7 - iVar6) {
    iVar5 = *(int *)(&DAT_00013778 + param_1);
    iVar9 = iVar7;
    if (iVar5 < iVar7) {
      iVar9 = iVar5;
    }
    iVar6 = *(int *)(&DAT_0001377c + param_1);
    if (iVar9 <= *(int *)(&DAT_0001377c + param_1)) {
      iVar6 = iVar9;
    }
    iVar9 = *(int *)(&DAT_00013780 + param_1);
    if (iVar6 <= *(int *)(&DAT_00013780 + param_1)) {
      iVar9 = iVar6;
    }
    iVar6 = *(int *)(&DAT_00013784 + param_1);
    if (iVar9 <= *(int *)(&DAT_00013784 + param_1)) {
      iVar6 = iVar9;
    }
    iVar9 = *(int *)(&DAT_00013788 + param_1);
    if (iVar6 <= *(int *)(&DAT_00013788 + param_1)) {
      iVar9 = iVar6;
    }
    iVar6 = *(int *)(&DAT_0001378c + param_1);
    if (iVar9 <= *(int *)(&DAT_0001378c + param_1)) {
      iVar6 = iVar9;
    }
    iVar9 = *(int *)(&DAT_00013790 + param_1);
    if (iVar6 <= *(int *)(&DAT_00013790 + param_1)) {
      iVar9 = iVar6;
    }
    iVar6 = *(int *)(&DAT_00013794 + param_1);
    if (iVar9 <= *(int *)(&DAT_00013794 + param_1)) {
      iVar6 = iVar9;
    }
    iVar9 = *(int *)(&DAT_00013798 + param_1);
    if (iVar6 <= *(int *)(&DAT_00013798 + param_1)) {
      iVar9 = iVar6;
    }
    iVar6 = *(int *)(&DAT_0001379c + param_1);
    if (iVar9 <= *(int *)(&DAT_0001379c + param_1)) {
      iVar6 = iVar9;
    }
    iVar9 = *(int *)(&DAT_000137a0 + param_1);
    if (iVar6 <= *(int *)(&DAT_000137a0 + param_1)) {
      iVar9 = iVar6;
    }
    iVar6 = *(int *)(&DAT_000137a4 + param_1);
    if (iVar9 <= *(int *)(&DAT_000137a4 + param_1)) {
      iVar6 = iVar9;
    }
    if ((&DAT_00013970)[param_1] == '\0') {
      local_34 = 1.0;
    }
    else {
      local_34 = 0.0;
    }
    if ((&DAT_00013971)[param_1] == '\0') {
      local_30 = 1.0;
    }
    else {
      local_30 = 0.0;
    }
    if (0 < iVar6) {
      local_2c = 1;
      local_20 = 0;
      do {
        *(float *)(&DAT_000137a8 + param_1) =
             *(float *)(&DAT_000137a8 + param_1) + *(float *)(&DAT_000137d8 + param_1);
        *(float *)(&DAT_000137ac + param_1) =
             *(float *)(&DAT_000137ac + param_1) + *(float *)(&DAT_000137dc + param_1);
        *(float *)(&DAT_000137b0 + param_1) =
             *(float *)(&DAT_000137b0 + param_1) + *(float *)(&DAT_000137e0 + param_1);
        *(float *)(&DAT_000137b4 + param_1) =
             *(float *)(&DAT_000137b4 + param_1) + *(float *)(&DAT_000137e4 + param_1);
        *(float *)(&DAT_000137b8 + param_1) =
             *(float *)(&DAT_000137b8 + param_1) + *(float *)(&DAT_000137e8 + param_1);
        *(float *)(&DAT_000137bc + param_1) =
             *(float *)(&DAT_000137bc + param_1) + *(float *)(&DAT_000137ec + param_1);
        *(float *)(&DAT_000137c0 + param_1) =
             *(float *)(&DAT_000137c0 + param_1) + *(float *)(&DAT_000137f0 + param_1);
        *(float *)(&DAT_000137c4 + param_1) =
             *(float *)(&DAT_000137c4 + param_1) + *(float *)(&DAT_000137f4 + param_1);
        *(float *)(&DAT_000137c8 + param_1) =
             *(float *)(&DAT_000137c8 + param_1) + *(float *)(&DAT_000137f8 + param_1);
        *(float *)(&DAT_000137cc + param_1) =
             *(float *)(&DAT_000137cc + param_1) + *(float *)(&DAT_000137fc + param_1);
        *(float *)(&DAT_000137d0 + param_1) =
             *(float *)(&DAT_000137d0 + param_1) + *(float *)(FUN_000137fe + param_1 + 2);
        *(float *)(&DAT_000137d4 + param_1) =
             *(float *)(&DAT_000137d4 + param_1) + *(float *)(param_1 + 0x13804);
        local_2c = local_2c + -1;
        if (local_2c == 0) {
          fVar11 = *(float *)(&DAT_00013968 + param_1);
          lVar10 = (longdouble)
                   (**(code **)(**(int **)(&DAT_00013700 + param_1) + 0x6c))
                             (*(int **)(&DAT_00013700 + param_1),0);
          *(float *)(&DAT_00013968 + param_1) = fVar11 * 0.98 + (float)lVar10 * 0.02;
          fVar11 = *(float *)(&DAT_0001396c + param_1);
          lVar10 = (longdouble)
                   (**(code **)(**(int **)(&DAT_00013704 + param_1) + 0x6c))
                             (*(int **)(&DAT_00013704 + param_1),0);
          *(float *)(&DAT_0001396c + param_1) = fVar11 * 0.98 + (float)lVar10 * 0.02;
          local_2c = 10;
        }
        FUN_0002a18e(param_1);
        *(float *)(&DAT_00013950 + param_1) =
             (*(float *)(&DAT_00013974 + param_1) + *(float *)(&DAT_000138fc + param_1)) *
             (local_34 - *(float *)(&DAT_00013968 + param_1));
        *(float *)(&DAT_00013954 + param_1) =
             (*(float *)(&DAT_00013978 + param_1) + *(float *)(&DAT_00013900 + param_1)) *
             (local_30 - *(float *)(&DAT_0001396c + param_1));
        *(float *)(&DAT_000138ec + param_1) =
             *(float *)(&DAT_000138ec + param_1) + *(float *)(&DAT_00013968 + param_1);
        *(float *)(&DAT_000138f0 + param_1) =
             *(float *)(&DAT_000138f0 + param_1) + *(float *)(&DAT_0001396c + param_1);
        fVar11 = *(float *)(&DAT_00013918 + param_1) + *(float *)(&DAT_000137c4 + param_1) +
                 *(float *)(param_1 + 0x174);
        *(float *)(*(int *)(&DAT_00013708 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(float *)(&DAT_000138ac + param_1) * *(float *)(&DAT_000137a8 + param_1);
        *(float *)(*(int *)(&DAT_00013714 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(float *)(&DAT_000138b0 + param_1) * *(float *)(&DAT_000137ac + param_1);
        *(undefined4 *)(*(int *)(&DAT_00013720 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(&DAT_000138b4 + param_1);
        *(undefined4 *)(*(int *)(&DAT_0001372c + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(&DAT_000138b8 + param_1);
        *(float *)(*(int *)(&DAT_0001370c + param_1) + *(int *)(param_1 + 0x168) * 4) =
             fVar11 + *(float *)(&DAT_000138bc + param_1);
        *(float *)(*(int *)(&DAT_00013718 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             fVar11 + *(float *)(&DAT_000138c0 + param_1);
        *(float *)(*(int *)(&DAT_00013724 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             fVar11 + *(float *)(&DAT_000138c4 + param_1);
        *(float *)(*(int *)(&DAT_00013730 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             fVar11 + *(float *)(&DAT_000138c8 + param_1);
        *(undefined4 *)(*(int *)(&DAT_00013710 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(param_1 + 0x138cc);
        *(undefined4 *)(*(int *)(&DAT_0001371c + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(param_1 + 0x138d0);
        *(undefined4 *)(*(int *)(&DAT_00013728 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(param_1 + 0x138d4);
        *(undefined4 *)(*(int *)(&DAT_00013734 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(param_1 + 0x138d8);
        *(undefined4 *)(*(int *)(&DAT_00013738 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(&DAT_0001393c + param_1);
        *(undefined4 *)(*(int *)(&DAT_0001373c + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(&DAT_00013940 + param_1);
        *(float *)(*(int *)(&DAT_00013740 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(float *)(&DAT_000137b8 + param_1) * *(float *)(&DAT_00013950 + param_1) +
             *(float *)(&DAT_000138ec + param_1);
        *(float *)(*(int *)(&DAT_00013748 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(float *)(&DAT_000137bc + param_1) * *(float *)(&DAT_00013954 + param_1) +
             *(float *)(&DAT_000138f0 + param_1);
        *(undefined4 *)(*(int *)(&DAT_00013744 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(&DAT_000138f4 + param_1);
        *(undefined4 *)(*(int *)(&DAT_0001374c + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(&DAT_000138f8 + param_1);
        *(float *)(*(int *)(&DAT_00013750 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(float *)(&DAT_00013914 + param_1) * *(float *)(&DAT_000137c0 + param_1) *
             *(float *)(&DAT_0001390c + param_1);
        *(float *)(*(int *)(&DAT_00013754 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(float *)(&DAT_00013914 + param_1) * *(float *)(&DAT_000137c0 + param_1) *
             *(float *)(&DAT_00013910 + param_1);
        *(undefined4 *)(*(int *)(&DAT_00013758 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(&DAT_0001391c + param_1);
        *(undefined4 *)(*(int *)(&DAT_0001375c + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(&DAT_00013920 + param_1);
        *(undefined4 *)(*(int *)(&DAT_00013760 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(&DAT_00013904 + param_1);
        *(undefined4 *)(*(int *)(&DAT_00013764 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(&DAT_00013908 + param_1);
        *(undefined4 *)(*(int *)(&DAT_00013768 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(param_1 + 0x138dc);
        *(undefined4 *)(*(int *)(&DAT_0001376c + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(param_1 + 0x138e0);
        *(undefined4 *)(*(int *)(&DAT_00013770 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(param_1 + 0x138e4);
        *(undefined4 *)(*(int *)(&DAT_00013774 + param_1) + *(int *)(param_1 + 0x168) * 4) =
             *(undefined4 *)(param_1 + 0x138e8);
        *(int *)(param_1 + 0x168) = *(int *)(param_1 + 0x168) + 1;
        local_20 = local_20 + 1;
      } while (iVar6 != local_20);
      iVar5 = *(int *)(&DAT_00013778 + param_1);
    }
    *(int *)(&DAT_00013778 + param_1) = iVar5 - iVar6;
    if (iVar5 - iVar6 < 1) {
      EnvADSFR_c_vslot_57(param_1 + 0x4150);
    }
    iVar5 = *(int *)(&DAT_0001377c + param_1);
    *(int *)(&DAT_0001377c + param_1) = iVar5 - iVar6;
    if (iVar5 - iVar6 < 1) {
      EnvADSFR_c_vslot_57(param_1 + 0x44d8);
    }
    iVar5 = *(int *)(&DAT_00013780 + param_1);
    *(int *)(&DAT_00013780 + param_1) = iVar5 - iVar6;
    if (iVar5 - iVar6 < 1) {
      EnvADSFR_c_vslot_57(param_1 + 0x4860);
    }
    iVar5 = *(int *)(&DAT_00013784 + param_1);
    *(int *)(&DAT_00013784 + param_1) = iVar5 - iVar6;
    if (iVar5 - iVar6 < 1) {
      EnvADSFR_c_vslot_57(&UNK_00004be8 + param_1);
    }
    iVar5 = *(int *)(&DAT_00013788 + param_1);
    *(int *)(&DAT_00013788 + param_1) = iVar5 - iVar6;
    if (iVar5 - iVar6 < 1) {
      EnvADSFR_c_vslot_57(param_1 + 0x4f70);
    }
    iVar5 = *(int *)(&DAT_0001378c + param_1);
    *(int *)(&DAT_0001378c + param_1) = iVar5 - iVar6;
    if (iVar5 - iVar6 < 1) {
      EnvADSFR_c_vslot_57(&UNK_000052f8 + param_1);
    }
    iVar5 = *(int *)(&DAT_00013790 + param_1);
    *(int *)(&DAT_00013790 + param_1) = iVar5 - iVar6;
    if (iVar5 - iVar6 < 1) {
      EnvADSFR_c_vslot_57(param_1 + 0x5680);
    }
    iVar5 = *(int *)(&DAT_00013794 + param_1);
    *(int *)(&DAT_00013794 + param_1) = iVar5 - iVar6;
    if (iVar5 - iVar6 < 1) {
      RampGlide_c_vslot_57(&UNK_00005a08 + param_1);
    }
    iVar5 = *(int *)(&DAT_00013798 + param_1);
    *(int *)(&DAT_00013798 + param_1) = iVar5 - iVar6;
    if (iVar5 - iVar6 < 1) {
      *(undefined4 *)(param_1 + 0xe34) = *(undefined4 *)(&DAT_00013924 + param_1);
      AdvLFO_c_vslot_57(param_1 + 0xc50);
LAB_000692d4:
      iVar5 = *(int *)(&DAT_0001379c + param_1);
      *(int *)(&DAT_0001379c + param_1) = iVar5 - iVar6;
      if (0 < iVar5 - iVar6) goto LAB_000692ea;
LAB_00069559:
      *(undefined4 *)(param_1 + 0x1b74) = *(undefined4 *)(&DAT_00013928 + param_1);
      AdvLFO_c_vslot_57(param_1 + 0x1990);
LAB_00069305:
      iVar5 = *(int *)(&DAT_000137a0 + param_1);
      *(int *)(&DAT_000137a0 + param_1) = iVar5 - iVar6;
      if (0 < iVar5 - iVar6) goto LAB_0006931b;
LAB_00069510:
      *(undefined4 *)(&DAT_000028b4 + param_1) = *(undefined4 *)(&DAT_0001392c + param_1);
      AdvLFO_c_vslot_57(param_1 + 0x26d0);
LAB_00069336:
      iVar5 = *(int *)(&DAT_000137a4 + param_1);
      *(int *)(&DAT_000137a4 + param_1) = iVar5 - iVar6;
      if (0 < iVar5 - iVar6) goto LAB_0006934c;
LAB_000694c7:
      *(undefined4 *)(LPAUSynth_vslot_83 + param_1 + 6) = *(undefined4 *)(&DAT_00013930 + param_1);
      AdvLFO_c_vslot_57(param_1 + 0x3410);
    }
    else {
      if (*(float *)(&DAT_00013924 + param_1) == *(float *)(param_1 + 0xe34)) goto LAB_000692d4;
      FUN_00084c9e(param_1 + 0xc50,*(float *)(&DAT_00013924 + param_1));
      iVar5 = *(int *)(&DAT_0001379c + param_1);
      *(int *)(&DAT_0001379c + param_1) = iVar5 - iVar6;
      if (iVar5 - iVar6 < 1) goto LAB_00069559;
LAB_000692ea:
      if (*(float *)(&DAT_00013928 + param_1) == *(float *)(param_1 + 0x1b74)) goto LAB_00069305;
      FUN_00084c9e(param_1 + 0x1990,*(float *)(&DAT_00013928 + param_1));
      iVar5 = *(int *)(&DAT_000137a0 + param_1);
      *(int *)(&DAT_000137a0 + param_1) = iVar5 - iVar6;
      if (iVar5 - iVar6 < 1) goto LAB_00069510;
LAB_0006931b:
      if (*(float *)(&DAT_0001392c + param_1) == *(float *)(&DAT_000028b4 + param_1))
      goto LAB_00069336;
      FUN_00084c9e(param_1 + 0x26d0,*(float *)(&DAT_0001392c + param_1));
      iVar5 = *(int *)(&DAT_000137a4 + param_1);
      *(int *)(&DAT_000137a4 + param_1) = iVar5 - iVar6;
      if (iVar5 - iVar6 < 1) goto LAB_000694c7;
LAB_0006934c:
      if (*(float *)(&DAT_00013930 + param_1) != *(float *)(LPAUSynth_vslot_83 + param_1 + 6)) {
        FUN_00084c9e(param_1 + 0x3410,*(float *)(&DAT_00013930 + param_1));
      }
    }
  }
LAB_00069375:
  iVar7 = *(int *)(param_1 + 0x160);
  if (iVar7 == 0) {
    return (*(byte *)(param_1 + 0x5860) | 1) != 0;
  }
  cVar1 = (&DAT_000028cc)[iVar7];
  cVar2 = *(char *)(iVar7 + 0x2d9c);
  cVar3 = *(char *)(iVar7 + 0x2e0c);
  if (*(char *)(iVar7 + 0x285c) == '\0') {
    local_24 = 1;
  }
  else {
    local_24 = (**(code **)(**(int **)(&DAT_000136f0 + param_1) + 0xec))
                         (*(int **)(&DAT_000136f0 + param_1),param_2);
    local_24 = local_24 & 1;
    Pan_c_vslot_56(param_1 + 0x907c,param_2);
    if (*(char *)(*(int *)(param_1 + 0x160) + 0x541c) != '\0') {
      Pan51_c_vslot_56(param_1 + 0x989c,param_2);
    }
  }
  if (cVar1 != '\0') {
    bVar4 = (**(code **)(**(int **)(&DAT_000136f4 + param_1) + 0xec))
                      (*(int **)(&DAT_000136f4 + param_1),param_2);
    local_24 = bVar4 & local_24;
    Pan_c_vslot_56(param_1 + 0x9284,param_2);
    if (*(char *)(*(int *)(param_1 + 0x160) + 0x548c) != '\0') {
      Pan51_c_vslot_56(param_1 + 0x9ab0,param_2);
    }
  }
  if (cVar2 != '\0') {
    bVar4 = (**(code **)(**(int **)(&DAT_000136f8 + param_1) + 0xec))
                      (*(int **)(&DAT_000136f8 + param_1),param_2);
    Pan_c_vslot_56(param_1 + 0x948c,param_2);
    local_24 = local_24 & bVar4;
  }
  if (cVar3 != '\0') {
    bVar4 = (**(code **)(**(int **)(&DAT_000136fc + param_1) + 0xec))
                      (*(int **)(&DAT_000136fc + param_1),param_2);
    Pan_c_vslot_56(param_1 + 0x9694,param_2);
    local_24 = local_24 & bVar4;
  }
  if (*(char *)(*(int *)(param_1 + 0x160) + 0x32dc) == '\0') {
    Amp_c_vslot_56(&UNK_000132e0 + param_1,param_2);
    cVar1 = *(char *)(*(int *)(param_1 + 0x160) + 0x334c);
  }
  else {
    Satur_c_vslot_56(param_1 + 0xa0ec,param_2);
    (**(code **)(**(int **)(&DAT_00013700 + param_1) + 0xe0))
              (*(int **)(&DAT_00013700 + param_1),param_2);
    iVar7 = *(int *)(param_1 + 0x160);
    if (*(char *)(iVar7 + 0x54fc) != '\0') {
      Pan51_c_vslot_56(param_1 + 0x9cc4,param_2);
      iVar7 = *(int *)(param_1 + 0x160);
    }
    cVar1 = *(char *)(iVar7 + 0x334c);
  }
  if (cVar1 == '\0') {
    Amp_c_vslot_56(&UNK_000134e8 + param_1,param_2);
  }
  else {
    Satur_c_vslot_56(param_1 + 0xa2d4,param_2);
    (**(code **)(**(int **)(&DAT_00013704 + param_1) + 0xe0))
              (*(int **)(&DAT_00013704 + param_1),param_2);
    if (*(char *)(*(int *)(param_1 + 0x160) + 0x556c) != '\0') {
      Pan51_c_vslot_56(param_1 + 0x9ed8,param_2);
    }
  }
  return local_24 != 0 || *(char *)(param_1 + 0x5860) != '\0';
}

