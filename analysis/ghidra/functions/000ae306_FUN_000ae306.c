/* 000ae306 FUN_000ae306 */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_000ae306(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint uVar6;
  uint local_2c;
  uint local_28;
  int local_20;
  
  if ((*(int *)(param_2 + 8) == 0x6c70636d) && ((*(byte *)(param_2 + 0xc) & 0x20) != 0)) {
    uVar6 = *(uint *)(param_2 + 0x1c);
    if ((uint)param_1[4] < uVar6) {
      puVar4 = (undefined4 *)___cxa_allocate_exception(4);
      *puVar4 = 0xffffd58c;
      goto LAB_000ae3ef;
    }
    local_20 = uVar6 - 1;
    local_28 = 1;
  }
  else {
    local_28 = *(uint *)(param_2 + 0x1c);
    uVar6 = 1;
    local_20 = 0;
  }
  puVar5 = (uint *)param_1[2];
  *puVar5 = uVar6;
  puVar5 = puVar5 + 1;
  uVar6 = param_1[3];
  iVar1 = *(int *)(param_2 + 0x18);
  iVar2 = param_1[5];
  local_2c = uVar6;
  if (local_20 != -1) {
    iVar3 = 0;
    do {
      *puVar5 = local_28;
      puVar5[2] = uVar6;
      puVar5[1] = iVar1 * param_3;
      uVar6 = uVar6 + (iVar1 * iVar2 + 0xfU & 0xfffffff0);
      puVar5 = puVar5 + 3;
      iVar3 = iVar3 + 1;
    } while (iVar3 != local_20 + 1);
    local_2c = param_1[3];
  }
  if (uVar6 - local_2c <= (uint)param_1[6]) {
    *param_1 = 1;
    return param_1[2];
  }
  puVar4 = (undefined4 *)___cxa_allocate_exception(4);
  *puVar4 = 0xffffd586;
LAB_000ae3ef:
                    /* WARNING: Subroutine does not return */
  ___cxa_throw(puVar4,PTR_001037fc,0);
}

