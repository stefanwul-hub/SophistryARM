/* 000c5bba FUN_000c5bba */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

void FUN_000c5bba(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  void *pvVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  
  puVar14 = (undefined4 *)param_1[1];
  if (puVar14 != (undefined4 *)param_1[2]) {
    if (puVar14 == (undefined4 *)0x0) {
      iVar9 = 0;
    }
    else {
      *puVar14 = puVar14[-3];
      puVar14[1] = puVar14[-2];
      puVar14[2] = puVar14[-1];
      iVar9 = param_1[1];
    }
    param_1[1] = iVar9 + 0xc;
    uVar1 = param_3[2];
    uVar2 = param_3[1];
    uVar3 = *param_3;
    iVar11 = iVar9 + -0xc;
    iVar5 = (iVar11 - (int)param_2 >> 2) * -0x55555555;
    if (0 < iVar5) {
      iVar12 = 0;
      do {
        *(undefined4 *)(iVar9 + -0xc) = *(undefined4 *)(iVar11 + -0xc);
        *(undefined4 *)(iVar9 + -8) = *(undefined4 *)(iVar11 + -8);
        *(undefined4 *)(iVar9 + -4) = *(undefined4 *)(iVar11 + -4);
        iVar12 = iVar12 + 1;
        iVar11 = iVar11 + -0xc;
        iVar9 = iVar9 + -0xc;
      } while (iVar5 != iVar12);
    }
    param_2[2] = uVar1;
    param_2[1] = uVar2;
    *param_2 = uVar3;
    return;
  }
  iVar9 = (int)puVar14 - *param_1 >> 2;
  uVar6 = iVar9 * -0x55555555;
  if (uVar6 == 0x15555555) {
                    /* WARNING: Subroutine does not return */
    std::__throw_length_error("vector::_M_insert_aux");
  }
  if (uVar6 == 0) {
    uVar10 = 1;
  }
  else {
    uVar10 = iVar9 * 0x55555556;
    if (uVar10 < uVar6) {
      uVar10 = 0x15555555;
    }
    else if (0x15555555 < uVar10) {
                    /* WARNING: Subroutine does not return */
      std::__throw_bad_alloc();
    }
  }
  puVar7 = (undefined4 *)operator_new(uVar10 * 0xc);
  puVar14 = puVar7;
  for (puVar13 = (undefined4 *)*param_1; param_2 != puVar13; puVar13 = puVar13 + 3) {
    if (puVar14 != (undefined4 *)0x0) {
      *puVar14 = *puVar13;
      puVar14[1] = puVar13[1];
      puVar14[2] = puVar13[2];
    }
    puVar14 = puVar14 + 3;
  }
  if (puVar14 != (undefined4 *)0x0) {
    *puVar14 = *param_3;
    puVar14[1] = param_3[1];
    puVar14[2] = param_3[2];
  }
  puVar13 = (undefined4 *)param_1[1];
  puVar14 = puVar14 + 3;
  if (puVar13 != param_2) {
    do {
      if (puVar14 != (undefined4 *)0x0) {
        *puVar14 = *param_2;
        puVar14[1] = param_2[1];
        puVar14[2] = param_2[2];
      }
      param_2 = param_2 + 3;
      puVar14 = puVar14 + 3;
    } while (param_2 != puVar13);
  }
  pvVar4 = (void *)*param_1;
  for (pvVar8 = pvVar4; (void *)param_1[1] != pvVar8; pvVar8 = (void *)((int)pvVar8 + 0xc)) {
  }
  if (pvVar4 != (void *)0x0) {
    operator_delete(pvVar4);
  }
  *param_1 = (int)puVar7;
  param_1[1] = (int)puVar14;
  param_1[2] = (int)(puVar7 + uVar10 * 3);
  return;
}

