/* 00004250 LPAUSynth_vslot_22 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 LPAUSynth_vslot_22(int *param_1,uint *param_2,double *param_3,undefined4 param_4)

{
  uint *puVar1;
  undefined1 auVar2 [12];
  uint uVar3;
  int *piVar4;
  void *pvVar5;
  void *pvVar6;
  uint *puVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  double dVar11;
  double dVar12;
  uint local_7c;
  uint local_4c;
  uint local_48;
  uint local_40;
  uint local_38;
  int local_30;
  
  if (*(char *)((int)param_1 + 0x32b432) != '\0') {
    uVar3 = param_1[0x15] - param_1[0x14] >> 2;
    if (uVar3 != 0) {
      local_4c = 0;
      do {
        piVar4 = (int *)param_1[0x14] + local_4c;
        if ((((int *)param_1[0x15] <= piVar4) || (piVar4 < (int *)param_1[0x14])) ||
           (iVar9 = *piVar4, iVar9 == 0)) goto LAB_000044d5;
        FUN_000ae306(iVar9 + 0x5c,iVar9 + 0x34,param_4);
        piVar4 = (int *)param_1[0x14] + local_4c;
        if ((((int *)param_1[0x15] <= piVar4) || (piVar4 < (int *)param_1[0x14])) ||
           (iVar9 = *piVar4, iVar9 == 0)) {
LAB_000045aa:
          puVar8 = (undefined4 *)___cxa_allocate_exception(4);
          *puVar8 = 0xffffd583;
                    /* WARNING: Subroutine does not return */
          ___cxa_throw(puVar8,PTR_001037fc,0);
        }
        if (*(int *)(iVar9 + 0x5c) == 0) goto LAB_00004898;
        puVar1 = *(uint **)(iVar9 + 100);
        if (*puVar1 != 0) {
          local_48 = 0;
          puVar7 = puVar1;
          do {
            _memset((void *)puVar7[3],0,puVar7[2]);
            local_48 = local_48 + 1;
            puVar7 = puVar7 + 3;
          } while (local_48 < *puVar1);
        }
        local_4c = local_4c + 1;
      } while (local_4c < uVar3);
    }
    *param_2 = *param_2 | 0x10;
    return 0;
  }
  dVar11 = *(double *)(param_1 + 0xcad0e);
  if ((dVar11 != 0.0) && (dVar11 < *param_3)) {
    *(undefined1 *)((int)param_1 + 0x32b431) = 1;
    dVar11 = *param_3 - dVar11;
    dVar12 = dVar11;
    if (4294967295.0 <= dVar11) {
      dVar12 = 4294967295.0;
    }
    if (dVar12 <= 0.0) {
      dVar12 = 0.0;
    }
    uVar3 = (uint)(dVar12 - (double)(-(ulonglong)(2147483648.0 <= dVar11) & 0x41e0000000000000));
    local_7c = (uint)(2147483648.0 <= dVar11) * -0x80000000 ^ uVar3;
    pvVar5 = operator_new__(uVar3 << 4);
    _memset(pvVar5,0,uVar3 << 4);
    if (param_1[0xcad08] != 0) {
      uVar10 = 0;
      do {
        pvVar6 = pvVar5;
        if ((uVar10 & 1) == 0) {
          pvVar6 = (void *)((int)pvVar5 + uVar3 * 4);
        }
        *(void **)(param_1[0xcad00] + uVar10 * 4) = pvVar6;
        uVar10 = uVar10 + 1;
      } while (uVar10 < (uint)param_1[0xcad08]);
    }
    *(void **)param_1[0xcacff] = (void *)((int)pvVar5 + uVar3 * 8);
    *(void **)(param_1[0xcacff] + 4) = (void *)((int)pvVar5 + uVar3 * 0xc);
    param_1[0x342b] = 0;
    (**(code **)(param_1[0x3b] + 0xb0))(param_1 + 0x3b,param_1[0xcacff],param_1[0xcad00],local_7c);
    if (pvVar5 != (void *)0x0) {
      operator_delete__(pvVar5);
    }
    *(undefined1 *)((int)param_1 + 0x32b431) = 0;
  }
  auVar2._4_4_ = param_4;
  auVar2._0_4_ = param_4;
  auVar2._8_4_ = 0x43300000;
  *(double *)(param_1 + 0xcad0e) = (auVar2._4_8_ - 4503599627370496.0) + 0.0 + *param_3;
  param_1[0xcacd7] = *(int *)param_3;
  param_1[0xcacd8] = *(int *)((int)param_3 + 4);
  param_1[0xcacd9] = *(int *)(param_3 + 1);
  param_1[0xcacda] = *(int *)((int)param_3 + 0xc);
  param_1[0xcacdb] = *(int *)(param_3 + 2);
  param_1[0xcacdc] = *(int *)((int)param_3 + 0x14);
  param_1[0xcacdd] = *(int *)(param_3 + 3);
  param_1[0xcacde] = *(int *)((int)param_3 + 0x1c);
  param_1[0xcacdf] = *(int *)(param_3 + 4);
  param_1[0xcace0] = *(int *)((int)param_3 + 0x24);
  param_1[0xcace1] = *(int *)(param_3 + 5);
  param_1[0xcace2] = *(int *)((int)param_3 + 0x2c);
  param_1[0xcace3] = *(int *)(param_3 + 6);
  param_1[0xcace4] = *(int *)((int)param_3 + 0x34);
  param_1[0xcace5] = *(int *)(param_3 + 7);
  param_1[0xcace6] = *(int *)((int)param_3 + 0x3c);
  (**(code **)(*param_1 + 0x138))(param_1);
  uVar3 = param_1[0x15] - param_1[0x14] >> 2;
  if (uVar3 == 0) {
    uVar10 = 0;
LAB_0000439c:
    iVar9 = uVar10 * 4;
    do {
      *(undefined4 *)(iVar9 + param_1[0xcad00]) = 0;
      uVar10 = uVar10 + 1;
      iVar9 = iVar9 + 4;
    } while (uVar10 != 6);
  }
  else {
    local_40 = 0;
    uVar10 = 0;
    do {
      piVar4 = (int *)param_1[0x14] + local_40;
      if ((((int *)param_1[0x15] <= piVar4) || (piVar4 < (int *)param_1[0x14])) ||
         (iVar9 = *piVar4, iVar9 == 0)) goto LAB_000045aa;
      FUN_000ae306(iVar9 + 0x5c,iVar9 + 0x34,param_4);
      piVar4 = (int *)param_1[0x14] + local_40;
      if ((((int *)param_1[0x15] <= piVar4) || (piVar4 < (int *)param_1[0x14])) ||
         (iVar9 = *piVar4, iVar9 == 0)) goto LAB_000045aa;
      if (*(int *)(iVar9 + 0x5c) == 0) goto LAB_00004898;
      puVar1 = *(uint **)(iVar9 + 100);
      if ((uVar10 < 6) && (*puVar1 != 0)) {
        local_30 = uVar10 * 4;
        local_38 = 0;
        puVar7 = puVar1;
        do {
          _memset((void *)puVar7[3],0,puVar7[2]);
          if ((uVar10 < (uint)param_1[0xcad08]) && (uVar10 < (uint)param_1[0x342a])) {
            *(uint *)(local_30 + param_1[0xcad00]) = puVar7[3];
          }
          uVar10 = uVar10 + 1;
          local_38 = local_38 + 1;
          if (uVar10 == 6) break;
          puVar7 = puVar7 + 3;
          local_30 = local_30 + 4;
        } while (local_38 < *puVar1);
      }
      local_40 = local_40 + 1;
    } while (local_40 < uVar3);
    if (uVar10 < 6) goto LAB_0000439c;
  }
  piVar4 = (int *)param_1[0xf];
  if (param_1[0x10] - (int)piVar4 >> 2 == 0) {
LAB_000043ce:
    uVar3 = 0;
  }
  else {
    if (((int *)param_1[0x10] <= piVar4) || (iVar9 = *piVar4, iVar9 == 0)) {
LAB_000044d5:
      puVar8 = (undefined4 *)___cxa_allocate_exception(4);
      *puVar8 = 0xffffd583;
LAB_000044e7:
                    /* WARNING: Subroutine does not return */
      ___cxa_throw(puVar8,PTR_001037fc,0);
    }
    if (*(int *)(iVar9 + 0x78) == 0) goto LAB_000043ce;
    iVar9 = FUN_000ab0d8(iVar9,param_2,param_3,0,param_4);
    if (iVar9 == 0) {
      if (((int *)param_1[0x10] <= (int *)param_1[0xf]) ||
         (iVar9 = *(int *)param_1[0xf], iVar9 == 0)) goto LAB_000044d5;
      if (*(int *)(iVar9 + 0x5c) == 0) {
LAB_00004898:
        puVar8 = (undefined4 *)___cxa_allocate_exception(4);
        *puVar8 = 0xffffffff;
        goto LAB_000044e7;
      }
      puVar1 = *(uint **)(iVar9 + 100);
      if (*puVar1 == 0) goto LAB_000047be;
      uVar3 = 0;
      puVar7 = puVar1;
      do {
        *(uint *)(param_1[0xcacff] + uVar3 * 4) = puVar7[3];
        uVar3 = uVar3 + 1;
        puVar7 = puVar7 + 3;
      } while (uVar3 < *puVar1);
    }
    else {
LAB_000047be:
      uVar3 = 0;
    }
    param_1[0x342b] = uVar3;
    if (uVar3 == 1) {
      ((undefined4 *)param_1[0xcacff])[1] = *(undefined4 *)param_1[0xcacff];
      param_1[0x342b] = 2;
      goto LAB_000043ef;
    }
    if (1 < uVar3) goto LAB_000043ef;
  }
  iVar9 = uVar3 * 4;
  do {
    *(undefined4 *)(param_1[0xcacff] + iVar9) = 0;
    uVar3 = uVar3 + 1;
    iVar9 = iVar9 + 4;
  } while (uVar3 != 2);
LAB_000043ef:
  (**(code **)(param_1[0x3b] + 0xb0))(param_1 + 0x3b,param_1[0xcacff],param_1[0xcad00],param_4);
  return 0;
}

