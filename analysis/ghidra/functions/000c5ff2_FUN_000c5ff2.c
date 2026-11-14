/* 000c5ff2 FUN_000c5ff2 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000c5ff2(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  void *pvVar10;
  uint uVar11;
  undefined4 *puVar12;
  void *pvVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  undefined4 *puVar18;
  int iVar19;
  
  puVar1 = (undefined4 *)param_1[1];
  if (puVar1 != (undefined4 *)param_1[2]) {
    if (puVar1 == (undefined4 *)0x0) {
      iVar15 = 0;
    }
    else {
      *puVar1 = puVar1[-8];
      puVar1[1] = puVar1[-7];
      puVar1[2] = puVar1[-6];
      puVar1[3] = puVar1[-5];
      puVar1[4] = puVar1[-4];
      puVar1[5] = puVar1[-3];
      puVar1[6] = puVar1[-2];
      puVar1[7] = puVar1[-1];
      iVar15 = param_1[1];
    }
    param_1[1] = iVar15 + 0x20;
    uVar2 = *param_3;
    uVar3 = param_3[1];
    uVar4 = param_3[2];
    uVar5 = param_3[3];
    uVar6 = param_3[4];
    uVar7 = param_3[5];
    uVar8 = param_3[6];
    uVar9 = param_3[7];
    iVar14 = iVar15 + -0x20;
    iVar19 = iVar14 - (int)param_2 >> 5;
    if (0 < iVar19) {
      iVar17 = 0;
      do {
        *(undefined4 *)(iVar15 + -0x20) = *(undefined4 *)(iVar14 + -0x20);
        *(undefined4 *)(iVar15 + -0x1c) = *(undefined4 *)(iVar14 + -0x1c);
        *(undefined4 *)(iVar15 + -0x18) = *(undefined4 *)(iVar14 + -0x18);
        *(undefined4 *)(iVar15 + -0x14) = *(undefined4 *)(iVar14 + -0x14);
        *(undefined4 *)(iVar15 + -0x10) = *(undefined4 *)(iVar14 + -0x10);
        *(undefined4 *)(iVar15 + -0xc) = *(undefined4 *)(iVar14 + -0xc);
        *(undefined4 *)(iVar15 + -8) = *(undefined4 *)(iVar14 + -8);
        *(undefined4 *)(iVar15 + -4) = *(undefined4 *)(iVar14 + -4);
        iVar17 = iVar17 + 1;
        iVar14 = iVar14 + -0x20;
        iVar15 = iVar15 + -0x20;
      } while (iVar19 != iVar17);
    }
    *param_2 = uVar2;
    param_2[1] = uVar3;
    param_2[2] = uVar4;
    param_2[3] = uVar5;
    param_2[4] = uVar6;
    param_2[5] = uVar7;
    param_2[6] = uVar8;
    param_2[7] = uVar9;
    return;
  }
  uVar11 = (int)puVar1 - *param_1 >> 5;
  if (uVar11 == 0x7ffffff) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("vector::_M_insert_aux");
  }
  if (uVar11 == 0) {
    uVar16 = 1;
  }
  else {
    uVar16 = uVar11 * 2;
    if (uVar16 < uVar11) {
      uVar16 = 0x7ffffff;
    }
    else if (0x7ffffff < uVar16) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_alloc();
    }
  }
  puVar12 = (undefined4 *)operator_new(uVar16 * 0x20);
  puVar18 = puVar12;
  for (puVar1 = (undefined4 *)*param_1; param_2 != puVar1; puVar1 = puVar1 + 8) {
    if (puVar18 != (undefined4 *)0x0) {
      *puVar18 = *puVar1;
      puVar18[1] = puVar1[1];
      puVar18[2] = puVar1[2];
      puVar18[3] = puVar1[3];
      puVar18[4] = puVar1[4];
      puVar18[5] = puVar1[5];
      puVar18[6] = puVar1[6];
      puVar18[7] = puVar1[7];
    }
    puVar18 = puVar18 + 8;
  }
  if (puVar18 != (undefined4 *)0x0) {
    *puVar18 = *param_3;
    puVar18[1] = param_3[1];
    puVar18[2] = param_3[2];
    puVar18[3] = param_3[3];
    puVar18[4] = param_3[4];
    puVar18[5] = param_3[5];
    puVar18[6] = param_3[6];
    puVar18[7] = param_3[7];
  }
  puVar1 = (undefined4 *)param_1[1];
  puVar18 = puVar18 + 8;
  if (puVar1 != param_2) {
    do {
      if (puVar18 != (undefined4 *)0x0) {
        *puVar18 = *param_2;
        puVar18[1] = param_2[1];
        puVar18[2] = param_2[2];
        puVar18[3] = param_2[3];
        puVar18[4] = param_2[4];
        puVar18[5] = param_2[5];
        puVar18[6] = param_2[6];
        puVar18[7] = param_2[7];
      }
      param_2 = param_2 + 8;
      puVar18 = puVar18 + 8;
    } while (param_2 != puVar1);
  }
  pvVar10 = (void *)*param_1;
  for (pvVar13 = pvVar10; (void *)param_1[1] != pvVar13; pvVar13 = (void *)((int)pvVar13 + 0x20)) {
  }
  if (pvVar10 != (void *)0x0) {
    operator_delete(pvVar10);
  }
  *param_1 = (int)puVar12;
  param_1[1] = (int)puVar18;
  param_1[2] = (int)(puVar12 + uVar16 * 8);
  return;
}

