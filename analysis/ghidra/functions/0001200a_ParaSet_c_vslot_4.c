/* 0001200a ParaSet_c_vslot_4 */

/* WARNING: Restarted to delay deadcode elimination for space: stack */

uint ParaSet_c_vslot_4(int param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int local_30;
  int local_28;
  
  if (*(int *)(param_1 + 4) == 0) {
    return 0;
  }
  if (param_4 < 0) {
    param_4 = 0;
  }
  iVar3 = *(int *)(param_1 + 0xc);
  if (param_4 <= *(int *)(param_1 + 0xc)) {
    iVar3 = param_4;
  }
  if (((*(char *)(param_1 + 0x12) == '\0') &&
      (iVar3 = *(int *)(param_1 + 4) + iVar3 * *(int *)(param_1 + 0x18) * 0x70,
      0 < *(int *)(param_1 + 0x18))) && (3 < param_3 >> 2)) {
    uVar4 = 3;
    local_30 = 0;
    do {
      FUN_00010eee(iVar3);
      iVar1 = *(int *)(iVar3 + 4);
      if ((iVar1 == 7) || (iVar1 == 2)) {
        uVar2 = *(uint *)(param_2 + uVar4 * 4);
        uVar4 = uVar4 + 1;
        if (0 < (int)uVar2) {
          if (iVar1 == 7) {
            FUN_00010e34(iVar3,param_2 + uVar4 * 4);
            uVar4 = uVar4 + (uVar2 >> 2);
          }
          else {
            FUN_00010d02(iVar3,param_2 + uVar4 * 4);
            uVar4 = uVar4 + (uVar2 >> 2);
          }
        }
      }
      else if (iVar1 == 8) {
        iVar1 = *(int *)(param_2 + uVar4 * 4);
        uVar4 = uVar4 + 1;
        if (0 < iVar1) {
          puVar5 = (undefined4 *)(param_2 + uVar4 * 4);
          local_28 = 0;
          do {
            uVar4 = uVar4 + 1;
            FUN_000103f8(iVar3,local_28,*puVar5);
            local_28 = local_28 + 1;
            puVar5 = puVar5 + 1;
          } while (iVar1 != local_28);
        }
      }
      else {
        iVar1 = uVar4 * 4;
        uVar4 = uVar4 + 1;
        FUN_000109c8(iVar3,*(undefined4 *)(param_2 + iVar1));
      }
      local_30 = local_30 + 1;
    } while ((local_30 < *(int *)(param_1 + 0x18)) && (iVar3 = iVar3 + 0x70, uVar4 < param_3 >> 2));
  }
  return param_3;
}

