/* 000c20a4 FUN_000c20a4 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Type propagation algorithm not settling */

void FUN_000c20a4(int param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  longdouble lVar8;
  float fVar9;
  float fVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  char local_1f;
  char local_1e;
  char local_1d;
  
  if (((*(int *)(param_1 + 0x160) == 0) || (*(int *)(param_1 + 0x144) == 0)) ||
     (*(int *)(&DAT_00013958 + param_1) == 0)) {
    return;
  }
  iVar5 = 0;
  uVar4 = *(uint *)(param_1 + 0x160);
  iVar6 = param_1;
  do {
    while (*(char *)(iVar5 + uVar4 + 0x36cc) == '\0') {
      *(undefined4 *)(iVar6 + 0x1d8) = 0;
      iVar5 = iVar5 + 0x70;
      iVar6 = iVar6 + 4;
      if (iVar5 == 0x460) goto LAB_000c2111;
    }
    *(undefined4 *)(iVar6 + 0x1d8) = *(undefined4 *)(iVar5 + uVar4 + 0xe0c);
    iVar5 = iVar5 + 0x70;
    iVar6 = iVar6 + 4;
  } while (iVar5 != 0x460);
LAB_000c2111:
  iVar6 = *(int *)(uVar4 + 0x2768);
  iVar5 = *(int *)(uVar4 + 0x27d8);
  iVar2 = *(int *)(uVar4 + 0x2ca8);
  iVar3 = *(int *)(uVar4 + 0x2d18);
  *(float *)(&DAT_000138ac + param_1) =
       *(float *)(uVar4 + 0x4f48) * *(float *)(&DAT_000139b0 + param_1);
  *(float *)(&DAT_000138b0 + param_1) =
       *(float *)(uVar4 + 0x4fb8) * *(float *)(&DAT_000139b4 + param_1);
  *(float *)(&DAT_000138b4 + param_1) =
       *(float *)(uVar4 + 0x5028) * *(float *)(&DAT_000139b8 + param_1);
  *(float *)(&DAT_000138b8 + param_1) =
       *(float *)(uVar4 + 0x5098) * *(float *)(&DAT_000139bc + param_1);
  if ((iVar6 == 0) && (*(int *)(&DAT_00013960 + param_1) == 0)) {
    *(float *)(&DAT_000138ac + param_1) = *(float *)(&DAT_000138ac + param_1) * 0.5;
  }
  if (iVar5 == 0) {
    *(float *)(&DAT_000138b0 + param_1) = *(float *)(&DAT_000138b0 + param_1) * 0.5;
  }
  if ((iVar2 == 0) && (*(int *)(&DAT_00013964 + param_1) == 0)) {
    *(float *)(&DAT_000138b4 + param_1) = *(float *)(&DAT_000138b4 + param_1) * 0.5;
  }
  if (iVar3 == 0) {
    *(float *)(&DAT_000138b8 + param_1) = *(float *)(&DAT_000138b8 + param_1) * 0.5;
  }
  *(undefined4 *)(&DAT_000138bc + param_1) = *(undefined4 *)(&DAT_0001397c + param_1);
  *(undefined4 *)(&DAT_000138c0 + param_1) = *(undefined4 *)(&DAT_00013980 + param_1);
  *(undefined4 *)(&DAT_000138c4 + param_1) = *(undefined4 *)(&DAT_00013984 + param_1);
  *(undefined4 *)(&DAT_000138c8 + param_1) = *(undefined4 *)(&DAT_00013988 + param_1);
  *(undefined4 *)(param_1 + 0x138cc) = *(undefined4 *)(&DAT_0001398c + param_1);
  *(undefined4 *)(param_1 + 0x138d0) = *(undefined4 *)(&DAT_00013990 + param_1);
  *(undefined4 *)(param_1 + 0x138d4) = *(undefined4 *)(&DAT_00013994 + param_1);
  *(undefined4 *)(param_1 + 0x138d8) = *(undefined4 *)(&DAT_00013998 + param_1);
  iVar6 = *(int *)(uVar4 + 0x2768);
  if (iVar6 == 1) {
    uVar12 = 9;
    uVar11 = *(undefined4 *)(param_1 + 0x140);
    iVar6 = param_1 + 0x6e6c;
LAB_000c2856:
    iVar6 = Envelope_c_vslot_12(iVar6,uVar11,uVar12);
    local_1f = 0 < iVar6;
    uVar4 = *(uint *)(param_1 + 0x160);
    iVar6 = *(int *)(uVar4 + 0x27d8);
    iVar5 = iVar6 + -1;
    bVar7 = iVar5 == 0;
    if (bVar7) goto LAB_000c2879;
LAB_000c224b:
    if (bVar7 || SBORROW4(iVar6,1) != iVar5 < 0) {
      if (iVar6 == 0) {
        uVar12 = 0xc;
        uVar11 = *(undefined4 *)(param_1 + 0x140);
        iVar6 = param_1 + 0x60a4;
        goto LAB_000c2891;
      }
    }
    else if (iVar6 == 2) {
      iVar6 = (**(code **)(*(int *)(param_1 + 0x8018) + 0x30))
                        (param_1 + 0x8018,*(undefined4 *)(param_1 + 0x140),8);
      local_1e = 0 < iVar6;
      uVar4 = *(uint *)(param_1 + 0x160);
    }
    else if (iVar6 == 3) {
      local_1e = '\0';
    }
    iVar6 = *(int *)(uVar4 + 0x2ca8);
    if (iVar6 != 1) goto LAB_000c2272;
LAB_000c28b4:
    uVar12 = 9;
    uVar11 = *(undefined4 *)(param_1 + 0x140);
    iVar6 = param_1 + 0x75fc;
LAB_000c28cc:
    iVar6 = Envelope_c_vslot_12(iVar6,uVar11,uVar12);
    local_1d = 0 < iVar6;
    uVar4 = *(uint *)(param_1 + 0x160);
  }
  else {
    if (iVar6 < 2) {
      if (iVar6 == 0) {
        uVar12 = 0xc;
        uVar11 = *(undefined4 *)(param_1 + 0x140);
        iVar6 = param_1 + 0x5c0c;
        goto LAB_000c2856;
      }
    }
    else if (iVar6 == 2) {
      iVar6 = (**(code **)(*(int *)(FUN_00007d88 + param_1 + 4) + 0x30))
                        (param_1 + 0x7d8c,*(undefined4 *)(param_1 + 0x140),8);
      local_1f = 0 < iVar6;
      uVar4 = *(uint *)(param_1 + 0x160);
    }
    else if (iVar6 == 3) {
      local_1f = '\0';
    }
    iVar6 = *(int *)(uVar4 + 0x27d8);
    iVar5 = iVar6 + -1;
    bVar7 = iVar6 == 1;
    if (!bVar7) goto LAB_000c224b;
LAB_000c2879:
    uVar12 = 9;
    uVar11 = *(undefined4 *)(param_1 + 0x140);
    iVar6 = param_1 + 0x7234;
LAB_000c2891:
    iVar6 = Envelope_c_vslot_12(iVar6,uVar11,uVar12);
    local_1e = 0 < iVar6;
    uVar4 = *(uint *)(param_1 + 0x160);
    iVar6 = *(int *)(uVar4 + 0x2ca8);
    if (iVar6 == 1) goto LAB_000c28b4;
LAB_000c2272:
    if (iVar6 == 2) {
      iVar6 = (**(code **)(*(int *)(param_1 + 0x82a4) + 0x30))
                        (param_1 + 0x82a4,*(undefined4 *)(param_1 + 0x140),8);
      local_1d = 0 < iVar6;
      uVar4 = *(uint *)(param_1 + 0x160);
    }
    else if (iVar6 == 0) {
      uVar12 = 0xc;
      uVar11 = *(undefined4 *)(param_1 + 0x140);
      iVar6 = param_1 + 0x653c;
      goto LAB_000c28cc;
    }
  }
  iVar6 = *(int *)(uVar4 + 0x2d18);
  if (iVar6 == 1) {
    uVar12 = 9;
    uVar11 = *(undefined4 *)(param_1 + 0x140);
    iVar6 = param_1 + 0x79c4;
  }
  else {
    if (iVar6 == 2) {
      iVar6 = (**(code **)(*(int *)(param_1 + 0x8530) + 0x30))
                        (param_1 + 0x8530,*(undefined4 *)(param_1 + 0x140),8);
      uVar4 = (uint)(0 < iVar6);
      goto LAB_000c22a3;
    }
    if (iVar6 != 0) goto LAB_000c22a3;
    uVar12 = 0xc;
    uVar11 = *(undefined4 *)(param_1 + 0x140);
    iVar6 = param_1 + 0x69d4;
  }
  iVar6 = Envelope_c_vslot_12(iVar6,uVar11,uVar12);
  uVar4 = (uint)(0 < iVar6);
LAB_000c22a3:
  if ((local_1f != '\0') && (*(int *)(*(int *)(param_1 + 0x160) + 0x2618) == 0)) {
    *(float *)(&DAT_000138ac + param_1) = *(float *)(&DAT_000138ac + param_1) * 0.45;
  }
  if (local_1e != '\0') {
    *(float *)(&DAT_000138b0 + param_1) = *(float *)(&DAT_000138b0 + param_1) * 0.45;
  }
  if ((local_1d != '\0') && (*(int *)(LPAUSynth_vslot_35 + *(int *)(param_1 + 0x160) + 4) == 0)) {
    *(float *)(&DAT_000138b4 + param_1) = *(float *)(&DAT_000138b4 + param_1) * 0.45;
  }
  if ((char)uVar4 != '\0') {
    *(float *)(&DAT_000138b8 + param_1) = *(float *)(&DAT_000138b8 + param_1) * 0.45;
  }
  fVar10 = *(float *)(&DAT_0001399c + param_1);
  iVar6 = Envelope_c_vslot_12(param_1 + 0x907c,*(undefined4 *)(param_1 + 0x140),2);
  *(float *)(param_1 + 0x138dc) = (float)iVar6 * 0.01 + fVar10;
  fVar10 = *(float *)(&DAT_000139a0 + param_1);
  iVar6 = Envelope_c_vslot_12(param_1 + 0x9284,*(undefined4 *)(param_1 + 0x140),2);
  *(float *)(param_1 + 0x138e0) = (float)iVar6 * 0.01 + fVar10;
  fVar10 = *(float *)(&DAT_000139a4 + param_1);
  iVar6 = Envelope_c_vslot_12(param_1 + 0x948c,*(undefined4 *)(param_1 + 0x140),2);
  *(float *)(param_1 + 0x138e4) = (float)iVar6 * 0.01 + fVar10;
  fVar10 = *(float *)(&DAT_000139a8 + param_1);
  iVar6 = Envelope_c_vslot_12(param_1 + 0x9694,*(undefined4 *)(param_1 + 0x140),2);
  *(float *)(param_1 + 0x138e8) = (float)iVar6 * 0.01 + fVar10;
  iVar6 = *(int *)(param_1 + 0x144);
  iVar5 = *(int *)(param_1 + 0x160);
  fVar9 = *(float *)(iVar6 + 0x134) + *(float *)(&DAT_000139d0 + param_1) +
          *(float *)(iVar5 + 0x571c);
  *(float *)(&DAT_0001391c + param_1) = fVar9;
  *(float *)(&DAT_00013920 + param_1) =
       (*(float *)(iVar6 + 0x134) - *(float *)(&DAT_000139d0 + param_1)) +
       *(float *)(iVar5 + 0x578c);
  fVar10 = -1.0;
  fVar1 = fVar10;
  if (-1.0 <= fVar9) {
    fVar1 = (float)(~-(uint)(fVar9 <= 1.0) & (uint)1.0 | (uint)fVar9 & -(uint)(fVar9 <= 1.0));
  }
  *(float *)(&DAT_0001391c + param_1) = fVar1;
  fVar1 = *(float *)(&DAT_00013920 + param_1);
  if ((-1.0 <= fVar1) && (fVar10 = 1.0, fVar1 <= 1.0)) {
    fVar10 = fVar1;
  }
  *(float *)(&DAT_00013920 + param_1) = fVar10;
  *(undefined4 *)(&DAT_000138ec + param_1) = *(undefined4 *)(&DAT_000139c0 + param_1);
  fVar10 = *(float *)(&DAT_000139c8 + param_1);
  lVar8 = (longdouble)
          (**(code **)(**(int **)(&DAT_00013700 + param_1) + 0x6c))
                    (*(int **)(&DAT_00013700 + param_1),1);
  *(float *)(&DAT_000138f4 + param_1) = fVar10 + (float)lVar8;
  *(undefined4 *)(&DAT_000138fc + param_1) = 0;
  *(undefined4 *)(&DAT_000138f0 + param_1) = *(undefined4 *)(&DAT_000139c4 + param_1);
  fVar10 = *(float *)(&DAT_000139cc + param_1);
  lVar8 = (longdouble)
          (**(code **)(**(int **)(&DAT_00013704 + param_1) + 0x6c))
                    (*(int **)(&DAT_00013704 + param_1),1);
  *(float *)(&DAT_000138f8 + param_1) = fVar10 + (float)lVar8;
  *(undefined4 *)(&DAT_00013900 + param_1) = 0;
  lVar8 = (longdouble)
          (**(code **)(**(int **)(&DAT_00013700 + param_1) + 0x6c))
                    (*(int **)(&DAT_00013700 + param_1),2);
  *(float *)(&DAT_00013904 + param_1) = (float)lVar8 + *(float *)(&DAT_000139ac + param_1);
  lVar8 = (longdouble)
          (**(code **)(**(int **)(&DAT_00013704 + param_1) + 0x6c))
                    (*(int **)(&DAT_00013704 + param_1),2);
  *(float *)(&DAT_00013908 + param_1) = (float)lVar8 - *(float *)(&DAT_000139ac + param_1);
  iVar6 = *(int *)(param_1 + 0x160);
  *(undefined4 *)(&DAT_0001390c + param_1) = *(undefined4 *)(iVar6 + 0x5a38);
  *(undefined4 *)(&DAT_00013910 + param_1) = *(undefined4 *)(iVar6 + 0x5aa8);
  *(undefined4 *)(&DAT_00013914 + param_1) = *(undefined4 *)(iVar6 + 0xf8);
  *(undefined4 *)(&DAT_00013918 + param_1) =
       *(undefined4 *)(*(int *)(&DAT_00013958 + param_1) + 0x3b9c);
  *(undefined4 *)(&DAT_0001392c + param_1) = *(undefined4 *)(&DAT_000139d4 + param_1);
  *(undefined4 *)(&DAT_00013924 + param_1) = *(undefined4 *)(&DAT_000139d4 + param_1);
  *(undefined4 *)(&DAT_00013930 + param_1) = *(undefined4 *)(&DAT_000139d8 + param_1);
  *(undefined4 *)(&DAT_00013928 + param_1) = *(undefined4 *)(&DAT_000139d8 + param_1);
  *(undefined4 *)(&DAT_00013934 + param_1) = 0;
  *(undefined4 *)(&DAT_00013938 + param_1) = 0;
  *(undefined4 *)(&DAT_0001393c + param_1) = 0;
  *(undefined4 *)(&DAT_00013940 + param_1) = 0;
  if (*(char *)(iVar6 + 0x231c) != '\0') {
    *(float *)(&DAT_00013914 + param_1) =
         (*(float *)(*(int *)(param_1 + 0x144) + 0x130) + 1.0) * *(float *)(&DAT_00013914 + param_1)
    ;
  }
  fVar10 = *(float *)(param_1 + 0x124);
  *(float *)(&DAT_00013914 + param_1) =
       (fVar10 * *(float *)(LPAUSynth_vslot_0 + iVar6 + 4) + 1.0) *
       *(float *)(&DAT_00013914 + param_1);
  *(float *)(&DAT_000138ec + param_1) =
       *(float *)(&DAT_000138ec + param_1) + fVar10 * *(float *)(iVar6 + 0x4c9c) * 0.5;
  *(float *)(&DAT_000138f0 + param_1) =
       *(float *)(&DAT_000138f0 + param_1) + fVar10 * *(float *)(iVar6 + 0x4d0c) * 0.5;
  FUN_0002a00a();
  return;
}

