/* 000c6e62 FUN_000c6e62 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000c6e62(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  void *pvVar7;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  void *pvVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  
  puVar17 = (undefined4 *)param_1[1];
  if (puVar17 != (undefined4 *)param_1[2]) {
    if (puVar17 == (undefined4 *)0x0) {
      iVar12 = 0;
    }
    else {
      *puVar17 = puVar17[-6];
      puVar17[1] = puVar17[-5];
      puVar17[2] = puVar17[-4];
      puVar17[3] = puVar17[-3];
      puVar17[4] = puVar17[-2];
      puVar17[5] = puVar17[-1];
      iVar12 = param_1[1];
    }
    param_1[1] = iVar12 + 0x18;
    uVar3 = param_3[5];
    uVar1 = param_3[4];
    uVar2 = param_3[3];
    uVar4 = param_3[2];
    uVar5 = param_3[1];
    uVar6 = *param_3;
    iVar14 = iVar12 + -0x18;
    iVar8 = (iVar14 - (int)param_2 >> 3) * -0x55555555;
    if (0 < iVar8) {
      iVar15 = 0;
      do {
        *(undefined4 *)(iVar12 + -0x18) = *(undefined4 *)(iVar14 + -0x18);
        *(undefined4 *)(iVar12 + -0x14) = *(undefined4 *)(iVar14 + -0x14);
        *(undefined4 *)(iVar12 + -0x10) = *(undefined4 *)(iVar14 + -0x10);
        *(undefined4 *)(iVar12 + -0xc) = *(undefined4 *)(iVar14 + -0xc);
        *(undefined4 *)(iVar12 + -8) = *(undefined4 *)(iVar14 + -8);
        *(undefined4 *)(iVar12 + -4) = *(undefined4 *)(iVar14 + -4);
        iVar15 = iVar15 + 1;
        iVar14 = iVar14 + -0x18;
        iVar12 = iVar12 + -0x18;
      } while (iVar8 != iVar15);
    }
    param_2[5] = uVar3;
    param_2[4] = uVar1;
    param_2[3] = uVar2;
    param_2[2] = uVar4;
    param_2[1] = uVar5;
    *param_2 = uVar6;
    return;
  }
  iVar12 = (int)puVar17 - *param_1 >> 3;
  uVar9 = iVar12 * -0x55555555;
  if (uVar9 == 0xaaaaaaa) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("vector::_M_insert_aux");
  }
  if (uVar9 == 0) {
    uVar13 = 1;
  }
  else {
    uVar13 = iVar12 * 0x55555556;
    if (uVar13 < uVar9) {
      uVar13 = 0xaaaaaaa;
    }
    else if (0xaaaaaaa < uVar13) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_alloc();
    }
  }
  puVar10 = (undefined4 *)operator_new(uVar13 * 0x18);
  puVar17 = puVar10;
  for (puVar16 = (undefined4 *)*param_1; param_2 != puVar16; puVar16 = puVar16 + 6) {
    if (puVar17 != (undefined4 *)0x0) {
      *puVar17 = *puVar16;
      puVar17[1] = puVar16[1];
      puVar17[2] = puVar16[2];
      puVar17[3] = puVar16[3];
      puVar17[4] = puVar16[4];
      puVar17[5] = puVar16[5];
    }
    puVar17 = puVar17 + 6;
  }
  if (puVar17 != (undefined4 *)0x0) {
    *puVar17 = *param_3;
    puVar17[1] = param_3[1];
    puVar17[2] = param_3[2];
    puVar17[3] = param_3[3];
    puVar17[4] = param_3[4];
    puVar17[5] = param_3[5];
  }
  puVar16 = (undefined4 *)param_1[1];
  puVar17 = puVar17 + 6;
  if (puVar16 != param_2) {
    do {
      if (puVar17 != (undefined4 *)0x0) {
        *puVar17 = *param_2;
        puVar17[1] = param_2[1];
        puVar17[2] = param_2[2];
        puVar17[3] = param_2[3];
        puVar17[4] = param_2[4];
        puVar17[5] = param_2[5];
      }
      param_2 = param_2 + 6;
      puVar17 = puVar17 + 6;
    } while (param_2 != puVar16);
  }
  pvVar7 = (void *)*param_1;
  for (pvVar11 = pvVar7; (void *)param_1[1] != pvVar11; pvVar11 = (void *)((int)pvVar11 + 0x18)) {
  }
  if (pvVar7 != (void *)0x0) {
    operator_delete(pvVar7);
  }
  *param_1 = (int)puVar10;
  param_1[1] = (int)puVar17;
  param_1[2] = (int)(puVar10 + uVar13 * 6);
  return;
}

