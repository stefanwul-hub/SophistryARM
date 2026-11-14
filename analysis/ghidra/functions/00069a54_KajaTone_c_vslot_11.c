/* 00069a54 KajaTone_c_vslot_11 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */
/* WARNING: Type propagation algorithm not settling */

void KajaTone_c_vslot_11(int param_1,undefined4 param_2,int param_3,undefined1 param_4,char param_5)

{
  undefined8 uVar1;
  undefined4 *puVar2;
  float *pfVar3;
  undefined4 *puVar4;
  byte bVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  float *pfVar11;
  longdouble lVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  undefined4 *local_88;
  undefined4 *local_84;
  int local_80;
  int local_7c;
  undefined *local_30;
  undefined1 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  if (*(int *)(&DAT_00013958 + param_1) == 0) {
    return;
  }
  piVar6 = (int *)FUN_00017d68(*(int *)(&DAT_00013958 + param_1),param_2);
  if (piVar6 == (int *)0x0) {
    return;
  }
  iVar7 = (**(code **)(*piVar6 + 0x88))(piVar6,*(undefined4 *)(param_3 + 0x10));
  if (-1 < iVar7) {
    bVar5 = (**(code **)(*piVar6 + 0x84))(piVar6,*(undefined4 *)(param_3 + 0x10));
    uVar8 = (**(code **)(*piVar6 + 0x88))(piVar6,*(undefined4 *)(param_3 + 0x10));
    RampGlide_c_vslot_58(&UNK_00005a08 + param_1,param_2,uVar8,bVar5 ^ 1);
  }
  FUN_0002a3ec(param_1,4,piVar6 + 0x47,1,0);
  FUN_0002a3ec(param_1,5,piVar6 + 0x48,1,1);
  FUN_0002a3ec(param_1,6,piVar6 + 0x49,1,1);
  FUN_0002a3ec(param_1,7,piVar6 + 0x4a,1,1);
  FUN_0002a3ec(param_1,8,piVar6 + 0x4b,1,1);
  FUN_0002a3ec(param_1,9,piVar6 + 0x4e,1,0);
  FUN_0002a3ec(param_1,10,piVar6 + 0x4f,1,0);
  FUN_0002a3ec(param_1,0xb,piVar6 + 0x50,1,0);
  FUN_0002a3ec(param_1,0xc,piVar6 + 0x51,1,0);
  FUN_0002a3ec(param_1,0x19,piVar6 + 0xc7b,0,1);
  local_2c = *(undefined1 *)(param_3 + 4);
  local_28 = *(undefined4 *)(param_3 + 8);
  local_24 = *(undefined4 *)(param_3 + 0xc);
  local_30 = PTR_DAT_00103814 + 8;
  local_20 = *(undefined4 *)(param_3 + 0x10);
  Tone_c_vslot_11(param_1,param_2,&local_30,param_4,param_5);
  local_30 = PTR_DAT_00103808 + 8;
  if (*(int *)(param_1 + 0x160) == 0) {
    return;
  }
  if (*(char *)(*(int *)(param_1 + 0x160) + 0x23fc) == '\0') {
    *(undefined4 *)(param_1 + 0x170) = 0;
    *(undefined4 *)(param_1 + 0x16c) = 0;
    iVar7 = (**(code **)(**(int **)(&DAT_0001395c + param_1) + 0x30))
                      (*(int **)(&DAT_0001395c + param_1),param_2,0x95);
    if (iVar7 == 0) goto LAB_00069d6e;
LAB_0006a09e:
    uVar1 = *(undefined8 *)(*(int *)(param_1 + 0x144) + 0x160);
    FUN_00084996(param_1 + 0xc50,(int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
    iVar7 = (**(code **)(**(int **)(&DAT_0001395c + param_1) + 0x30))
                      (*(int **)(&DAT_0001395c + param_1),param_2,0x96);
    if (iVar7 == 0) goto LAB_00069d96;
LAB_0006a0ec:
    uVar1 = *(undefined8 *)(*(int *)(param_1 + 0x144) + 0x168);
    FUN_00084996(param_1 + 0x1990,(int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
    iVar7 = (**(code **)(**(int **)(&DAT_0001395c + param_1) + 0x30))
                      (*(int **)(&DAT_0001395c + param_1),param_2,0x97);
    if (iVar7 == 0) goto LAB_00069dbe;
LAB_0006a13a:
    uVar1 = *(undefined8 *)(*(int *)(param_1 + 0x144) + 0x170);
    FUN_00084996(param_1 + 0x26d0,(int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
    iVar7 = (**(code **)(**(int **)(&DAT_0001395c + param_1) + 0x30))
                      (*(int **)(&DAT_0001395c + param_1),param_2,0x98);
  }
  else {
    iVar7 = (**(code **)(**(int **)(&DAT_0001395c + param_1) + 0x30))
                      (*(int **)(&DAT_0001395c + param_1),param_2,0x95);
    if (iVar7 != 0) goto LAB_0006a09e;
LAB_00069d6e:
    iVar7 = (**(code **)(**(int **)(&DAT_0001395c + param_1) + 0x30))
                      (*(int **)(&DAT_0001395c + param_1),param_2,0x96);
    if (iVar7 != 0) goto LAB_0006a0ec;
LAB_00069d96:
    iVar7 = (**(code **)(**(int **)(&DAT_0001395c + param_1) + 0x30))
                      (*(int **)(&DAT_0001395c + param_1),param_2,0x97);
    if (iVar7 != 0) goto LAB_0006a13a;
LAB_00069dbe:
    iVar7 = (**(code **)(**(int **)(&DAT_0001395c + param_1) + 0x30))
                      (*(int **)(&DAT_0001395c + param_1),param_2,0x98);
  }
  if (iVar7 != 0) {
    uVar1 = *(undefined8 *)(*(int *)(param_1 + 0x144) + 0x178);
    FUN_00084996(param_1 + 0x3410,(int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  }
  FUN_0002aea8(param_1,8,0x20,0x38,0x1c,10,4,0xffffffff);
  iVar7 = *(int *)(param_1 + 0x160);
  iVar10 = *(int *)(iVar7 + 0x2768);
  if (iVar10 == 1) {
    *(int *)(&DAT_000136f0 + param_1) = param_1 + 0x6e6c;
  }
  else if (iVar10 < 2) {
    if (iVar10 == 0) {
      *(int *)(&DAT_000136f0 + param_1) = param_1 + 0x5c0c;
    }
  }
  else if (iVar10 == 2) {
    *(int *)(&DAT_000136f0 + param_1) = param_1 + 0x7d8c;
  }
  else {
    if (iVar10 != 3) {
      iVar10 = *(int *)(iVar7 + 0x27d8);
      goto joined_r0x0006a1d6;
    }
    *(int *)(&DAT_000136f0 + param_1) = param_1 + 0x87bc;
  }
  iVar10 = *(int *)(iVar7 + 0x27d8);
joined_r0x0006a1d6:
  if (iVar10 == 1) {
    *(int *)(&DAT_000136f4 + param_1) = param_1 + 0x7234;
    iVar10 = *(int *)(iVar7 + 0x2ca8);
  }
  else {
    if (iVar10 < 2) {
      if (iVar10 == 0) {
        *(int *)(&DAT_000136f4 + param_1) = param_1 + 0x60a4;
      }
    }
    else if (iVar10 == 2) {
      *(int *)(&DAT_000136f4 + param_1) = param_1 + 0x8018;
    }
    else if (iVar10 == 3) {
      *(int *)(&DAT_000136f4 + param_1) = param_1 + 0x8c1c;
    }
    iVar10 = *(int *)(iVar7 + 0x2ca8);
  }
  if (iVar10 == 1) {
    *(int *)(&DAT_000136f8 + param_1) = param_1 + 0x75fc;
    iVar10 = *(int *)(iVar7 + 0x2d18);
  }
  else {
    if (iVar10 == 2) {
      *(int *)(&DAT_000136f8 + param_1) = param_1 + 0x82a4;
    }
    else if (iVar10 == 0) {
      *(int *)(&DAT_000136f8 + param_1) = param_1 + 0x653c;
    }
    iVar10 = *(int *)(iVar7 + 0x2d18);
  }
  if (iVar10 == 1) {
    *(int *)(&DAT_000136fc + param_1) = param_1 + 0x79c4;
    iVar10 = *(int *)(iVar7 + 0x2e68);
  }
  else {
    if (iVar10 == 2) {
      *(int *)(&DAT_000136fc + param_1) = param_1 + 0x8530;
    }
    else if (iVar10 == 0) {
      *(int *)(&DAT_000136fc + param_1) = param_1 + 0x69d4;
    }
    iVar10 = *(int *)(iVar7 + 0x2e68);
  }
  if (iVar10 == 0) {
    *(int *)(&DAT_00013700 + param_1) = param_1 + 0xa4bc;
  }
  else if (iVar10 == 1) {
    *(int *)(&DAT_00013700 + param_1) = param_1 + 0x12b34;
  }
  local_7c = param_1 + 0x8c1c;
  local_80 = param_1 + 0x87bc;
  if (*(int *)(iVar7 + 0x2ed8) == 0) {
    *(int *)(&DAT_00013704 + param_1) = param_1 + 0xe7f8;
  }
  else if (*(int *)(iVar7 + 0x2ed8) == 1) {
    *(int *)(&DAT_00013704 + param_1) = param_1 + 0x12e10;
  }
  (**(code **)(**(int **)(&DAT_000136f0 + param_1) + 0x98))
            (*(int **)(&DAT_000136f0 + param_1),param_2);
  (**(code **)(**(int **)(&DAT_000136f4 + param_1) + 0x98))
            (*(int **)(&DAT_000136f4 + param_1),param_2);
  (**(code **)(**(int **)(&DAT_000136f8 + param_1) + 0x98))
            (*(int **)(&DAT_000136f8 + param_1),param_2);
  (**(code **)(**(int **)(&DAT_000136fc + param_1) + 0x98))
            (*(int **)(&DAT_000136fc + param_1),param_2);
  (**(code **)(**(int **)(&DAT_00013700 + param_1) + 0x98))
            (*(int **)(&DAT_00013700 + param_1),param_2);
  (**(code **)(**(int **)(&DAT_00013704 + param_1) + 0x98))
            (*(int **)(&DAT_00013704 + param_1),param_2);
  lVar12 = (longdouble)
           _pow((double)(1.0 - *(float *)(*(int *)(param_1 + 0x160) + 0x57fc)),0,0x3ff80000);
  fVar13 = (float)((double)lVar12 * 4.0);
  fVar14 = fVar13 * 0.02;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_0001397c + param_1) = (float)lVar12 * fVar14;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_00013980 + param_1) = (float)lVar12 * fVar14;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_00013984 + param_1) = (float)lVar12 * fVar14;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_00013988 + param_1) = fVar14 * (float)lVar12;
  fVar14 = fVar13 * 1.2;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_0001398c + param_1) = (float)lVar12 * fVar14;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_00013990 + param_1) = (float)lVar12 * fVar14;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_00013994 + param_1) = (float)lVar12 * fVar14;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_00013998 + param_1) = fVar14 * (float)lVar12;
  fVar14 = fVar13 * 1.4;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_0001399c + param_1) = (float)lVar12 * fVar14;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139a0 + param_1) = (float)lVar12 * fVar14;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139a4 + param_1) = (float)lVar12 * fVar14;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139a8 + param_1) = fVar14 * (float)lVar12;
  fVar14 = fVar13 * 0.5;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139ac + param_1) = (float)lVar12 * fVar14;
  fVar15 = fVar13 * -2.0;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139b0 + param_1) = (float)lVar12 * fVar15 + 1.0;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139b4 + param_1) = (float)lVar12 * fVar15 + 1.0;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139b8 + param_1) = (float)lVar12 * fVar15 + 1.0;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139bc + param_1) = fVar15 * (float)lVar12 + 1.0;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139c0 + param_1) = (float)lVar12 * fVar14;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139c4 + param_1) = (float)lVar12 * fVar14;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139c8 + param_1) = (float)lVar12 * fVar13 * 0.7;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139cc + param_1) = fVar13 * 0.7 * (float)lVar12;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139d0 + param_1) = fVar13 * (float)lVar12;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139d4 + param_1) = (float)lVar12 * fVar14;
  lVar12 = (longdouble)FUN_0002e314();
  *(float *)(&DAT_000139d8 + param_1) = fVar14 * (float)lVar12;
  lVar12 = (longdouble)
           (**(code **)(**(int **)(&DAT_00013700 + param_1) + 0x6c))
                     (*(int **)(&DAT_00013700 + param_1),0);
  *(float *)(&DAT_00013968 + param_1) = (float)lVar12;
  lVar12 = (longdouble)
           (**(code **)(**(int **)(&DAT_00013704 + param_1) + 0x6c))
                     (*(int **)(&DAT_00013704 + param_1),0);
  *(float *)(&DAT_0001396c + param_1) = (float)lVar12;
  iVar7 = *(int *)(param_1 + 0x160);
  (&DAT_00013970)[param_1] = *(undefined1 *)(iVar7 + 0x32c);
  (&DAT_00013971)[param_1] = *(undefined1 *)(iVar7 + 0x357c);
  *(undefined4 *)(&DAT_00013974 + param_1) = *(undefined4 *)(iVar7 + 0x2ac);
  *(undefined4 *)(&DAT_00013978 + param_1) = *(undefined4 *)(iVar7 + 0x34fc);
  *(undefined4 *)(&DAT_00013944 + param_1) = 0;
  *(undefined4 *)(&DAT_00013948 + param_1) = 0;
  if (*(int *)(param_1 + 0x160) != 0) {
    iVar9 = 0;
    iVar10 = param_1;
    do {
      if (*(char *)(iVar9 + iVar7 + 0x36cc) == '\0') {
        *(undefined4 *)(iVar10 + 0x1d8) = 0;
      }
      else {
        *(undefined4 *)(iVar10 + 0x1d8) = *(undefined4 *)(iVar9 + iVar7 + 0xe0c);
      }
      iVar9 = iVar9 + 0x70;
      iVar10 = iVar10 + 4;
    } while (iVar9 != 0x460);
    *(int *)(param_1 + 0xc28) = param_1 + 0x9d0;
    *(int *)(param_1 + 0xc2c) = param_1 + 0xa34;
    *(int *)(param_1 + 0xc30) = param_1 + 0xa98;
    pfVar11 = *(float **)(param_1 + 0x9d0);
    if (pfVar11 != (float *)0x0) {
      local_88 = (undefined4 *)(param_1 + 0x9d4);
      do {
        puVar2 = *(undefined4 **)(param_1 + 0xc30);
        pfVar3 = (float *)*puVar2;
        puVar4 = *(undefined4 **)(param_1 + 0xc2c);
        *pfVar3 = (*pfVar11 * *(float *)*puVar4 + 1.0) * *pfVar3;
        *(undefined4 **)(param_1 + 0xc30) = puVar2 + 1;
        *(undefined4 **)(param_1 + 0xc28) = local_88;
        *(undefined4 **)(param_1 + 0xc2c) = puVar4 + 1;
        pfVar11 = (float *)*local_88;
        local_88 = local_88 + 1;
      } while (pfVar11 != (float *)0x0);
    }
    *(int *)(param_1 + 0xc28) = param_1 + 0xafc;
    *(int *)(param_1 + 0xc2c) = param_1 + 0xb60;
    *(int *)(param_1 + 0xc30) = param_1 + 0xbc4;
    pfVar11 = *(float **)(param_1 + 0xafc);
    if (pfVar11 != (float *)0x0) {
      local_84 = (undefined4 *)(param_1 + 0xb00);
      do {
        puVar2 = *(undefined4 **)(param_1 + 0xc30);
        pfVar3 = (float *)*puVar2;
        puVar4 = *(undefined4 **)(param_1 + 0xc2c);
        *pfVar3 = *pfVar11 * *(float *)*puVar4 + *pfVar3;
        *(undefined4 **)(param_1 + 0xc30) = puVar2 + 1;
        *(undefined4 **)(param_1 + 0xc28) = local_84;
        *(undefined4 **)(param_1 + 0xc2c) = puVar4 + 1;
        pfVar11 = (float *)*local_84;
        local_84 = local_84 + 1;
      } while (pfVar11 != (float *)0x0);
    }
  }
  if (param_5 == '\0') {
    FUN_0003c484(param_1 + 0x5680,0);
    FUN_0003c484(param_1 + 0x4f70,0);
    FUN_0003c484(&UNK_000052f8 + param_1,0);
    FUN_0003c484(param_1 + 0x4860,0);
    FUN_0003c484(&UNK_00004be8 + param_1,0);
  }
  FUN_00036822(local_80,*(undefined4 *)(&DAT_00013944 + param_1));
  FUN_00036822(local_7c,*(undefined4 *)(&DAT_00013948 + param_1));
  return;
}

