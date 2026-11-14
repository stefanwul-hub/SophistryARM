/* 000a8ce4 LPAUSynth_vslot_53 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

int LPAUSynth_vslot_53(int *param_1,int *param_2,uint param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  uint *puVar10;
  uint *local_38;
  uint local_30;
  uint local_2c;
  uint local_20;
  
  piVar2 = param_2 + 1;
  iVar9 = param_2[1];
  iVar5 = *param_2;
  if (iVar9 != iVar5) {
    iVar3 = iVar9 - iVar5 >> 5;
    if (iVar3 == 1) {
      iVar7 = 0;
    }
    else {
      iVar7 = 0;
      do {
        iVar7 = iVar7 + 1;
        iVar3 = iVar3 >> 1;
      } while (iVar3 != 1);
      iVar7 = iVar7 * 2;
    }
    FUN_000c595c(iVar5,iVar9,iVar7,FUN_000a66a0);
    FUN_000c508a(iVar5,iVar9,FUN_000a66a0);
  }
  if ((int)param_3 < 1) {
    return 0;
  }
  local_30 = param_3;
  local_2c = 0;
  puVar10 = (uint *)*param_2;
  local_38 = (uint *)*piVar2;
  if (puVar10 == local_38) goto LAB_000a8ec4;
LAB_000a8d8b:
  local_20 = param_3;
  puVar8 = puVar10;
  do {
    while( true ) {
      uVar4 = puVar8[4];
      if (((int)local_2c < (int)uVar4) && ((int)uVar4 < (int)local_20)) goto LAB_000a8dd1;
      if ((puVar8[3] != 2) || (uVar4 = uVar4 + puVar8[5], (int)uVar4 <= (int)local_2c)) break;
      if ((int)local_20 <= (int)uVar4) {
        uVar4 = local_20;
      }
      puVar8 = puVar8 + 8;
      local_20 = uVar4;
      if (local_38 == puVar8) goto LAB_000a8dd1;
    }
    puVar8 = puVar8 + 8;
    uVar4 = local_20;
  } while (local_38 != puVar8);
LAB_000a8dd1:
  do {
    local_20 = uVar4;
    iVar9 = local_20 - local_2c;
    if (puVar10 != local_38) {
LAB_000a8e49:
      do {
        if (puVar10[3] == 2) {
          if ((int)puVar10[4] < (int)local_20) {
            if (puVar10[4] + puVar10[5] <= local_2c) {
              puVar10 = puVar10 + 8;
              if (local_38 == puVar10) break;
              goto LAB_000a8e49;
            }
LAB_000a8deb:
            uVar4 = *puVar10;
            if (4 < uVar4) {
              puVar6 = (undefined4 *)___cxa_allocate_exception(4);
              *puVar6 = 0xffffd58e;
                    /* WARNING: Subroutine does not return */
              ___cxa_throw(puVar6,PTR_001037fc,0);
            }
            piVar1 = (int *)param_1[uVar4 * 5 + 10] + puVar10[1];
            if (((piVar1 < (int *)param_1[uVar4 * 5 + 0xb]) &&
                ((int *)param_1[uVar4 * 5 + 10] <= piVar1)) && (*piVar1 != 0)) {
              FUN_000aba02(*piVar1,puVar10[2],puVar10,local_2c,iVar9);
              local_38 = (uint *)*piVar2;
            }
          }
        }
        else if (puVar10[4] <= local_2c) goto LAB_000a8deb;
        puVar10 = puVar10 + 8;
      } while (local_38 != puVar10);
    }
    iVar5 = (**(code **)(*param_1 + 0xd8))(param_1,param_4,local_2c,iVar9,param_3);
    if (iVar5 != 0) {
      return iVar5;
    }
    local_30 = local_30 - iVar9;
    if ((int)local_30 < 1) {
      return 0;
    }
    local_2c = local_20;
    puVar10 = (uint *)*param_2;
    local_38 = (uint *)*piVar2;
    if (puVar10 != local_38) goto LAB_000a8d8b;
LAB_000a8ec4:
    uVar4 = param_3;
  } while( true );
}

