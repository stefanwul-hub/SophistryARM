/* 00080cf0 CScrollbarPl_vslot_72 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

longdouble CScrollbarPl_vslot_72(int param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  longdouble lVar7;
  int local_20;
  
  *(undefined1 *)(param_1 + 0x6d) = 0;
  *(undefined1 *)(param_1 + 0x6c) = 0;
  if (*(char *)(param_1 + 0xd4) == '\0') {
    iVar5 = *(int *)(param_1 + 0xcc) - *(int *)(param_1 + 0xc4);
  }
  else {
    iVar5 = *(int *)(param_1 + 200) - *(int *)(param_1 + 0xc0);
  }
  fVar1 = (float)(iVar5 + *(int *)(param_1 + 0xd8) * -2);
  lVar7 = (longdouble)FUN_00001ace(param_1,1);
  iVar4 = (int)((float)lVar7 * fVar1);
  iVar5 = (int)fVar1;
  if (iVar4 < 8) {
    local_20 = iVar5 + -8;
    iVar5 = 8;
  }
  else {
    if (iVar4 <= iVar5) {
      local_20 = iVar5 - iVar4;
      iVar2 = local_20 + iVar4;
      iVar5 = iVar4;
      goto joined_r0x00080e17;
    }
    local_20 = 0;
  }
  iVar2 = local_20 + iVar5;
joined_r0x00080e17:
  if (local_20 < 1) {
    return (longdouble)0;
  }
  if (*(char *)(param_1 + 0xd4) == '\0') {
    iVar4 = param_2[1];
    iVar6 = *(int *)(param_1 + 0xc);
  }
  else {
    iVar4 = *param_2;
    iVar6 = *(int *)(param_1 + 8);
  }
  if ((iVar4 < iVar6) || (iVar6 + *(int *)(param_1 + 0xd8) <= iVar4)) {
    if (iVar4 < iVar2 + iVar6) {
      iVar5 = (iVar4 - iVar5 / 2) - (iVar6 + *(int *)(param_1 + 0xd8));
    }
    else {
      lVar7 = (longdouble)FUN_00001ace(param_1,0);
      uVar3 = *(uint *)(param_1 + 0xd8);
      if (0x7fffffff < uVar3) {
        uVar3 = uVar3 + 7;
      }
      iVar5 = (int)((float)local_20 * (float)lVar7 + 0.499) + ((int)uVar3 >> 3);
      FUN_00001c28(param_1,0x28);
    }
  }
  else {
    lVar7 = (longdouble)FUN_00001ace(param_1,0);
    uVar3 = *(uint *)(param_1 + 0xd8);
    if (0x7fffffff < uVar3) {
      uVar3 = uVar3 + 7;
    }
    iVar5 = (int)((float)local_20 * (float)lVar7 + 0.499) - ((int)uVar3 >> 3);
    FUN_00001c28(param_1,0x28);
  }
  if (-1 < iVar5) {
    if (local_20 < iVar5) {
      lVar7 = (longdouble)FUN_000152c0();
      return lVar7;
    }
    lVar7 = (longdouble)FUN_000152c0();
    return lVar7;
  }
  lVar7 = (longdouble)FUN_000152c0();
  return lVar7;
}

