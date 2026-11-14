/* 000ae41e FUN_000ae41e */

/* WARNING: Function: __i686.get_pc_thunk.bx replaced with injection: get_pc_thunk_bx */

undefined4 FUN_000ae41e(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint local_20;
  
  if ((*(int *)(param_2 + 8) == 0x6c70636d) && ((*(byte *)(param_2 + 0xc) & 0x20) != 0)) {
    local_20 = *(uint *)(param_2 + 0x1c);
    if ((uint)param_1[4] < local_20) {
      puVar3 = (undefined4 *)___cxa_allocate_exception(4);
      *puVar3 = 0xffffd58c;
                    /* WARNING: Subroutine does not return */
      ___cxa_throw(puVar3,PTR_001037fc,0);
    }
    iVar4 = local_20 - 1;
    uVar6 = 1;
  }
  else {
    uVar6 = *(uint *)(param_2 + 0x1c);
    local_20 = 1;
    iVar4 = 0;
  }
  puVar2 = (uint *)param_1[2];
  *puVar2 = local_20;
  puVar2 = puVar2 + 1;
  iVar1 = *(int *)(param_2 + 0x18);
  if (iVar4 != -1) {
    iVar5 = 0;
    do {
      *puVar2 = uVar6;
      puVar2[2] = 0;
      puVar2[1] = iVar1 * param_3;
      puVar2 = puVar2 + 3;
      iVar5 = iVar5 + 1;
    } while (iVar5 != iVar4 + 1);
  }
  *param_1 = 2;
  return param_1[2];
}

